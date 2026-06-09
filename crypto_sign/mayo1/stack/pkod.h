// SPDX-License-Identifier: Apache-2.0

#ifndef PKOD_H
#define PKOD_H
#include <stddef.h>
#include <stdint.h>
#include "aes-publicinputs.h"
#include "mayo.h"

/**
 * Mayo pseudo-random function (PRF) context.
 */
typedef struct
{
  aes128ctx_publicinputs key;     ///< Expanded seed for PRF.
  uint8_t cache[AES_BLOCKBYTES];  ///< Buffer for holding output of PRF.
  uint32_t cache_ctr;             ///< The counter value used to produce the block in cache.
} mayo_pkod_prf_ctx_t;

/**
 * On-demand decompressed public key.
 */
typedef struct
{
  mayo_pkod_prf_ctx_t prf;        ///< PRF source for P1 and P2.
  const uint8_t * trs;            ///< Transmitted sequence for P3.
  uint32_t P2_off;                /**< Offset to add to vec_idx for calculating position in PRF for
                                       P2. Equals PARAM_P1_limbs/m_vec_limbs. */
  uint8_t m;                      ///< Parameter m.
} mayo_pkod_t;

/**
 * Initialize an on-demand decompressed public key instance.
 *
 * @param[out] PP The pkod instance to initialize
 * @param[in] p Mayo parameter set
 * @param[in] cpk Compressed public key
 */
void pkod_init(mayo_pkod_t * const PP, const mayo_params_t * const p,
               const unsigned char * const cpk);

/**
 * Decompress a vector of P1, P2, or P3 on-demand
 *
 * Note that only the first m/2 bytes will be set. The caller is responsible for zeroizing the tail
 * bytes.
 *
 * @param[out] out Where to place the decompressed vector
 * @param[in] vec_idx Which vector of the given point to return
 * @param[in] P_idx Which point to return a vector from
 * @param[in] PP An initialized mayo_pkod_t instance
 */
void pkod_get_vector(uint64_t out[M_VEC_LIMBS_MAX], const uint32_t vec_idx, const uint8_t P_idx,
                     mayo_pkod_t * const PP);

#endif
