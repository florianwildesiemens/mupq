// SPDX-License-Identifier: Apache-2.0

#include <mayo.h>

#ifdef ENABLE_PARAMS_DYNAMIC
static const unsigned char f_tail_64_2[] = F_TAIL_64_2;
static const unsigned char f_tail_64_3[] = F_TAIL_64_3;
static const unsigned char f_tail_64[] = F_TAIL_64;
static const unsigned char f_tail_66_5[] = F_TAIL_66_5;
static const unsigned char f_tail_68_6[] = F_TAIL_68_6;
static const unsigned char f_tail_70_7[] = F_TAIL_70_7;
static const unsigned char f_tail_74_8[] = F_TAIL_74_8;
static const unsigned char f_tail_76_9[] = F_TAIL_76_9;
static const unsigned char f_tail_78[] = F_TAIL_78;
static const unsigned char f_tail_96_2[] = F_TAIL_96_2;
static const unsigned char f_tail_96_3[] = F_TAIL_96_3;
static const unsigned char f_tail_96_4[] = F_TAIL_96_4;
static const unsigned char f_tail_98_5[] = F_TAIL_98_5;
static const unsigned char f_tail_98_6[] = F_TAIL_98_6;
static const unsigned char f_tail_100_7[] = F_TAIL_100_7;
static const unsigned char f_tail_102_8[] = F_TAIL_102_8;
static const unsigned char f_tail_104_9[] = F_TAIL_104_9;
static const unsigned char f_tail_106_10[] = F_TAIL_106_10;
static const unsigned char f_tail_108[] = F_TAIL_108;
static const unsigned char f_tail_114_13[] = F_TAIL_114_13;
static const unsigned char f_tail_142[] = F_TAIL_142;

#define MAYO_GEN_PARAMS(nm) \
  const mayo_params_t nm = { \
    .m = PARAM_JOIN2(nm, m), \
    .n = PARAM_JOIN2(nm, n), \
    .o = PARAM_JOIN2(nm, o), \
    .k = PARAM_JOIN2(nm, k), \
    .q = PARAM_JOIN2(nm, q), \
    .f_tail = PARAM_JOIN2(nm, f_tail_arr), \
    .m_bytes = PARAM_JOIN2(nm, m_bytes), \
    .O_bytes = PARAM_JOIN2(nm, O_bytes), \
    .v_bytes = PARAM_JOIN2(nm, v_bytes), \
    .r_bytes = PARAM_JOIN2(nm, r_bytes), \
    .P1_bytes = PARAM_JOIN2(nm, P1_bytes), \
    .P2_bytes = PARAM_JOIN2(nm, P2_bytes), \
    .P3_bytes = PARAM_JOIN2(nm, P3_bytes), \
    .csk_bytes = PARAM_JOIN2(nm, csk_bytes), \
    .cpk_bytes = PARAM_JOIN2(nm, cpk_bytes), \
    .sig_bytes = PARAM_JOIN2(nm, sig_bytes), \
    .salt_bytes = PARAM_JOIN2(nm, salt_bytes), \
    .sk_seed_bytes = PARAM_JOIN2(nm, sk_seed_bytes), \
    .digest_bytes = PARAM_JOIN2(nm, digest_bytes), \
    .pk_seed_bytes = PARAM_JOIN2(nm, pk_seed_bytes), \
    .m_vec_limbs = PARAM_JOIN2(nm, m_vec_limbs), \
    .name = #nm \
  };

MAYO_GEN_PARAMS(MAYO_1);
MAYO_GEN_PARAMS(MAYO_109);
MAYO_GEN_PARAMS(MAYO_108);
MAYO_GEN_PARAMS(MAYO_107);
MAYO_GEN_PARAMS(MAYO_106);
MAYO_GEN_PARAMS(MAYO_105);
MAYO_GEN_PARAMS(MAYO_2);
MAYO_GEN_PARAMS(MAYO_103);
MAYO_GEN_PARAMS(MAYO_102);
MAYO_GEN_PARAMS(MAYO_313);
MAYO_GEN_PARAMS(MAYO_3);
MAYO_GEN_PARAMS(MAYO_310);
MAYO_GEN_PARAMS(MAYO_309);
MAYO_GEN_PARAMS(MAYO_308);
MAYO_GEN_PARAMS(MAYO_307);
MAYO_GEN_PARAMS(MAYO_306);
MAYO_GEN_PARAMS(MAYO_305);
MAYO_GEN_PARAMS(MAYO_304);
MAYO_GEN_PARAMS(MAYO_303);
MAYO_GEN_PARAMS(MAYO_302);
MAYO_GEN_PARAMS(MAYO_5);
#endif

