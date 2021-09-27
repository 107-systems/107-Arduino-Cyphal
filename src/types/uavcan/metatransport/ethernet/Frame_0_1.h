// This is an AUTO-GENERATED UAVCAN DSDL data type implementation. Curious? See https://uavcan.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended unless it is used as part of a high-SIL
// safety-critical codebase. The typical usage scenario is to generate it as part of the build process.
//
// To avoid conflicts with definitions given in the source DSDL file, all entities created by the code generator
// are named with an underscore at the end, like foo_bar_().
//
// Generator:     nunavut-1.4.2 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/uavcan/metatransport/ethernet/Frame.0.1.uavcan
// Generated at:  2021-09-27 06:53:04.470256 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     uavcan.metatransport.ethernet.Frame
// Version:       0.1
//
// Platform
//     python_implementation:  CPython
//     python_version:  3.8.0
//     python_release_level:  final
//     python_build:  ('default', 'Feb 25 2021 22:10:10')
//     python_compiler:  GCC 8.4.0
//     python_revision:
//     python_xoptions:  {}
//     runtime_platform:  Linux-5.4.0-86-generic-x86_64-with-glibc2.27
//
// Language Options
//     target_endianness:  any
//     omit_float_serialization_support:  False
//     enable_serialization_asserts:  True
//     enable_override_variable_array_capacity:  False

#ifndef UAVCAN_METATRANSPORT_ETHERNET_FRAME_0_1_INCLUDED_
#define UAVCAN_METATRANSPORT_ETHERNET_FRAME_0_1_INCLUDED_

#include <nunavut/support/serialization.h>
#include <types/uavcan/metatransport/ethernet/EtherType_0_1.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_TARGET_ENDIANNESS == 1693710260,
              "/tmp/public_regulated_data_types/uavcan/metatransport/ethernet/Frame.0.1.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_OMIT_FLOAT_SERIALIZATION_SUPPORT == 0,
              "/tmp/public_regulated_data_types/uavcan/metatransport/ethernet/Frame.0.1.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_SERIALIZATION_ASSERTS == 1,
              "/tmp/public_regulated_data_types/uavcan/metatransport/ethernet/Frame.0.1.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_OVERRIDE_VARIABLE_ARRAY_CAPACITY == 0,
              "/tmp/public_regulated_data_types/uavcan/metatransport/ethernet/Frame.0.1.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );

#ifdef __cplusplus
extern "C" {
#endif

/// This type does not have a fixed port-ID. See https://forum.uavcan.org/t/choosing-message-and-service-ids/889
#define uavcan_metatransport_ethernet_Frame_0_1_HAS_FIXED_PORT_ID_ false

#define uavcan_metatransport_ethernet_Frame_0_1_FULL_NAME_             "uavcan.metatransport.ethernet.Frame"
#define uavcan_metatransport_ethernet_Frame_0_1_FULL_NAME_AND_VERSION_ "uavcan.metatransport.ethernet.Frame.0.1"

/// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
/// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
/// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
/// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
/// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
/// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
/// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.
#define uavcan_metatransport_ethernet_Frame_0_1_EXTENT_BYTES_                    9232UL
#define uavcan_metatransport_ethernet_Frame_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_ 9232UL
static_assert(uavcan_metatransport_ethernet_Frame_0_1_EXTENT_BYTES_ >= uavcan_metatransport_ethernet_Frame_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_,
              "Internal constraint violation");

/// Array metadata for: saturated uint8[6] destination
#define uavcan_metatransport_ethernet_Frame_0_1_destination_ARRAY_CAPACITY_           6U
#define uavcan_metatransport_ethernet_Frame_0_1_destination_ARRAY_IS_VARIABLE_LENGTH_ false
/// Array metadata for: saturated uint8[6] source
#define uavcan_metatransport_ethernet_Frame_0_1_source_ARRAY_CAPACITY_           6U
#define uavcan_metatransport_ethernet_Frame_0_1_source_ARRAY_IS_VARIABLE_LENGTH_ false
/// Array metadata for: saturated uint8[<=9216] payload
#define uavcan_metatransport_ethernet_Frame_0_1_payload_ARRAY_CAPACITY_           9216U
#define uavcan_metatransport_ethernet_Frame_0_1_payload_ARRAY_IS_VARIABLE_LENGTH_ true

typedef struct
{
    /// saturated uint8[6] destination
    uint8_t destination[6];

    /// saturated uint8[6] source
    uint8_t source[6];

    /// uavcan.metatransport.ethernet.EtherType.0.1 ethertype
    uavcan_metatransport_ethernet_EtherType_0_1 ethertype;

    /// saturated uint8[<=9216] payload
    struct  /// Array address equivalence guarantee: &elements[0] == &payload
    {
        uint8_t elements[uavcan_metatransport_ethernet_Frame_0_1_payload_ARRAY_CAPACITY_];
        size_t count;
    } payload;
} uavcan_metatransport_ethernet_Frame_0_1;

/// Serialize an instance into the provided buffer.
/// The lifetime of the resulting serialized representation is independent of the original instance.
/// This method may be slow for large objects (e.g., images, point clouds, radar samples), so in a later revision
/// we may define a zero-copy alternative that keeps references to the original object where possible.
///
/// @param obj      The object to serialize.
///
/// @param buffer   The destination buffer. There are no alignment requirements.
///                 @see uavcan_metatransport_ethernet_Frame_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_
///
/// @param inout_buffer_size_bytes  When calling, this is a pointer to the size of the buffer in bytes.
///                                 Upon return this value will be updated with the size of the constructed serialized
///                                 representation (in bytes); this value is then to be passed over to the transport
///                                 layer. In case of error this value is undefined.
///
/// @returns Negative on error, zero on success.
static inline int8_t uavcan_metatransport_ethernet_Frame_0_1_serialize_(
    const uavcan_metatransport_ethernet_Frame_0_1* const obj, uint8_t* const buffer,  size_t* const inout_buffer_size_bytes)
{
    if ((obj == NULL) || (buffer == NULL) || (inout_buffer_size_bytes == NULL))
    {
        return -NUNAVUT_ERROR_INVALID_ARGUMENT;
    }

    const size_t capacity_bytes = *inout_buffer_size_bytes;
    if ((8U * (size_t) capacity_bytes) < 73856UL)
    {
        return -NUNAVUT_ERROR_SERIALIZATION_BUFFER_TOO_SMALL;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    size_t offset_bits = 0U;

    {   // saturated uint8[6] destination
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 48ULL) <= (capacity_bytes * 8U));
        const size_t _origin0_ = offset_bits;
        for (size_t _index0_ = 0U; _index0_ < 6UL; ++_index0_)
        {
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 8ULL) <= (capacity_bytes * 8U));
            // Saturation code not emitted -- native representation matches the serialized representation.
            buffer[offset_bits / 8U] = (uint8_t)(obj->destination[_index0_]);  // C std, 6.3.1.3 Signed and unsigned integers
            offset_bits += 8U;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((offset_bits - _origin0_) == 48ULL);
        (void) _origin0_;
    }

    {   // saturated uint8[6] source
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 48ULL) <= (capacity_bytes * 8U));
        const size_t _origin1_ = offset_bits;
        for (size_t _index1_ = 0U; _index1_ < 6UL; ++_index1_)
        {
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 8ULL) <= (capacity_bytes * 8U));
            // Saturation code not emitted -- native representation matches the serialized representation.
            buffer[offset_bits / 8U] = (uint8_t)(obj->source[_index1_]);  // C std, 6.3.1.3 Signed and unsigned integers
            offset_bits += 8U;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((offset_bits - _origin1_) == 48ULL);
        (void) _origin1_;
    }

    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad0_ = (uint8_t)(8U - offset_bits % 8U);
        NUNAVUT_ASSERT(_pad0_ > 0);
        const int8_t _err0_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad0_);  // Optimize?
        if (_err0_ < 0)
        {
            return _err0_;
        }
        offset_bits += _pad0_;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    }

    {   // uavcan.metatransport.ethernet.EtherType.0.1 ethertype
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes0_ = 2UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes0_) <= capacity_bytes);
        int8_t _err1_ = uavcan_metatransport_ethernet_EtherType_0_1_serialize_(
            &obj->ethertype, &buffer[offset_bits / 8U], &_size_bytes0_);
        if (_err1_ < 0)
        {
            return _err1_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes0_ * 8U) == 16ULL);
        offset_bits += _size_bytes0_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }

    {   // saturated uint8[<=9216] payload
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 73744ULL) <= (capacity_bytes * 8U));
        if (obj->payload.count > 9216)
        {
            return -NUNAVUT_ERROR_REPRESENTATION_BAD_ARRAY_LENGTH;
        }
        // Array length prefix: truncated uint16
        const int8_t _err2_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, obj->payload.count, 16U);
        if (_err2_ < 0)
        {
            return _err2_;
        }
        offset_bits += 16U;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        for (size_t _index2_ = 0U; _index2_ < obj->payload.count; ++_index2_)
        {
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 8ULL) <= (capacity_bytes * 8U));
            // Saturation code not emitted -- native representation matches the serialized representation.
            buffer[offset_bits / 8U] = (uint8_t)(obj->payload.elements[_index2_]);  // C std, 6.3.1.3 Signed and unsigned integers
            offset_bits += 8U;
        }
    }

    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad1_ = (uint8_t)(8U - offset_bits % 8U);
        NUNAVUT_ASSERT(_pad1_ > 0);
        const int8_t _err3_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad1_);  // Optimize?
        if (_err3_ < 0)
        {
            return _err3_;
        }
        offset_bits += _pad1_;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    }
    // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.

    NUNAVUT_ASSERT(offset_bits >= 128ULL);
    NUNAVUT_ASSERT(offset_bits <= 73856ULL);

    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    *inout_buffer_size_bytes = (size_t) (offset_bits / 8U);

    return NUNAVUT_SUCCESS;
}

/// Deserialize an instance from the provided buffer.
/// The lifetime of the resulting object is independent of the original buffer.
/// This method may be slow for large objects (e.g., images, point clouds, radar samples), so in a later revision
/// we may define a zero-copy alternative that keeps references to the original buffer where possible.
///
/// @param obj      The object to update from the provided serialized representation.
///
/// @param buffer   The source buffer containing the serialized representation. There are no alignment requirements.
///                 If the buffer is shorter or longer than expected, it will be implicitly zero-extended or truncated,
///                 respectively; see Specification for "implicit zero extension" and "implicit truncation" rules.
///
/// @param inout_buffer_size_bytes  When calling, this is a pointer to the size of the supplied serialized
///                                 representation, in bytes. Upon return this value will be updated with the
///                                 size of the consumed fragment of the serialized representation (in bytes),
///                                 which may be smaller due to the implicit truncation rule, but it is guaranteed
///                                 to never exceed the original buffer size even if the implicit zero extension rule
///                                 was activated. In case of error this value is undefined.
///
/// @returns Negative on error, zero on success.
static inline int8_t uavcan_metatransport_ethernet_Frame_0_1_deserialize_(
    uavcan_metatransport_ethernet_Frame_0_1* const out_obj, const uint8_t* const buffer, size_t* const inout_buffer_size_bytes)
{
    if ((out_obj == NULL) || (buffer == NULL) || (inout_buffer_size_bytes == NULL))
    {
        return -NUNAVUT_ERROR_INVALID_ARGUMENT;
    }

    const size_t capacity_bytes = *inout_buffer_size_bytes;
    const size_t capacity_bits = capacity_bytes * (size_t) 8U;
    size_t offset_bits = 0U;

    // saturated uint8[6] destination
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    for (size_t _index3_ = 0U; _index3_ < 6UL; ++_index3_)
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        if ((offset_bits + 8U) <= capacity_bits)
        {
            out_obj->destination[_index3_] = buffer[offset_bits / 8U] & 255U;
        }
        else
        {
            out_obj->destination[_index3_] = 0U;
        }
        offset_bits += 8U;
    }

    // saturated uint8[6] source
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    for (size_t _index4_ = 0U; _index4_ < 6UL; ++_index4_)
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        if ((offset_bits + 8U) <= capacity_bits)
        {
            out_obj->source[_index4_] = buffer[offset_bits / 8U] & 255U;
        }
        else
        {
            out_obj->source[_index4_] = 0U;
        }
        offset_bits += 8U;
    }

    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.

    // uavcan.metatransport.ethernet.EtherType.0.1 ethertype
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    {
        size_t _size_bytes1_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        const int8_t _err4_ = uavcan_metatransport_ethernet_EtherType_0_1_deserialize_(
            &out_obj->ethertype, &buffer[offset_bits / 8U], &_size_bytes1_);
        if (_err4_ < 0)
        {
            return _err4_;
        }
        offset_bits += _size_bytes1_ * 8U;  // Advance by the size of the nested serialized representation.
    }

    // saturated uint8[<=9216] payload
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    // Array length prefix: truncated uint16
    out_obj->payload.count = nunavutGetU16(&buffer[0], capacity_bytes, offset_bits, 16);
    offset_bits += 16U;
    if (out_obj->payload.count > 9216U)
    {
        return -NUNAVUT_ERROR_REPRESENTATION_BAD_ARRAY_LENGTH;
    }
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    for (size_t _index5_ = 0U; _index5_ < out_obj->payload.count; ++_index5_)
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        if ((offset_bits + 8U) <= capacity_bits)
        {
            out_obj->payload.elements[_index5_] = buffer[offset_bits / 8U] & 255U;
        }
        else
        {
            out_obj->payload.elements[_index5_] = 0U;
        }
        offset_bits += 8U;
    }

    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    *inout_buffer_size_bytes = (size_t) (nunavutChooseMin(offset_bits, capacity_bits) / 8U);
    NUNAVUT_ASSERT(capacity_bytes >= *inout_buffer_size_bytes);

    return NUNAVUT_SUCCESS;
}

/// Initialize an instance to default values. Does nothing if @param out_obj is NULL.
/// This function intentionally leaves inactive elements uninitialized; for example, members of a variable-length
/// array beyond its length are left uninitialized; aliased union memory that is not used by the first union field
/// is left uninitialized, etc. If full zero-initialization is desired, just use memset(&obj, 0, sizeof(obj)).
static inline void uavcan_metatransport_ethernet_Frame_0_1_initialize_(uavcan_metatransport_ethernet_Frame_0_1* const out_obj)
{
    if (out_obj != NULL)
    {
        size_t size_bytes = 0;
        const uint8_t buf = 0;
        const int8_t err = uavcan_metatransport_ethernet_Frame_0_1_deserialize_(out_obj, &buf, &size_bytes);
        NUNAVUT_ASSERT(err >= 0);
        (void) err;
    }
}

#ifdef __cplusplus
}
#endif
#endif // UAVCAN_METATRANSPORT_ETHERNET_FRAME_0_1_INCLUDED_
