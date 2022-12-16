// This is an AUTO-GENERATED UAVCAN DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended unless it is used as part of a high-SIL
// safety-critical codebase. The typical usage scenario is to generate it as part of the build process.
//
// To avoid conflicts with definitions given in the source DSDL file, all entities created by the code generator
// are named with an underscore at the end, like foo_bar_().
//
// Generator:     nunavut-1.9.0 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/uavcan/internet/udp/8174.OutgoingPacket.0.2.dsdl
// Generated at:  2022-12-15 23:20:52.248213 UTC
// Is deprecated: no
// Fixed port-ID: 8174
// Full name:     uavcan.internet.udp.OutgoingPacket
// Version:       0.2
//
// Platform
//     python_implementation:  CPython
//     python_version:  3.10.6
//     python_release_level:  final
//     python_build:  ('main', 'Nov 14 2022 16:10:14')
//     python_compiler:  GCC 11.3.0
//     python_revision:
//     python_xoptions:  {}
//     runtime_platform:  Linux-5.15.0-56-generic-x86_64-with-glibc2.35
//
// Language Options
//     target_endianness:  any
//     omit_float_serialization_support:  False
//     enable_serialization_asserts:  True
//     enable_override_variable_array_capacity:  False
//     cast_format:  (({type}) {value})

#ifndef UAVCAN_INTERNET_UDP_OUTGOING_PACKET_0_2_INCLUDED_
#define UAVCAN_INTERNET_UDP_OUTGOING_PACKET_0_2_INCLUDED_

#include <nunavut/support/serialization.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_TARGET_ENDIANNESS == 1693710260,
              "/tmp/public_regulated_data_types/uavcan/internet/udp/8174.OutgoingPacket.0.2.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_OMIT_FLOAT_SERIALIZATION_SUPPORT == 0,
              "/tmp/public_regulated_data_types/uavcan/internet/udp/8174.OutgoingPacket.0.2.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_SERIALIZATION_ASSERTS == 1,
              "/tmp/public_regulated_data_types/uavcan/internet/udp/8174.OutgoingPacket.0.2.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_OVERRIDE_VARIABLE_ARRAY_CAPACITY == 0,
              "/tmp/public_regulated_data_types/uavcan/internet/udp/8174.OutgoingPacket.0.2.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_CAST_FORMAT == 2368206204,
              "/tmp/public_regulated_data_types/uavcan/internet/udp/8174.OutgoingPacket.0.2.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );

#ifdef __cplusplus
extern "C" {
#endif

#define uavcan_internet_udp_OutgoingPacket_0_2_HAS_FIXED_PORT_ID_ true
#define uavcan_internet_udp_OutgoingPacket_0_2_FIXED_PORT_ID_     8174U

#define uavcan_internet_udp_OutgoingPacket_0_2_FULL_NAME_             "uavcan.internet.udp.OutgoingPacket"
#define uavcan_internet_udp_OutgoingPacket_0_2_FULL_NAME_AND_VERSION_ "uavcan.internet.udp.OutgoingPacket.0.2"

/// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
/// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
/// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
/// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
/// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
/// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
/// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.
#define uavcan_internet_udp_OutgoingPacket_0_2_EXTENT_BYTES_                    600UL
#define uavcan_internet_udp_OutgoingPacket_0_2_SERIALIZATION_BUFFER_SIZE_BYTES_ 561UL
static_assert(uavcan_internet_udp_OutgoingPacket_0_2_EXTENT_BYTES_ >= uavcan_internet_udp_OutgoingPacket_0_2_SERIALIZATION_BUFFER_SIZE_BYTES_,
              "Internal constraint violation");

/// saturated uint32 NAT_ENTRY_MIN_TTL = 86400
#define uavcan_internet_udp_OutgoingPacket_0_2_NAT_ENTRY_MIN_TTL (86400UL)

/// Array metadata for: saturated uint8[<=45] destination_address
#define uavcan_internet_udp_OutgoingPacket_0_2_destination_address_ARRAY_CAPACITY_           45U
#define uavcan_internet_udp_OutgoingPacket_0_2_destination_address_ARRAY_IS_VARIABLE_LENGTH_ true
/// Array metadata for: saturated uint8[<=508] payload
#define uavcan_internet_udp_OutgoingPacket_0_2_payload_ARRAY_CAPACITY_           508U
#define uavcan_internet_udp_OutgoingPacket_0_2_payload_ARRAY_IS_VARIABLE_LENGTH_ true

typedef struct
{
    /// saturated uint16 session_id
    uint16_t session_id;

    /// saturated uint16 destination_port
    uint16_t destination_port;

    /// saturated uint8[<=45] destination_address
    struct  /// Array address equivalence guarantee: &elements[0] == &destination_address
    {
        uint8_t elements[uavcan_internet_udp_OutgoingPacket_0_2_destination_address_ARRAY_CAPACITY_];
        size_t count;
    } destination_address;

    /// saturated bool use_masquerading
    bool use_masquerading;

    /// saturated bool use_dtls
    bool use_dtls;

    /// saturated uint8[<=508] payload
    struct  /// Array address equivalence guarantee: &elements[0] == &payload
    {
        uint8_t elements[uavcan_internet_udp_OutgoingPacket_0_2_payload_ARRAY_CAPACITY_];
        size_t count;
    } payload;
} uavcan_internet_udp_OutgoingPacket_0_2;

/// Serialize an instance into the provided buffer.
/// The lifetime of the resulting serialized representation is independent of the original instance.
/// This method may be slow for large objects (e.g., images, point clouds, radar samples), so in a later revision
/// we may define a zero-copy alternative that keeps references to the original object where possible.
///
/// @param obj      The object to serialize.
///
/// @param buffer   The destination buffer. There are no alignment requirements.
///                 @see uavcan_internet_udp_OutgoingPacket_0_2_SERIALIZATION_BUFFER_SIZE_BYTES_
///
/// @param inout_buffer_size_bytes  When calling, this is a pointer to the size of the buffer in bytes.
///                                 Upon return this value will be updated with the size of the constructed serialized
///                                 representation (in bytes); this value is then to be passed over to the transport
///                                 layer. In case of error this value is undefined.
///
/// @returns Negative on error, zero on success.
static inline int8_t uavcan_internet_udp_OutgoingPacket_0_2_serialize_(
    const uavcan_internet_udp_OutgoingPacket_0_2* const obj, uint8_t* const buffer,  size_t* const inout_buffer_size_bytes)
{
    if ((obj == NULL) || (buffer == NULL) || (inout_buffer_size_bytes == NULL))
    {
        return -NUNAVUT_ERROR_INVALID_ARGUMENT;
    }

    const size_t capacity_bytes = *inout_buffer_size_bytes;
    if ((8U * (size_t) capacity_bytes) < 4488UL)
    {
        return -NUNAVUT_ERROR_SERIALIZATION_BUFFER_TOO_SMALL;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    size_t offset_bits = 0U;

    {   // saturated uint16 session_id
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
        // Saturation code not emitted -- native representation matches the serialized representation.
        const int8_t _err0_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, obj->session_id, 16U);
        if (_err0_ < 0)
        {
            return _err0_;
        }
        offset_bits += 16U;
    }

    {   // saturated uint16 destination_port
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
        // Saturation code not emitted -- native representation matches the serialized representation.
        const int8_t _err1_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, obj->destination_port, 16U);
        if (_err1_ < 0)
        {
            return _err1_;
        }
        offset_bits += 16U;
    }

    {   // saturated uint8[<=45] destination_address
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 368ULL) <= (capacity_bytes * 8U));
        if (obj->destination_address.count > 45)
        {
            return -NUNAVUT_ERROR_REPRESENTATION_BAD_ARRAY_LENGTH;
        }
        // Array length prefix: truncated uint8
        buffer[offset_bits / 8U] = (uint8_t)(obj->destination_address.count);  // C std, 6.3.1.3 Signed and unsigned integers
        offset_bits += 8U;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        for (size_t _index0_ = 0U; _index0_ < obj->destination_address.count; ++_index0_)
        {
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 8ULL) <= (capacity_bytes * 8U));
            // Saturation code not emitted -- native representation matches the serialized representation.
            buffer[offset_bits / 8U] = (uint8_t)(obj->destination_address.elements[_index0_]);  // C std, 6.3.1.3 Signed and unsigned integers
            offset_bits += 8U;
        }
    }

    {   // saturated bool use_masquerading
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 1ULL) <= (capacity_bytes * 8U));
        buffer[offset_bits / 8U] = obj->use_masquerading ? 1U : 0U;
        offset_bits += 1U;
    }

    {   // saturated bool use_dtls
        NUNAVUT_ASSERT((offset_bits + 1ULL) <= (capacity_bytes * 8U));
        if (obj->use_dtls)
        {
            buffer[offset_bits / 8U] = (uint8_t)(buffer[offset_bits / 8U] | (1U << (offset_bits % 8U)));
        }
        else
        {
            buffer[offset_bits / 8U] = (uint8_t)(buffer[offset_bits / 8U] & ~(1U << (offset_bits % 8U)));
        }
        offset_bits += 1U;
    }

    {   // void6
        NUNAVUT_ASSERT((offset_bits + 6ULL) <= (capacity_bytes * 8U));
        const int8_t _err2_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, 6U);  // Optimize?
        if (_err2_ < 0)
        {
            return _err2_;
        }
        offset_bits += 6UL;
    }

    {   // saturated uint8[<=508] payload
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 4080ULL) <= (capacity_bytes * 8U));
        if (obj->payload.count > 508)
        {
            return -NUNAVUT_ERROR_REPRESENTATION_BAD_ARRAY_LENGTH;
        }
        // Array length prefix: truncated uint16
        const int8_t _err3_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, obj->payload.count, 16U);
        if (_err3_ < 0)
        {
            return _err3_;
        }
        offset_bits += 16U;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        for (size_t _index1_ = 0U; _index1_ < obj->payload.count; ++_index1_)
        {
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 8ULL) <= (capacity_bytes * 8U));
            // Saturation code not emitted -- native representation matches the serialized representation.
            buffer[offset_bits / 8U] = (uint8_t)(obj->payload.elements[_index1_]);  // C std, 6.3.1.3 Signed and unsigned integers
            offset_bits += 8U;
        }
    }

    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad0_ = (uint8_t)(8U - offset_bits % 8U);
        NUNAVUT_ASSERT(_pad0_ > 0);
        const int8_t _err4_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad0_);  // Optimize?
        if (_err4_ < 0)
        {
            return _err4_;
        }
        offset_bits += _pad0_;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    }
    // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.

    NUNAVUT_ASSERT(offset_bits >= 64ULL);
    NUNAVUT_ASSERT(offset_bits <= 4488ULL);

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
static inline int8_t uavcan_internet_udp_OutgoingPacket_0_2_deserialize_(
    uavcan_internet_udp_OutgoingPacket_0_2* const out_obj, const uint8_t* buffer, size_t* const inout_buffer_size_bytes)
{
    if ((out_obj == NULL) || (inout_buffer_size_bytes == NULL) || ((buffer == NULL) && (0 != *inout_buffer_size_bytes)))
    {
        return -NUNAVUT_ERROR_INVALID_ARGUMENT;
    }
    if (buffer == NULL)
    {
        buffer = (const uint8_t*)"";
    }

    const size_t capacity_bytes = *inout_buffer_size_bytes;
    const size_t capacity_bits = capacity_bytes * (size_t) 8U;
    size_t offset_bits = 0U;

    // saturated uint16 session_id
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->session_id = nunavutGetU16(&buffer[0], capacity_bytes, offset_bits, 16);
    offset_bits += 16U;

    // saturated uint16 destination_port
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->destination_port = nunavutGetU16(&buffer[0], capacity_bytes, offset_bits, 16);
    offset_bits += 16U;

    // saturated uint8[<=45] destination_address
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    // Array length prefix: truncated uint8
    if ((offset_bits + 8U) <= capacity_bits)
    {
        out_obj->destination_address.count = buffer[offset_bits / 8U] & 255U;
    }
    else
    {
        out_obj->destination_address.count = 0U;
    }
    offset_bits += 8U;
    if (out_obj->destination_address.count > 45U)
    {
        return -NUNAVUT_ERROR_REPRESENTATION_BAD_ARRAY_LENGTH;
    }
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    for (size_t _index2_ = 0U; _index2_ < out_obj->destination_address.count; ++_index2_)
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        if ((offset_bits + 8U) <= capacity_bits)
        {
            out_obj->destination_address.elements[_index2_] = buffer[offset_bits / 8U] & 255U;
        }
        else
        {
            out_obj->destination_address.elements[_index2_] = 0U;
        }
        offset_bits += 8U;
    }

    // saturated bool use_masquerading
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    if (offset_bits < capacity_bits)
    {
        out_obj->use_masquerading = (buffer[offset_bits / 8U] & 1U) != 0U;
    }
    else
    {
        out_obj->use_masquerading = false;
    }
    offset_bits += 1U;

    // saturated bool use_dtls
    if (offset_bits < capacity_bits)
    {
        out_obj->use_dtls = (buffer[offset_bits / 8U] & (1U << (offset_bits % 8U))) != 0U;
    }
    else
    {
        out_obj->use_dtls = false;
    }
    offset_bits += 1U;

    // void6
    offset_bits += 6;

    // saturated uint8[<=508] payload
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    // Array length prefix: truncated uint16
    out_obj->payload.count = nunavutGetU16(&buffer[0], capacity_bytes, offset_bits, 16);
    offset_bits += 16U;
    if (out_obj->payload.count > 508U)
    {
        return -NUNAVUT_ERROR_REPRESENTATION_BAD_ARRAY_LENGTH;
    }
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    for (size_t _index3_ = 0U; _index3_ < out_obj->payload.count; ++_index3_)
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        if ((offset_bits + 8U) <= capacity_bits)
        {
            out_obj->payload.elements[_index3_] = buffer[offset_bits / 8U] & 255U;
        }
        else
        {
            out_obj->payload.elements[_index3_] = 0U;
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
static inline void uavcan_internet_udp_OutgoingPacket_0_2_initialize_(uavcan_internet_udp_OutgoingPacket_0_2* const out_obj)
{
    if (out_obj != NULL)
    {
        size_t size_bytes = 0;
        const uint8_t buf = 0;
        const int8_t err = uavcan_internet_udp_OutgoingPacket_0_2_deserialize_(out_obj, &buf, &size_bytes);
        NUNAVUT_ASSERT(err >= 0);
        (void) err;
    }
}

#ifdef __cplusplus
}
#endif
#endif // UAVCAN_INTERNET_UDP_OUTGOING_PACKET_0_2_INCLUDED_

