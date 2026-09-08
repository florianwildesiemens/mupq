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

#ifndef MAYO_H
#define MAYO_H

#ifndef PQM4
#define PQM4
#endif
#include "mayo_variant.h"

#include <stdint.h>
#include <stdlib.h>

#define F_TAIL_LEN 4
#define F_TAIL_78 { 8, 1, 1, 0 } /* f(z) =  z^78 + z^2 + z + x^3 */
#define F_TAIL_76 { 2, 2, 4, 2 } /* z^76 + x*z^3 + x^2*z^2 + x*z + x */
#define F_TAIL_74 { 8, 0, 2, 8 } /* z^74 + x^3*z^3 + x*z^2 + x^3 */
#define F_TAIL_70 { 8, 1, 0, 1 } /* z^70 + z^3 + z + x^3 */
#define F_TAIL_68 { 2, 0, 1, 1 } /* z^68 + z^3 + z^2 + x */
#define F_TAIL_66 { 4, 0, 8, 4 } /* z^66 + x^2*z^3 + x^3*z^2 + x^2 */
#define F_TAIL_64 { 8, 0, 2, 8 } /* f(z) =  z^64 + x^3*z^3 + x*z^2 + x^3 */
#define F_TAIL_114 { 1, 2, 1, 0 } /* z^114 + z^2 + x*z + 1 */
#define F_TAIL_108 { 8, 0, 1, 7 } /* f(z) =  z^108 + (x^2 + x + 1)*z^3 + z^2 + x^3 */
#define F_TAIL_106 { 2, 2, 1, 2 } /* z^106 + x*z^3 + z^2 + x*z + x */
#define F_TAIL_104 { 4, 8, 1, 4 } /* z^104 + x^2*z^3 + z^2 + x^3*z + x^2 */
#define F_TAIL_102 { 1, 0, 1, 2 } /* z^102 + x*z^3 + z^2 + 1 */
#define F_TAIL_100 { 4, 2, 4, 4 } /* z^100 + x^2*z^3 + x^2*z^2 + x*z + x^2 */
#define F_TAIL_98 { 1, 1, 0, 8 } /* z^98 + x^3*z^3 + z + 1 */
#define F_TAIL_96 { 4, 4, 0, 4 } /* z^96 + x^2*z^3 + x^2*z + x^2 */
#define F_TAIL_146 { 4, 10, 2, 1 } /* z^146 + z^3 + x*z^2 + (x^3 + x)*z + x^2 */
#define F_TAIL_144 { 4, 0, 8, 4 } /* z^144 + x^2*z^3 + x^3*z^2 + x^2 */
#define F_TAIL_142 { 4, 0, 8, 1 } /* f(z) =  z^142 + z^3 + x^3*z^2 + x^2 */
#define F_TAIL_140 { 8, 8, 1, 2 } /* z^140 + x*z^3 + z^2 + x^3*z + x^3 */
#define F_TAIL_138 { 8, 2, 0, 2 } /* z^138 + x*z^3 + x*z + x^3 */
#define F_TAIL_136 { 8, 8, 1, 8 } /* z^136 + x^3*z^3 + z^2 + x^3*z + x^3 */
#define F_TAIL_134 { 8, 8, 8, 1 } /* z^134 + z^3 + x^3*z^2 + x^3*z + x^3 */
#define F_TAIL_132 { 1, 0, 1, 2 } /* z^132 + x*z^3 + z^2 + 1 */
#define F_TAIL_130 { 4, 1, 4, 2 } /* z^130 + x*z^3 + x^2*z^2 + z + x^2 */

#define MAYO_1_n 86
#define MAYO_1_m 78
#define MAYO_1_m_vec_limbs 5
#define MAYO_1_o 8
#define MAYO_1_v 78
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

#define MAYO_109_n 85
#define MAYO_109_m 76
#define MAYO_109_m_vec_limbs 5
#define MAYO_109_o 9
#define MAYO_109_v 76
#define MAYO_109_A_cols (MAYO_109_k * MAYO_109_o + 1)
#define MAYO_109_k 9
#define MAYO_109_q 16
#define MAYO_109_m_bytes 38
#define MAYO_109_O_bytes 342
#define MAYO_109_v_bytes 38
#define MAYO_109_r_bytes 41
#define MAYO_109_P1_bytes 111188
#define MAYO_109_P2_bytes 25992
#define MAYO_109_P3_bytes 1710
#define MAYO_109_csk_bytes 24
#define MAYO_109_cpk_bytes 1726
#define MAYO_109_sig_bytes 407
#define MAYO_109_f_tail F_TAIL_76
#define MAYO_109_f_tail_arr f_tail_76
#define MAYO_109_salt_bytes 24
#define MAYO_109_digest_bytes 32
#define MAYO_109_pk_seed_bytes 16
#define MAYO_109_sk_seed_bytes 24

#define MAYO_108_n 84
#define MAYO_108_m 74
#define MAYO_108_m_vec_limbs 5
#define MAYO_108_o 10
#define MAYO_108_v 74
#define MAYO_108_A_cols (MAYO_108_k * MAYO_108_o + 1)
#define MAYO_108_k 8
#define MAYO_108_q 16
#define MAYO_108_m_bytes 37
#define MAYO_108_O_bytes 370
#define MAYO_108_v_bytes 37
#define MAYO_108_r_bytes 40
#define MAYO_108_P1_bytes 102675
#define MAYO_108_P2_bytes 27380
#define MAYO_108_P3_bytes 2035
#define MAYO_108_csk_bytes 24
#define MAYO_108_cpk_bytes 2051
#define MAYO_108_sig_bytes 360
#define MAYO_108_f_tail F_TAIL_74
#define MAYO_108_f_tail_arr f_tail_74
#define MAYO_108_salt_bytes 24
#define MAYO_108_digest_bytes 32
#define MAYO_108_pk_seed_bytes 16
#define MAYO_108_sk_seed_bytes 24

#define MAYO_107_n 81
#define MAYO_107_m 70
#define MAYO_107_m_vec_limbs 5
#define MAYO_107_o 11
#define MAYO_107_v 70
#define MAYO_107_A_cols (MAYO_107_k * MAYO_107_o + 1)
#define MAYO_107_k 7
#define MAYO_107_q 16
#define MAYO_107_m_bytes 35
#define MAYO_107_O_bytes 385
#define MAYO_107_v_bytes 35
#define MAYO_107_r_bytes 39
#define MAYO_107_P1_bytes 86975
#define MAYO_107_P2_bytes 26950
#define MAYO_107_P3_bytes 2310
#define MAYO_107_csk_bytes 24
#define MAYO_107_cpk_bytes 2326
#define MAYO_107_sig_bytes 308
#define MAYO_107_f_tail F_TAIL_70
#define MAYO_107_f_tail_arr f_tail_70
#define MAYO_107_salt_bytes 24
#define MAYO_107_digest_bytes 32
#define MAYO_107_pk_seed_bytes 16
#define MAYO_107_sk_seed_bytes 24

#define MAYO_106_n 80
#define MAYO_106_m 68
#define MAYO_106_m_vec_limbs 5
#define MAYO_106_o 12
#define MAYO_106_v 68
#define MAYO_106_A_cols (MAYO_106_k * MAYO_106_o + 1)
#define MAYO_106_k 6
#define MAYO_106_q 16
#define MAYO_106_m_bytes 34
#define MAYO_106_O_bytes 408
#define MAYO_106_v_bytes 34
#define MAYO_106_r_bytes 36
#define MAYO_106_P1_bytes 79764
#define MAYO_106_P2_bytes 27744
#define MAYO_106_P3_bytes 2652
#define MAYO_106_csk_bytes 24
#define MAYO_106_cpk_bytes 2668
#define MAYO_106_sig_bytes 264
#define MAYO_106_f_tail F_TAIL_68
#define MAYO_106_f_tail_arr f_tail_68
#define MAYO_106_salt_bytes 24
#define MAYO_106_digest_bytes 32
#define MAYO_106_pk_seed_bytes 16
#define MAYO_106_sk_seed_bytes 24

#define MAYO_105_n 80
#define MAYO_105_m 66
#define MAYO_105_m_vec_limbs 5
#define MAYO_105_o 14
#define MAYO_105_v 66
#define MAYO_105_A_cols (MAYO_105_k * MAYO_105_o + 1)
#define MAYO_105_k 5
#define MAYO_105_q 16
#define MAYO_105_m_bytes 33
#define MAYO_105_O_bytes 462
#define MAYO_105_v_bytes 33
#define MAYO_105_r_bytes 35
#define MAYO_105_P1_bytes 72963
#define MAYO_105_P2_bytes 30492
#define MAYO_105_P3_bytes 3465
#define MAYO_105_csk_bytes 24
#define MAYO_105_cpk_bytes 3481
#define MAYO_105_sig_bytes 224
#define MAYO_105_f_tail F_TAIL_66
#define MAYO_105_f_tail_arr f_tail_66
#define MAYO_105_salt_bytes 24
#define MAYO_105_digest_bytes 32
#define MAYO_105_pk_seed_bytes 16
#define MAYO_105_sk_seed_bytes 24

#define MAYO_2_n 81
#define MAYO_2_m 64
#define MAYO_2_m_vec_limbs 4
#define MAYO_2_o 17
#define MAYO_2_v 64
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

#define MAYO_2B_n 96
#define MAYO_2B_m 64
#define MAYO_2B_m_vec_limbs 4
#define MAYO_2B_o 16
#define MAYO_2B_v 80
#define MAYO_2B_A_cols (MAYO_2B_k * MAYO_2B_o + 1)
#define MAYO_2B_k 4
#define MAYO_2B_q 16
#define MAYO_2B_m_bytes 32
#define MAYO_2B_O_bytes 640
#define MAYO_2B_v_bytes 40
#define MAYO_2B_r_bytes 32
#define MAYO_2B_P1_bytes 103680
#define MAYO_2B_P2_bytes 40960
#define MAYO_2B_P3_bytes 4352
#define MAYO_2B_csk_bytes 24
#define MAYO_2B_cpk_bytes 4368
#define MAYO_2B_sig_bytes 216
#define MAYO_2B_f_tail F_TAIL_64
#define MAYO_2B_f_tail_arr f_tail_64
#define MAYO_2B_salt_bytes 24
#define MAYO_2B_digest_bytes 32
#define MAYO_2B_pk_seed_bytes 16
#define MAYO_2B_sk_seed_bytes 24

#define MAYO_103_n 86
#define MAYO_103_m 64
#define MAYO_103_m_vec_limbs 4
#define MAYO_103_o 22
#define MAYO_103_v 64
#define MAYO_103_A_cols (MAYO_103_k * MAYO_103_o + 1)
#define MAYO_103_k 3
#define MAYO_103_q 16
#define MAYO_103_m_bytes 32
#define MAYO_103_O_bytes 704
#define MAYO_103_v_bytes 32
#define MAYO_103_r_bytes 33
#define MAYO_103_P1_bytes 66560
#define MAYO_103_P2_bytes 45056
#define MAYO_103_P3_bytes 8096
#define MAYO_103_csk_bytes 24
#define MAYO_103_cpk_bytes 8112
#define MAYO_103_sig_bytes 153
#define MAYO_103_f_tail F_TAIL_64
#define MAYO_103_f_tail_arr f_tail_64
#define MAYO_103_salt_bytes 24
#define MAYO_103_digest_bytes 32
#define MAYO_103_pk_seed_bytes 16
#define MAYO_103_sk_seed_bytes 24

#define MAYO_102_n 100
#define MAYO_102_m 64
#define MAYO_102_m_vec_limbs 4
#define MAYO_102_o 33
#define MAYO_102_v 67
#define MAYO_102_A_cols (MAYO_102_k * MAYO_102_o + 1)
#define MAYO_102_k 2
#define MAYO_102_q 16
#define MAYO_102_m_bytes 32
#define MAYO_102_O_bytes 1106
#define MAYO_102_v_bytes 34
#define MAYO_102_r_bytes 33
#define MAYO_102_P1_bytes 72896
#define MAYO_102_P2_bytes 70752
#define MAYO_102_P3_bytes 17952
#define MAYO_102_csk_bytes 24
#define MAYO_102_cpk_bytes 17968
#define MAYO_102_sig_bytes 124
#define MAYO_102_f_tail F_TAIL_64
#define MAYO_102_f_tail_arr f_tail_64
#define MAYO_102_salt_bytes 24
#define MAYO_102_digest_bytes 32
#define MAYO_102_pk_seed_bytes 16
#define MAYO_102_sk_seed_bytes 24

#define MAYO_313_n 123
#define MAYO_313_m 114
#define MAYO_313_m_vec_limbs 8
#define MAYO_313_o 9
#define MAYO_313_v 114
#define MAYO_313_A_cols (MAYO_313_k * MAYO_313_o + 1)
#define MAYO_313_k 13
#define MAYO_313_q 16
#define MAYO_313_m_bytes 57
#define MAYO_313_O_bytes 513
#define MAYO_313_v_bytes 57
#define MAYO_313_r_bytes 59
#define MAYO_313_P1_bytes 373635
#define MAYO_313_P2_bytes 58482
#define MAYO_313_P3_bytes 2565
#define MAYO_313_csk_bytes 32
#define MAYO_313_cpk_bytes 2581
#define MAYO_313_sig_bytes 832
#define MAYO_313_f_tail F_TAIL_114
#define MAYO_313_f_tail_arr f_tail_114
#define MAYO_313_salt_bytes 32
#define MAYO_313_digest_bytes 48
#define MAYO_313_pk_seed_bytes 16
#define MAYO_313_sk_seed_bytes 32

#define MAYO_3_n 118
#define MAYO_3_m 108
#define MAYO_3_m_vec_limbs 7
#define MAYO_3_o 10
#define MAYO_3_v 108
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

#define MAYO_310_n 117
#define MAYO_310_m 106
#define MAYO_310_m_vec_limbs 7
#define MAYO_310_o 11
#define MAYO_310_v 106
#define MAYO_310_A_cols (MAYO_310_k * MAYO_310_o + 1)
#define MAYO_310_k 10
#define MAYO_310_q 16
#define MAYO_310_m_bytes 53
#define MAYO_310_O_bytes 583
#define MAYO_310_v_bytes 53
#define MAYO_310_r_bytes 55
#define MAYO_310_P1_bytes 300563
#define MAYO_310_P2_bytes 61798
#define MAYO_310_P3_bytes 3498
#define MAYO_310_csk_bytes 32
#define MAYO_310_cpk_bytes 3514
#define MAYO_310_sig_bytes 617
#define MAYO_310_f_tail F_TAIL_106
#define MAYO_310_f_tail_arr f_tail_106
#define MAYO_310_salt_bytes 32
#define MAYO_310_digest_bytes 48
#define MAYO_310_pk_seed_bytes 16
#define MAYO_310_sk_seed_bytes 32

#define MAYO_309_n 116
#define MAYO_309_m 104
#define MAYO_309_m_vec_limbs 7
#define MAYO_309_o 12
#define MAYO_309_v 104
#define MAYO_309_A_cols (MAYO_309_k * MAYO_309_o + 1)
#define MAYO_309_k 9
#define MAYO_309_q 16
#define MAYO_309_m_bytes 52
#define MAYO_309_O_bytes 624
#define MAYO_309_v_bytes 52
#define MAYO_309_r_bytes 54
#define MAYO_309_P1_bytes 283920
#define MAYO_309_P2_bytes 64896
#define MAYO_309_P3_bytes 4056
#define MAYO_309_csk_bytes 32
#define MAYO_309_cpk_bytes 4072
#define MAYO_309_sig_bytes 554
#define MAYO_309_f_tail F_TAIL_104
#define MAYO_309_f_tail_arr f_tail_104
#define MAYO_309_salt_bytes 32
#define MAYO_309_digest_bytes 48
#define MAYO_309_pk_seed_bytes 16
#define MAYO_309_sk_seed_bytes 32

#define MAYO_308_n 115
#define MAYO_308_m 102
#define MAYO_308_m_vec_limbs 7
#define MAYO_308_o 13
#define MAYO_308_v 102
#define MAYO_308_A_cols (MAYO_308_k * MAYO_308_o + 1)
#define MAYO_308_k 8
#define MAYO_308_q 16
#define MAYO_308_m_bytes 51
#define MAYO_308_O_bytes 663
#define MAYO_308_v_bytes 51
#define MAYO_308_r_bytes 52
#define MAYO_308_P1_bytes 267903
#define MAYO_308_P2_bytes 67626
#define MAYO_308_P3_bytes 4641
#define MAYO_308_csk_bytes 32
#define MAYO_308_cpk_bytes 4657
#define MAYO_308_sig_bytes 492
#define MAYO_308_f_tail F_TAIL_102
#define MAYO_308_f_tail_arr f_tail_102
#define MAYO_308_salt_bytes 32
#define MAYO_308_digest_bytes 48
#define MAYO_308_pk_seed_bytes 16
#define MAYO_308_sk_seed_bytes 32

#define MAYO_307_n 115
#define MAYO_307_m 100
#define MAYO_307_m_vec_limbs 7
#define MAYO_307_o 15
#define MAYO_307_v 100
#define MAYO_307_A_cols (MAYO_307_k * MAYO_307_o + 1)
#define MAYO_307_k 7
#define MAYO_307_q 16
#define MAYO_307_m_bytes 50
#define MAYO_307_O_bytes 750
#define MAYO_307_v_bytes 50
#define MAYO_307_r_bytes 53
#define MAYO_307_P1_bytes 252500
#define MAYO_307_P2_bytes 75000
#define MAYO_307_P3_bytes 6000
#define MAYO_307_csk_bytes 32
#define MAYO_307_cpk_bytes 6016
#define MAYO_307_sig_bytes 435
#define MAYO_307_f_tail F_TAIL_100
#define MAYO_307_f_tail_arr f_tail_100
#define MAYO_307_salt_bytes 32
#define MAYO_307_digest_bytes 48
#define MAYO_307_pk_seed_bytes 16
#define MAYO_307_sk_seed_bytes 32

#define MAYO_306_n 115
#define MAYO_306_m 98
#define MAYO_306_m_vec_limbs 7
#define MAYO_306_o 17
#define MAYO_306_v 98
#define MAYO_306_A_cols (MAYO_306_k * MAYO_306_o + 1)
#define MAYO_306_k 6
#define MAYO_306_q 16
#define MAYO_306_m_bytes 49
#define MAYO_306_O_bytes 833
#define MAYO_306_v_bytes 49
#define MAYO_306_r_bytes 51
#define MAYO_306_P1_bytes 237699
#define MAYO_306_P2_bytes 81634
#define MAYO_306_P3_bytes 7497
#define MAYO_306_csk_bytes 32
#define MAYO_306_cpk_bytes 7513
#define MAYO_306_sig_bytes 377
#define MAYO_306_f_tail F_TAIL_98
#define MAYO_306_f_tail_arr f_tail_98
#define MAYO_306_salt_bytes 32
#define MAYO_306_digest_bytes 48
#define MAYO_306_pk_seed_bytes 16
#define MAYO_306_sk_seed_bytes 32

#define MAYO_305_n 118
#define MAYO_305_m 98
#define MAYO_305_m_vec_limbs 7
#define MAYO_305_o 20
#define MAYO_305_v 98
#define MAYO_305_A_cols (MAYO_305_k * MAYO_305_o + 1)
#define MAYO_305_k 5
#define MAYO_305_q 16
#define MAYO_305_m_bytes 49
#define MAYO_305_O_bytes 980
#define MAYO_305_v_bytes 49
#define MAYO_305_r_bytes 50
#define MAYO_305_P1_bytes 237699
#define MAYO_305_P2_bytes 96040
#define MAYO_305_P3_bytes 10290
#define MAYO_305_csk_bytes 32
#define MAYO_305_cpk_bytes 10306
#define MAYO_305_sig_bytes 327
#define MAYO_305_f_tail F_TAIL_98
#define MAYO_305_f_tail_arr f_tail_98
#define MAYO_305_salt_bytes 32
#define MAYO_305_digest_bytes 48
#define MAYO_305_pk_seed_bytes 16
#define MAYO_305_sk_seed_bytes 32

#define MAYO_304_n 121
#define MAYO_304_m 96
#define MAYO_304_m_vec_limbs 6
#define MAYO_304_o 25
#define MAYO_304_v 96
#define MAYO_304_A_cols (MAYO_304_k * MAYO_304_o + 1)
#define MAYO_304_k 4
#define MAYO_304_q 16
#define MAYO_304_m_bytes 48
#define MAYO_304_O_bytes 1200
#define MAYO_304_v_bytes 48
#define MAYO_304_r_bytes 50
#define MAYO_304_P1_bytes 223488
#define MAYO_304_P2_bytes 115200
#define MAYO_304_P3_bytes 15600
#define MAYO_304_csk_bytes 32
#define MAYO_304_cpk_bytes 15616
#define MAYO_304_sig_bytes 274
#define MAYO_304_f_tail F_TAIL_96
#define MAYO_304_f_tail_arr f_tail_96
#define MAYO_304_salt_bytes 32
#define MAYO_304_digest_bytes 48
#define MAYO_304_pk_seed_bytes 16
#define MAYO_304_sk_seed_bytes 32

#define MAYO_303_n 129
#define MAYO_303_m 96
#define MAYO_303_m_vec_limbs 6
#define MAYO_303_o 33
#define MAYO_303_v 96
#define MAYO_303_A_cols (MAYO_303_k * MAYO_303_o + 1)
#define MAYO_303_k 3
#define MAYO_303_q 16
#define MAYO_303_m_bytes 48
#define MAYO_303_O_bytes 1584
#define MAYO_303_v_bytes 48
#define MAYO_303_r_bytes 50
#define MAYO_303_P1_bytes 223488
#define MAYO_303_P2_bytes 152064
#define MAYO_303_P3_bytes 26928
#define MAYO_303_csk_bytes 32
#define MAYO_303_cpk_bytes 26944
#define MAYO_303_sig_bytes 226
#define MAYO_303_f_tail F_TAIL_96
#define MAYO_303_f_tail_arr f_tail_96
#define MAYO_303_salt_bytes 32
#define MAYO_303_digest_bytes 48
#define MAYO_303_pk_seed_bytes 16
#define MAYO_303_sk_seed_bytes 32

#define MAYO_302_n 150
#define MAYO_302_m 96
#define MAYO_302_m_vec_limbs 6
#define MAYO_302_o 49
#define MAYO_302_v 101
#define MAYO_302_A_cols (MAYO_302_k * MAYO_302_o + 1)
#define MAYO_302_k 2
#define MAYO_302_q 16
#define MAYO_302_m_bytes 48
#define MAYO_302_O_bytes 2475
#define MAYO_302_v_bytes 51
#define MAYO_302_r_bytes 49
#define MAYO_302_P1_bytes 247248
#define MAYO_302_P2_bytes 237552
#define MAYO_302_P3_bytes 58800
#define MAYO_302_csk_bytes 32
#define MAYO_302_cpk_bytes 58816
#define MAYO_302_sig_bytes 182
#define MAYO_302_f_tail F_TAIL_96
#define MAYO_302_f_tail_arr f_tail_96
#define MAYO_302_salt_bytes 32
#define MAYO_302_digest_bytes 48
#define MAYO_302_pk_seed_bytes 16
#define MAYO_302_sk_seed_bytes 32

#define MAYO_515_n 156
#define MAYO_515_m 146
#define MAYO_515_m_vec_limbs 10
#define MAYO_515_o 10
#define MAYO_515_v 146
#define MAYO_515_A_cols (MAYO_515_k * MAYO_515_o + 1)
#define MAYO_515_k 15
#define MAYO_515_q 16
#define MAYO_515_m_bytes 73
#define MAYO_515_O_bytes 730
#define MAYO_515_v_bytes 73
#define MAYO_515_r_bytes 75
#define MAYO_515_P1_bytes 783363
#define MAYO_515_P2_bytes 106580
#define MAYO_515_P3_bytes 4015
#define MAYO_515_csk_bytes 40
#define MAYO_515_cpk_bytes 4031
#define MAYO_515_sig_bytes 1210
#define MAYO_515_f_tail F_TAIL_146
#define MAYO_515_f_tail_arr f_tail_146
#define MAYO_515_salt_bytes 40
#define MAYO_515_digest_bytes 64
#define MAYO_515_pk_seed_bytes 16
#define MAYO_515_sk_seed_bytes 40

#define MAYO_514_n 155
#define MAYO_514_m 144
#define MAYO_514_m_vec_limbs 9
#define MAYO_514_o 11
#define MAYO_514_v 144
#define MAYO_514_A_cols (MAYO_514_k * MAYO_514_o + 1)
#define MAYO_514_k 14
#define MAYO_514_q 16
#define MAYO_514_m_bytes 72
#define MAYO_514_O_bytes 792
#define MAYO_514_v_bytes 72
#define MAYO_514_r_bytes 77
#define MAYO_514_P1_bytes 751680
#define MAYO_514_P2_bytes 114048
#define MAYO_514_P3_bytes 4752
#define MAYO_514_csk_bytes 40
#define MAYO_514_cpk_bytes 4768
#define MAYO_514_sig_bytes 1125
#define MAYO_514_f_tail F_TAIL_144
#define MAYO_514_f_tail_arr f_tail_144
#define MAYO_514_salt_bytes 40
#define MAYO_514_digest_bytes 64
#define MAYO_514_pk_seed_bytes 16
#define MAYO_514_sk_seed_bytes 40

#define MAYO_5_n 154
#define MAYO_5_m 142
#define MAYO_5_m_vec_limbs 9
#define MAYO_5_o 12
#define MAYO_5_v 142
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

#define MAYO_511_n 153
#define MAYO_511_m 140
#define MAYO_511_m_vec_limbs 9
#define MAYO_511_o 13
#define MAYO_511_v 140
#define MAYO_511_A_cols (MAYO_511_k * MAYO_511_o + 1)
#define MAYO_511_k 11
#define MAYO_511_q 16
#define MAYO_511_m_bytes 70
#define MAYO_511_O_bytes 910
#define MAYO_511_v_bytes 70
#define MAYO_511_r_bytes 72
#define MAYO_511_P1_bytes 690900
#define MAYO_511_P2_bytes 127400
#define MAYO_511_P3_bytes 6370
#define MAYO_511_csk_bytes 40
#define MAYO_511_cpk_bytes 6386
#define MAYO_511_sig_bytes 882
#define MAYO_511_f_tail F_TAIL_140
#define MAYO_511_f_tail_arr f_tail_140
#define MAYO_511_salt_bytes 40
#define MAYO_511_digest_bytes 64
#define MAYO_511_pk_seed_bytes 16
#define MAYO_511_sk_seed_bytes 40

#define MAYO_510_n 152
#define MAYO_510_m 138
#define MAYO_510_m_vec_limbs 9
#define MAYO_510_o 14
#define MAYO_510_v 138
#define MAYO_510_A_cols (MAYO_510_k * MAYO_510_o + 1)
#define MAYO_510_k 10
#define MAYO_510_q 16
#define MAYO_510_m_bytes 69
#define MAYO_510_O_bytes 966
#define MAYO_510_v_bytes 69
#define MAYO_510_r_bytes 70
#define MAYO_510_P1_bytes 661779
#define MAYO_510_P2_bytes 133308
#define MAYO_510_P3_bytes 7245
#define MAYO_510_csk_bytes 40
#define MAYO_510_cpk_bytes 7261
#define MAYO_510_sig_bytes 800
#define MAYO_510_f_tail F_TAIL_138
#define MAYO_510_f_tail_arr f_tail_138
#define MAYO_510_salt_bytes 40
#define MAYO_510_digest_bytes 64
#define MAYO_510_pk_seed_bytes 16
#define MAYO_510_sk_seed_bytes 40

#define MAYO_509_n 152
#define MAYO_509_m 136
#define MAYO_509_m_vec_limbs 9
#define MAYO_509_o 16
#define MAYO_509_v 136
#define MAYO_509_A_cols (MAYO_509_k * MAYO_509_o + 1)
#define MAYO_509_k 9
#define MAYO_509_q 16
#define MAYO_509_m_bytes 68
#define MAYO_509_O_bytes 1088
#define MAYO_509_v_bytes 68
#define MAYO_509_r_bytes 72
#define MAYO_509_P1_bytes 633488
#define MAYO_509_P2_bytes 147968
#define MAYO_509_P3_bytes 9248
#define MAYO_509_csk_bytes 40
#define MAYO_509_cpk_bytes 9264
#define MAYO_509_sig_bytes 724
#define MAYO_509_f_tail F_TAIL_136
#define MAYO_509_f_tail_arr f_tail_136
#define MAYO_509_salt_bytes 40
#define MAYO_509_digest_bytes 64
#define MAYO_509_pk_seed_bytes 16
#define MAYO_509_sk_seed_bytes 40

#define MAYO_508_n 151
#define MAYO_508_m 134
#define MAYO_508_m_vec_limbs 9
#define MAYO_508_o 17
#define MAYO_508_v 134
#define MAYO_508_A_cols (MAYO_508_k * MAYO_508_o + 1)
#define MAYO_508_k 8
#define MAYO_508_q 16
#define MAYO_508_m_bytes 67
#define MAYO_508_O_bytes 1139
#define MAYO_508_v_bytes 67
#define MAYO_508_r_bytes 68
#define MAYO_508_P1_bytes 606015
#define MAYO_508_P2_bytes 152626
#define MAYO_508_P3_bytes 10251
#define MAYO_508_csk_bytes 40
#define MAYO_508_cpk_bytes 10267
#define MAYO_508_sig_bytes 644
#define MAYO_508_f_tail F_TAIL_134
#define MAYO_508_f_tail_arr f_tail_134
#define MAYO_508_salt_bytes 40
#define MAYO_508_digest_bytes 64
#define MAYO_508_pk_seed_bytes 16
#define MAYO_508_sk_seed_bytes 40

#define MAYO_507_n 152
#define MAYO_507_m 132
#define MAYO_507_m_vec_limbs 9
#define MAYO_507_o 20
#define MAYO_507_v 132
#define MAYO_507_A_cols (MAYO_507_k * MAYO_507_o + 1)
#define MAYO_507_k 7
#define MAYO_507_q 16
#define MAYO_507_m_bytes 66
#define MAYO_507_O_bytes 1320
#define MAYO_507_v_bytes 66
#define MAYO_507_r_bytes 70
#define MAYO_507_P1_bytes 579348
#define MAYO_507_P2_bytes 174240
#define MAYO_507_P3_bytes 13860
#define MAYO_507_csk_bytes 40
#define MAYO_507_cpk_bytes 13876
#define MAYO_507_sig_bytes 572
#define MAYO_507_f_tail F_TAIL_132
#define MAYO_507_f_tail_arr f_tail_132
#define MAYO_507_salt_bytes 40
#define MAYO_507_digest_bytes 64
#define MAYO_507_pk_seed_bytes 16
#define MAYO_507_sk_seed_bytes 40

#define MAYO_506_n 155
#define MAYO_506_m 132
#define MAYO_506_m_vec_limbs 9
#define MAYO_506_o 23
#define MAYO_506_v 132
#define MAYO_506_A_cols (MAYO_506_k * MAYO_506_o + 1)
#define MAYO_506_k 6
#define MAYO_506_q 16
#define MAYO_506_m_bytes 66
#define MAYO_506_O_bytes 1518
#define MAYO_506_v_bytes 66
#define MAYO_506_r_bytes 69
#define MAYO_506_P1_bytes 579348
#define MAYO_506_P2_bytes 200376
#define MAYO_506_P3_bytes 18216
#define MAYO_506_csk_bytes 40
#define MAYO_506_cpk_bytes 18232
#define MAYO_506_sig_bytes 505
#define MAYO_506_f_tail F_TAIL_132
#define MAYO_506_f_tail_arr f_tail_132
#define MAYO_506_salt_bytes 40
#define MAYO_506_digest_bytes 64
#define MAYO_506_pk_seed_bytes 16
#define MAYO_506_sk_seed_bytes 40

#define MAYO_505_n 157
#define MAYO_505_m 130
#define MAYO_505_m_vec_limbs 9
#define MAYO_505_o 27
#define MAYO_505_v 130
#define MAYO_505_A_cols (MAYO_505_k * MAYO_505_o + 1)
#define MAYO_505_k 5
#define MAYO_505_q 16
#define MAYO_505_m_bytes 65
#define MAYO_505_O_bytes 1755
#define MAYO_505_v_bytes 65
#define MAYO_505_r_bytes 68
#define MAYO_505_P1_bytes 553475
#define MAYO_505_P2_bytes 228150
#define MAYO_505_P3_bytes 24570
#define MAYO_505_csk_bytes 40
#define MAYO_505_cpk_bytes 24586
#define MAYO_505_sig_bytes 433
#define MAYO_505_f_tail F_TAIL_130
#define MAYO_505_f_tail_arr f_tail_130
#define MAYO_505_salt_bytes 40
#define MAYO_505_digest_bytes 64
#define MAYO_505_pk_seed_bytes 16
#define MAYO_505_sk_seed_bytes 40

#define PARAM_JOIN2_(a, b) a##_##b
#define PARAM_JOIN2(a, b) PARAM_JOIN2_(a, b)
#define PARAM_NAME(end) PARAM_JOIN2(MAYO_VARIANT, end)

#define PARAM_JOIN3_(a, b, c) pqmayo_##a##_##b##_##c
#define PARAM_JOIN3(a, b, c) PARAM_JOIN3_(a, b, c)
#define PARAM_NAME3(end, s) PARAM_JOIN3(MAYO_VARIANT, end, s)

#ifdef ENABLE_PARAMS_DYNAMIC
#define N_MAX 157
#define M_MAX 146
#define O_MAX 49
#define K_MAX 15
#define Q_MAX 16
#define NISTLEVEL_MAX 5
#define SK_SALT_BYTES_MAX 40
#define PK_BYTES_MAX 16
#define DIGEST_BYTES_MAX 64
#define V_MAX 146
#define O_BYTES_MAX 2475
#define V_BYTES_MAX 73
#define R_BYTES_MAX 77
#define P1_BYTES_MAX 783363
#define P2_BYTES_MAX 237552
#define P3_BYTES_MAX 58800
#define SIG_BYTES_MAX 1210
#define CPK_BYTES_MAX 58816
#define CSK_BYTES_MAX 40
#define M_BYTES_MAX 73
#define PK_SEED_BYTES_MAX 16
#define SK_SEED_BYTES_MAX 40
#define SALT_BYTES_MAX 40
#define M_VEC_LIMBS_MAX 10
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
extern const mayo_params_t MAYO_2B;
extern const mayo_params_t MAYO_103;
extern const mayo_params_t MAYO_102;
extern const mayo_params_t MAYO_313;
extern const mayo_params_t MAYO_3;
extern const mayo_params_t MAYO_310;
extern const mayo_params_t MAYO_309;
extern const mayo_params_t MAYO_308;
extern const mayo_params_t MAYO_307;
extern const mayo_params_t MAYO_306;
extern const mayo_params_t MAYO_305;
extern const mayo_params_t MAYO_304;
extern const mayo_params_t MAYO_303;
extern const mayo_params_t MAYO_302;
extern const mayo_params_t MAYO_515;
extern const mayo_params_t MAYO_514;
extern const mayo_params_t MAYO_5;
extern const mayo_params_t MAYO_511;
extern const mayo_params_t MAYO_510;
extern const mayo_params_t MAYO_509;
extern const mayo_params_t MAYO_508;
extern const mayo_params_t MAYO_507;
extern const mayo_params_t MAYO_506;
extern const mayo_params_t MAYO_505;
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
