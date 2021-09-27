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
// Source file:   /tmp/public_regulated_data_types/reg/drone/service/actuator/common/FaultFlags.0.1.uavcan
// Generated at:  2021-09-27 06:53:05.674875 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     reg.drone.service.actuator.common.FaultFlags
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

#ifndef REG_DRONE_SERVICE_ACTUATOR_COMMON_FAULT_FLAGS_0_1_INCLUDED_
#define REG_DRONE_SERVICE_ACTUATOR_COMMON_FAULT_FLAGS_0_1_INCLUDED_

#include <nunavut/support/serialization.h>
#include <stdbool.h>
#include <stdlib.h>

static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_TARGET_ENDIANNESS == 1693710260,
              "/tmp/public_regulated_data_types/reg/drone/service/actuator/common/FaultFlags.0.1.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_OMIT_FLOAT_SERIALIZATION_SUPPORT == 0,
              "/tmp/public_regulated_data_types/reg/drone/service/actuator/common/FaultFlags.0.1.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_SERIALIZATION_ASSERTS == 1,
              "/tmp/public_regulated_data_types/reg/drone/service/actuator/common/FaultFlags.0.1.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_OVERRIDE_VARIABLE_ARRAY_CAPACITY == 0,
              "/tmp/public_regulated_data_types/reg/drone/service/actuator/common/FaultFlags.0.1.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );

#ifdef __cplusplus
extern "C" {
#endif

/// This type does not have a fixed port-ID. See https://forum.uavcan.org/t/choosing-message-and-service-ids/889
#define reg_drone_service_actuator_common_FaultFlags_0_1_HAS_FIXED_PORT_ID_ false

#define reg_drone_service_actuator_common_FaultFlags_0_1_FULL_NAME_             "reg.drone.service.actuator.common.FaultFlags"
#define reg_drone_service_actuator_common_FaultFlags_0_1_FULL_NAME_AND_VERSION_ "reg.drone.service.actuator.common.FaultFlags.0.1"

/// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
/// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
/// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
/// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
/// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
/// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
/// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.
#define reg_drone_service_actuator_common_FaultFlags_0_1_EXTENT_BYTES_                    2UL
#define reg_drone_service_actuator_common_FaultFlags_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_ 2UL
static_assert(reg_drone_service_actuator_common_FaultFlags_0_1_EXTENT_BYTES_ >= reg_drone_service_actuator_common_FaultFlags_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_,
              "Internal constraint violation");

typedef struct
{
    /// saturated bool overload
    bool overload;

    /// saturated bool voltage
    bool voltage;

    /// saturated bool motor_temperature
    bool motor_temperature;

    /// saturated bool controller_temperature
    bool controller_temperature;

    /// saturated bool velocity
    bool velocity;

    /// saturated bool mechanical
    bool mechanical;

    /// saturated bool vibration
    bool vibration;

    /// saturated bool configuration
    bool configuration;

    /// saturated bool control_mode
    bool control_mode;

    /// saturated bool other
    bool other;
} reg_drone_service_actuator_common_FaultFlags_0_1;

/// Serialize an instance into the provided buffer.
/// The lifetime of the resulting serialized representation is independent of the original instance.
/// This method may be slow for large objects (e.g., images, point clouds, radar samples), so in a later revision
/// we may define a zero-copy alternative that keeps references to the original object where possible.
///
/// @param obj      The object to serialize.
///
/// @param buffer   The destination buffer. There are no alignment requirements.
///                 @see reg_drone_service_actuator_common_FaultFlags_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_
///
/// @param inout_buffer_size_bytes  When calling, this is a pointer to the size of the buffer in bytes.
///                                 Upon return this value will be updated with the size of the constructed serialized
///                                 representation (in bytes); this value is then to be passed over to the transport
///                                 layer. In case of error this value is undefined.
///
/// @returns Negative on error, zero on success.
static inline int8_t reg_drone_service_actuator_common_FaultFlags_0_1_serialize_(
    const reg_drone_service_actuator_common_FaultFlags_0_1* const obj, uint8_t* const buffer,  size_t* const inout_buffer_size_bytes)
{
    if ((obj == NULL) || (buffer == NULL) || (inout_buffer_size_bytes == NULL))
    {
        return -NUNAVUT_ERROR_INVALID_ARGUMENT;
    }

    const size_t capacity_bytes = *inout_buffer_size_bytes;
    if ((8U * (size_t) capacity_bytes) < 16UL)
    {
        return -NUNAVUT_ERROR_SERIALIZATION_BUFFER_TOO_SMALL;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    size_t offset_bits = 0U;

    {   // saturated bool overload
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 1ULL) <= (capacity_bytes * 8U));
        buffer[offset_bits / 8U] = obj->overload ? 1U : 0U;
        offset_bits += 1U;
    }

    {   // saturated bool voltage
        NUNAVUT_ASSERT((offset_bits + 1ULL) <= (capacity_bytes * 8U));
        if (obj->voltage)
        {
            buffer[offset_bits / 8U] = (uint8_t)(buffer[offset_bits / 8U] | (1U << (offset_bits % 8U)));
        }
        else
        {
            buffer[offset_bits / 8U] = (uint8_t)(buffer[offset_bits / 8U] & ~(1U << (offset_bits % 8U)));
        }
        offset_bits += 1U;
    }

    {   // saturated bool motor_temperature
        NUNAVUT_ASSERT((offset_bits + 1ULL) <= (capacity_bytes * 8U));
        if (obj->motor_temperature)
        {
            buffer[offset_bits / 8U] = (uint8_t)(buffer[offset_bits / 8U] | (1U << (offset_bits % 8U)));
        }
        else
        {
            buffer[offset_bits / 8U] = (uint8_t)(buffer[offset_bits / 8U] & ~(1U << (offset_bits % 8U)));
        }
        offset_bits += 1U;
    }

    {   // saturated bool controller_temperature
        NUNAVUT_ASSERT((offset_bits + 1ULL) <= (capacity_bytes * 8U));
        if (obj->controller_temperature)
        {
            buffer[offset_bits / 8U] = (uint8_t)(buffer[offset_bits / 8U] | (1U << (offset_bits % 8U)));
        }
        else
        {
            buffer[offset_bits / 8U] = (uint8_t)(buffer[offset_bits / 8U] & ~(1U << (offset_bits % 8U)));
        }
        offset_bits += 1U;
    }

    {   // saturated bool velocity
        NUNAVUT_ASSERT((offset_bits + 1ULL) <= (capacity_bytes * 8U));
        if (obj->velocity)
        {
            buffer[offset_bits / 8U] = (uint8_t)(buffer[offset_bits / 8U] | (1U << (offset_bits % 8U)));
        }
        else
        {
            buffer[offset_bits / 8U] = (uint8_t)(buffer[offset_bits / 8U] & ~(1U << (offset_bits % 8U)));
        }
        offset_bits += 1U;
    }

    {   // saturated bool mechanical
        NUNAVUT_ASSERT((offset_bits + 1ULL) <= (capacity_bytes * 8U));
        if (obj->mechanical)
        {
            buffer[offset_bits / 8U] = (uint8_t)(buffer[offset_bits / 8U] | (1U << (offset_bits % 8U)));
        }
        else
        {
            buffer[offset_bits / 8U] = (uint8_t)(buffer[offset_bits / 8U] & ~(1U << (offset_bits % 8U)));
        }
        offset_bits += 1U;
    }

    {   // saturated bool vibration
        NUNAVUT_ASSERT((offset_bits + 1ULL) <= (capacity_bytes * 8U));
        if (obj->vibration)
        {
            buffer[offset_bits / 8U] = (uint8_t)(buffer[offset_bits / 8U] | (1U << (offset_bits % 8U)));
        }
        else
        {
            buffer[offset_bits / 8U] = (uint8_t)(buffer[offset_bits / 8U] & ~(1U << (offset_bits % 8U)));
        }
        offset_bits += 1U;
    }

    {   // saturated bool configuration
        NUNAVUT_ASSERT((offset_bits + 1ULL) <= (capacity_bytes * 8U));
        if (obj->configuration)
        {
            buffer[offset_bits / 8U] = (uint8_t)(buffer[offset_bits / 8U] | (1U << (offset_bits % 8U)));
        }
        else
        {
            buffer[offset_bits / 8U] = (uint8_t)(buffer[offset_bits / 8U] & ~(1U << (offset_bits % 8U)));
        }
        offset_bits += 1U;
    }

    {   // saturated bool control_mode
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 1ULL) <= (capacity_bytes * 8U));
        buffer[offset_bits / 8U] = obj->control_mode ? 1U : 0U;
        offset_bits += 1U;
    }

    {   // void6
        NUNAVUT_ASSERT((offset_bits + 6ULL) <= (capacity_bytes * 8U));
        const int8_t _err0_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, 6U);  // Optimize?
        if (_err0_ < 0)
        {
            return _err0_;
        }
        offset_bits += 6UL;
    }

    {   // saturated bool other
        NUNAVUT_ASSERT((offset_bits + 1ULL) <= (capacity_bytes * 8U));
        if (obj->other)
        {
            buffer[offset_bits / 8U] = (uint8_t)(buffer[offset_bits / 8U] | (1U << (offset_bits % 8U)));
        }
        else
        {
            buffer[offset_bits / 8U] = (uint8_t)(buffer[offset_bits / 8U] & ~(1U << (offset_bits % 8U)));
        }
        offset_bits += 1U;
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
    // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.

    NUNAVUT_ASSERT(offset_bits == 16ULL);

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
static inline int8_t reg_drone_service_actuator_common_FaultFlags_0_1_deserialize_(
    reg_drone_service_actuator_common_FaultFlags_0_1* const out_obj, const uint8_t* const buffer, size_t* const inout_buffer_size_bytes)
{
    if ((out_obj == NULL) || (buffer == NULL) || (inout_buffer_size_bytes == NULL))
    {
        return -NUNAVUT_ERROR_INVALID_ARGUMENT;
    }

    const size_t capacity_bytes = *inout_buffer_size_bytes;
    const size_t capacity_bits = capacity_bytes * (size_t) 8U;
    size_t offset_bits = 0U;

    // saturated bool overload
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    if (offset_bits < capacity_bits)
    {
        out_obj->overload = (buffer[offset_bits / 8U] & 1U) != 0U;
    }
    else
    {
        out_obj->overload = false;
    }
    offset_bits += 1U;

    // saturated bool voltage
    if (offset_bits < capacity_bits)
    {
        out_obj->voltage = (buffer[offset_bits / 8U] & (1U << (offset_bits % 8U))) != 0U;
    }
    else
    {
        out_obj->voltage = false;
    }
    offset_bits += 1U;

    // saturated bool motor_temperature
    if (offset_bits < capacity_bits)
    {
        out_obj->motor_temperature = (buffer[offset_bits / 8U] & (1U << (offset_bits % 8U))) != 0U;
    }
    else
    {
        out_obj->motor_temperature = false;
    }
    offset_bits += 1U;

    // saturated bool controller_temperature
    if (offset_bits < capacity_bits)
    {
        out_obj->controller_temperature = (buffer[offset_bits / 8U] & (1U << (offset_bits % 8U))) != 0U;
    }
    else
    {
        out_obj->controller_temperature = false;
    }
    offset_bits += 1U;

    // saturated bool velocity
    if (offset_bits < capacity_bits)
    {
        out_obj->velocity = (buffer[offset_bits / 8U] & (1U << (offset_bits % 8U))) != 0U;
    }
    else
    {
        out_obj->velocity = false;
    }
    offset_bits += 1U;

    // saturated bool mechanical
    if (offset_bits < capacity_bits)
    {
        out_obj->mechanical = (buffer[offset_bits / 8U] & (1U << (offset_bits % 8U))) != 0U;
    }
    else
    {
        out_obj->mechanical = false;
    }
    offset_bits += 1U;

    // saturated bool vibration
    if (offset_bits < capacity_bits)
    {
        out_obj->vibration = (buffer[offset_bits / 8U] & (1U << (offset_bits % 8U))) != 0U;
    }
    else
    {
        out_obj->vibration = false;
    }
    offset_bits += 1U;

    // saturated bool configuration
    if (offset_bits < capacity_bits)
    {
        out_obj->configuration = (buffer[offset_bits / 8U] & (1U << (offset_bits % 8U))) != 0U;
    }
    else
    {
        out_obj->configuration = false;
    }
    offset_bits += 1U;

    // saturated bool control_mode
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    if (offset_bits < capacity_bits)
    {
        out_obj->control_mode = (buffer[offset_bits / 8U] & 1U) != 0U;
    }
    else
    {
        out_obj->control_mode = false;
    }
    offset_bits += 1U;

    // void6
    offset_bits += 6;

    // saturated bool other
    if (offset_bits < capacity_bits)
    {
        out_obj->other = (buffer[offset_bits / 8U] & (1U << (offset_bits % 8U))) != 0U;
    }
    else
    {
        out_obj->other = false;
    }
    offset_bits += 1U;

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
static inline void reg_drone_service_actuator_common_FaultFlags_0_1_initialize_(reg_drone_service_actuator_common_FaultFlags_0_1* const out_obj)
{
    if (out_obj != NULL)
    {
        size_t size_bytes = 0;
        const uint8_t buf = 0;
        const int8_t err = reg_drone_service_actuator_common_FaultFlags_0_1_deserialize_(out_obj, &buf, &size_bytes);
        NUNAVUT_ASSERT(err >= 0);
        (void) err;
    }
}

#ifdef __cplusplus
}
#endif
#endif // REG_DRONE_SERVICE_ACTUATOR_COMMON_FAULT_FLAGS_0_1_INCLUDED_
