// SPDX-License-Identifier: Apache-2.0

#ifndef MAYO_H
#define MAYO_H

#ifndef PQM4
#define PQM4
#endif
#include "mayo_variant.h"
#define MAYO_q 16

#include <stdint.h>
#include <stdlib.h>

#define F_TAIL_LEN 4
#define F_TAIL_64                                                              \
  { 8, 0, 2, 8 } // f(z) =  z^64 + x^3*z^3 + x*z^2 + x^3
#define F_TAIL_78                                                              \
  { 8, 1, 1, 0 } // f(z) =  z^78 + z^2 + z + x^3
#define F_TAIL_108                                                             \
  { 8, 0, 1, 7 } // f(z) =  z^108 + (x^2 + x + 1)*z^3 + z^2 + x^3
#define F_TAIL_142                                                             \
  { 4, 0, 8, 1 } // f(z) =  z^142 + z^3 + x^3*z^2 + x^2

#define MAYO_1_name "MAYO_1"
#define MAYO_1_n 86
#define MAYO_1_m 78
#define MAYO_1_m_vec_limbs 5
#define MAYO_1_o 8
#define MAYO_1_v (MAYO_1_n - MAYO_1_o)
#define MAYO_1_A_cols (MAYO_1_k * MAYO_1_o + 1)
#define MAYO_1_k 10
#define MAYO_1_q 16
#define MAYO_1_m_bytes 39
#define MAYO_1_O_bytes 312
#define MAYO_1_v_bytes 39
#define MAYO_1_r_bytes 40
#define MAYO_1_P1_bytes 120159
#define MAYO_1_P2_bytes 24336
#define MAYO_1_P3_bytes 1404
#define MAYO_1_csk_bytes 24
#define MAYO_1_cpk_bytes 1420
#define MAYO_1_sig_bytes 454
#define MAYO_1_f_tail F_TAIL_78
#define MAYO_1_f_tail_arr f_tail_78
#define MAYO_1_salt_bytes 24
#define MAYO_1_digest_bytes 32
#define MAYO_1_pk_seed_bytes 16
#define MAYO_1_sk_seed_bytes 24

#define MAYO_109_name "MAYO_109"
#define MAYO_109_n 85
#define MAYO_109_m 76
#define MAYO_109_o 9
#define MAYO_109_k 9
#define MAYO_109_cpk_bytes 1726
#define MAYO_109_sig_bytes 406
#define F_TAIL_76_9 { 2, 2, 4, 2 } /* z^76 + x*z^3 + x^2*z^2 + x*z + x */
#define MAYO_109_f_tail F_TAIL_76_9
#define MAYO_109_f_tail_arr f_tail_76_9
#define MAYO_109_m_vec_limbs ((MAYO_109_m + 15) / 16)
#define MAYO_109_v (MAYO_109_n - MAYO_109_o)
#define MAYO_109_A_cols (MAYO_109_k * MAYO_109_o + 1)
#define MAYO_109_r_bytes (MAYO_109_A_cols / 2)
#define MAYO_109_O_bytes (((MAYO_109_v * MAYO_109_o) + 1) / 2)
#define MAYO_109_v_bytes ((MAYO_109_v + 1) / 2)
#define MAYO_109_m_bytes ((MAYO_109_m + 1) / 2)
#define MAYO_109_P1_bytes (((MAYO_109_v * (MAYO_109_v + 1)) / 2) * MAYO_109_m_bytes)
#define MAYO_109_P2_bytes (( MAYO_109_v *  MAYO_109_o)           * MAYO_109_m_bytes)
#define MAYO_109_P3_bytes (((MAYO_109_o * (MAYO_109_o + 1)) / 2) * MAYO_109_m_bytes)
#define MAYO_109_csk_bytes MAYO_1_csk_bytes
#define MAYO_109_salt_bytes MAYO_1_salt_bytes
#define MAYO_109_digest_bytes MAYO_1_digest_bytes
#define MAYO_109_pk_seed_bytes MAYO_1_pk_seed_bytes
#define MAYO_109_sk_seed_bytes MAYO_1_sk_seed_bytes
#define MAYO_109_q MAYO_q

#define MAYO_108_name "MAYO_108"
#define MAYO_108_n 84
#define MAYO_108_m 74
#define MAYO_108_o 10
#define MAYO_108_k 8
#define MAYO_108_cpk_bytes 2051
#define MAYO_108_sig_bytes 360
#define F_TAIL_74_8 { 8, 0, 2, 8 } /* z^74 + x^3*z^3 + x*z^2 + x^3 */
#define MAYO_108_f_tail F_TAIL_74_8
#define MAYO_108_f_tail_arr f_tail_74_8
#define MAYO_108_m_vec_limbs ((MAYO_108_m + 15) / 16)
#define MAYO_108_v (MAYO_108_n - MAYO_108_o)
#define MAYO_108_A_cols (MAYO_108_k * MAYO_108_o + 1)
#define MAYO_108_r_bytes (MAYO_108_A_cols / 2)
#define MAYO_108_O_bytes (((MAYO_108_v * MAYO_108_o) + 1) / 2)
#define MAYO_108_v_bytes ((MAYO_108_v + 1) / 2)
#define MAYO_108_m_bytes ((MAYO_108_m + 1) / 2)
#define MAYO_108_P1_bytes (((MAYO_108_v * (MAYO_108_v + 1)) / 2) * MAYO_108_m_bytes)
#define MAYO_108_P2_bytes (( MAYO_108_v *  MAYO_108_o)           * MAYO_108_m_bytes)
#define MAYO_108_P3_bytes (((MAYO_108_o * (MAYO_108_o + 1)) / 2) * MAYO_108_m_bytes)
#define MAYO_108_csk_bytes MAYO_1_csk_bytes
#define MAYO_108_salt_bytes MAYO_1_salt_bytes
#define MAYO_108_digest_bytes MAYO_1_digest_bytes
#define MAYO_108_pk_seed_bytes MAYO_1_pk_seed_bytes
#define MAYO_108_sk_seed_bytes MAYO_1_sk_seed_bytes
#define MAYO_108_q MAYO_q

#define MAYO_107_name "MAYO_107"
#define MAYO_107_n 81
#define MAYO_107_m 70
#define MAYO_107_o 11
#define MAYO_107_k 7
#define MAYO_107_cpk_bytes 2326
#define MAYO_107_sig_bytes 307
#define F_TAIL_70_7 { 8, 1, 0, 1 } /* z^70 + z^3 + z + x^3 */
#define MAYO_107_f_tail F_TAIL_70_7
#define MAYO_107_f_tail_arr f_tail_70_7
#define MAYO_107_m_vec_limbs ((MAYO_107_m + 15) / 16)
#define MAYO_107_v (MAYO_107_n - MAYO_107_o)
#define MAYO_107_A_cols (MAYO_107_k * MAYO_107_o + 1)
#define MAYO_107_r_bytes (MAYO_107_A_cols / 2)
#define MAYO_107_O_bytes (((MAYO_107_v * MAYO_107_o) + 1) / 2)
#define MAYO_107_v_bytes ((MAYO_107_v + 1) / 2)
#define MAYO_107_m_bytes ((MAYO_107_m + 1) / 2)
#define MAYO_107_P1_bytes (((MAYO_107_v * (MAYO_107_v + 1)) / 2) * MAYO_107_m_bytes)
#define MAYO_107_P2_bytes (( MAYO_107_v *  MAYO_107_o)           * MAYO_107_m_bytes)
#define MAYO_107_P3_bytes (((MAYO_107_o * (MAYO_107_o + 1)) / 2) * MAYO_107_m_bytes)
#define MAYO_107_csk_bytes MAYO_1_csk_bytes
#define MAYO_107_salt_bytes MAYO_1_salt_bytes
#define MAYO_107_digest_bytes MAYO_1_digest_bytes
#define MAYO_107_pk_seed_bytes MAYO_1_pk_seed_bytes
#define MAYO_107_sk_seed_bytes MAYO_1_sk_seed_bytes
#define MAYO_107_q MAYO_q

#define MAYO_106_name "MAYO_106"
#define MAYO_106_n 70
#define MAYO_106_m 68
#define MAYO_106_o 12
#define MAYO_106_k 6
#define MAYO_106_cpk_bytes 2668
#define MAYO_106_sig_bytes 264
#define F_TAIL_68_6 { 2, 0, 1, 1 } /* z^68 + z^3 + z^2 + x */
#define MAYO_106_f_tail F_TAIL_68_6
#define MAYO_106_f_tail_arr f_tail_68_6
#define MAYO_106_m_vec_limbs ((MAYO_106_m + 15) / 16)
#define MAYO_106_v (MAYO_106_n - MAYO_106_o)
#define MAYO_106_A_cols (MAYO_106_k * MAYO_106_o + 1)
#define MAYO_106_r_bytes (MAYO_106_A_cols / 2)
#define MAYO_106_O_bytes (((MAYO_106_v * MAYO_106_o) + 1) / 2)
#define MAYO_106_v_bytes ((MAYO_106_v + 1) / 2)
#define MAYO_106_m_bytes ((MAYO_106_m + 1) / 2)
#define MAYO_106_P1_bytes (((MAYO_106_v * (MAYO_106_v + 1)) / 2) * MAYO_106_m_bytes)
#define MAYO_106_P2_bytes (( MAYO_106_v *  MAYO_106_o)           * MAYO_106_m_bytes)
#define MAYO_106_P3_bytes (((MAYO_106_o * (MAYO_106_o + 1)) / 2) * MAYO_106_m_bytes)
#define MAYO_106_csk_bytes MAYO_1_csk_bytes
#define MAYO_106_salt_bytes MAYO_1_salt_bytes
#define MAYO_106_digest_bytes MAYO_1_digest_bytes
#define MAYO_106_pk_seed_bytes MAYO_1_pk_seed_bytes
#define MAYO_106_sk_seed_bytes MAYO_1_sk_seed_bytes
#define MAYO_106_q MAYO_q

#define MAYO_105_name "MAYO_105"
#define MAYO_105_n 80
#define MAYO_105_m 66
#define MAYO_105_o 14
#define MAYO_105_k 5
#define MAYO_105_cpk_bytes 3481
#define MAYO_105_sig_bytes 224
#define F_TAIL_66_5 { 4, 0, 8, 4 } /* z^66 + x^2*z^3 + x^3*z^2 + x^2 */
#define MAYO_105_f_tail F_TAIL_66_5
#define MAYO_105_f_tail_arr f_tail_66_5
#define MAYO_105_m_vec_limbs ((MAYO_105_m + 15) / 16)
#define MAYO_105_v (MAYO_105_n - MAYO_105_o)
#define MAYO_105_A_cols (MAYO_105_k * MAYO_105_o + 1)
#define MAYO_105_r_bytes (MAYO_105_A_cols / 2)
#define MAYO_105_O_bytes (((MAYO_105_v * MAYO_105_o) + 1) / 2)
#define MAYO_105_v_bytes ((MAYO_105_v + 1) / 2)
#define MAYO_105_m_bytes ((MAYO_105_m + 1) / 2)
#define MAYO_105_P1_bytes (((MAYO_105_v * (MAYO_105_v + 1)) / 2) * MAYO_105_m_bytes)
#define MAYO_105_P2_bytes (( MAYO_105_v *  MAYO_105_o)           * MAYO_105_m_bytes)
#define MAYO_105_P3_bytes (((MAYO_105_o * (MAYO_105_o + 1)) / 2) * MAYO_105_m_bytes)
#define MAYO_105_csk_bytes MAYO_1_csk_bytes
#define MAYO_105_salt_bytes MAYO_1_salt_bytes
#define MAYO_105_digest_bytes MAYO_1_digest_bytes
#define MAYO_105_pk_seed_bytes MAYO_1_pk_seed_bytes
#define MAYO_105_sk_seed_bytes MAYO_1_sk_seed_bytes
#define MAYO_105_q MAYO_q

#define MAYO_2_name "MAYO_2"
#define MAYO_2_n 81
#define MAYO_2_m 64
#define MAYO_2_m_vec_limbs 4
#define MAYO_2_o 17
#define MAYO_2_v (MAYO_2_n - MAYO_2_o)
#define MAYO_2_A_cols (MAYO_2_k * MAYO_2_o + 1)
#define MAYO_2_k 4
#define MAYO_2_q 16
#define MAYO_2_m_bytes 32
#define MAYO_2_O_bytes 544
#define MAYO_2_v_bytes 32
#define MAYO_2_r_bytes 34
#define MAYO_2_P1_bytes 66560
#define MAYO_2_P2_bytes 34816
#define MAYO_2_P3_bytes 4896
#define MAYO_2_csk_bytes 24
#define MAYO_2_cpk_bytes 4912
#define MAYO_2_sig_bytes 186
#define MAYO_2_f_tail F_TAIL_64
#define MAYO_2_f_tail_arr f_tail_64
#define MAYO_2_salt_bytes 24
#define MAYO_2_digest_bytes 32
#define MAYO_2_pk_seed_bytes 16
#define MAYO_2_sk_seed_bytes 24

#define MAYO_3_name "MAYO_3"
#define MAYO_3_n 118
#define MAYO_3_m 108
#define MAYO_3_m_vec_limbs 7
#define MAYO_3_o 10
#define MAYO_3_v (MAYO_3_n - MAYO_3_o)
#define MAYO_3_A_cols (MAYO_3_k * MAYO_3_o + 1)
#define MAYO_3_k 11
#define MAYO_3_q 16
#define MAYO_3_m_bytes 54
#define MAYO_3_O_bytes 540
#define MAYO_3_v_bytes 54
#define MAYO_3_r_bytes 55
#define MAYO_3_P1_bytes 317844
#define MAYO_3_P2_bytes 58320
#define MAYO_3_P3_bytes 2970
#define MAYO_3_csk_bytes 32
#define MAYO_3_cpk_bytes 2986
#define MAYO_3_sig_bytes 681
#define MAYO_3_f_tail F_TAIL_108
#define MAYO_3_f_tail_arr f_tail_108
#define MAYO_3_salt_bytes 32
#define MAYO_3_digest_bytes 48
#define MAYO_3_pk_seed_bytes 16
#define MAYO_3_sk_seed_bytes 32

#define MAYO_5_name "MAYO_5"
#define MAYO_5_n 154
#define MAYO_5_m 142
#define MAYO_5_m_vec_limbs 9
#define MAYO_5_o 12
#define MAYO_5_v (MAYO_5_n - MAYO_5_o)
#define MAYO_5_A_cols (MAYO_5_k * MAYO_5_o + 1)
#define MAYO_5_k 12
#define MAYO_5_q 16
#define MAYO_5_m_bytes 71
#define MAYO_5_O_bytes 852
#define MAYO_5_v_bytes 71
#define MAYO_5_r_bytes 72
#define MAYO_5_P1_bytes 720863
#define MAYO_5_P2_bytes 120984
#define MAYO_5_P3_bytes 5538
#define MAYO_5_csk_bytes 40
#define MAYO_5_cpk_bytes 5554
#define MAYO_5_sig_bytes 964
#define MAYO_5_f_tail F_TAIL_142
#define MAYO_5_f_tail_arr f_tail_142
#define MAYO_5_salt_bytes 40
#define MAYO_5_digest_bytes 64
#define MAYO_5_pk_seed_bytes 16
#define MAYO_5_sk_seed_bytes 40

#define PARAM_JOIN2_(a, b) a##_##b
#define PARAM_JOIN2(a, b) PARAM_JOIN2_(a, b)
#define PARAM_NAME(end) PARAM_JOIN2(MAYO_VARIANT, end)

#define PARAM_JOIN3_(a, b, c) pqmayo_##a##_##b##_##c
#define PARAM_JOIN3(a, b, c) PARAM_JOIN3_(a, b, c)
#define PARAM_NAME3(end, s) PARAM_JOIN3(MAYO_VARIANT, end, s)

#ifdef ENABLE_PARAMS_DYNAMIC
#define N_MAX 154
#define M_MAX 142
#define O_MAX 17
#define K_MAX 12
#define Q_MAX 16
#define PK_SEED_BYTES_MAX 16
#define SK_SEED_BYTES_MAX 40
#define SALT_BYTES_MAX 40
#define DIGEST_BYTES_MAX 64
#define V_MAX 142
#define O_BYTES_MAX 852
#define V_BYTES_MAX 71
#define R_BYTES_MAX 72
#define P1_BYTES_MAX 720863
#define P2_BYTES_MAX 120984
#define P3_BYTES_MAX 5538
#define SIG_BYTES_MAX 964
#define CPK_BYTES_MAX 5554
#define CSK_BYTES_MAX 40
#define M_BYTES_MAX 71
#define M_VEC_LIMBS_MAX 9
#elif defined(MAYO_VARIANT)
#define M_MAX PARAM_NAME(m)
#define M_VEC_LIMBS_MAX PARAM_NAME(m_vec_limbs)
#define N_MAX PARAM_NAME(n)
#define O_MAX PARAM_NAME(o)
#define V_MAX PARAM_NAME(v)
#define K_MAX PARAM_NAME(k)
#define Q_MAX PARAM_NAME(q)
#define M_BYTES_MAX PARAM_NAME(m_bytes)
#define O_BYTES_MAX PARAM_NAME(O_bytes)
#define V_BYTES_MAX PARAM_NAME(v_bytes)
#define R_BYTES_MAX PARAM_NAME(r_bytes)
#define P1_BYTES_MAX PARAM_NAME(P1_bytes)
#define P2_BYTES_MAX PARAM_NAME(P2_bytes)
#define P3_BYTES_MAX PARAM_NAME(P3_bytes)
#define SIG_BYTES_MAX PARAM_NAME(sig_bytes)
#define CSK_BYTES_MAX PARAM_NAME(csk_bytes)
#define CPK_BYTES_MAX PARAM_NAME(cpk_bytes)
#define SALT_BYTES_MAX PARAM_NAME(salt_bytes)
#define DIGEST_BYTES_MAX PARAM_NAME(digest_bytes)
#define PK_SEED_BYTES_MAX PARAM_NAME(pk_seed_bytes)
#define SK_SEED_BYTES_MAX SALT_BYTES_MAX
#else
#error "Parameter not specified"
#endif

#define P1_LIMBS_MAX (V_MAX*(V_MAX+1)/2*M_VEC_LIMBS_MAX)
#define P2_LIMBS_MAX (V_MAX*O_MAX*M_VEC_LIMBS_MAX)
#define P3_LIMBS_MAX (O_MAX*(O_MAX+1)/2*M_VEC_LIMBS_MAX)

#ifdef ENABLE_PARAMS_DYNAMIC
#define PARAM_name(p) (p->name)
#define PARAM_m(p) (p->m)
#define PARAM_m_vec_limbs(p) (p->m_vec_limbs)
#define PARAM_n(p) (p->n)
#define PARAM_o(p) (p->o)
#define PARAM_v(p) (p->n - p->o)
#define PARAM_A_cols(p) (p->k * p->o + 1)
#define PARAM_k(p) (p->k)
#define PARAM_q(p) (p->q)
#define PARAM_m_bytes(p) (p->m_bytes)
#define PARAM_O_bytes(p) (p->O_bytes)
#define PARAM_v_bytes(p) (p->v_bytes)
#define PARAM_r_bytes(p) (p->r_bytes)
#define PARAM_P1_bytes(p) (p->P1_bytes)
#define PARAM_P2_bytes(p) (p->P2_bytes)
#define PARAM_P3_bytes(p) (p->P3_bytes)
#define PARAM_csk_bytes(p) (p->csk_bytes)
#define PARAM_cpk_bytes(p) (p->cpk_bytes)
#define PARAM_sig_bytes(p) (p->sig_bytes)
#define PARAM_f_tail(p) (p->f_tail)
#define PARAM_salt_bytes(p) (p->salt_bytes)
#define PARAM_sk_seed_bytes(p) (p->sk_seed_bytes)
#define PARAM_digest_bytes(p) (p->digest_bytes)
#define PARAM_pk_seed_bytes(p) (p->pk_seed_bytes)
#elif defined(MAYO_VARIANT)
#define PARAM_name(p) PARAM_NAME(name)
#define PARAM_m(p) PARAM_NAME(m)
#define PARAM_m_vec_limbs(p) PARAM_NAME(m_vec_limbs)
#define PARAM_n(p) PARAM_NAME(n)
#define PARAM_o(p) PARAM_NAME(o)
#define PARAM_v(p) PARAM_NAME(v)
#define PARAM_A_cols(p) PARAM_NAME(A_cols)
#define PARAM_k(p) PARAM_NAME(k)
#define PARAM_q(p) PARAM_NAME(q)
#define PARAM_m_bytes(p) PARAM_NAME(m_bytes)
#define PARAM_O_bytes(p) PARAM_NAME(O_bytes)
#define PARAM_v_bytes(p) PARAM_NAME(v_bytes)
#define PARAM_r_bytes(p) PARAM_NAME(r_bytes)
#define PARAM_P1_bytes(p) PARAM_NAME(P1_bytes)
#define PARAM_P2_bytes(p) PARAM_NAME(P2_bytes)
#define PARAM_P3_bytes(p) PARAM_NAME(P3_bytes)
#define PARAM_csk_bytes(p) PARAM_NAME(csk_bytes)
#define PARAM_cpk_bytes(p) PARAM_NAME(cpk_bytes)
#define PARAM_epk_bytes(p) PARAM_NAME(epk_bytes)
#define PARAM_sig_bytes(p) PARAM_NAME(sig_bytes)
static const unsigned char f_tail[] = PARAM_NAME(f_tail);
#define PARAM_salt_bytes(p) PARAM_NAME(salt_bytes)
#define PARAM_sk_seed_bytes(p) PARAM_NAME(sk_seed_bytes)
#define PARAM_digest_bytes(p) PARAM_NAME(digest_bytes)
#define PARAM_pk_seed_bytes(p) PARAM_NAME(pk_seed_bytes)
#define PARAM_f_tail(p) f_tail
#else
#error "Parameter not specified"
#endif

#define PARAM_P1_limbs(p) (PARAM_v(p)*(PARAM_v(p)+1)/2*PARAM_m_vec_limbs(p))
#define PARAM_P2_limbs(p) (PARAM_v(p)*PARAM_o(p)*PARAM_m_vec_limbs(p))
#define PARAM_P3_limbs(p) (PARAM_o(p)*(PARAM_o(p)+1)/2*PARAM_m_vec_limbs(p))
#define PARAM_EPK_limbs(p) (PARAM_P1_limbs(p) + PARAM_P2_limbs(p) + PARAM_P3_limbs(p))

/**
 * Struct defining MAYO parameters
 */
typedef struct {
    int m;
    int n;
    int o;
    int k;
    int q;
    const unsigned char *f_tail;
    int m_bytes;
    int O_bytes;
    int v_bytes;
    int r_bytes;
    int R_bytes;
    int P1_bytes;
    int P2_bytes;
    int P3_bytes;
    int csk_bytes;
    int cpk_bytes;
    int sig_bytes;
    int salt_bytes;
    int sk_seed_bytes;
    int digest_bytes;
    int pk_seed_bytes;
    int m_vec_limbs;
    const char *name;
} mayo_params_t;

typedef struct sk_t {
    uint64_t p[P1_LIMBS_MAX + P2_LIMBS_MAX];
    uint8_t O[V_MAX*O_MAX];
} sk_t;

typedef struct pk_t {
    uint64_t p[P1_LIMBS_MAX + P2_LIMBS_MAX + P3_LIMBS_MAX];
} pk_t;

/**
 * MAYO parameter sets
 */
#ifdef ENABLE_PARAMS_DYNAMIC
extern const mayo_params_t MAYO_1;
extern const mayo_params_t MAYO_109;
extern const mayo_params_t MAYO_108;
extern const mayo_params_t MAYO_107;
extern const mayo_params_t MAYO_106;
extern const mayo_params_t MAYO_105;
extern const mayo_params_t MAYO_2;
extern const mayo_params_t MAYO_3;
extern const mayo_params_t MAYO_5;
#endif

/**
 * Status codes
 */
#define MAYO_OK 0
#define MAYO_ERR 1

/**
 * Mayo keypair generation.
 *
 * The implementation corresponds to Mayo.CompactKeyGen() in the Mayo spec.
 * The caller is responsible to allocate sufficient memory to hold pk and sk.
 *
 * @param[in] p Mayo parameter set
 * @param[out] pk Mayo public key
 * @param[out] sk Mayo secret key
 * @return int status code
 */
int mayo_keypair(const mayo_params_t *p, unsigned char *pk, unsigned char *sk);

int mayo_sign_signature(const mayo_params_t *p, unsigned char *sig,
              size_t *siglen, const unsigned char *m,
              size_t mlen, const unsigned char *csk);

/**
 * MAYO signature generation.
 *
 * The implementation performs Mayo.expandSK() + Mayo.sign() in the Mayo spec.
 * Keys provided is a compacted secret keys.
 * The caller is responsible to allocate sufficient memory to hold sm.
 *
 * @param[in] p Mayo parameter set
 * @param[out] sm Signature concatenated with message
 * @param[out] smlen Pointer to the length of sm
 * @param[in] m Message to be signed
 * @param[in] mlen Message length
 * @param[in] sk Compacted secret key
 * @return int status code
 */
int mayo_sign(const mayo_params_t *p, unsigned char *sm,
              size_t *smlen, const unsigned char *m,
              size_t mlen, const unsigned char *sk);

/**
 * Mayo open signature.
 *
 * The implementation performs Mayo.verify(). If the signature verification succeeded, the original message is stored in m.
 * Keys provided is a compact public key.
 * The caller is responsible to allocate sufficient memory to hold m.
 *
 * @param[in] p Mayo parameter set
 * @param[out] m Message stored if verification succeeds
 * @param[out] mlen Pointer to the length of m
 * @param[in] sm Signature concatenated with message
 * @param[in] smlen Length of sm
 * @param[in] pk Compacted public key
 * @return int status code
 */
int mayo_open(const mayo_params_t *p, unsigned char *m,
              size_t *mlen, const unsigned char *sm,
              size_t smlen, const unsigned char *pk);

/**
 * Mayo compact keypair generation.
 *
 * The implementation corresponds to Mayo.CompactKeyGen() in the Mayo spec.
 * The caller is responsible to allocate sufficient memory to hold pk and sk.
 *
 * outputs a pair (csk, cpk) \in B^{csk_bytes} x B^{cpk_bytes}, where csk and
 * cpk are compact representations of a Mayo secret key and public key
 *
 * @param[in] p Mayo parameter set
 * @param[out] cpk Mayo compacted public key
 * @param[out] csk Mayo compacted secret key
 * @return int status code
 */
int mayo_keypair_compact(const mayo_params_t *p, unsigned char *cpk,
                         unsigned char *csk);

/**
 * Mayo expand public key.
 *
 * The implementation corresponds to Mayo.expandPK() in the Mayo spec.
 * The caller is responsible to allocate sufficient memory to hold epk.
 *
 * @param[in] p Mayo parameter set
 * @param[in] cpk Compacted public key.
 * @param[out] epk Expanded public key.
 * @return int return code
 */
int mayo_expand_pk(const mayo_params_t *p, const unsigned char *cpk,
                   uint64_t *epk);

/**
 * Mayo expand secret key.
 *
 * The implementation corresponds to Mayo.expandSK() in the Mayo spec.
 * The caller is responsible to allocate sufficient memory to hold esk.
 *
 * @param[in] p Mayo parameter set
 * @param[in] csk Compacted secret key.
 * @param[out] esk Expanded secret key.
 * @return int return code
 */
int mayo_expand_sk(const mayo_params_t *p, const unsigned char *csk,
                   sk_t *esk);

/**
 * Mayo verify signature.
 *
 * The implementation performs Mayo.verify(). If the signature verification succeeded, returns 0, otherwise 1.
 * Keys provided is a compact public key.
 *
 * @param[in] p Mayo parameter set
 * @param[out] m Message stored if verification succeeds
 * @param[out] mlen Pointer to the length of m
 * @param[in] sig Signature
 * @param[in] pk Compacted public key
 * @return int 0 if verification succeeded, 1 otherwise.
 */
int mayo_verify(const mayo_params_t *p, const unsigned char *m,
                size_t mlen, const unsigned char *sig,
                const unsigned char *pk);

#endif

