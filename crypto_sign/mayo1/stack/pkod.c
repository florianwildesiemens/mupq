// SPDX-License-Identifier: Apache-2.0
// -----------------------------------------------------
//   Copyright (c) Siemens 2025
// -----------------------------------------------------
/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <string.h>
#include "pkod.h"

#define PKOD_MIN(x, y) (((x) < (y)) ? (x) : (y))
#define BLOCK_INDEX(byte_pos)  ((byte_pos) / AES_BLOCKBYTES)
#define POS_IN_BLOCK(byte_pos) ((byte_pos) % AES_BLOCKBYTES)

static inline void ctr_to_plaintext(uint32_t ctr, uint32_t plaintext[4])
{
  ctr = ((ctr & (uint32_t)0x00FF00FF) << 8) | ((ctr >> 8) & (uint32_t)0x00FF00FF);
  plaintext[3] = (ctr << 16) | (ctr >> 16);
}

static void pkod_PRF(uint8_t * out, const uint_fast32_t off_bytes, size_t len_bytes,
                     mayo_pkod_prf_ctx_t * const ctx)
{
  uint32_t plaintext[AES_BLOCKBYTES / sizeof(uint32_t)] = {0};
  uint32_t ctr = BLOCK_INDEX(off_bytes);
  const unsigned pos_in_block = POS_IN_BLOCK(off_bytes);

  if (pos_in_block > 0u)
  { // We start in the middle of an AES block, check if we got it in cache, otherwise create it
    const size_t head_bytes = AES_BLOCKBYTES - pos_in_block;
    if (ctr != ctx->cache_ctr)
    { // Cache currently contains another block, which should not happen that often
      ctr_to_plaintext(ctr, plaintext);
      aes128_ecb_publicinputs(ctx->cache, (unsigned char *) plaintext, 1u, &(ctx->key));
      ctx->cache_ctr = ctr;
    }
    // Now we can copy the head bytes from our cache
    memcpy(out, ctx->cache + pos_in_block, head_bytes);
    out += head_bytes;
    len_bytes -= head_bytes;
    ctr++;
  }
  // Now we are at an AES block border and can produce the pseudo-random sequence directly in out
  for (; len_bytes >= AES_BLOCKBYTES; out += AES_BLOCKBYTES, len_bytes -= AES_BLOCKBYTES, ctr++)
  {
    ctr_to_plaintext(ctr, plaintext);
    aes128_ecb_publicinputs(out, (unsigned char *) plaintext, 1u, &(ctx->key));
  }
  if (len_bytes > 0)
  { // We have to append a partial AES block and will keep the rest in our cache for the next vector
    ctr_to_plaintext(ctr, plaintext);
    aes128_ecb_publicinputs(ctx->cache, (unsigned char *) plaintext, 1u, &(ctx->key));
    ctx->cache_ctr = ctr;
    // Now we can copy the tail bytes from our cache
    memcpy(out, ctx->cache, len_bytes);
  }
}

void pkod_get_vector(uint64_t out[M_VEC_LIMBS_MAX], const uint32_t vec_idx, const uint8_t P_idx,
                     mayo_pkod_t * const PP)
{
  /* The expanded public key is a consecutive array of vectors. First those of P1, followed by those
     of P2. P3 is expanded separately from a transmitted sequence (TRS) of bytes, not the PRF.
     A vector is a vector of m nibbles (i.e. 4 bit) organized as a consecutive array of limbs. A
     limb is a uint64_t, so a vector thus contains m_vec_limbs = (m + 15) / 16 limbs. The m nibbles
     are put in the front, so the first m/2 bytes of each vector contain the information, the
     remaining bytes are just padded with zeros. For P1 and P2, the nibbles come from the PRF, for
     P3 they come from the TRS. */
#ifdef TARGET_BIG_ENDIAN
  const size_t m_vec_limbs = (PP->m + 15u) / 16u; // The number of limbs in a vector
#endif
  const size_t bytes_from_SEQ = PP->m / 2u; // The number of bytes from the PRF or TRS in a vector
  const uint_fast32_t offset_in_SEQ = ((P_idx == 2u) ? (vec_idx + PP->P2_off) : vec_idx) * \
                                                                                     bytes_from_SEQ;

  if (P_idx == 3u)
  { // Copy required bytes from transmitted sequence (TRS) to head of vector
    memcpy(out, PP->trs + offset_in_SEQ, bytes_from_SEQ);
  }
  else
  { // Produce required sequence via PRF and place in head of vector
    pkod_PRF((uint8_t *) out, offset_in_SEQ, bytes_from_SEQ, &(PP->prf));
  }
#ifdef TARGET_BIG_ENDIAN
  for (size_t i = 0; i < m_vec_limbs; i++)
  { // Swap non-zero bytes if we are on a big-endian machine
    out[i] = BSWAP64(out[i]);
  }
#endif
}

void pkod_init(mayo_pkod_t * const PP, const mayo_params_t * const p,
               const unsigned char * const cpk)
{
  #ifndef ENABLE_PARAMS_DYNAMIC
  (void) p;
  #endif
  aes128_ctr_keyexp_publicinputs(&(PP->prf.key), cpk);
  PP->prf.cache_ctr = UINT32_MAX;
  PP->trs = cpk + PARAM_pk_seed_bytes(p);
  PP->P2_off = PARAM_P1_limbs(p) / PARAM_m_vec_limbs(p);
  PP->m = PARAM_m(p);
}
