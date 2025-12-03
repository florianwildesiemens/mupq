// SPDX-License-Identifier: Apache-2.0

#ifndef GENERIC_ARITHMETIC_H
#define GENERIC_ARITHMETIC_H

#include <simple_arithmetic.h>
#include <pkod.h>
#include <string.h>

#ifdef ENABLE_PARAMS_DYNAMIC
#include <arithmetic_dynamic.h>
#else
#include <arithmetic_fixed.h>
#endif

// multiplies m (possibly upper triangular) matrices with a single matrix and adds result to acc
static inline
void mul_add_m_upper_triangular_mat_x_mat(const int m_vec_limbs, const uint64_t *bs_mat, const unsigned char *mat, uint64_t *acc,
                                          const int bs_mat_rows, const int bs_mat_cols, const int mat_cols, const int triangular) {

    int bs_mat_entries_used = 0;
    for (int r = 0; r < bs_mat_rows; r++) {
        for (int c = triangular * r; c < bs_mat_cols; c++) {
            for (int k = 0; k < mat_cols; k += 1) {
                m_vec_mul_add(m_vec_limbs, bs_mat + m_vec_limbs * bs_mat_entries_used, mat[c * mat_cols + k], acc + m_vec_limbs * (r * mat_cols + k));
            }
            bs_mat_entries_used += 1;
        }
    }
}

// multiplies m (possibly upper triangular) matrices with the transpose of a single matrix and adds result to acc
static inline
void mul_add_m_upper_triangular_mat_x_mat_trans(const int m_vec_limbs, const uint64_t *bs_mat, const unsigned char *mat, uint64_t *acc,
                                                const int bs_mat_rows, const int bs_mat_cols, const int mat_rows, const int triangular) {
    int bs_mat_entries_used = 0;
    for (int r = 0; r < bs_mat_rows; r++) {
        for (int c = triangular * r; c < bs_mat_cols; c++) {
            for (int k = 0; k < mat_rows; k += 1) {
                m_vec_mul_add(m_vec_limbs, bs_mat + m_vec_limbs * bs_mat_entries_used, mat[k * bs_mat_cols + c], acc + m_vec_limbs * (r * mat_rows + k));
            }
            bs_mat_entries_used += 1;
        }
    }
}

// multiplies the transpose of a single matrix with m matrices and adds result to acc
static inline
void mul_add_mat_trans_x_m_mat(const int m_vec_limbs, const unsigned char *mat, const uint64_t *bs_mat, uint64_t *acc,
                               const int mat_rows, const int mat_cols, const int bs_mat_cols) {

    for (int r = 0; r < mat_cols; r++) {
        for (int c = 0; c < mat_rows; c++) {
            for (int k = 0; k < bs_mat_cols; k += 1) {
                m_vec_mul_add(m_vec_limbs, bs_mat + m_vec_limbs * (c * bs_mat_cols + k), mat[c * mat_cols + r], acc + m_vec_limbs * (r * bs_mat_cols + k));
            }
        }
    }
}

// multiplies a single matrix with m matrices and adds result to acc
static inline
void mul_add_mat_x_m_mat(const int m_vec_limbs, const unsigned char *mat, const uint64_t *bs_mat, uint64_t *acc,
                         const int mat_rows, const int mat_cols, const int bs_mat_cols) {

    for (int r = 0; r < mat_rows; r++) {
        for (int c = 0; c < mat_cols; c++) {
            for (int k = 0; k < bs_mat_cols; k += 1) {
                m_vec_mul_add(m_vec_limbs, bs_mat + m_vec_limbs * (c * bs_mat_cols + k), mat[r * mat_cols + c], acc + m_vec_limbs * (r * bs_mat_cols + k));
            }
        }
    }
}

static inline
void P1_times_O(const mayo_params_t* p, const uint64_t* P1, const unsigned char* O, uint64_t* acc){
    #ifndef ENABLE_PARAMS_DYNAMIC
    (void) p;
    #endif
    mul_add_m_upper_triangular_mat_x_mat(PARAM_m_vec_limbs(p), P1, O, acc, PARAM_v(p), PARAM_v(p), PARAM_o(p), 1);
}

static inline
void P1_times_Vt(const mayo_params_t* p, const uint64_t* P1, const unsigned char* V, uint64_t* acc){
    #ifndef ENABLE_PARAMS_DYNAMIC
    (void) p;
    #endif
    mul_add_m_upper_triangular_mat_x_mat_trans(PARAM_m_vec_limbs(p), P1, V, acc, PARAM_v(p), PARAM_v(p), PARAM_k(p), 1);
}

#if defined(HAVE_STACKEFFICIENT) || defined(PQM4)
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

#else

// compute P * S^t = [ P1  P2 ] * [S1] = [P1*S1 + P2*S2]
//                   [  0  P3 ]   [S2]   [        P3*S2]
static inline void mayo_generic_m_calculate_PS(mayo_pkod_t * const pkod, const unsigned char *S, const int m, const int v, const int o, const int k, uint64_t *PS) {

    const int n = o + v;
    const int m_vec_limbs = (m + 15)/16;

    uint64_t accumulator[16 * ((M_MAX+15)/16) * K_MAX * N_MAX] = {0};
    uint64_t vector[(M_MAX+15)/16] = {0}; // Must be zero initialized, because pkod_get_vector() only sets m_vec_limbs per vector, but m_vec_add() from arithmetic_fixed.h adds M_VEC_LIMBS_MAX per vector
    int P1_used = 0;
    for (int row = 0; row < v; row++) {
        for (int j = row; j < v; j++) {
            pkod_get_vector(vector, P1_used, 1u, pkod);
            for (int col = 0; col < k; col++) {
                m_vec_add(m_vec_limbs, vector, accumulator + ( (row * k + col) * 16 + S[col * n + j] )*m_vec_limbs);
            }
            P1_used ++;
        }

        for (int j = 0; j < o; j++) {
            pkod_get_vector(vector, (row * o + j), 2u, pkod);
            for (int col = 0; col < k; col++) {
                m_vec_add(m_vec_limbs, vector, accumulator + ( (row * k + col) * 16 + S[(col * n) + j + v] )* m_vec_limbs);
            }
        }
    }

    int P3_used = 0;
    for (int row = v; row < n; row++) {
        for (int j = row; j < n; j++) {
            pkod_get_vector(vector, P3_used, 3u, pkod);
            for (int col = 0; col < k; col++) {
                m_vec_add(m_vec_limbs, vector, accumulator + ( (row * k + col) * 16 + S[col * n + j] )* m_vec_limbs );
            }
            P3_used ++;
        }
    }

    // multiply stuff according to the bins of the accumulator and add to PS.
    int i = 0;
    while (i < n * k) {
        m_vec_multiply_bins(m_vec_limbs, accumulator + i * 16 * m_vec_limbs, PS + i * m_vec_limbs);
        i++;
    }

}

// compute S * PS  = [ S1 S2 ] * [ P1*S1 + P2*S2 = P1 ] = [ S1*P1 + S2*P2 ]
//                               [         P3*S2 = P2 ]
static inline void mayo_generic_m_calculate_SPS(const uint64_t *PS, const unsigned char *S, int m, int k, int  n, uint64_t *SPS){
    uint64_t accumulator[16*((M_MAX+15)/16)*K_MAX*K_MAX] = {0};
    const int m_vec_limbs = (m + 15)/ 16;
    for (int row = 0; row < k; row++) {
        for (int j = 0; j < n; j++) {
            for (int col = 0; col < k; col += 1) {
                    m_vec_add(m_vec_limbs, PS + (j * k + col) * m_vec_limbs, accumulator + ( (row * k + col) * 16 + S[row * n + j] )*m_vec_limbs);
            }
        }
    }

    // multiply stuff according to the bins of the accumulator and add to PS.
    int i = 0;
    while (i < k*k) {
        m_vec_multiply_bins(m_vec_limbs, accumulator + i * 16 * m_vec_limbs, SPS + i * m_vec_limbs);
        i++;
    }
}

#endif


static inline
void P1P1t_times_O(const mayo_params_t* p, const uint64_t* P1, const unsigned char* O, uint64_t* acc){
    #ifndef ENABLE_PARAMS_DYNAMIC
    (void) p;
    #endif
    const int param_o = PARAM_o(p);
    const int param_v = PARAM_v(p);
    const int m_vec_limbs = PARAM_m_vec_limbs(p);

    int bs_mat_entries_used = 0;
    for (int r = 0; r < param_v; r++) {
        for (int c = r; c < param_v; c++) {
            if(c==r) {
                bs_mat_entries_used += 1;
                continue;
            }
            for (int k = 0; k < param_o; k += 1) {
                m_vec_mul_add(m_vec_limbs, P1 + m_vec_limbs * bs_mat_entries_used, O[c * param_o + k], acc + m_vec_limbs * (r * param_o + k));
                m_vec_mul_add(m_vec_limbs, P1 + m_vec_limbs * bs_mat_entries_used, O[r * param_o + k], acc + m_vec_limbs * (c * param_o + k));
            }
            bs_mat_entries_used += 1;
        }
    }
}


static inline
void compute_M_and_VPV(const mayo_params_t* p, const unsigned char* Vdec, const uint64_t *L, const uint64_t *P1, uint64_t *VL, uint64_t *VP1V){

    const int param_k = PARAM_k(p);
    const int param_v = PARAM_v(p);
    const int param_o = PARAM_o(p);

    //VL
    mul_add_mat_x_m_mat(PARAM_m_vec_limbs(p), Vdec, L, VL, param_k, param_v, param_o);

    //VP1V
    uint64_t Pv[V_MAX * K_MAX * M_VEC_LIMBS_MAX] = {0};
    P1_times_Vt(p, P1, Vdec, Pv);
    mul_add_mat_x_m_mat(PARAM_m_vec_limbs(p), Vdec, Pv, VP1V, param_k, param_v, param_k);
}

static inline
void compute_P3(const mayo_params_t* p, const uint64_t* P1, uint64_t *P2, const unsigned char *O, uint64_t *P3){

    const int m_vec_limbs = PARAM_m_vec_limbs(p);
    const int param_v = PARAM_v(p);
    const int param_o = PARAM_o(p);

    // compute P1*O + P2
    P1_times_O(p, P1, O, P2);

    // compute P3 = O^t * (P1*O + P2)
    mul_add_mat_trans_x_m_mat(m_vec_limbs, O, P2, P3, param_v, param_o, param_o);
}

// compute P * S^t = [ P1  P2 ] * [S1] = [P1*S1 + P2*S2]
//                   [  0  P3 ]   [S2]   [        P3*S2]
// compute S * PS  = [ S1 S2 ] * [ P1*S1 + P2*S2 = P1 ] = [ S1*P1 + S2*P2 ]
//                               [         P3*S2 = P2 ]
static inline void m_calculate_PS_SPS(const mayo_params_t *p, mayo_pkod_t * const pkod, const unsigned char *s, uint64_t *SPS) {
    // compute P * S^t = {(P1, P2), (0, P3)} * S^t = {(P1*S1 + P2*S2), (P3 * S2)}
    #ifndef ENABLE_PARAMS_DYNAMIC
    (void) p;
    #endif
    #if defined(HAVE_STACKEFFICIENT) || defined(PQM4)
    mayo_generic_m_calculate_PS_SPS(pkod, s, PARAM_m(p), PARAM_v(p), PARAM_o(p), PARAM_k(p), SPS);
    #else
    uint64_t PS[N_MAX * K_MAX * M_VEC_LIMBS_MAX] = { 0 };
    mayo_generic_m_calculate_PS(P1, P2, P3, s, PARAM_m(p), PARAM_v(p), PARAM_o(p), PARAM_k(p), PS);

    // compute S * P * S = S* (P*S)
    mayo_generic_m_calculate_SPS(PS, s, PARAM_m(p), PARAM_k(p), PARAM_n(p), SPS);
    #endif
}

#endif
