// SPDX-License-Identifier: Apache-2.0

#ifndef PKOD_H
#define PKOD_H
#include <stddef.h>
#include <stdint.h>
#include "aes-publicinputs.h"
#include "mayo.h"

/**
 * On-demand decompressed public key point via pseudo-random function (PRF).
 */
typedef struct
{
  const aes128ctx_publicinputs * key; ///< Pointer to expanded seed for PRF.
  uint8_t cache[AES_BLOCKBYTES];  ///< Buffer for holding output of PRF.
  uint32_t cache_ctr; ///< The counter value used to produce the block in cache.
} mayo_pkod_prf_point_t;

/**
 * On-demand decompressed public key point from transmitted sequence (TRS).
 */
typedef struct
{
  const uint8_t * seq; ///< Pointer to the transmitted sequence.
} mayo_pkod_trs_point_t;

/**
 * On-demand decompressed public key point.
 */
typedef struct
{
  union
  {
    mayo_pkod_prf_point_t prf;
    mayo_pkod_trs_point_t trs;
  } src; ///< Type specific data for this point.
  uint32_t limb_off;  /**< Limb offset for this point, which is 0 for P1 and P3,
                           and PARAM_P1_limbs for P2. */
  uint8_t m;        ///< Parameter m.
  uint8_t point_type; ///< Type of point. If equal to 3, trs is used, otherwise prf.
} mayo_pkod_point_t;

/**
 * On-demand decompressed public key.
 */
typedef struct
{
  aes128ctx_publicinputs key; ///< Expanded key for PRF
  mayo_pkod_point_t P1;
  mayo_pkod_point_t P2;
  mayo_pkod_point_t P3;
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
 * Decompress a limb of P1, P2, or P3 on-demand
 *
 * @param[in] i Limb index within the given point to return
 * @param[in] P Point to return a limb of, either P1, P2, or P3 of a mayo_pkod_t instance
 * @return The requested limb of the given point
 */
uint64_t pkod_P(const uint_fast32_t i, mayo_pkod_point_t * const P);

#endif
