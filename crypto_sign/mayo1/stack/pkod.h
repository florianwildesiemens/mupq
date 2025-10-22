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
  aes128ctx_publicinputs key; ///< Expanded seed for PRF.
  uint8_t cache[AES_BLOCKBYTES];  ///< Buffer for holding output of PRF.
  uint32_t cache_ctr; ///< The counter value used to produce the block in cache.
} mayo_pkod_prf_ctx_t;

/**
 * On-demand decompressed public key point.
 */
typedef struct
{
  union
  {
    mayo_pkod_prf_ctx_t * prf;
    const uint8_t * trs;
  } src; ///< Type specific data for this point.
  uint32_t vec_off;  /**< Offset to add to vec_idx for calculating position in src.
                          Is 0 for P1 and P3, and PARAM_P1_limbs/m_vec_limbs for P2. */
  uint8_t m;        ///< Parameter m.
  uint8_t point_type; ///< Type of point. If equal to 3, trs is used, otherwise prf.
} mayo_pkod_point_t;

/**
 * On-demand decompressed public key.
 */
typedef struct
{
  mayo_pkod_point_t P1;
  mayo_pkod_point_t P2;
  mayo_pkod_point_t P3;
  mayo_pkod_prf_ctx_t ctx;
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
 * @param[out] out Where to place the decompressed vector
 * @param[in] vec_idx Which vector of the provided point to return
 * @param[in] P Point to return a vector of, either P1, P2, or P3 of a mayo_pkod_t instance
 */
void pkod_get_vector(uint64_t * const out, const uint32_t vec_idx, const mayo_pkod_point_t * const P);

#endif
