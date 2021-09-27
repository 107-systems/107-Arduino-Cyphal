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
// Source file:   /tmp/public_regulated_data_types/uavcan/metatransport/udp/Frame.0.1.uavcan
// Generated at:  2021-09-27 06:53:04.477619 UTC
// Is deprecated: yes
// Fixed port-ID: None
// Full name:     uavcan.metatransport.udp.Frame
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

//           _____  ______ _____  _____  ______ _____       _______ ______ _____
//          |  __ `|  ____|  __ `|  __ `|  ____/ ____|   /`|__   __|  ____|  __ `
//          | |  | | |__  | |__) | |__) | |__ | |       /  `  | |  | |__  | |  | |
//          | |  | |  __| |  ___/|  _  /|  __|| |      / /` ` | |  |  __| | |  | |
//          | |__| | |____| |    | | ` `| |___| |____ / ____ `| |  | |____| |__| |
//          |_____/|______|_|    |_|  `_`______`_____/_/    `_`_|  |______|_____/
//
// WARNING: this data type is deprecated and is nearing the end of its life cycle. Seek replacement.

#ifndef UAVCAN_METATRANSPORT_UDP_FRAME_0_1_INCLUDED_
#define UAVCAN_METATRANSPORT_UDP_FRAME_0_1_INCLUDED_

#include <nunavut/support/serialization.h>
#include <types/uavcan/metatransport/udp/Endpoint_0_1.h>
#include <types/uavcan/time/SynchronizedTimestamp_1_0.h>
#include <stdint.h>
#include <stdlib.h>

static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_TARGET_ENDIANNESS == 1693710260,
              "/tmp/public_regulated_data_types/uavcan/metatransport/udp/Frame.0.1.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_OMIT_FLOAT_SERIALIZATION_SUPPORT == 0,
              "/tmp/public_regulated_data_types/uavcan/metatransport/udp/Frame.0.1.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_SERIALIZATION_ASSERTS == 1,
              "/tmp/public_regulated_data_types/uavcan/metatransport/udp/Frame.0.1.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_OVERRIDE_VARIABLE_ARRAY_CAPACITY == 0,
              "/tmp/public_regulated_data_types/uavcan/metatransport/udp/Frame.0.1.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );

#ifdef __cplusplus
extern "C" {
#endif

/// This type does not have a fixed port-ID. See https://forum.uavcan.org/t/choosing-message-and-service-ids/889
#define uavcan_metatransport_udp_Frame_0_1_HAS_FIXED_PORT_ID_ false

#define uavcan_metatransport_udp_Frame_0_1_FULL_NAME_             "uavcan.metatransport.udp.Frame"
#define uavcan_metatransport_udp_Frame_0_1_FULL_NAME_AND_VERSION_ "uavcan.metatransport.udp.Frame.0.1"

/// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
/// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
/// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
/// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
/// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
/// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
/// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.
#define uavcan_metatransport_udp_Frame_0_1_EXTENT_BYTES_                    10240UL
#define uavcan_metatransport_udp_Frame_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_ 9262UL
static_assert(uavcan_metatransport_udp_Frame_0_1_EXTENT_BYTES_ >= uavcan_metatransport_udp_Frame_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_,
              "Internal constraint violation");

/// saturated uint14 MTU = 9188
#define uavcan_metatransport_udp_Frame_0_1_MTU (9188U)

/// Array metadata for: saturated uint8[<=9188] data
#define uavcan_metatransport_udp_Frame_0_1_data_ARRAY_CAPACITY_           9188U
#define uavcan_metatransport_udp_Frame_0_1_data_ARRAY_IS_VARIABLE_LENGTH_ true

typedef struct
{
    /// uavcan.time.SynchronizedTimestamp.1.0 timestamp
    uavcan_time_SynchronizedTimestamp_1_0 timestamp;

    /// uavcan.metatransport.udp.Endpoint.0.1 source
    uavcan_metatransport_udp_Endpoint_0_1 source;

    /// uavcan.metatransport.udp.Endpoint.0.1 destination
    uavcan_metatransport_udp_Endpoint_0_1 destination;

    /// saturated uint8[<=9188] data
    struct  /// Array address equivalence guarantee: &elements[0] == &data
    {
        uint8_t elements[uavcan_metatransport_udp_Frame_0_1_data_ARRAY_CAPACITY_];
        size_t count;
    } data;
} uavcan_metatransport_udp_Frame_0_1;

/// Serialize an instance into the provided buffer.
/// The lifetime of the resulting serialized representation is independent of the original instance.
/// This method may be slow for large objects (e.g., images, point clouds, radar samples), so in a later revision
/// we may define a zero-copy alternative that keeps references to the original object where possible.
///
/// @param obj      The object to serialize.
///
/// @param buffer   The destination buffer. There are no alignment requirements.
///                 @see uavcan_metatransport_udp_Frame_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_
///
/// @param inout_buffer_size_bytes  When calling, this is a pointer to the size of the buffer in bytes.
///                                 Upon return this value will be updated with the size of the constructed serialized
///                                 representation (in bytes); this value is then to be passed over to the transport
///                                 layer. In case of error this value is undefined.
///
/// @returns Negative on error, zero on success.
static inline int8_t uavcan_metatransport_udp_Frame_0_1_serialize_(
    const uavcan_metatransport_udp_Frame_0_1* const obj, uint8_t* const buffer,  size_t* const inout_buffer_size_bytes)
{
    if ((obj == NULL) || (buffer == NULL) || (inout_buffer_size_bytes == NULL))
    {
        return -NUNAVUT_ERROR_INVALID_ARGUMENT;
    }

    const size_t capacity_bytes = *inout_buffer_size_bytes;
    if ((8U * (size_t) capacity_bytes) < 74096UL)
    {
        return -NUNAVUT_ERROR_SERIALIZATION_BUFFER_TOO_SMALL;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    size_t offset_bits = 0U;

    {   // uavcan.time.SynchronizedTimestamp.1.0 timestamp
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 56ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes0_ = 7UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes0_) <= capacity_bytes);
        int8_t _err0_ = uavcan_time_SynchronizedTimestamp_1_0_serialize_(
            &obj->timestamp, &buffer[offset_bits / 8U], &_size_bytes0_);
        if (_err0_ < 0)
        {
            return _err0_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes0_ * 8U) == 56ULL);
        offset_bits += _size_bytes0_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }

    {   // void8
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 8ULL) <= (capacity_bytes * 8U));
        buffer[offset_bits / 8U] = 0U;
        offset_bits += 8UL;
    }

    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad0_ = (uint8_t)(8U - offset_bits % 8U);
        NUNAVUT_ASSERT(_pad0_ > 0);
        const int8_t _err1_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad0_);  // Optimize?
        if (_err1_ < 0)
        {
            return _err1_;
        }
        offset_bits += _pad0_;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    }

    {   // uavcan.metatransport.udp.Endpoint.0.1 source
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 256ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes1_ = 32UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes1_) <= capacity_bytes);
        int8_t _err2_ = uavcan_metatransport_udp_Endpoint_0_1_serialize_(
            &obj->source, &buffer[offset_bits / 8U], &_size_bytes1_);
        if (_err2_ < 0)
        {
            return _err2_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes1_ * 8U) == 256ULL);
        offset_bits += _size_bytes1_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
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

    {   // uavcan.metatransport.udp.Endpoint.0.1 destination
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 256ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes2_ = 32UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes2_) <= capacity_bytes);
        int8_t _err4_ = uavcan_metatransport_udp_Endpoint_0_1_serialize_(
            &obj->destination, &buffer[offset_bits / 8U], &_size_bytes2_);
        if (_err4_ < 0)
        {
            return _err4_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes2_ * 8U) == 256ULL);
        offset_bits += _size_bytes2_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }

    {   // saturated uint8[<=9188] data
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 73520ULL) <= (capacity_bytes * 8U));
        if (obj->data.count > 9188)
        {
            return -NUNAVUT_ERROR_REPRESENTATION_BAD_ARRAY_LENGTH;
        }
        // Array length prefix: truncated uint16
        const int8_t _err5_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, obj->data.count, 16U);
        if (_err5_ < 0)
        {
            return _err5_;
        }
        offset_bits += 16U;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        for (size_t _index0_ = 0U; _index0_ < obj->data.count; ++_index0_)
        {
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 8ULL) <= (capacity_bytes * 8U));
            // Saturation code not emitted -- native representation matches the serialized representation.
            buffer[offset_bits / 8U] = (uint8_t)(obj->data.elements[_index0_]);  // C std, 6.3.1.3 Signed and unsigned integers
            offset_bits += 8U;
        }
    }

    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad2_ = (uint8_t)(8U - offset_bits % 8U);
        NUNAVUT_ASSERT(_pad2_ > 0);
        const int8_t _err6_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad2_);  // Optimize?
        if (_err6_ < 0)
        {
            return _err6_;
        }
        offset_bits += _pad2_;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    }
    // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.

    NUNAVUT_ASSERT(offset_bits >= 592ULL);
    NUNAVUT_ASSERT(offset_bits <= 74096ULL);

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
static inline int8_t uavcan_metatransport_udp_Frame_0_1_deserialize_(
    uavcan_metatransport_udp_Frame_0_1* const out_obj, const uint8_t* const buffer, size_t* const inout_buffer_size_bytes)
{
    if ((out_obj == NULL) || (buffer == NULL) || (inout_buffer_size_bytes == NULL))
    {
        return -NUNAVUT_ERROR_INVALID_ARGUMENT;
    }

    const size_t capacity_bytes = *inout_buffer_size_bytes;
    const size_t capacity_bits = capacity_bytes * (size_t) 8U;
    size_t offset_bits = 0U;

    // uavcan.time.SynchronizedTimestamp.1.0 timestamp
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    {
        size_t _size_bytes3_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        const int8_t _err7_ = uavcan_time_SynchronizedTimestamp_1_0_deserialize_(
            &out_obj->timestamp, &buffer[offset_bits / 8U], &_size_bytes3_);
        if (_err7_ < 0)
        {
            return _err7_;
        }
        offset_bits += _size_bytes3_ * 8U;  // Advance by the size of the nested serialized representation.
    }

    // void8
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    offset_bits += 8;

    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.

    // uavcan.metatransport.udp.Endpoint.0.1 source
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    {
        size_t _size_bytes4_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        const int8_t _err8_ = uavcan_metatransport_udp_Endpoint_0_1_deserialize_(
            &out_obj->source, &buffer[offset_bits / 8U], &_size_bytes4_);
        if (_err8_ < 0)
        {
            return _err8_;
        }
        offset_bits += _size_bytes4_ * 8U;  // Advance by the size of the nested serialized representation.
    }

    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.

    // uavcan.metatransport.udp.Endpoint.0.1 destination
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    {
        size_t _size_bytes5_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        const int8_t _err9_ = uavcan_metatransport_udp_Endpoint_0_1_deserialize_(
            &out_obj->destination, &buffer[offset_bits / 8U], &_size_bytes5_);
        if (_err9_ < 0)
        {
            return _err9_;
        }
        offset_bits += _size_bytes5_ * 8U;  // Advance by the size of the nested serialized representation.
    }

    // saturated uint8[<=9188] data
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    // Array length prefix: truncated uint16
    out_obj->data.count = nunavutGetU16(&buffer[0], capacity_bytes, offset_bits, 16);
    offset_bits += 16U;
    if (out_obj->data.count > 9188U)
    {
        return -NUNAVUT_ERROR_REPRESENTATION_BAD_ARRAY_LENGTH;
    }
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    for (size_t _index1_ = 0U; _index1_ < out_obj->data.count; ++_index1_)
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        if ((offset_bits + 8U) <= capacity_bits)
        {
            out_obj->data.elements[_index1_] = buffer[offset_bits / 8U] & 255U;
        }
        else
        {
            out_obj->data.elements[_index1_] = 0U;
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
static inline void uavcan_metatransport_udp_Frame_0_1_initialize_(uavcan_metatransport_udp_Frame_0_1* const out_obj)
{
    if (out_obj != NULL)
    {
        size_t size_bytes = 0;
        const uint8_t buf = 0;
        const int8_t err = uavcan_metatransport_udp_Frame_0_1_deserialize_(out_obj, &buf, &size_bytes);
        NUNAVUT_ASSERT(err >= 0);
        (void) err;
    }
}

#ifdef __cplusplus
}
#endif
#endif // UAVCAN_METATRANSPORT_UDP_FRAME_0_1_INCLUDED_

