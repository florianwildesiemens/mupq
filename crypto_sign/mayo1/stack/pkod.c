#include <string.h>
#include "pkod.h"

#define PKOD_MIN(x, y) (((x) < (y)) ? (x) : (y))
#define BLOCK_INDEX(byte_pos)  ((byte_pos) / AES_BLOCKBYTES)
#define POS_IN_BLOCK(byte_pos) ((byte_pos) % AES_BLOCKBYTES)

static inline void ctr_to_plain(uint32_t ctr, uint32_t plaintext[4])
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
      ctr_to_plain(ctr, plaintext);
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
    ctr_to_plain(ctr, plaintext);
    aes128_ecb_publicinputs(out, (unsigned char *) plaintext, 1u, &(ctx->key));
  }
  if (len_bytes > 0)
  { // We have to append a partial AES block and will keep the rest in our cache for the next vector
    ctr_to_plain(ctr, plaintext);
    aes128_ecb_publicinputs(ctx->cache, (unsigned char *) plaintext, 1u, &(ctx->key));
    ctx->cache_ctr = ctr;
    // Now we can copy the tail bytes from our cache
    memcpy(out, ctx->cache, len_bytes);
  }
}

void pkod_get_vector(uint64_t * const out, const uint32_t vec_idx, const mayo_pkod_point_t * const P)
{
  /* The expanded public key is a consecutive array of vectors. First those of P1, followed by those
     of P2. P3 is expanded separately from a transmitted sequence (TRS) of bytes, not the PRF.
     A vector is a consecutive array of m_vec_limbs = (m + 15) / 16 limbs. A limb is a uint64_t. The
     first m/2 bytes of each vector come from the PRF respectively TRS, the remaining bytes are
     zero. */
  const uint_fast8_t m_vec_limbs = (P->m + 15u) / 16u; // The number of limbs in a vector
  const size_t bytes_from_SEQ = P->m / 2u; // The number of bytes from the PRF or TRS in a vector
  const uint_fast32_t offset_in_SEQ = (P->vec_off + vec_idx) * bytes_from_SEQ;
  // The number of non-zero limbs in a vector
#ifdef TARGET_BIG_ENDIAN
  const uint_fast8_t limbs_with_SEQ = (bytes_from_SEQ + sizeof(uint64_t) - 1u) / sizeof(uint64_t);
#endif

  for (uint_fast8_t i = bytes_from_SEQ / sizeof(uint64_t); i < m_vec_limbs; i++)
  { // Quickly zeroize tail of vector
    out[i] = 0u;
  }
  if (P->point_type == 3u)
  { // Copy required bytes from transmitted sequence (TRS) to head of vector
    memcpy(out, P->src.trs + offset_in_SEQ, bytes_from_SEQ);
  }
  else
  { // Produce required sequence via PRF and place in head of vector
    pkod_PRF((uint8_t *) out, offset_in_SEQ, bytes_from_SEQ, P->src.prf);
  }

#ifdef TARGET_BIG_ENDIAN
  for (uint_fast8_t i = 0; i < limbs_with_SEQ; i++)
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
  aes128_ctr_keyexp_publicinputs(&(PP->ctx.key), cpk);
  PP->ctx.cache_ctr = UINT32_MAX;

  PP->P1.point_type = 1u;
  PP->P1.m = PARAM_m(p);
  PP->P1.vec_off = 0u;
  PP->P1.src.prf = &(PP->ctx);

  PP->P2.point_type = 2u;
  PP->P2.m = PP->P1.m;
  PP->P2.vec_off = PARAM_P1_limbs(p) / PARAM_m_vec_limbs(p);
  PP->P2.src.prf = &(PP->ctx);

  PP->P3.point_type = 3u;
  PP->P3.m = PP->P1.m;
  PP->P3.vec_off = 0u;
  PP->P3.src.trs = cpk + PARAM_pk_seed_bytes(p);
}
