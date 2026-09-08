// SPDX-License-Identifier: Apache-2.0
/* Copyright 2026 Siemens AG
 *
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

#include <pkod.h>

// compute P * S^t = [ P1  P2 ] * [S1] = [P1*S1 + P2*S2]
//                   [  0  P3 ]   [S2]   [        P3*S2]
// compute S * PS  = [ S1 S2 ] * [ P1*S1 + P2*S2 = PS1 ] = [ S1*PS1 + S2*PS2 ]
//                               [         P3*S2 = PS2 ]

/* With a dynamically expanded public key, it is crucial for runtime to expand it only once. So, to
   use each element of P only once. We thus calculate S * P * S^t by reordering the sums and
   multiplications to have the loops iterating P as the outermost ones.

   SPS is a k by k matrix of vectors, equivalent to a k by k by m cuboid of nibbles. Its elements
   can be calculated as
     SPS_{i,j} = SUM_{h,l} P_{h,l} S_{i,h} S_{j,l}
   where i, j run from 1 to k, and h, l run from 1 to n.

   To iterate over the elements of P only once, we calculate all elements of SPS in parallel. So, we
   iterate over i, j in the inner loops and over h, l in the outer loops.

   Since we now use the same element of P k^2 times in various multiples, we can cheaply get rid of
   the accumulator by calculating all multiples once after generating the element of P and adding
   the respective multiple directly on the corresponding element of SPS. While we need to hold the
   15 multiples of the element of P now, these 15*M_VEC_LIMBS_MAX uint64_t are k^2 times less than
   the size of the accumulator of K_MAX*K_MAX*15*M_VEC_LIMBS_MAX.

   To save some run-time in the innermost loops, the product of the two elements of S is found in a
   16 by 16 look-up table. This way the innermost loop does not have to perform any multiplications,
   but only a table look-up to get an index for the following add operation.

   Note that we rely on S being passed as a k by n matrix in conventional C memory organization,
   which means S[0] up to S[n-1] provide the first row of S.
 */

  /** Macro to iterate over all entries of SPS within mayo_generic_m_calculate_PS_SPS()

     While iterating over i = SPS_row, j = SPS_col, the elements of S are accessed column-wise.
     Therefore, it is more efficient to keep a pointer for each of the two columns and increment it
     by n rather than calculating the indexes everytime from SPS_row and SPS_col. */

#define BINS (16u - 1u)
static void mayo_generic_get_P_vector_multiples(uint64_t P[BINS][M_VEC_LIMBS_MAX],
                                                const uint32_t vec_idx, const uint8_t P_idx,
                                                mayo_pkod_t * const pkod,
                                                const unsigned m_vec_limbs)
{
  pkod_get_vector(P[0], vec_idx, P_idx, pkod);
  m_vec_mul_x(m_vec_limbs, P[0], P[1]);
  m_vec_copy(m_vec_limbs, P[1], P[2]);
  m_vec_add(m_vec_limbs, P[0], P[2]);
  m_vec_mul_x(m_vec_limbs, P[1], P[3]);
  m_vec_copy(m_vec_limbs, P[3], P[4]);
  m_vec_add(m_vec_limbs, P[0], P[4]);
  m_vec_copy(m_vec_limbs, P[3], P[5]);
  m_vec_add(m_vec_limbs, P[1], P[5]);
  m_vec_copy(m_vec_limbs, P[3], P[6]);
  m_vec_add(m_vec_limbs, P[2], P[6]);
  m_vec_mul_x(m_vec_limbs, P[3], P[7]);
  m_vec_copy(m_vec_limbs, P[7], P[8]);
  m_vec_add(m_vec_limbs, P[0], P[8]);
  m_vec_copy(m_vec_limbs, P[7], P[9]);
  m_vec_add(m_vec_limbs, P[1], P[9]);
  m_vec_copy(m_vec_limbs, P[7], P[10]);
  m_vec_add(m_vec_limbs, P[2], P[10]);
  m_vec_copy(m_vec_limbs, P[7], P[11]);
  m_vec_add(m_vec_limbs, P[3], P[11]);
  m_vec_copy(m_vec_limbs, P[7], P[12]);
  m_vec_add(m_vec_limbs, P[4], P[12]);
  m_vec_copy(m_vec_limbs, P[7], P[13]);
  m_vec_add(m_vec_limbs, P[5], P[13]);
  m_vec_copy(m_vec_limbs, P[7], P[14]);
  m_vec_add(m_vec_limbs, P[6], P[14]);
}

#define ADD_FOR_SPS                                                                                \
  const unsigned char * S_h = S + P_row;                                                           \
  for (uint_fast8_t SPS_row = 0; SPS_row < k; SPS_row++, S_h += n)                                 \
  {                                                                                                \
    if (0 < *S_h)                                                                                  \
    {                                                                                              \
      const unsigned char * S_l = S + P_col;                                                       \
      for (uint_fast8_t SPS_col = 0; SPS_col < k; SPS_col++, S_l += n)                             \
      {                                                                                            \
        if (0 < *S_l)                                                                              \
        {                                                                                          \
          m_vec_add(m_vec_limbs, Phl[mul_f_LUT(*S_h, *S_l)-1u], accumulator[SPS_row][SPS_col]);    \
        }                                                                                          \
      }                                                                                            \
    }                                                                                              \
  }

static inline void mayo_generic_m_calculate_PS_SPS(mayo_pkod_t * const pkod,
                                                   const unsigned char * const S,
                                                   const unsigned m, const unsigned v,
                                                   const unsigned o, const unsigned k,
                                                   uint64_t * SPS)
{
  uint64_t (*accumulator)[K_MAX][M_VEC_LIMBS_MAX] = (uint64_t (*)[K_MAX][M_VEC_LIMBS_MAX])SPS;
  uint64_t Phl[BINS][M_VEC_LIMBS_MAX] = {0};

#define NIBBLES_PER_LIMB (64 / 4)
  const unsigned m_vec_limbs = (m + (NIBBLES_PER_LIMB - 1)) / NIBBLES_PER_LIMB;
  const unsigned n = o + v;
#define S_IDX(r,c) (((r) * n) + (c))

  uint_fast16_t P_lix = 0;
  for (uint_fast8_t P_row = 0; P_row < v; P_row++)
  {
    for (uint_fast8_t P_col = P_row; P_col < v; P_col++)
    {
      mayo_generic_get_P_vector_multiples(Phl, P_lix++, 1u, pkod, m_vec_limbs);
      ADD_FOR_SPS
    }
  }
  P_lix = 0;
  for (uint_fast8_t P_row = 0; P_row < v; P_row++)
  {
    for (uint_fast8_t P_col = v; P_col < n; P_col++)
    {
      mayo_generic_get_P_vector_multiples(Phl, P_lix++, 2u, pkod, m_vec_limbs);
      ADD_FOR_SPS
    }
  }
  P_lix = 0;
  for (uint_fast8_t P_row = v; P_row < n; P_row++)
  {
    for (uint_fast8_t P_col = P_row; P_col < n; P_col++)
    {
      mayo_generic_get_P_vector_multiples(Phl, P_lix++, 3u, pkod, m_vec_limbs);
      ADD_FOR_SPS
    }
  }
}

