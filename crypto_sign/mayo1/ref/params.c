// SPDX-License-Identifier: Apache-2.0
/* Data for parameter sets 109, 108, 107, 106, 105, 2B, 103, 102, 313, 310, 309, 308, 307, 306, 305, 304, 303, 302, 515,
 * 514, 511, 510, 509, 508, 507, 506, and 505 are Copyright 2026 Siemens AG
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

#include <mayo.h>

#ifdef ENABLE_PARAMS_DYNAMIC
static const unsigned char f_tail_64[] = F_TAIL_64;
static const unsigned char f_tail_66[] = F_TAIL_66;
static const unsigned char f_tail_68[] = F_TAIL_68;
static const unsigned char f_tail_70[] = F_TAIL_70;
static const unsigned char f_tail_74[] = F_TAIL_74;
static const unsigned char f_tail_76[] = F_TAIL_76;
static const unsigned char f_tail_78[] = F_TAIL_78;
static const unsigned char f_tail_96[] = F_TAIL_96;
static const unsigned char f_tail_98[] = F_TAIL_98;
static const unsigned char f_tail_100[] = F_TAIL_100;
static const unsigned char f_tail_102[] = F_TAIL_102;
static const unsigned char f_tail_104[] = F_TAIL_104;
static const unsigned char f_tail_106[] = F_TAIL_106;
static const unsigned char f_tail_108[] = F_TAIL_108;
static const unsigned char f_tail_114[] = F_TAIL_114;
static const unsigned char f_tail_130[] = F_TAIL_130;
static const unsigned char f_tail_132[] = F_TAIL_132;
static const unsigned char f_tail_134[] = F_TAIL_134;
static const unsigned char f_tail_136[] = F_TAIL_136;
static const unsigned char f_tail_138[] = F_TAIL_138;
static const unsigned char f_tail_140[] = F_TAIL_140;
static const unsigned char f_tail_142[] = F_TAIL_142;
static const unsigned char f_tail_144[] = F_TAIL_144;
static const unsigned char f_tail_146[] = F_TAIL_146;

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
MAYO_GEN_PARAMS(MAYO_2B);
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
MAYO_GEN_PARAMS(MAYO_515);
MAYO_GEN_PARAMS(MAYO_514);
MAYO_GEN_PARAMS(MAYO_5);
MAYO_GEN_PARAMS(MAYO_511);
MAYO_GEN_PARAMS(MAYO_510);
MAYO_GEN_PARAMS(MAYO_509);
MAYO_GEN_PARAMS(MAYO_508);
MAYO_GEN_PARAMS(MAYO_507);
MAYO_GEN_PARAMS(MAYO_506);
MAYO_GEN_PARAMS(MAYO_505);
#endif

