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
// Source file:   /tmp/public_regulated_data_types/reg/drone/service/battery/Status.0.2.uavcan
// Generated at:  2021-09-27 06:53:05.737101 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     reg.drone.service.battery.Status
// Version:       0.2
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

#ifndef REG_DRONE_SERVICE_BATTERY_STATUS_0_2_INCLUDED_
#define REG_DRONE_SERVICE_BATTERY_STATUS_0_2_INCLUDED_

#include <nunavut/support/serialization.h>
#include <types/reg/drone/service/battery/Error_0_1.h>
#include <types/reg/drone/service/common/Heartbeat_0_1.h>
#include <types/uavcan/si/unit/electric_charge/Scalar_1_0.h>
#include <types/uavcan/si/unit/temperature/Scalar_1_0.h>
#include <stdint.h>
#include <stdlib.h>

static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_TARGET_ENDIANNESS == 1693710260,
              "/tmp/public_regulated_data_types/reg/drone/service/battery/Status.0.2.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_OMIT_FLOAT_SERIALIZATION_SUPPORT == 0,
              "/tmp/public_regulated_data_types/reg/drone/service/battery/Status.0.2.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_SERIALIZATION_ASSERTS == 1,
              "/tmp/public_regulated_data_types/reg/drone/service/battery/Status.0.2.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_OVERRIDE_VARIABLE_ARRAY_CAPACITY == 0,
              "/tmp/public_regulated_data_types/reg/drone/service/battery/Status.0.2.uavcan is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );

#ifdef __cplusplus
extern "C" {
#endif

/// This type does not have a fixed port-ID. See https://forum.uavcan.org/t/choosing-message-and-service-ids/889
#define reg_drone_service_battery_Status_0_2_HAS_FIXED_PORT_ID_ false

#define reg_drone_service_battery_Status_0_2_FULL_NAME_             "reg.drone.service.battery.Status"
#define reg_drone_service_battery_Status_0_2_FULL_NAME_AND_VERSION_ "reg.drone.service.battery.Status.0.2"

/// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
/// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
/// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
/// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
/// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
/// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
/// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.
#define reg_drone_service_battery_Status_0_2_EXTENT_BYTES_                    600UL
#define reg_drone_service_battery_Status_0_2_SERIALIZATION_BUFFER_SIZE_BYTES_ 534UL
static_assert(reg_drone_service_battery_Status_0_2_EXTENT_BYTES_ >= reg_drone_service_battery_Status_0_2_SERIALIZATION_BUFFER_SIZE_BYTES_,
              "Internal constraint violation");

/// saturated uint8 MAX_CELLS = 255
#define reg_drone_service_battery_Status_0_2_MAX_CELLS (255U)

/// Array metadata for: uavcan.si.unit.temperature.Scalar.1.0[2] temperature_min_max
#define reg_drone_service_battery_Status_0_2_temperature_min_max_ARRAY_CAPACITY_           2U
#define reg_drone_service_battery_Status_0_2_temperature_min_max_ARRAY_IS_VARIABLE_LENGTH_ false
/// Array metadata for: saturated float16[<=255] cell_voltages
#define reg_drone_service_battery_Status_0_2_cell_voltages_ARRAY_CAPACITY_           255U
#define reg_drone_service_battery_Status_0_2_cell_voltages_ARRAY_IS_VARIABLE_LENGTH_ true

typedef struct
{
    /// reg.drone.service.common.Heartbeat.0.1 heartbeat
    reg_drone_service_common_Heartbeat_0_1 heartbeat;

    /// uavcan.si.unit.temperature.Scalar.1.0[2] temperature_min_max
    uavcan_si_unit_temperature_Scalar_1_0 temperature_min_max[2];

    /// uavcan.si.unit.electric_charge.Scalar.1.0 available_charge
    uavcan_si_unit_electric_charge_Scalar_1_0 available_charge;

    /// reg.drone.service.battery.Error.0.1 error
    reg_drone_service_battery_Error_0_1 _error;

    /// saturated float16[<=255] cell_voltages
    struct  /// Array address equivalence guarantee: &elements[0] == &cell_voltages
    {
        float elements[reg_drone_service_battery_Status_0_2_cell_voltages_ARRAY_CAPACITY_];
        size_t count;
    } cell_voltages;
} reg_drone_service_battery_Status_0_2;

/// Serialize an instance into the provided buffer.
/// The lifetime of the resulting serialized representation is independent of the original instance.
/// This method may be slow for large objects (e.g., images, point clouds, radar samples), so in a later revision
/// we may define a zero-copy alternative that keeps references to the original object where possible.
///
/// @param obj      The object to serialize.
///
/// @param buffer   The destination buffer. There are no alignment requirements.
///                 @see reg_drone_service_battery_Status_0_2_SERIALIZATION_BUFFER_SIZE_BYTES_
///
/// @param inout_buffer_size_bytes  When calling, this is a pointer to the size of the buffer in bytes.
///                                 Upon return this value will be updated with the size of the constructed serialized
///                                 representation (in bytes); this value is then to be passed over to the transport
///                                 layer. In case of error this value is undefined.
///
/// @returns Negative on error, zero on success.
static inline int8_t reg_drone_service_battery_Status_0_2_serialize_(
    const reg_drone_service_battery_Status_0_2* const obj, uint8_t* const buffer,  size_t* const inout_buffer_size_bytes)
{
    if ((obj == NULL) || (buffer == NULL) || (inout_buffer_size_bytes == NULL))
    {
        return -NUNAVUT_ERROR_INVALID_ARGUMENT;
    }

    const size_t capacity_bytes = *inout_buffer_size_bytes;
    if ((8U * (size_t) capacity_bytes) < 4272UL)
    {
        return -NUNAVUT_ERROR_SERIALIZATION_BUFFER_TOO_SMALL;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    size_t offset_bits = 0U;

    {   // reg.drone.service.common.Heartbeat.0.1 heartbeat
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes0_ = 2UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes0_) <= capacity_bytes);
        int8_t _err0_ = reg_drone_service_common_Heartbeat_0_1_serialize_(
            &obj->heartbeat, &buffer[offset_bits / 8U], &_size_bytes0_);
        if (_err0_ < 0)
        {
            return _err0_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes0_ * 8U) == 16ULL);
        offset_bits += _size_bytes0_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
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

    {   // uavcan.si.unit.temperature.Scalar.1.0[2] temperature_min_max
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 64ULL) <= (capacity_bytes * 8U));
        const size_t _origin0_ = offset_bits;
        for (size_t _index0_ = 0U; _index0_ < 2UL; ++_index0_)
        {
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 32ULL) <= (capacity_bytes * 8U));
            size_t _size_bytes1_ = 4UL;  // Nested object (max) size, in bytes.
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes1_) <= capacity_bytes);
            int8_t _err2_ = uavcan_si_unit_temperature_Scalar_1_0_serialize_(
                &obj->temperature_min_max[_index0_], &buffer[offset_bits / 8U], &_size_bytes1_);
            if (_err2_ < 0)
            {
                return _err2_;
            }
            // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
            NUNAVUT_ASSERT((_size_bytes1_ * 8U) == 32ULL);
            offset_bits += _size_bytes1_ * 8U;  // Advance by the size of the nested object.
            NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((offset_bits - _origin0_) == 64ULL);
        (void) _origin0_;
    }

    {   // void64
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 64ULL) <= (capacity_bytes * 8U));
        (void) memset(&buffer[offset_bits / 8U], 0, 8);
        offset_bits += 64UL;
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

    {   // uavcan.si.unit.electric_charge.Scalar.1.0 available_charge
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 32ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes2_ = 4UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes2_) <= capacity_bytes);
        int8_t _err4_ = uavcan_si_unit_electric_charge_Scalar_1_0_serialize_(
            &obj->available_charge, &buffer[offset_bits / 8U], &_size_bytes2_);
        if (_err4_ < 0)
        {
            return _err4_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes2_ * 8U) == 32ULL);
        offset_bits += _size_bytes2_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }

    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad2_ = (uint8_t)(8U - offset_bits % 8U);
        NUNAVUT_ASSERT(_pad2_ > 0);
        const int8_t _err5_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad2_);  // Optimize?
        if (_err5_ < 0)
        {
            return _err5_;
        }
        offset_bits += _pad2_;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    }

    {   // reg.drone.service.battery.Error.0.1 error
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 8ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes3_ = 1UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes3_) <= capacity_bytes);
        int8_t _err6_ = reg_drone_service_battery_Error_0_1_serialize_(
            &obj->_error, &buffer[offset_bits / 8U], &_size_bytes3_);
        if (_err6_ < 0)
        {
            return _err6_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes3_ * 8U) == 8ULL);
        offset_bits += _size_bytes3_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }

    {   // saturated float16[<=255] cell_voltages
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 4088ULL) <= (capacity_bytes * 8U));
        if (obj->cell_voltages.count > 255)
        {
            return -NUNAVUT_ERROR_REPRESENTATION_BAD_ARRAY_LENGTH;
        }
        // Array length prefix: truncated uint8
        buffer[offset_bits / 8U] = (uint8_t)(obj->cell_voltages.count);  // C std, 6.3.1.3 Signed and unsigned integers
        offset_bits += 8U;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        for (size_t _index1_ = 0U; _index1_ < obj->cell_voltages.count; ++_index1_)
        {
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
            float _sat0_ = obj->cell_voltages.elements[_index1_];
            if (isfinite(_sat0_))
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
            const int8_t _err7_ = nunavutSetF16(&buffer[0], capacity_bytes, offset_bits, _sat0_);
            if (_err7_ < 0)
            {
                return _err7_;
            }
            offset_bits += 16U;
        }
    }

    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad3_ = (uint8_t)(8U - offset_bits % 8U);
        NUNAVUT_ASSERT(_pad3_ > 0);
        const int8_t _err8_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad3_);  // Optimize?
        if (_err8_ < 0)
        {
            return _err8_;
        }
        offset_bits += _pad3_;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    }
    // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.

    NUNAVUT_ASSERT(offset_bits >= 192ULL);
    NUNAVUT_ASSERT(offset_bits <= 4272ULL);

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
static inline int8_t reg_drone_service_battery_Status_0_2_deserialize_(
    reg_drone_service_battery_Status_0_2* const out_obj, const uint8_t* const buffer, size_t* const inout_buffer_size_bytes)
{
    if ((out_obj == NULL) || (buffer == NULL) || (inout_buffer_size_bytes == NULL))
    {
        return -NUNAVUT_ERROR_INVALID_ARGUMENT;
    }

    const size_t capacity_bytes = *inout_buffer_size_bytes;
    const size_t capacity_bits = capacity_bytes * (size_t) 8U;
    size_t offset_bits = 0U;

    // reg.drone.service.common.Heartbeat.0.1 heartbeat
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    {
        size_t _size_bytes4_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        const int8_t _err9_ = reg_drone_service_common_Heartbeat_0_1_deserialize_(
            &out_obj->heartbeat, &buffer[offset_bits / 8U], &_size_bytes4_);
        if (_err9_ < 0)
        {
            return _err9_;
        }
        offset_bits += _size_bytes4_ * 8U;  // Advance by the size of the nested serialized representation.
    }

    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.

    // uavcan.si.unit.temperature.Scalar.1.0[2] temperature_min_max
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    for (size_t _index2_ = 0U; _index2_ < 2UL; ++_index2_)
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        {
            size_t _size_bytes5_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            const int8_t _err10_ = uavcan_si_unit_temperature_Scalar_1_0_deserialize_(
                &out_obj->temperature_min_max[_index2_], &buffer[offset_bits / 8U], &_size_bytes5_);
            if (_err10_ < 0)
            {
                return _err10_;
            }
            offset_bits += _size_bytes5_ * 8U;  // Advance by the size of the nested serialized representation.
        }
    }

    // void64
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    offset_bits += 64;

    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.

    // uavcan.si.unit.electric_charge.Scalar.1.0 available_charge
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    {
        size_t _size_bytes6_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        const int8_t _err11_ = uavcan_si_unit_electric_charge_Scalar_1_0_deserialize_(
            &out_obj->available_charge, &buffer[offset_bits / 8U], &_size_bytes6_);
        if (_err11_ < 0)
        {
            return _err11_;
        }
        offset_bits += _size_bytes6_ * 8U;  // Advance by the size of the nested serialized representation.
    }

    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.

    // reg.drone.service.battery.Error.0.1 error
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    {
        size_t _size_bytes7_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        const int8_t _err12_ = reg_drone_service_battery_Error_0_1_deserialize_(
            &out_obj->_error, &buffer[offset_bits / 8U], &_size_bytes7_);
        if (_err12_ < 0)
        {
            return _err12_;
        }
        offset_bits += _size_bytes7_ * 8U;  // Advance by the size of the nested serialized representation.
    }

    // saturated float16[<=255] cell_voltages
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    // Array length prefix: truncated uint8
    if ((offset_bits + 8U) <= capacity_bits)
    {
        out_obj->cell_voltages.count = buffer[offset_bits / 8U] & 255U;
    }
    else
    {
        out_obj->cell_voltages.count = 0U;
    }
    offset_bits += 8U;
    if (out_obj->cell_voltages.count > 255U)
    {
        return -NUNAVUT_ERROR_REPRESENTATION_BAD_ARRAY_LENGTH;
    }
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    for (size_t _index3_ = 0U; _index3_ < out_obj->cell_voltages.count; ++_index3_)
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        out_obj->cell_voltages.elements[_index3_] = nunavutGetF16(&buffer[0], capacity_bytes, offset_bits);
        offset_bits += 16U;
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
static inline void reg_drone_service_battery_Status_0_2_initialize_(reg_drone_service_battery_Status_0_2* const out_obj)
{
    if (out_obj != NULL)
    {
        size_t size_bytes = 0;
        const uint8_t buf = 0;
        const int8_t err = reg_drone_service_battery_Status_0_2_deserialize_(out_obj, &buf, &size_bytes);
        NUNAVUT_ASSERT(err >= 0);
        (void) err;
    }
}

#ifdef __cplusplus
}
#endif
#endif // REG_DRONE_SERVICE_BATTERY_STATUS_0_2_INCLUDED_

