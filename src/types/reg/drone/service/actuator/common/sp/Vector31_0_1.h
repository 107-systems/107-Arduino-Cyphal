// This is an AUTO-GENERATED UAVCAN DSDL data type implementation. Curious? See https://uavcan.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended unless it is used as part of a high-SIL
// safety-critical codebase. The typical usage scenario is to generate it as part of the build process.
//
// To avoid conflicts with definitions given in the source DSDL file, all entities created by the code generator
// are named with an underscore at the end, like foo_bar_().
//
// Generator:     nunavut-1.0.0 (serialization was enabled)
// Source file:   /home/alex/projects/107-systems/public_regulated_data_types/reg/drone/service/actuator/common/sp/Vector31.0.1.uavcan
// Generated at:  2021-02-08 09:43:07.844797 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     reg.drone.service.actuator.common.sp.Vector31
// Version:       0.1
//
// Language Options
//     target_endianness:  any
//     omit_float_serialization_support:  False
//     enable_serialization_asserts:  True

#ifndef REG_DRONE_SERVICE_ACTUATOR_COMMON_SP_VECTOR31_0_1_INCLUDED_
#define REG_DRONE_SERVICE_ACTUATOR_COMMON_SP_VECTOR31_0_1_INCLUDED_

#include <nunavut/support/serialization.h>
#include <stdlib.h>
#include <string.h>
#undef infinite
#include <cmath>

static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_TARGET_ENDIANNESS == 1693710260,
              "/home/alex/projects/107-systems/public_regulated_data_types/reg/drone/service/actuator/common/sp/Vector31.0.1.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_OMIT_FLOAT_SERIALIZATION_SUPPORT == 0,
              "/home/alex/projects/107-systems/public_regulated_data_types/reg/drone/service/actuator/common/sp/Vector31.0.1.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_SERIALIZATION_ASSERTS == 1,
              "/home/alex/projects/107-systems/public_regulated_data_types/reg/drone/service/actuator/common/sp/Vector31.0.1.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );

#ifdef __cplusplus
extern "C" {
#endif

/// This type does not have a fixed port-ID. See https://forum.uavcan.org/t/choosing-message-and-service-ids/889
#define reg_drone_service_actuator_common_sp_Vector31_0_1_HAS_FIXED_PORT_ID_ false

#define reg_drone_service_actuator_common_sp_Vector31_0_1_FULL_NAME_             "reg.drone.service.actuator.common.sp.Vector31"
#define reg_drone_service_actuator_common_sp_Vector31_0_1_FULL_NAME_AND_VERSION_ "reg.drone.service.actuator.common.sp.Vector31.0.1"

/// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
/// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
/// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
/// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
/// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
/// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
/// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.
#define reg_drone_service_actuator_common_sp_Vector31_0_1_EXTENT_BYTES_                    512UL
#define reg_drone_service_actuator_common_sp_Vector31_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_ 62UL
static_assert(reg_drone_service_actuator_common_sp_Vector31_0_1_EXTENT_BYTES_ >= reg_drone_service_actuator_common_sp_Vector31_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_,
              "Internal constraint violation");

/// Array metadata for: saturated float16[31] value
#define reg_drone_service_actuator_common_sp_Vector31_0_1_value_ARRAY_CAPACITY_           31U
#define reg_drone_service_actuator_common_sp_Vector31_0_1_value_ARRAY_IS_VARIABLE_LENGTH_ false

typedef struct
{
    /// saturated float16[31] value
    float value[31];
} reg_drone_service_actuator_common_sp_Vector31_0_1;

/// Serialize an instance into the provided buffer.
/// The lifetime of the resulting serialized representation is independent of the original instance.
/// This method may be slow for large objects (e.g., images, point clouds, radar samples), so in a later revision
/// we may define a zero-copy alternative that keeps references to the original object where possible.
///
/// @param obj      The object to serialize.
///
/// @param buffer   The destination buffer. There are no alignment requirements.
///                 @see reg_drone_service_actuator_common_sp_Vector31_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_
///
/// @param inout_buffer_size_bytes  When calling, this is a pointer to the size of the buffer in bytes.
///                                 Upon return this value will be updated with the size of the constructed serialized
///                                 representation (in bytes); this value is then to be passed over to the transport
///                                 layer. In case of error this value is undefined.
///
/// @returns Negative on error, zero on success.
static inline int8_t reg_drone_service_actuator_common_sp_Vector31_0_1_serialize_(
    const reg_drone_service_actuator_common_sp_Vector31_0_1* const obj, uint8_t* const buffer,  size_t* const inout_buffer_size_bytes)
{
    if ((obj == NULL) || (buffer == NULL) || (inout_buffer_size_bytes == NULL))
    {
        return -NUNAVUT_ERROR_INVALID_ARGUMENT;
    }

    const size_t capacity_bytes = *inout_buffer_size_bytes;
    if ((8U * (size_t) capacity_bytes) < 496UL)
    {
        return -NUNAVUT_ERROR_SERIALIZATION_BUFFER_TOO_SMALL;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    size_t offset_bits = 0U;

    {   // saturated float16[31] value
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 496ULL) <= (capacity_bytes * 8U));
        const size_t _origin0_ = offset_bits;
        {   // Array element #0
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat0_ = obj->value[0];
            if (std::isfinite(_sat0_))
            {
                if (_sat0_ < ((float) -65504.0))
                {
                    _sat0_ = ((float) -65504.0);
                }
                if (_sat0_ > ((float) 65504.0))
                {
                    _sat0_ = ((float) 65504.0);
                }
            }
            const int8_t _err0_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat0_);
            if (_err0_ < 0)
            {
                return _err0_;
            }
            offset_bits += 16U;
        }
        {   // Array element #1
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat1_ = obj->value[1];
            if (std::isfinite(_sat1_))
            {
                if (_sat1_ < ((float) -65504.0))
                {
                    _sat1_ = ((float) -65504.0);
                }
                if (_sat1_ > ((float) 65504.0))
                {
                    _sat1_ = ((float) 65504.0);
                }
            }
            const int8_t _err1_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat1_);
            if (_err1_ < 0)
            {
                return _err1_;
            }
            offset_bits += 16U;
        }
        {   // Array element #2
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat2_ = obj->value[2];
            if (std::isfinite(_sat2_))
            {
                if (_sat2_ < ((float) -65504.0))
                {
                    _sat2_ = ((float) -65504.0);
                }
                if (_sat2_ > ((float) 65504.0))
                {
                    _sat2_ = ((float) 65504.0);
                }
            }
            const int8_t _err2_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat2_);
            if (_err2_ < 0)
            {
                return _err2_;
            }
            offset_bits += 16U;
        }
        {   // Array element #3
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat3_ = obj->value[3];
            if (std::isfinite(_sat3_))
            {
                if (_sat3_ < ((float) -65504.0))
                {
                    _sat3_ = ((float) -65504.0);
                }
                if (_sat3_ > ((float) 65504.0))
                {
                    _sat3_ = ((float) 65504.0);
                }
            }
            const int8_t _err3_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat3_);
            if (_err3_ < 0)
            {
                return _err3_;
            }
            offset_bits += 16U;
        }
        {   // Array element #4
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat4_ = obj->value[4];
            if (std::isfinite(_sat4_))
            {
                if (_sat4_ < ((float) -65504.0))
                {
                    _sat4_ = ((float) -65504.0);
                }
                if (_sat4_ > ((float) 65504.0))
                {
                    _sat4_ = ((float) 65504.0);
                }
            }
            const int8_t _err4_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat4_);
            if (_err4_ < 0)
            {
                return _err4_;
            }
            offset_bits += 16U;
        }
        {   // Array element #5
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat5_ = obj->value[5];
            if (std::isfinite(_sat5_))
            {
                if (_sat5_ < ((float) -65504.0))
                {
                    _sat5_ = ((float) -65504.0);
                }
                if (_sat5_ > ((float) 65504.0))
                {
                    _sat5_ = ((float) 65504.0);
                }
            }
            const int8_t _err5_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat5_);
            if (_err5_ < 0)
            {
                return _err5_;
            }
            offset_bits += 16U;
        }
        {   // Array element #6
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat6_ = obj->value[6];
            if (std::isfinite(_sat6_))
            {
                if (_sat6_ < ((float) -65504.0))
                {
                    _sat6_ = ((float) -65504.0);
                }
                if (_sat6_ > ((float) 65504.0))
                {
                    _sat6_ = ((float) 65504.0);
                }
            }
            const int8_t _err6_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat6_);
            if (_err6_ < 0)
            {
                return _err6_;
            }
            offset_bits += 16U;
        }
        {   // Array element #7
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat7_ = obj->value[7];
            if (std::isfinite(_sat7_))
            {
                if (_sat7_ < ((float) -65504.0))
                {
                    _sat7_ = ((float) -65504.0);
                }
                if (_sat7_ > ((float) 65504.0))
                {
                    _sat7_ = ((float) 65504.0);
                }
            }
            const int8_t _err7_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat7_);
            if (_err7_ < 0)
            {
                return _err7_;
            }
            offset_bits += 16U;
        }
        {   // Array element #8
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat8_ = obj->value[8];
            if (std::isfinite(_sat8_))
            {
                if (_sat8_ < ((float) -65504.0))
                {
                    _sat8_ = ((float) -65504.0);
                }
                if (_sat8_ > ((float) 65504.0))
                {
                    _sat8_ = ((float) 65504.0);
                }
            }
            const int8_t _err8_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat8_);
            if (_err8_ < 0)
            {
                return _err8_;
            }
            offset_bits += 16U;
        }
        {   // Array element #9
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat9_ = obj->value[9];
            if (std::isfinite(_sat9_))
            {
                if (_sat9_ < ((float) -65504.0))
                {
                    _sat9_ = ((float) -65504.0);
                }
                if (_sat9_ > ((float) 65504.0))
                {
                    _sat9_ = ((float) 65504.0);
                }
            }
            const int8_t _err9_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat9_);
            if (_err9_ < 0)
            {
                return _err9_;
            }
            offset_bits += 16U;
        }
        {   // Array element #10
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat10_ = obj->value[10];
            if (std::isfinite(_sat10_))
            {
                if (_sat10_ < ((float) -65504.0))
                {
                    _sat10_ = ((float) -65504.0);
                }
                if (_sat10_ > ((float) 65504.0))
                {
                    _sat10_ = ((float) 65504.0);
                }
            }
            const int8_t _err10_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat10_);
            if (_err10_ < 0)
            {
                return _err10_;
            }
            offset_bits += 16U;
        }
        {   // Array element #11
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat11_ = obj->value[11];
            if (std::isfinite(_sat11_))
            {
                if (_sat11_ < ((float) -65504.0))
                {
                    _sat11_ = ((float) -65504.0);
                }
                if (_sat11_ > ((float) 65504.0))
                {
                    _sat11_ = ((float) 65504.0);
                }
            }
            const int8_t _err11_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat11_);
            if (_err11_ < 0)
            {
                return _err11_;
            }
            offset_bits += 16U;
        }
        {   // Array element #12
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat12_ = obj->value[12];
            if (std::isfinite(_sat12_))
            {
                if (_sat12_ < ((float) -65504.0))
                {
                    _sat12_ = ((float) -65504.0);
                }
                if (_sat12_ > ((float) 65504.0))
                {
                    _sat12_ = ((float) 65504.0);
                }
            }
            const int8_t _err12_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat12_);
            if (_err12_ < 0)
            {
                return _err12_;
            }
            offset_bits += 16U;
        }
        {   // Array element #13
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat13_ = obj->value[13];
            if (std::isfinite(_sat13_))
            {
                if (_sat13_ < ((float) -65504.0))
                {
                    _sat13_ = ((float) -65504.0);
                }
                if (_sat13_ > ((float) 65504.0))
                {
                    _sat13_ = ((float) 65504.0);
                }
            }
            const int8_t _err13_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat13_);
            if (_err13_ < 0)
            {
                return _err13_;
            }
            offset_bits += 16U;
        }
        {   // Array element #14
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat14_ = obj->value[14];
            if (std::isfinite(_sat14_))
            {
                if (_sat14_ < ((float) -65504.0))
                {
                    _sat14_ = ((float) -65504.0);
                }
                if (_sat14_ > ((float) 65504.0))
                {
                    _sat14_ = ((float) 65504.0);
                }
            }
            const int8_t _err14_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat14_);
            if (_err14_ < 0)
            {
                return _err14_;
            }
            offset_bits += 16U;
        }
        {   // Array element #15
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat15_ = obj->value[15];
            if (std::isfinite(_sat15_))
            {
                if (_sat15_ < ((float) -65504.0))
                {
                    _sat15_ = ((float) -65504.0);
                }
                if (_sat15_ > ((float) 65504.0))
                {
                    _sat15_ = ((float) 65504.0);
                }
            }
            const int8_t _err15_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat15_);
            if (_err15_ < 0)
            {
                return _err15_;
            }
            offset_bits += 16U;
        }
        {   // Array element #16
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat16_ = obj->value[16];
            if (std::isfinite(_sat16_))
            {
                if (_sat16_ < ((float) -65504.0))
                {
                    _sat16_ = ((float) -65504.0);
                }
                if (_sat16_ > ((float) 65504.0))
                {
                    _sat16_ = ((float) 65504.0);
                }
            }
            const int8_t _err16_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat16_);
            if (_err16_ < 0)
            {
                return _err16_;
            }
            offset_bits += 16U;
        }
        {   // Array element #17
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat17_ = obj->value[17];
            if (std::isfinite(_sat17_))
            {
                if (_sat17_ < ((float) -65504.0))
                {
                    _sat17_ = ((float) -65504.0);
                }
                if (_sat17_ > ((float) 65504.0))
                {
                    _sat17_ = ((float) 65504.0);
                }
            }
            const int8_t _err17_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat17_);
            if (_err17_ < 0)
            {
                return _err17_;
            }
            offset_bits += 16U;
        }
        {   // Array element #18
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat18_ = obj->value[18];
            if (std::isfinite(_sat18_))
            {
                if (_sat18_ < ((float) -65504.0))
                {
                    _sat18_ = ((float) -65504.0);
                }
                if (_sat18_ > ((float) 65504.0))
                {
                    _sat18_ = ((float) 65504.0);
                }
            }
            const int8_t _err18_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat18_);
            if (_err18_ < 0)
            {
                return _err18_;
            }
            offset_bits += 16U;
        }
        {   // Array element #19
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat19_ = obj->value[19];
            if (std::isfinite(_sat19_))
            {
                if (_sat19_ < ((float) -65504.0))
                {
                    _sat19_ = ((float) -65504.0);
                }
                if (_sat19_ > ((float) 65504.0))
                {
                    _sat19_ = ((float) 65504.0);
                }
            }
            const int8_t _err19_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat19_);
            if (_err19_ < 0)
            {
                return _err19_;
            }
            offset_bits += 16U;
        }
        {   // Array element #20
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat20_ = obj->value[20];
            if (std::isfinite(_sat20_))
            {
                if (_sat20_ < ((float) -65504.0))
                {
                    _sat20_ = ((float) -65504.0);
                }
                if (_sat20_ > ((float) 65504.0))
                {
                    _sat20_ = ((float) 65504.0);
                }
            }
            const int8_t _err20_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat20_);
            if (_err20_ < 0)
            {
                return _err20_;
            }
            offset_bits += 16U;
        }
        {   // Array element #21
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat21_ = obj->value[21];
            if (std::isfinite(_sat21_))
            {
                if (_sat21_ < ((float) -65504.0))
                {
                    _sat21_ = ((float) -65504.0);
                }
                if (_sat21_ > ((float) 65504.0))
                {
                    _sat21_ = ((float) 65504.0);
                }
            }
            const int8_t _err21_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat21_);
            if (_err21_ < 0)
            {
                return _err21_;
            }
            offset_bits += 16U;
        }
        {   // Array element #22
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat22_ = obj->value[22];
            if (std::isfinite(_sat22_))
            {
                if (_sat22_ < ((float) -65504.0))
                {
                    _sat22_ = ((float) -65504.0);
                }
                if (_sat22_ > ((float) 65504.0))
                {
                    _sat22_ = ((float) 65504.0);
                }
            }
            const int8_t _err22_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat22_);
            if (_err22_ < 0)
            {
                return _err22_;
            }
            offset_bits += 16U;
        }
        {   // Array element #23
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat23_ = obj->value[23];
            if (std::isfinite(_sat23_))
            {
                if (_sat23_ < ((float) -65504.0))
                {
                    _sat23_ = ((float) -65504.0);
                }
                if (_sat23_ > ((float) 65504.0))
                {
                    _sat23_ = ((float) 65504.0);
                }
            }
            const int8_t _err23_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat23_);
            if (_err23_ < 0)
            {
                return _err23_;
            }
            offset_bits += 16U;
        }
        {   // Array element #24
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat24_ = obj->value[24];
            if (std::isfinite(_sat24_))
            {
                if (_sat24_ < ((float) -65504.0))
                {
                    _sat24_ = ((float) -65504.0);
                }
                if (_sat24_ > ((float) 65504.0))
                {
                    _sat24_ = ((float) 65504.0);
                }
            }
            const int8_t _err24_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat24_);
            if (_err24_ < 0)
            {
                return _err24_;
            }
            offset_bits += 16U;
        }
        {   // Array element #25
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat25_ = obj->value[25];
            if (std::isfinite(_sat25_))
            {
                if (_sat25_ < ((float) -65504.0))
                {
                    _sat25_ = ((float) -65504.0);
                }
                if (_sat25_ > ((float) 65504.0))
                {
                    _sat25_ = ((float) 65504.0);
                }
            }
            const int8_t _err25_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat25_);
            if (_err25_ < 0)
            {
                return _err25_;
            }
            offset_bits += 16U;
        }
        {   // Array element #26
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat26_ = obj->value[26];
            if (std::isfinite(_sat26_))
            {
                if (_sat26_ < ((float) -65504.0))
                {
                    _sat26_ = ((float) -65504.0);
                }
                if (_sat26_ > ((float) 65504.0))
                {
                    _sat26_ = ((float) 65504.0);
                }
            }
            const int8_t _err26_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat26_);
            if (_err26_ < 0)
            {
                return _err26_;
            }
            offset_bits += 16U;
        }
        {   // Array element #27
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat27_ = obj->value[27];
            if (std::isfinite(_sat27_))
            {
                if (_sat27_ < ((float) -65504.0))
                {
                    _sat27_ = ((float) -65504.0);
                }
                if (_sat27_ > ((float) 65504.0))
                {
                    _sat27_ = ((float) 65504.0);
                }
            }
            const int8_t _err27_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat27_);
            if (_err27_ < 0)
            {
                return _err27_;
            }
            offset_bits += 16U;
        }
        {   // Array element #28
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat28_ = obj->value[28];
            if (std::isfinite(_sat28_))
            {
                if (_sat28_ < ((float) -65504.0))
                {
                    _sat28_ = ((float) -65504.0);
                }
                if (_sat28_ > ((float) 65504.0))
                {
                    _sat28_ = ((float) 65504.0);
                }
            }
            const int8_t _err28_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat28_);
            if (_err28_ < 0)
            {
                return _err28_;
            }
            offset_bits += 16U;
        }
        {   // Array element #29
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat29_ = obj->value[29];
            if (std::isfinite(_sat29_))
            {
                if (_sat29_ < ((float) -65504.0))
                {
                    _sat29_ = ((float) -65504.0);
                }
                if (_sat29_ > ((float) 65504.0))
                {
                    _sat29_ = ((float) 65504.0);
                }
            }
            const int8_t _err29_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat29_);
            if (_err29_ < 0)
            {
                return _err29_;
            }
            offset_bits += 16U;
        }
        {   // Array element #30
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat30_ = obj->value[30];
            if (std::isfinite(_sat30_))
            {
                if (_sat30_ < ((float) -65504.0))
                {
                    _sat30_ = ((float) -65504.0);
                }
                if (_sat30_ > ((float) 65504.0))
                {
                    _sat30_ = ((float) 65504.0);
                }
            }
            const int8_t _err30_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat30_);
            if (_err30_ < 0)
            {
                return _err30_;
            }
            offset_bits += 16U;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((offset_bits - _origin0_) == 496ULL);
        (void) _origin0_;
    }

    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad0_ = (uint8_t)(8U - offset_bits % 8U);
        NUNAVUT_ASSERT(_pad0_ > 0);
        const int8_t _err31_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad0_);  // Optimize?
        if (_err31_ < 0)
        {
            return _err31_;
        }
        offset_bits += _pad0_;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    }
    // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.

    NUNAVUT_ASSERT(offset_bits == 496ULL);

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
static inline int8_t reg_drone_service_actuator_common_sp_Vector31_0_1_deserialize_(
    reg_drone_service_actuator_common_sp_Vector31_0_1* const out_obj, const uint8_t* const buffer, size_t* const inout_buffer_size_bytes)
{
    if ((out_obj == NULL) || (buffer == NULL) || (inout_buffer_size_bytes == NULL))
    {
        return -NUNAVUT_ERROR_INVALID_ARGUMENT;
    }

    const size_t capacity_bytes = *inout_buffer_size_bytes;
    const size_t capacity_bits = capacity_bytes * (size_t) 8U;
    size_t offset_bits = 0U;

    // saturated float16[31] value
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    // Array element #0
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[0] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #1
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[1] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #2
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[2] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #3
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[3] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #4
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[4] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #5
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[5] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #6
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[6] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #7
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[7] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #8
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[8] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #9
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[9] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #10
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[10] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #11
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[11] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #12
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[12] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #13
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[13] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #14
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[14] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #15
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[15] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #16
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[16] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #17
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[17] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #18
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[18] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #19
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[19] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #20
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[20] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #21
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[21] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #22
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[22] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #23
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[23] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #24
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[24] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #25
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[25] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #26
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[26] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #27
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[27] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #28
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[28] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #29
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[29] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;
    // Array element #30
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->value[30] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 16U;

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
static inline void reg_drone_service_actuator_common_sp_Vector31_0_1_initialize_(reg_drone_service_actuator_common_sp_Vector31_0_1* const out_obj)
{
    if (out_obj != NULL)
    {
        size_t size_bytes = 0;
        const uint8_t buf = 0;
        const int8_t err = reg_drone_service_actuator_common_sp_Vector31_0_1_deserialize_(out_obj, &buf, &size_bytes);
        NUNAVUT_ASSERT(err >= 0);
        (void) err;
    }
}

#ifdef __cplusplus
}
#endif
#endif // REG_DRONE_SERVICE_ACTUATOR_COMMON_SP_VECTOR31_0_1_INCLUDED_
