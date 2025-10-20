#include <string.h>
#include "pkod.h"

#define PKOD_MIN(x, y) (((x) < (y)) ? (x) : (y))
#define BLOCK_INDEX(byte_pos)  ((byte_pos) / AES_BLOCKBYTES)
#define POS_IN_BLOCK(byte_pos) ((byte_pos) % AES_BLOCKBYTES)

static inline void to_BE32(uint8_t buf[AES_BLOCKBYTES], const uint32_t val)
{
  buf[AES_BLOCKBYTES - 4u] =  val >> 24u;
  buf[AES_BLOCKBYTES - 3u] = (val >> 16u) & 0xff;
  buf[AES_BLOCKBYTES - 2u] = (val >>  8u) & 0xff;
  buf[AES_BLOCKBYTES - 1u] = (val       ) & 0xff;
}

static void update_cache(mayo_pkod_prf_point_t * const point, const uint32_t new_cache_ctr)
{
  uint8_t ctr[AES_BLOCKBYTES] = {0};

  if (new_cache_ctr != point->cache_ctr)
  { // We have to change cache content
    to_BE32(ctr, new_cache_ctr);
    aes128_ecb_publicinputs(point->cache, ctr, 1u, point->key);
    point->cache_ctr = new_cache_ctr;
  }
}

static void pkod_PRF(uint8_t * out, const uint_fast32_t off_bytes, const size_t len_bytes,
                     mayo_pkod_prf_point_t * const P)
{
  const uint32_t end_bytes = off_bytes + len_bytes;
  for (uint32_t position = off_bytes; ((position < end_bytes) && (len_bytes <= end_bytes)); )
  {
    const uint_fast16_t pos_in_block = POS_IN_BLOCK(position);
    const uint_fast16_t round_bytes = PKOD_MIN(end_bytes -position, AES_BLOCKBYTES -pos_in_block);
    const uint32_t ctr = BLOCK_INDEX(position);
    if (P->cache_ctr != ctr) update_cache(P, ctr);
    memcpy(out, P->cache + pos_in_block, round_bytes);
    out += round_bytes;
    position += round_bytes;
  }
}

uint64_t pkod_P(const uint_fast32_t i, mayo_pkod_point_t * const P)
{
  /* The expanded public key is a consecutive array of vectors. First those of P1, followed by those
     of P2. P3 is expanded separately from a transmitted sequence (TRS) of bytes, not the PRF.
     A vector is a consecutive array of m_vec_limbs = (m + 15) / 16 limbs. A limb is a uint64_t. The
     first m/2 bytes of each vector come from the PRF respectively TRS, the remaining bytes are
     zero. */
  union
  {
    uint64_t u64;
    uint8_t u8[sizeof(uint64_t)];
  } result = {0};
  const uint_fast16_t m_vec_limbs = (P->m + 15) / 16; // The number of limbs in a vector
  const uint_fast16_t m_vec_SEQ_bytes = P->m / 2; /* The number of bytes from the PRF or TRS in a
                                                     vector */
  const uint_fast32_t limb = i + P->limb_off; // The index of limb i in the array of limbs
  const uint_fast32_t vector = limb / m_vec_limbs; // The index of the vector that contains limb i
  const uint_fast32_t offset_in_vector = (limb % m_vec_limbs) * sizeof(uint64_t); /* Byte offset of
                                                                                 limb i in vector */
  if (offset_in_vector < m_vec_SEQ_bytes)
  { // The requested limb contains bytes from the PRF or TRS
    const uint_fast32_t offset_in_SEQ = (vector * m_vec_SEQ_bytes) + offset_in_vector;
    const size_t bytes_from_SEQ = PKOD_MIN(sizeof(uint64_t), m_vec_SEQ_bytes - offset_in_vector);
    if (P->point_type == 3u)
    { // Copy required bytes from transmitted sequence (TRS)
      memcpy(result.u8, P->src.trs.seq + offset_in_SEQ, bytes_from_SEQ);
    }
    else
    {
      pkod_PRF(result.u8, offset_in_SEQ, bytes_from_SEQ, &(P->src.prf));
    }
  }
#ifdef TARGET_BIG_ENDIAN
  return BSWAP64(result.u64);
#else
  return result.u64;
#endif
}

void pkod_init(mayo_pkod_t * const PP, const mayo_params_t * const p,
               const unsigned char * const cpk)
{
  #ifndef ENABLE_PARAMS_DYNAMIC
  (void) p;
  #endif
  aes128_ctr_keyexp_publicinputs(&(PP->key), cpk);

  PP->P1.point_type = 1u;
  PP->P1.m = PARAM_m(p);
  PP->P1.limb_off = 0u;
  PP->P1.src.prf.key = &(PP->key);
  PP->P1.src.prf.cache_ctr = UINT32_MAX;
  update_cache(&(PP->P1.src.prf), BLOCK_INDEX(PP->P1.limb_off * sizeof(uint64_t)));

  PP->P2.point_type = 2u;
  PP->P2.m = PP->P1.m;
  PP->P2.limb_off = PARAM_P1_limbs(p);
  PP->P2.src.prf.key = PP->P1.src.prf.key;
  PP->P2.src.prf.cache_ctr = PP->P1.src.prf.cache_ctr;
  update_cache(&(PP->P2.src.prf), BLOCK_INDEX(PP->P2.limb_off * sizeof(uint64_t)));

  PP->P3.point_type = 3u;
  PP->P3.m = PP->P1.m;
  PP->P3.limb_off = 0u;
  PP->P3.src.trs.seq = cpk + PARAM_pk_seed_bytes(p);
}
