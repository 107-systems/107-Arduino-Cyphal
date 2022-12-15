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
// Source file:   /tmp/public_regulated_data_types/uavcan/register/Value.1.0.dsdl
// Generated at:  2022-12-15 23:20:52.230595 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     uavcan.register.Value
// Version:       1.0
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

#ifndef UAVCAN_REGISTER_VALUE_1_0_INCLUDED_
#define UAVCAN_REGISTER_VALUE_1_0_INCLUDED_

#include <nunavut/support/serialization.h>
#include <stdint.h>
#include <stdlib.h>
#include <types/uavcan/primitive/Empty_1_0.h>
#include <types/uavcan/primitive/String_1_0.h>
#include <types/uavcan/primitive/Unstructured_1_0.h>
#include <types/uavcan/primitive/array/Bit_1_0.h>
#include <types/uavcan/primitive/array/Integer16_1_0.h>
#include <types/uavcan/primitive/array/Integer32_1_0.h>
#include <types/uavcan/primitive/array/Integer64_1_0.h>
#include <types/uavcan/primitive/array/Integer8_1_0.h>
#include <types/uavcan/primitive/array/Natural16_1_0.h>
#include <types/uavcan/primitive/array/Natural32_1_0.h>
#include <types/uavcan/primitive/array/Natural64_1_0.h>
#include <types/uavcan/primitive/array/Natural8_1_0.h>
#include <types/uavcan/primitive/array/Real16_1_0.h>
#include <types/uavcan/primitive/array/Real32_1_0.h>
#include <types/uavcan/primitive/array/Real64_1_0.h>

static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_TARGET_ENDIANNESS == 1693710260,
              "/tmp/public_regulated_data_types/uavcan/register/Value.1.0.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_OMIT_FLOAT_SERIALIZATION_SUPPORT == 0,
              "/tmp/public_regulated_data_types/uavcan/register/Value.1.0.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_SERIALIZATION_ASSERTS == 1,
              "/tmp/public_regulated_data_types/uavcan/register/Value.1.0.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_OVERRIDE_VARIABLE_ARRAY_CAPACITY == 0,
              "/tmp/public_regulated_data_types/uavcan/register/Value.1.0.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_CAST_FORMAT == 2368206204,
              "/tmp/public_regulated_data_types/uavcan/register/Value.1.0.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );

#ifdef __cplusplus
extern "C" {
#endif

/// This type does not have a fixed port-ID. See https://forum.opencyphal.org/t/choosing-message-and-service-ids/889
#define uavcan_register_Value_1_0_HAS_FIXED_PORT_ID_ false

#define uavcan_register_Value_1_0_FULL_NAME_             "uavcan.register.Value"
#define uavcan_register_Value_1_0_FULL_NAME_AND_VERSION_ "uavcan.register.Value.1.0"

/// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
/// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
/// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
/// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
/// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
/// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
/// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.
#define uavcan_register_Value_1_0_EXTENT_BYTES_                    259UL
#define uavcan_register_Value_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_ 259UL
static_assert(uavcan_register_Value_1_0_EXTENT_BYTES_ >= uavcan_register_Value_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_,
              "Internal constraint violation");

/// The number of fields in the union. Valid tag values range from zero to this value minus one, inclusive.
#define uavcan_register_Value_1_0_UNION_OPTION_COUNT_ 15U

typedef struct
{
    union  /// The union is placed first to ensure that the active element address equals the struct address.
    {
        /// uavcan.primitive.Empty.1.0 empty
        uavcan_primitive_Empty_1_0 empty;

        /// uavcan.primitive.String.1.0 string
        uavcan_primitive_String_1_0 _string;

        /// uavcan.primitive.Unstructured.1.0 unstructured
        uavcan_primitive_Unstructured_1_0 unstructured;

        /// uavcan.primitive.array.Bit.1.0 bit
        uavcan_primitive_array_Bit_1_0 bit;

        /// uavcan.primitive.array.Integer64.1.0 integer64
        uavcan_primitive_array_Integer64_1_0 integer64;

        /// uavcan.primitive.array.Integer32.1.0 integer32
        uavcan_primitive_array_Integer32_1_0 integer32;

        /// uavcan.primitive.array.Integer16.1.0 integer16
        uavcan_primitive_array_Integer16_1_0 integer16;

        /// uavcan.primitive.array.Integer8.1.0 integer8
        uavcan_primitive_array_Integer8_1_0 integer8;

        /// uavcan.primitive.array.Natural64.1.0 natural64
        uavcan_primitive_array_Natural64_1_0 natural64;

        /// uavcan.primitive.array.Natural32.1.0 natural32
        uavcan_primitive_array_Natural32_1_0 natural32;

        /// uavcan.primitive.array.Natural16.1.0 natural16
        uavcan_primitive_array_Natural16_1_0 natural16;

        /// uavcan.primitive.array.Natural8.1.0 natural8
        uavcan_primitive_array_Natural8_1_0 natural8;

        /// uavcan.primitive.array.Real64.1.0 real64
        uavcan_primitive_array_Real64_1_0 real64;

        /// uavcan.primitive.array.Real32.1.0 real32
        uavcan_primitive_array_Real32_1_0 real32;

        /// uavcan.primitive.array.Real16.1.0 real16
        uavcan_primitive_array_Real16_1_0 real16;
    };
    uint8_t _tag_;
} uavcan_register_Value_1_0;

/// Serialize an instance into the provided buffer.
/// The lifetime of the resulting serialized representation is independent of the original instance.
/// This method may be slow for large objects (e.g., images, point clouds, radar samples), so in a later revision
/// we may define a zero-copy alternative that keeps references to the original object where possible.
///
/// @param obj      The object to serialize.
///
/// @param buffer   The destination buffer. There are no alignment requirements.
///                 @see uavcan_register_Value_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_
///
/// @param inout_buffer_size_bytes  When calling, this is a pointer to the size of the buffer in bytes.
///                                 Upon return this value will be updated with the size of the constructed serialized
///                                 representation (in bytes); this value is then to be passed over to the transport
///                                 layer. In case of error this value is undefined.
///
/// @returns Negative on error, zero on success.
static inline int8_t uavcan_register_Value_1_0_serialize_(
    const uavcan_register_Value_1_0* const obj, uint8_t* const buffer,  size_t* const inout_buffer_size_bytes)
{
    if ((obj == NULL) || (buffer == NULL) || (inout_buffer_size_bytes == NULL))
    {
        return -NUNAVUT_ERROR_INVALID_ARGUMENT;
    }

    const size_t capacity_bytes = *inout_buffer_size_bytes;
    if ((8U * (size_t) capacity_bytes) < 2072UL)
    {
        return -NUNAVUT_ERROR_SERIALIZATION_BUFFER_TOO_SMALL;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    size_t offset_bits = 0U;

    {   // Union tag field: truncated uint8
        buffer[offset_bits / 8U] = (uint8_t)(obj->_tag_);  // C std, 6.3.1.3 Signed and unsigned integers
        offset_bits += 8U;
    }

    if (0U == obj->_tag_)  // uavcan.primitive.Empty.1.0 empty
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 0ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes0_ = 0UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes0_) <= capacity_bytes);
        int8_t _err0_ = uavcan_primitive_Empty_1_0_serialize_(
            &obj->empty, &buffer[offset_bits / 8U], &_size_bytes0_);
        if (_err0_ < 0)
        {
            return _err0_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes0_ * 8U) == 0ULL);
        offset_bits += _size_bytes0_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }
    else if (1U == obj->_tag_)  // uavcan.primitive.String.1.0 string
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 2064ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes1_ = 258UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes1_) <= capacity_bytes);
        int8_t _err1_ = uavcan_primitive_String_1_0_serialize_(
            &obj->_string, &buffer[offset_bits / 8U], &_size_bytes1_);
        if (_err1_ < 0)
        {
            return _err1_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes1_ * 8U) >= 16ULL);
        NUNAVUT_ASSERT((_size_bytes1_ * 8U) <= 2064ULL);
        offset_bits += _size_bytes1_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }
    else if (2U == obj->_tag_)  // uavcan.primitive.Unstructured.1.0 unstructured
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 2064ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes2_ = 258UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes2_) <= capacity_bytes);
        int8_t _err2_ = uavcan_primitive_Unstructured_1_0_serialize_(
            &obj->unstructured, &buffer[offset_bits / 8U], &_size_bytes2_);
        if (_err2_ < 0)
        {
            return _err2_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes2_ * 8U) >= 16ULL);
        NUNAVUT_ASSERT((_size_bytes2_ * 8U) <= 2064ULL);
        offset_bits += _size_bytes2_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }
    else if (3U == obj->_tag_)  // uavcan.primitive.array.Bit.1.0 bit
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 2064ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes3_ = 258UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes3_) <= capacity_bytes);
        int8_t _err3_ = uavcan_primitive_array_Bit_1_0_serialize_(
            &obj->bit, &buffer[offset_bits / 8U], &_size_bytes3_);
        if (_err3_ < 0)
        {
            return _err3_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes3_ * 8U) >= 16ULL);
        NUNAVUT_ASSERT((_size_bytes3_ * 8U) <= 2064ULL);
        offset_bits += _size_bytes3_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }
    else if (4U == obj->_tag_)  // uavcan.primitive.array.Integer64.1.0 integer64
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 2056ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes4_ = 257UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes4_) <= capacity_bytes);
        int8_t _err4_ = uavcan_primitive_array_Integer64_1_0_serialize_(
            &obj->integer64, &buffer[offset_bits / 8U], &_size_bytes4_);
        if (_err4_ < 0)
        {
            return _err4_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes4_ * 8U) >= 8ULL);
        NUNAVUT_ASSERT((_size_bytes4_ * 8U) <= 2056ULL);
        offset_bits += _size_bytes4_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }
    else if (5U == obj->_tag_)  // uavcan.primitive.array.Integer32.1.0 integer32
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 2056ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes5_ = 257UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes5_) <= capacity_bytes);
        int8_t _err5_ = uavcan_primitive_array_Integer32_1_0_serialize_(
            &obj->integer32, &buffer[offset_bits / 8U], &_size_bytes5_);
        if (_err5_ < 0)
        {
            return _err5_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes5_ * 8U) >= 8ULL);
        NUNAVUT_ASSERT((_size_bytes5_ * 8U) <= 2056ULL);
        offset_bits += _size_bytes5_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }
    else if (6U == obj->_tag_)  // uavcan.primitive.array.Integer16.1.0 integer16
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 2056ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes6_ = 257UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes6_) <= capacity_bytes);
        int8_t _err6_ = uavcan_primitive_array_Integer16_1_0_serialize_(
            &obj->integer16, &buffer[offset_bits / 8U], &_size_bytes6_);
        if (_err6_ < 0)
        {
            return _err6_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes6_ * 8U) >= 8ULL);
        NUNAVUT_ASSERT((_size_bytes6_ * 8U) <= 2056ULL);
        offset_bits += _size_bytes6_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }
    else if (7U == obj->_tag_)  // uavcan.primitive.array.Integer8.1.0 integer8
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 2064ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes7_ = 258UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes7_) <= capacity_bytes);
        int8_t _err7_ = uavcan_primitive_array_Integer8_1_0_serialize_(
            &obj->integer8, &buffer[offset_bits / 8U], &_size_bytes7_);
        if (_err7_ < 0)
        {
            return _err7_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes7_ * 8U) >= 16ULL);
        NUNAVUT_ASSERT((_size_bytes7_ * 8U) <= 2064ULL);
        offset_bits += _size_bytes7_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }
    else if (8U == obj->_tag_)  // uavcan.primitive.array.Natural64.1.0 natural64
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 2056ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes8_ = 257UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes8_) <= capacity_bytes);
        int8_t _err8_ = uavcan_primitive_array_Natural64_1_0_serialize_(
            &obj->natural64, &buffer[offset_bits / 8U], &_size_bytes8_);
        if (_err8_ < 0)
        {
            return _err8_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes8_ * 8U) >= 8ULL);
        NUNAVUT_ASSERT((_size_bytes8_ * 8U) <= 2056ULL);
        offset_bits += _size_bytes8_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }
    else if (9U == obj->_tag_)  // uavcan.primitive.array.Natural32.1.0 natural32
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 2056ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes9_ = 257UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes9_) <= capacity_bytes);
        int8_t _err9_ = uavcan_primitive_array_Natural32_1_0_serialize_(
            &obj->natural32, &buffer[offset_bits / 8U], &_size_bytes9_);
        if (_err9_ < 0)
        {
            return _err9_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes9_ * 8U) >= 8ULL);
        NUNAVUT_ASSERT((_size_bytes9_ * 8U) <= 2056ULL);
        offset_bits += _size_bytes9_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }
    else if (10U == obj->_tag_)  // uavcan.primitive.array.Natural16.1.0 natural16
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 2056ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes10_ = 257UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes10_) <= capacity_bytes);
        int8_t _err10_ = uavcan_primitive_array_Natural16_1_0_serialize_(
            &obj->natural16, &buffer[offset_bits / 8U], &_size_bytes10_);
        if (_err10_ < 0)
        {
            return _err10_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes10_ * 8U) >= 8ULL);
        NUNAVUT_ASSERT((_size_bytes10_ * 8U) <= 2056ULL);
        offset_bits += _size_bytes10_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }
    else if (11U == obj->_tag_)  // uavcan.primitive.array.Natural8.1.0 natural8
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 2064ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes11_ = 258UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes11_) <= capacity_bytes);
        int8_t _err11_ = uavcan_primitive_array_Natural8_1_0_serialize_(
            &obj->natural8, &buffer[offset_bits / 8U], &_size_bytes11_);
        if (_err11_ < 0)
        {
            return _err11_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes11_ * 8U) >= 16ULL);
        NUNAVUT_ASSERT((_size_bytes11_ * 8U) <= 2064ULL);
        offset_bits += _size_bytes11_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }
    else if (12U == obj->_tag_)  // uavcan.primitive.array.Real64.1.0 real64
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 2056ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes12_ = 257UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes12_) <= capacity_bytes);
        int8_t _err12_ = uavcan_primitive_array_Real64_1_0_serialize_(
            &obj->real64, &buffer[offset_bits / 8U], &_size_bytes12_);
        if (_err12_ < 0)
        {
            return _err12_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes12_ * 8U) >= 8ULL);
        NUNAVUT_ASSERT((_size_bytes12_ * 8U) <= 2056ULL);
        offset_bits += _size_bytes12_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }
    else if (13U == obj->_tag_)  // uavcan.primitive.array.Real32.1.0 real32
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 2056ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes13_ = 257UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes13_) <= capacity_bytes);
        int8_t _err13_ = uavcan_primitive_array_Real32_1_0_serialize_(
            &obj->real32, &buffer[offset_bits / 8U], &_size_bytes13_);
        if (_err13_ < 0)
        {
            return _err13_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes13_ * 8U) >= 8ULL);
        NUNAVUT_ASSERT((_size_bytes13_ * 8U) <= 2056ULL);
        offset_bits += _size_bytes13_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }
    else if (14U == obj->_tag_)  // uavcan.primitive.array.Real16.1.0 real16
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 2056ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes14_ = 257UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes14_) <= capacity_bytes);
        int8_t _err14_ = uavcan_primitive_array_Real16_1_0_serialize_(
            &obj->real16, &buffer[offset_bits / 8U], &_size_bytes14_);
        if (_err14_ < 0)
        {
            return _err14_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes14_ * 8U) >= 8ULL);
        NUNAVUT_ASSERT((_size_bytes14_ * 8U) <= 2056ULL);
        offset_bits += _size_bytes14_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }
    else
    {
        return -NUNAVUT_ERROR_REPRESENTATION_BAD_UNION_TAG;
    }

    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad0_ = (uint8_t)(8U - offset_bits % 8U);
        NUNAVUT_ASSERT(_pad0_ > 0);
        const int8_t _err15_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad0_);  // Optimize?
        if (_err15_ < 0)
        {
            return _err15_;
        }
        offset_bits += _pad0_;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    }
    // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.

    NUNAVUT_ASSERT(offset_bits >= 8ULL);
    NUNAVUT_ASSERT(offset_bits <= 2072ULL);

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
static inline int8_t uavcan_register_Value_1_0_deserialize_(
    uavcan_register_Value_1_0* const out_obj, const uint8_t* buffer, size_t* const inout_buffer_size_bytes)
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

    // Union tag field: truncated uint8
    if ((offset_bits + 8U) <= capacity_bits)
    {
        out_obj->_tag_ = buffer[offset_bits / 8U] & 255U;
    }
    else
    {
        out_obj->_tag_ = 0U;
    }
    offset_bits += 8U;

    if (0U == out_obj->_tag_)  // uavcan.primitive.Empty.1.0 empty
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        {
            size_t _size_bytes15_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            const int8_t _err16_ = uavcan_primitive_Empty_1_0_deserialize_(
                &out_obj->empty, &buffer[offset_bits / 8U], &_size_bytes15_);
            if (_err16_ < 0)
            {
                return _err16_;
            }
            offset_bits += _size_bytes15_ * 8U;  // Advance by the size of the nested serialized representation.
        }
    }
    else if (1U == out_obj->_tag_)  // uavcan.primitive.String.1.0 string
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        {
            size_t _size_bytes16_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            const int8_t _err17_ = uavcan_primitive_String_1_0_deserialize_(
                &out_obj->_string, &buffer[offset_bits / 8U], &_size_bytes16_);
            if (_err17_ < 0)
            {
                return _err17_;
            }
            offset_bits += _size_bytes16_ * 8U;  // Advance by the size of the nested serialized representation.
        }
    }
    else if (2U == out_obj->_tag_)  // uavcan.primitive.Unstructured.1.0 unstructured
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        {
            size_t _size_bytes17_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            const int8_t _err18_ = uavcan_primitive_Unstructured_1_0_deserialize_(
                &out_obj->unstructured, &buffer[offset_bits / 8U], &_size_bytes17_);
            if (_err18_ < 0)
            {
                return _err18_;
            }
            offset_bits += _size_bytes17_ * 8U;  // Advance by the size of the nested serialized representation.
        }
    }
    else if (3U == out_obj->_tag_)  // uavcan.primitive.array.Bit.1.0 bit
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        {
            size_t _size_bytes18_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            const int8_t _err19_ = uavcan_primitive_array_Bit_1_0_deserialize_(
                &out_obj->bit, &buffer[offset_bits / 8U], &_size_bytes18_);
            if (_err19_ < 0)
            {
                return _err19_;
            }
            offset_bits += _size_bytes18_ * 8U;  // Advance by the size of the nested serialized representation.
        }
    }
    else if (4U == out_obj->_tag_)  // uavcan.primitive.array.Integer64.1.0 integer64
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        {
            size_t _size_bytes19_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            const int8_t _err20_ = uavcan_primitive_array_Integer64_1_0_deserialize_(
                &out_obj->integer64, &buffer[offset_bits / 8U], &_size_bytes19_);
            if (_err20_ < 0)
            {
                return _err20_;
            }
            offset_bits += _size_bytes19_ * 8U;  // Advance by the size of the nested serialized representation.
        }
    }
    else if (5U == out_obj->_tag_)  // uavcan.primitive.array.Integer32.1.0 integer32
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        {
            size_t _size_bytes20_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            const int8_t _err21_ = uavcan_primitive_array_Integer32_1_0_deserialize_(
                &out_obj->integer32, &buffer[offset_bits / 8U], &_size_bytes20_);
            if (_err21_ < 0)
            {
                return _err21_;
            }
            offset_bits += _size_bytes20_ * 8U;  // Advance by the size of the nested serialized representation.
        }
    }
    else if (6U == out_obj->_tag_)  // uavcan.primitive.array.Integer16.1.0 integer16
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        {
            size_t _size_bytes21_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            const int8_t _err22_ = uavcan_primitive_array_Integer16_1_0_deserialize_(
                &out_obj->integer16, &buffer[offset_bits / 8U], &_size_bytes21_);
            if (_err22_ < 0)
            {
                return _err22_;
            }
            offset_bits += _size_bytes21_ * 8U;  // Advance by the size of the nested serialized representation.
        }
    }
    else if (7U == out_obj->_tag_)  // uavcan.primitive.array.Integer8.1.0 integer8
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        {
            size_t _size_bytes22_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            const int8_t _err23_ = uavcan_primitive_array_Integer8_1_0_deserialize_(
                &out_obj->integer8, &buffer[offset_bits / 8U], &_size_bytes22_);
            if (_err23_ < 0)
            {
                return _err23_;
            }
            offset_bits += _size_bytes22_ * 8U;  // Advance by the size of the nested serialized representation.
        }
    }
    else if (8U == out_obj->_tag_)  // uavcan.primitive.array.Natural64.1.0 natural64
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        {
            size_t _size_bytes23_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            const int8_t _err24_ = uavcan_primitive_array_Natural64_1_0_deserialize_(
                &out_obj->natural64, &buffer[offset_bits / 8U], &_size_bytes23_);
            if (_err24_ < 0)
            {
                return _err24_;
            }
            offset_bits += _size_bytes23_ * 8U;  // Advance by the size of the nested serialized representation.
        }
    }
    else if (9U == out_obj->_tag_)  // uavcan.primitive.array.Natural32.1.0 natural32
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        {
            size_t _size_bytes24_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            const int8_t _err25_ = uavcan_primitive_array_Natural32_1_0_deserialize_(
                &out_obj->natural32, &buffer[offset_bits / 8U], &_size_bytes24_);
            if (_err25_ < 0)
            {
                return _err25_;
            }
            offset_bits += _size_bytes24_ * 8U;  // Advance by the size of the nested serialized representation.
        }
    }
    else if (10U == out_obj->_tag_)  // uavcan.primitive.array.Natural16.1.0 natural16
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        {
            size_t _size_bytes25_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            const int8_t _err26_ = uavcan_primitive_array_Natural16_1_0_deserialize_(
                &out_obj->natural16, &buffer[offset_bits / 8U], &_size_bytes25_);
            if (_err26_ < 0)
            {
                return _err26_;
            }
            offset_bits += _size_bytes25_ * 8U;  // Advance by the size of the nested serialized representation.
        }
    }
    else if (11U == out_obj->_tag_)  // uavcan.primitive.array.Natural8.1.0 natural8
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        {
            size_t _size_bytes26_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            const int8_t _err27_ = uavcan_primitive_array_Natural8_1_0_deserialize_(
                &out_obj->natural8, &buffer[offset_bits / 8U], &_size_bytes26_);
            if (_err27_ < 0)
            {
                return _err27_;
            }
            offset_bits += _size_bytes26_ * 8U;  // Advance by the size of the nested serialized representation.
        }
    }
    else if (12U == out_obj->_tag_)  // uavcan.primitive.array.Real64.1.0 real64
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        {
            size_t _size_bytes27_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            const int8_t _err28_ = uavcan_primitive_array_Real64_1_0_deserialize_(
                &out_obj->real64, &buffer[offset_bits / 8U], &_size_bytes27_);
            if (_err28_ < 0)
            {
                return _err28_;
            }
            offset_bits += _size_bytes27_ * 8U;  // Advance by the size of the nested serialized representation.
        }
    }
    else if (13U == out_obj->_tag_)  // uavcan.primitive.array.Real32.1.0 real32
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        {
            size_t _size_bytes28_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            const int8_t _err29_ = uavcan_primitive_array_Real32_1_0_deserialize_(
                &out_obj->real32, &buffer[offset_bits / 8U], &_size_bytes28_);
            if (_err29_ < 0)
            {
                return _err29_;
            }
            offset_bits += _size_bytes28_ * 8U;  // Advance by the size of the nested serialized representation.
        }
    }
    else if (14U == out_obj->_tag_)  // uavcan.primitive.array.Real16.1.0 real16
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        {
            size_t _size_bytes29_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            const int8_t _err30_ = uavcan_primitive_array_Real16_1_0_deserialize_(
                &out_obj->real16, &buffer[offset_bits / 8U], &_size_bytes29_);
            if (_err30_ < 0)
            {
                return _err30_;
            }
            offset_bits += _size_bytes29_ * 8U;  // Advance by the size of the nested serialized representation.
        }
    }
    else
    {
        return -NUNAVUT_ERROR_REPRESENTATION_BAD_UNION_TAG;
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
static inline void uavcan_register_Value_1_0_initialize_(uavcan_register_Value_1_0* const out_obj)
{
    if (out_obj != NULL)
    {
        size_t size_bytes = 0;
        const uint8_t buf = 0;
        const int8_t err = uavcan_register_Value_1_0_deserialize_(out_obj, &buf, &size_bytes);
        NUNAVUT_ASSERT(err >= 0);
        (void) err;
    }
}

/// Mark option "empty" active without initializing it. Does nothing if @param obj is NULL.
static inline void uavcan_register_Value_1_0_select_empty_(uavcan_register_Value_1_0* const obj)
{
    if (obj != NULL)
    {
        obj->_tag_ = 0;
    }
}

/// Check if option "empty" is active. Returns false if @param obj is NULL.
static inline bool uavcan_register_Value_1_0_is_empty_(const uavcan_register_Value_1_0* const obj)
{
    return ((obj != NULL) && (obj->_tag_ == 0));
}

/// Mark option "string" active without initializing it. Does nothing if @param obj is NULL.
static inline void uavcan_register_Value_1_0_select_string_(uavcan_register_Value_1_0* const obj)
{
    if (obj != NULL)
    {
        obj->_tag_ = 1;
    }
}

/// Check if option "string" is active. Returns false if @param obj is NULL.
static inline bool uavcan_register_Value_1_0_is_string_(const uavcan_register_Value_1_0* const obj)
{
    return ((obj != NULL) && (obj->_tag_ == 1));
}

/// Mark option "unstructured" active without initializing it. Does nothing if @param obj is NULL.
static inline void uavcan_register_Value_1_0_select_unstructured_(uavcan_register_Value_1_0* const obj)
{
    if (obj != NULL)
    {
        obj->_tag_ = 2;
    }
}

/// Check if option "unstructured" is active. Returns false if @param obj is NULL.
static inline bool uavcan_register_Value_1_0_is_unstructured_(const uavcan_register_Value_1_0* const obj)
{
    return ((obj != NULL) && (obj->_tag_ == 2));
}

/// Mark option "bit" active without initializing it. Does nothing if @param obj is NULL.
static inline void uavcan_register_Value_1_0_select_bit_(uavcan_register_Value_1_0* const obj)
{
    if (obj != NULL)
    {
        obj->_tag_ = 3;
    }
}

/// Check if option "bit" is active. Returns false if @param obj is NULL.
static inline bool uavcan_register_Value_1_0_is_bit_(const uavcan_register_Value_1_0* const obj)
{
    return ((obj != NULL) && (obj->_tag_ == 3));
}

/// Mark option "integer64" active without initializing it. Does nothing if @param obj is NULL.
static inline void uavcan_register_Value_1_0_select_integer64_(uavcan_register_Value_1_0* const obj)
{
    if (obj != NULL)
    {
        obj->_tag_ = 4;
    }
}

/// Check if option "integer64" is active. Returns false if @param obj is NULL.
static inline bool uavcan_register_Value_1_0_is_integer64_(const uavcan_register_Value_1_0* const obj)
{
    return ((obj != NULL) && (obj->_tag_ == 4));
}

/// Mark option "integer32" active without initializing it. Does nothing if @param obj is NULL.
static inline void uavcan_register_Value_1_0_select_integer32_(uavcan_register_Value_1_0* const obj)
{
    if (obj != NULL)
    {
        obj->_tag_ = 5;
    }
}

/// Check if option "integer32" is active. Returns false if @param obj is NULL.
static inline bool uavcan_register_Value_1_0_is_integer32_(const uavcan_register_Value_1_0* const obj)
{
    return ((obj != NULL) && (obj->_tag_ == 5));
}

/// Mark option "integer16" active without initializing it. Does nothing if @param obj is NULL.
static inline void uavcan_register_Value_1_0_select_integer16_(uavcan_register_Value_1_0* const obj)
{
    if (obj != NULL)
    {
        obj->_tag_ = 6;
    }
}

/// Check if option "integer16" is active. Returns false if @param obj is NULL.
static inline bool uavcan_register_Value_1_0_is_integer16_(const uavcan_register_Value_1_0* const obj)
{
    return ((obj != NULL) && (obj->_tag_ == 6));
}

/// Mark option "integer8" active without initializing it. Does nothing if @param obj is NULL.
static inline void uavcan_register_Value_1_0_select_integer8_(uavcan_register_Value_1_0* const obj)
{
    if (obj != NULL)
    {
        obj->_tag_ = 7;
    }
}

/// Check if option "integer8" is active. Returns false if @param obj is NULL.
static inline bool uavcan_register_Value_1_0_is_integer8_(const uavcan_register_Value_1_0* const obj)
{
    return ((obj != NULL) && (obj->_tag_ == 7));
}

/// Mark option "natural64" active without initializing it. Does nothing if @param obj is NULL.
static inline void uavcan_register_Value_1_0_select_natural64_(uavcan_register_Value_1_0* const obj)
{
    if (obj != NULL)
    {
        obj->_tag_ = 8;
    }
}

/// Check if option "natural64" is active. Returns false if @param obj is NULL.
static inline bool uavcan_register_Value_1_0_is_natural64_(const uavcan_register_Value_1_0* const obj)
{
    return ((obj != NULL) && (obj->_tag_ == 8));
}

/// Mark option "natural32" active without initializing it. Does nothing if @param obj is NULL.
static inline void uavcan_register_Value_1_0_select_natural32_(uavcan_register_Value_1_0* const obj)
{
    if (obj != NULL)
    {
        obj->_tag_ = 9;
    }
}

/// Check if option "natural32" is active. Returns false if @param obj is NULL.
static inline bool uavcan_register_Value_1_0_is_natural32_(const uavcan_register_Value_1_0* const obj)
{
    return ((obj != NULL) && (obj->_tag_ == 9));
}

/// Mark option "natural16" active without initializing it. Does nothing if @param obj is NULL.
static inline void uavcan_register_Value_1_0_select_natural16_(uavcan_register_Value_1_0* const obj)
{
    if (obj != NULL)
    {
        obj->_tag_ = 10;
    }
}

/// Check if option "natural16" is active. Returns false if @param obj is NULL.
static inline bool uavcan_register_Value_1_0_is_natural16_(const uavcan_register_Value_1_0* const obj)
{
    return ((obj != NULL) && (obj->_tag_ == 10));
}

/// Mark option "natural8" active without initializing it. Does nothing if @param obj is NULL.
static inline void uavcan_register_Value_1_0_select_natural8_(uavcan_register_Value_1_0* const obj)
{
    if (obj != NULL)
    {
        obj->_tag_ = 11;
    }
}

/// Check if option "natural8" is active. Returns false if @param obj is NULL.
static inline bool uavcan_register_Value_1_0_is_natural8_(const uavcan_register_Value_1_0* const obj)
{
    return ((obj != NULL) && (obj->_tag_ == 11));
}

/// Mark option "real64" active without initializing it. Does nothing if @param obj is NULL.
static inline void uavcan_register_Value_1_0_select_real64_(uavcan_register_Value_1_0* const obj)
{
    if (obj != NULL)
    {
        obj->_tag_ = 12;
    }
}

/// Check if option "real64" is active. Returns false if @param obj is NULL.
static inline bool uavcan_register_Value_1_0_is_real64_(const uavcan_register_Value_1_0* const obj)
{
    return ((obj != NULL) && (obj->_tag_ == 12));
}

/// Mark option "real32" active without initializing it. Does nothing if @param obj is NULL.
static inline void uavcan_register_Value_1_0_select_real32_(uavcan_register_Value_1_0* const obj)
{
    if (obj != NULL)
    {
        obj->_tag_ = 13;
    }
}

/// Check if option "real32" is active. Returns false if @param obj is NULL.
static inline bool uavcan_register_Value_1_0_is_real32_(const uavcan_register_Value_1_0* const obj)
{
    return ((obj != NULL) && (obj->_tag_ == 13));
}

/// Mark option "real16" active without initializing it. Does nothing if @param obj is NULL.
static inline void uavcan_register_Value_1_0_select_real16_(uavcan_register_Value_1_0* const obj)
{
    if (obj != NULL)
    {
        obj->_tag_ = 14;
    }
}

/// Check if option "real16" is active. Returns false if @param obj is NULL.
static inline bool uavcan_register_Value_1_0_is_real16_(const uavcan_register_Value_1_0* const obj)
{
    return ((obj != NULL) && (obj->_tag_ == 14));
}

#ifdef __cplusplus
}
#endif
#endif // UAVCAN_REGISTER_VALUE_1_0_INCLUDED_

