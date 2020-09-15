/*
 *                                                                                                            +-+ +-+
 *  UAVCAN common serialization support routines.                                                             | | | |
 *                                                                                                            \  -  /
 *  This software is distributed under the terms of the MIT License.                                            ---
 *                                                                                                               o
 * +------------------------------------------------------------------------------------------------------------------+
 */
#ifndef NUNAVUT_SUPPORT_SERIALIZATION_H_INCLUDED
#define NUNAVUT_SUPPORT_SERIALIZATION_H_INCLUDED

#ifdef __cplusplus
#   if (__cplusplus < 201100L)
#       error "Unsupported language: ISO C11, C++11, or a newer version of either is required."
#   endif
extern "C"
{
#else
#   if !defined(__STDC_VERSION__) || (__STDC_VERSION__ < 201112L)
#       error "Unsupported language: ISO C11 or a newer version is required."
#   endif
#endif

#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#ifndef __cplusplus
#include <assert.h>
#endif

/// Serialization errors
/// Returned as negative numbers
#define NUNAVUT_ERR_INVALID_BUF 1   /// Indicates a NULL pointer to a data buffer was given.
#define NUNAVUT_ERR_INVALID_LEN 2   /// Indicates a variable length array was serialized with an
                                    /// invalid length tag.
#define NUNAVUT_ERR_BUF_OVERFLOW 3  /// Indicates the data being deserialized overflows the given
                                    /// buffer.
#define NUNAVUT_ERR_INVALID_TAG 4   /// Indicates that a union field was assigned an invalid tag.
#ifndef NUNAVUT_ASSERT
#define NUNAVUT_ASSERT(expr)
#endif
// --------------------------------------------- PRIMITIVE SERIALIZATION ---------------------------------------------

/// Calculate the number of bits to safely copy from serialized buffer.
/// Returns the smallest bit length based on requested parameters and available space.
///
/// @param buf_size_bytes       Size of the input buffer in bytes.
/// @param offset_bit           Offset (in bits) of data type in message.
/// @param requested_length_bit Size (in bits) of the data type requested.
/// @param value_length_bit     Size (in bits) of the data type that is being extracted into.
///
/// @returns                    Number of bits to safely read from buffer.
static inline uint32_t nunavutInternalGetBitCopySize(
    const size_t                   buf_size_bytes,
    const uint32_t offset_bit,
    const uint32_t requested_length_bit,
    const uint8_t                  value_length_bit)
{
    const uint32_t buf_size_bit  = (uint32_t)buf_size_bytes * 8U;
    const uint32_t remaining_bit = buf_size_bit - (((buf_size_bit) < (offset_bit)) ? (buf_size_bit) : (offset_bit));
    const uint32_t min_length_bit = (((requested_length_bit) < (value_length_bit)) ? (requested_length_bit) : (value_length_bit));
    const uint32_t min_remaining_length = (((remaining_bit) < (min_length_bit)) ? (remaining_bit) : (min_length_bit));
    return min_remaining_length;
}

// --------------------------------------------- PUBLIC API - BIT ARRAY ---------------------------------------------

static inline void nunavutCopyBits(const uint32_t length_bit,
                                   const uint32_t src_offset_bit,
                                   const uint32_t dst_offset_bit,
                                   const uint8_t* const           src,
                                   uint8_t* const                 dst)
{
    // The algorithm was originally designed by Ben Dyer for Libuavcan v0:
    // https://github.com/UAVCAN/libuavcan/blob/legacy-v0/libuavcan/src/marshal/uc_bit_array_copy.cpp
    // This version is modified for v1 where the bit order is the opposite.
    NUNAVUT_ASSERT(src != NULL);
    NUNAVUT_ASSERT(dst != NULL);
    NUNAVUT_ASSERT(src != dst);
    NUNAVUT_ASSERT(((src < dst) \
                       ? (src + ((src_offset_bit + length_bit + 4U) / 8U) <= dst) : 1));
    NUNAVUT_ASSERT(((src > dst) \
                       ? (dst + ((dst_offset_bit + length_bit + 4U) / 8U) <= src) : 1));
    if ((0U == (length_bit % 8U)) &&      //
        (0U == (src_offset_bit % 8U)) &&  //
        (0U == (dst_offset_bit % 8U)))
    {
        // Intentional violation of MISRA: Pointer arithmetics.
        // This is done to remove the API constraint that offsets be under 8 bits.
        // Fewer constraints reduce the chance of API misuse.
        (void) memcpy(dst + (dst_offset_bit / 8U),  // NOSONAR NOLINT
                      src + (src_offset_bit / 8U),  // NOSONAR
                      length_bit / 8U);
    }
    else
    {
        uint32_t       src_off  = src_offset_bit;
        uint32_t       dst_off  = dst_offset_bit;
        const uint32_t last_bit = src_off + length_bit;
        while (last_bit > src_off)
        {
            const uint8_t src_mod = (uint8_t)(src_off % 8U);
            const uint8_t dst_mod = (uint8_t)(dst_off % 8U);
            const uint8_t max_mod = (src_mod > dst_mod) ? src_mod : dst_mod;

            const uint8_t size = (uint8_t) (((8U - max_mod) < (last_bit - src_off)) ? (8U - max_mod) : (last_bit - src_off));
            NUNAVUT_ASSERT(size > 0U);
            NUNAVUT_ASSERT(size <= 8U);

            // Suppress a false warning from Clang-Tidy & Sonar that size is being over-shifted. It's not.
            const uint8_t mask = (uint8_t)((((1U << size) - 1U) << dst_mod) & 0xFFU);  // NOLINT NOSONAR
            NUNAVUT_ASSERT(mask > 0U);

            // Intentional violation of MISRA: indexing on a pointer.
            // This simplifies the implementation greatly and avoids pointer arithmetics.
            const uint8_t in = (uint8_t)((uint8_t)(src[src_off / 8U] >> src_mod) << dst_mod) &
                               0xFFU;  // NOSONAR

            // Intentional violation of MISRA: indexing on a pointer.
            // This simplifies the implementation greatly and avoids pointer arithmetics.
            const uint8_t a = dst[dst_off / 8U] & ((uint8_t) ~mask);  // NOSONAR
            const uint8_t b = in & mask;

            // Intentional violation of MISRA: indexing on a pointer.
            // This simplifies the implementation greatly and avoids pointer arithmetics.
            dst[dst_off / 8U] = a | b;  // NOSONAR

            src_off += size;
            dst_off += size;
        }
        NUNAVUT_ASSERT(last_bit == src_off);
    }
}

// --------------------------------------------- PUBLIC API - INTEGER ---------------------------------------------

static inline void nunavutSetBit(uint8_t* const buf, const uint32_t off_bit, const bool value)
{
    NUNAVUT_ASSERT(buf != NULL);
    const uint8_t val = value ? 1U : 0U;
    nunavutCopyBits(1U, 0U, off_bit, &val, buf);
}

static inline void nunavutSetUxx(uint8_t* const                 buf,
                                 const uint32_t off_bit,
                                 const uint64_t                 value,
                                 const uint8_t                  len_bit)
{
    static_assert(64U == (sizeof(uint64_t) * 8U), "Unexpected size of uint64_t");
    NUNAVUT_ASSERT(buf != NULL);
    const uint32_t saturated_len_bit = (((len_bit) < (64U)) ? (len_bit) : (64U));
    nunavutCopyBits(saturated_len_bit, 0U, off_bit, (const uint8_t*) &value, buf);
}

static inline void nunavutSetIxx(uint8_t* const                 buf,
                                 const uint32_t off_bit,
                                 const int64_t                  value,
                                 const uint8_t                  len_bit)
{
    // The naive sign conversion is safe and portable according to the C standard:
    // 6.3.1.3.3: if the new type is unsigned, the value is converted by repeatedly adding or subtracting one more
    // than the maximum value that can be represented in the new type until the value is in the range of the new type.
    nunavutSetUxx(buf, off_bit, (uint64_t) value, len_bit);
}

static inline uint8_t nunavutGetU8(const uint8_t* const           buf,
                                   const size_t                   buf_size,
                                   const uint32_t off_bit,
                                   const uint8_t                  len_bit);

static inline bool nunavutGetBit(const uint8_t* const           buf,
                                 const size_t                   buf_size,
                                 const uint32_t off_bit)
{
    return 1U == nunavutGetU8(buf, buf_size, off_bit, 1U);
}

static inline uint8_t nunavutGetU8(const uint8_t* const           buf,
                                   const size_t                   buf_size,
                                   const uint32_t off_bit,
                                   const uint8_t                  len_bit)
{
    NUNAVUT_ASSERT(buf != NULL);
    const uint32_t copy_size =
        nunavutInternalGetBitCopySize(buf_size, off_bit, len_bit, 8U);
    NUNAVUT_ASSERT(copy_size <= (sizeof(uint8_t) * 8U));
    uint8_t val = 0;
    nunavutCopyBits(copy_size, off_bit, 0U, buf, &val);
    return val;
}

static inline uint16_t nunavutGetU16(const uint8_t* const           buf,
                                     const size_t                   buf_size,
                                     const uint32_t off_bit,
                                     const uint8_t                  len_bit)
{
    NUNAVUT_ASSERT(buf != NULL);
    const uint32_t copy_size =
        nunavutInternalGetBitCopySize(buf_size, off_bit, len_bit, 16U);
    NUNAVUT_ASSERT(copy_size <= (sizeof(uint16_t) * 8U));
    uint16_t val = 0U;
    nunavutCopyBits(copy_size, off_bit, 0U, buf, (uint8_t*) &val);
    return val;
}

static inline uint32_t nunavutGetU32(const uint8_t* const           buf,
                                     const size_t                   buf_size,
                                     const uint32_t off_bit,
                                     const uint8_t                  len_bit)
{
    NUNAVUT_ASSERT(buf != NULL);
    const uint32_t copy_size =
        nunavutInternalGetBitCopySize(buf_size, off_bit, len_bit, 32U);
    NUNAVUT_ASSERT(copy_size <= (sizeof(uint32_t) * 8U));
    uint32_t val = 0U;
    nunavutCopyBits(copy_size, off_bit, 0U, buf, (uint8_t*) &val);
    return val;
}

static inline uint64_t nunavutGetU64(const uint8_t* const           buf,
                                     const size_t                   buf_size,
                                     const uint32_t off_bit,
                                     const uint8_t                  len_bit)
{
    NUNAVUT_ASSERT(buf != NULL);
    const uint32_t copy_size =
        nunavutInternalGetBitCopySize(buf_size, off_bit, len_bit, 64U);
    NUNAVUT_ASSERT(copy_size <= (sizeof(uint64_t) * 8U));
    uint64_t val = 0U;
    nunavutCopyBits(copy_size, off_bit, 0U, buf, (uint8_t*) &val);
    return val;
}

static inline int8_t nunavutGetI8(const uint8_t* const           buf,
                                  const size_t                   buf_size,
                                  const uint32_t off_bit,
                                  const uint8_t                  len_bit)
{
    const uint8_t sat = (uint8_t) (((len_bit) < (8U)) ? (len_bit) : (8U));
    uint8_t       val = nunavutGetU8(buf, buf_size, off_bit, sat);
    const bool    neg = (sat > 0U) && ((val & (1ULL << (sat - 1U))) != 0U);
    val = ((sat < 8U) && neg) ? (uint8_t)(val | ~((1U << sat) - 1U)) : val;  // Sign extension
    return neg ? (int8_t)((-(int8_t)(uint8_t) ~val) - 1) : (int8_t) val;
}

static inline int16_t nunavutGetI16(const uint8_t* const           buf,
                                    const size_t                   buf_size,
                                    const uint32_t off_bit,
                                    const uint8_t                  len_bit)
{
    const uint8_t sat = (uint8_t) (((len_bit) < (16U)) ? (len_bit) : (16U));
    uint16_t      val = nunavutGetU16(buf, buf_size, off_bit, sat);
    const bool    neg = (sat > 0U) && ((val & (1ULL << (sat - 1U))) != 0U);
    val = ((sat < 16U) && neg) ? (uint16_t)(val | ~((1U << sat) - 1U)) : val;  // Sign extension
    return neg ? (int16_t)((-(int16_t)(uint16_t) ~val) - 1) : (int16_t) val;
}

static inline int32_t nunavutGetI32(const uint8_t* const           buf,
                                    const size_t                   buf_size,
                                    const uint32_t off_bit,
                                    const uint8_t                  len_bit)
{
    const uint8_t sat = (uint8_t) (((len_bit) < (32U)) ? (len_bit) : (32U));
    uint32_t      val = nunavutGetU32(buf, buf_size, off_bit, sat);
    const bool    neg = (sat > 0U) && ((val & (1ULL << (sat - 1U))) != 0U);
    val = ((sat < 32U) && neg) ? (uint32_t)(val | ~((1UL << sat) - 1U)) : val;  // Sign extension
    return neg ? (int32_t)((-(int32_t) ~val) - 1) : (int32_t) val;
}

static inline int64_t nunavutGetI64(const uint8_t* const           buf,
                                    const size_t                   buf_size,
                                    const uint32_t off_bit,
                                    const uint8_t                  len_bit)
{
    const uint8_t sat = (uint8_t) (((len_bit) < (64U)) ? (len_bit) : (64U));
    uint64_t      val = nunavutGetU64(buf, buf_size, off_bit, sat);
    const bool    neg = (sat > 0U) && ((val & (1ULL << (sat - 1U))) != 0U);
    val = ((sat < 64U) && neg) ? (uint64_t)(val | ~((1ULL << sat) - 1U)) : val;  // Sign extension
    return neg ? (int64_t)((-(int64_t) ~val) - 1) : (int64_t) val;
}

// --------------------------------------------- PUBLIC API - FLOAT16 ---------------------------------------------// --------------------------------------------- PUBLIC API - FLOAT32 ---------------------------------------------// --------------------------------------------- PUBLIC API - FLOAT64 ---------------------------------------------#ifdef __cplusplus
}

#endif /* NUNAVUT_SUPPORT_SERIALIZATION_H_INCLUDED */
