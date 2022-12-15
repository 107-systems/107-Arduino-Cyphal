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
// Source file:   /tmp/public_regulated_data_types/reg/udral/service/battery/Parameters.0.3.dsdl
// Generated at:  2022-12-15 23:20:53.065017 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     reg.udral.service.battery.Parameters
// Version:       0.3
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

#ifndef REG_UDRAL_SERVICE_BATTERY_PARAMETERS_0_3_INCLUDED_
#define REG_UDRAL_SERVICE_BATTERY_PARAMETERS_0_3_INCLUDED_

#include <nunavut/support/serialization.h>
#include <types/reg/udral/service/battery/Technology_0_1.h>
#include <stdint.h>
#include <stdlib.h>
#include <types/uavcan/si/unit/electric_charge/Scalar_1_0.h>
#include <types/uavcan/si/unit/electric_current/Scalar_1_0.h>
#include <types/uavcan/si/unit/mass/Scalar_1_0.h>
#include <types/uavcan/si/unit/voltage/Scalar_1_0.h>

static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_TARGET_ENDIANNESS == 1693710260,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/Parameters.0.3.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_OMIT_FLOAT_SERIALIZATION_SUPPORT == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/Parameters.0.3.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_SERIALIZATION_ASSERTS == 1,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/Parameters.0.3.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_OVERRIDE_VARIABLE_ARRAY_CAPACITY == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/Parameters.0.3.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_CAST_FORMAT == 2368206204,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/Parameters.0.3.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );

#ifdef __cplusplus
extern "C" {
#endif

/// This type does not have a fixed port-ID. See https://forum.opencyphal.org/t/choosing-message-and-service-ids/889
#define reg_udral_service_battery_Parameters_0_3_HAS_FIXED_PORT_ID_ false

#define reg_udral_service_battery_Parameters_0_3_FULL_NAME_             "reg.udral.service.battery.Parameters"
#define reg_udral_service_battery_Parameters_0_3_FULL_NAME_AND_VERSION_ "reg.udral.service.battery.Parameters.0.3"

/// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
/// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
/// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
/// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
/// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
/// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
/// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.
#define reg_udral_service_battery_Parameters_0_3_EXTENT_BYTES_                    300UL
#define reg_udral_service_battery_Parameters_0_3_SERIALIZATION_BUFFER_SIZE_BYTES_ 128UL
static_assert(reg_udral_service_battery_Parameters_0_3_EXTENT_BYTES_ >= reg_udral_service_battery_Parameters_0_3_SERIALIZATION_BUFFER_SIZE_BYTES_,
              "Internal constraint violation");

/// Array metadata for: uavcan.si.unit.voltage.Scalar.1.0[2] design_cell_voltage_min_max
#define reg_udral_service_battery_Parameters_0_3_design_cell_voltage_min_max_ARRAY_CAPACITY_           2U
#define reg_udral_service_battery_Parameters_0_3_design_cell_voltage_min_max_ARRAY_IS_VARIABLE_LENGTH_ false
/// Array metadata for: saturated uint8[<=64] name
#define reg_udral_service_battery_Parameters_0_3_name_ARRAY_CAPACITY_           64U
#define reg_udral_service_battery_Parameters_0_3_name_ARRAY_IS_VARIABLE_LENGTH_ true

typedef struct
{
    /// truncated uint64 unique_id
    uint64_t unique_id;

    /// uavcan.si.unit.mass.Scalar.1.0 mass
    uavcan_si_unit_mass_Scalar_1_0 mass;

    /// uavcan.si.unit.electric_charge.Scalar.1.0 design_capacity
    uavcan_si_unit_electric_charge_Scalar_1_0 design_capacity;

    /// uavcan.si.unit.voltage.Scalar.1.0[2] design_cell_voltage_min_max
    uavcan_si_unit_voltage_Scalar_1_0 design_cell_voltage_min_max[2];

    /// uavcan.si.unit.electric_current.Scalar.1.0 discharge_current
    uavcan_si_unit_electric_current_Scalar_1_0 discharge_current;

    /// uavcan.si.unit.electric_current.Scalar.1.0 discharge_current_burst
    uavcan_si_unit_electric_current_Scalar_1_0 discharge_current_burst;

    /// uavcan.si.unit.electric_current.Scalar.1.0 charge_current
    uavcan_si_unit_electric_current_Scalar_1_0 charge_current;

    /// uavcan.si.unit.electric_current.Scalar.1.0 charge_current_fast
    uavcan_si_unit_electric_current_Scalar_1_0 charge_current_fast;

    /// uavcan.si.unit.electric_current.Scalar.1.0 charge_termination_threshold
    uavcan_si_unit_electric_current_Scalar_1_0 charge_termination_threshold;

    /// uavcan.si.unit.voltage.Scalar.1.0 charge_voltage
    uavcan_si_unit_voltage_Scalar_1_0 charge_voltage;

    /// saturated uint16 cycle_count
    uint16_t cycle_count;

    /// saturated uint8 series_cell_count
    uint8_t series_cell_count;

    /// saturated uint7 state_of_health_pct
    uint8_t state_of_health_pct;

    /// reg.udral.service.battery.Technology.0.1 technology
    reg_udral_service_battery_Technology_0_1 technology;

    /// uavcan.si.unit.voltage.Scalar.1.0 nominal_voltage
    uavcan_si_unit_voltage_Scalar_1_0 nominal_voltage;

    /// truncated uint40 unix_manufacture_time
    uint64_t unix_manufacture_time;

    /// saturated uint8[<=64] name
    struct  /// Array address equivalence guarantee: &elements[0] == &name
    {
        uint8_t elements[reg_udral_service_battery_Parameters_0_3_name_ARRAY_CAPACITY_];
        size_t count;
    } name;
} reg_udral_service_battery_Parameters_0_3;

/// Serialize an instance into the provided buffer.
/// The lifetime of the resulting serialized representation is independent of the original instance.
/// This method may be slow for large objects (e.g., images, point clouds, radar samples), so in a later revision
/// we may define a zero-copy alternative that keeps references to the original object where possible.
///
/// @param obj      The object to serialize.
///
/// @param buffer   The destination buffer. There are no alignment requirements.
///                 @see reg_udral_service_battery_Parameters_0_3_SERIALIZATION_BUFFER_SIZE_BYTES_
///
/// @param inout_buffer_size_bytes  When calling, this is a pointer to the size of the buffer in bytes.
///                                 Upon return this value will be updated with the size of the constructed serialized
///                                 representation (in bytes); this value is then to be passed over to the transport
///                                 layer. In case of error this value is undefined.
///
/// @returns Negative on error, zero on success.
static inline int8_t reg_udral_service_battery_Parameters_0_3_serialize_(
    const reg_udral_service_battery_Parameters_0_3* const obj, uint8_t* const buffer,  size_t* const inout_buffer_size_bytes)
{
    if ((obj == NULL) || (buffer == NULL) || (inout_buffer_size_bytes == NULL))
    {
        return -NUNAVUT_ERROR_INVALID_ARGUMENT;
    }

    const size_t capacity_bytes = *inout_buffer_size_bytes;
    if ((8U * (size_t) capacity_bytes) < 1024UL)
    {
        return -NUNAVUT_ERROR_SERIALIZATION_BUFFER_TOO_SMALL;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    size_t offset_bits = 0U;

    {   // truncated uint64 unique_id
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 64ULL) <= (capacity_bytes * 8U));
        const int8_t _err0_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, obj->unique_id, 64U);
        if (_err0_ < 0)
        {
            return _err0_;
        }
        offset_bits += 64U;
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

    {   // uavcan.si.unit.mass.Scalar.1.0 mass
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 32ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes0_ = 4UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes0_) <= capacity_bytes);
        int8_t _err2_ = uavcan_si_unit_mass_Scalar_1_0_serialize_(
            &obj->mass, &buffer[offset_bits / 8U], &_size_bytes0_);
        if (_err2_ < 0)
        {
            return _err2_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes0_ * 8U) == 32ULL);
        offset_bits += _size_bytes0_ * 8U;  // Advance by the size of the nested object.
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

    {   // uavcan.si.unit.electric_charge.Scalar.1.0 design_capacity
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 32ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes1_ = 4UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes1_) <= capacity_bytes);
        int8_t _err4_ = uavcan_si_unit_electric_charge_Scalar_1_0_serialize_(
            &obj->design_capacity, &buffer[offset_bits / 8U], &_size_bytes1_);
        if (_err4_ < 0)
        {
            return _err4_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes1_ * 8U) == 32ULL);
        offset_bits += _size_bytes1_ * 8U;  // Advance by the size of the nested object.
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

    {   // uavcan.si.unit.voltage.Scalar.1.0[2] design_cell_voltage_min_max
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 64ULL) <= (capacity_bytes * 8U));
        const size_t _origin0_ = offset_bits;
        for (size_t _index0_ = 0U; _index0_ < 2UL; ++_index0_)
        {
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 32ULL) <= (capacity_bytes * 8U));
            size_t _size_bytes2_ = 4UL;  // Nested object (max) size, in bytes.
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes2_) <= capacity_bytes);
            int8_t _err6_ = uavcan_si_unit_voltage_Scalar_1_0_serialize_(
                &obj->design_cell_voltage_min_max[_index0_], &buffer[offset_bits / 8U], &_size_bytes2_);
            if (_err6_ < 0)
            {
                return _err6_;
            }
            // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
            NUNAVUT_ASSERT((_size_bytes2_ * 8U) == 32ULL);
            offset_bits += _size_bytes2_ * 8U;  // Advance by the size of the nested object.
            NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((offset_bits - _origin0_) == 64ULL);
        (void) _origin0_;
    }

    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad3_ = (uint8_t)(8U - offset_bits % 8U);
        NUNAVUT_ASSERT(_pad3_ > 0);
        const int8_t _err7_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad3_);  // Optimize?
        if (_err7_ < 0)
        {
            return _err7_;
        }
        offset_bits += _pad3_;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    }

    {   // uavcan.si.unit.electric_current.Scalar.1.0 discharge_current
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 32ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes3_ = 4UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes3_) <= capacity_bytes);
        int8_t _err8_ = uavcan_si_unit_electric_current_Scalar_1_0_serialize_(
            &obj->discharge_current, &buffer[offset_bits / 8U], &_size_bytes3_);
        if (_err8_ < 0)
        {
            return _err8_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes3_ * 8U) == 32ULL);
        offset_bits += _size_bytes3_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }

    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad4_ = (uint8_t)(8U - offset_bits % 8U);
        NUNAVUT_ASSERT(_pad4_ > 0);
        const int8_t _err9_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad4_);  // Optimize?
        if (_err9_ < 0)
        {
            return _err9_;
        }
        offset_bits += _pad4_;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    }

    {   // uavcan.si.unit.electric_current.Scalar.1.0 discharge_current_burst
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 32ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes4_ = 4UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes4_) <= capacity_bytes);
        int8_t _err10_ = uavcan_si_unit_electric_current_Scalar_1_0_serialize_(
            &obj->discharge_current_burst, &buffer[offset_bits / 8U], &_size_bytes4_);
        if (_err10_ < 0)
        {
            return _err10_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes4_ * 8U) == 32ULL);
        offset_bits += _size_bytes4_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }

    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad5_ = (uint8_t)(8U - offset_bits % 8U);
        NUNAVUT_ASSERT(_pad5_ > 0);
        const int8_t _err11_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad5_);  // Optimize?
        if (_err11_ < 0)
        {
            return _err11_;
        }
        offset_bits += _pad5_;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    }

    {   // uavcan.si.unit.electric_current.Scalar.1.0 charge_current
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 32ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes5_ = 4UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes5_) <= capacity_bytes);
        int8_t _err12_ = uavcan_si_unit_electric_current_Scalar_1_0_serialize_(
            &obj->charge_current, &buffer[offset_bits / 8U], &_size_bytes5_);
        if (_err12_ < 0)
        {
            return _err12_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes5_ * 8U) == 32ULL);
        offset_bits += _size_bytes5_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }

    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad6_ = (uint8_t)(8U - offset_bits % 8U);
        NUNAVUT_ASSERT(_pad6_ > 0);
        const int8_t _err13_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad6_);  // Optimize?
        if (_err13_ < 0)
        {
            return _err13_;
        }
        offset_bits += _pad6_;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    }

    {   // uavcan.si.unit.electric_current.Scalar.1.0 charge_current_fast
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 32ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes6_ = 4UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes6_) <= capacity_bytes);
        int8_t _err14_ = uavcan_si_unit_electric_current_Scalar_1_0_serialize_(
            &obj->charge_current_fast, &buffer[offset_bits / 8U], &_size_bytes6_);
        if (_err14_ < 0)
        {
            return _err14_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes6_ * 8U) == 32ULL);
        offset_bits += _size_bytes6_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }

    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad7_ = (uint8_t)(8U - offset_bits % 8U);
        NUNAVUT_ASSERT(_pad7_ > 0);
        const int8_t _err15_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad7_);  // Optimize?
        if (_err15_ < 0)
        {
            return _err15_;
        }
        offset_bits += _pad7_;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    }

    {   // uavcan.si.unit.electric_current.Scalar.1.0 charge_termination_threshold
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 32ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes7_ = 4UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes7_) <= capacity_bytes);
        int8_t _err16_ = uavcan_si_unit_electric_current_Scalar_1_0_serialize_(
            &obj->charge_termination_threshold, &buffer[offset_bits / 8U], &_size_bytes7_);
        if (_err16_ < 0)
        {
            return _err16_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes7_ * 8U) == 32ULL);
        offset_bits += _size_bytes7_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }

    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad8_ = (uint8_t)(8U - offset_bits % 8U);
        NUNAVUT_ASSERT(_pad8_ > 0);
        const int8_t _err17_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad8_);  // Optimize?
        if (_err17_ < 0)
        {
            return _err17_;
        }
        offset_bits += _pad8_;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    }

    {   // uavcan.si.unit.voltage.Scalar.1.0 charge_voltage
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 32ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes8_ = 4UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes8_) <= capacity_bytes);
        int8_t _err18_ = uavcan_si_unit_voltage_Scalar_1_0_serialize_(
            &obj->charge_voltage, &buffer[offset_bits / 8U], &_size_bytes8_);
        if (_err18_ < 0)
        {
            return _err18_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes8_ * 8U) == 32ULL);
        offset_bits += _size_bytes8_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }

    {   // saturated uint16 cycle_count
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
        // Saturation code not emitted -- native representation matches the serialized representation.
        const int8_t _err19_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, obj->cycle_count, 16U);
        if (_err19_ < 0)
        {
            return _err19_;
        }
        offset_bits += 16U;
    }

    {   // void8
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 8ULL) <= (capacity_bytes * 8U));
        buffer[offset_bits / 8U] = 0U;
        offset_bits += 8UL;
    }

    {   // saturated uint8 series_cell_count
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 8ULL) <= (capacity_bytes * 8U));
        // Saturation code not emitted -- native representation matches the serialized representation.
        buffer[offset_bits / 8U] = (uint8_t)(obj->series_cell_count);  // C std, 6.3.1.3 Signed and unsigned integers
        offset_bits += 8U;
    }

    {   // saturated uint7 state_of_health_pct
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 7ULL) <= (capacity_bytes * 8U));
        uint8_t _sat0_ = obj->state_of_health_pct;
        if (_sat0_ > 127U)
        {
            _sat0_ = 127U;
        }
        buffer[offset_bits / 8U] = (uint8_t)(_sat0_);  // C std, 6.3.1.3 Signed and unsigned integers
        offset_bits += 7U;
    }

    {   // void1
        NUNAVUT_ASSERT((offset_bits + 1ULL) <= (capacity_bytes * 8U));
        const int8_t _err20_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, 1U);  // Optimize?
        if (_err20_ < 0)
        {
            return _err20_;
        }
        offset_bits += 1UL;
    }

    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad9_ = (uint8_t)(8U - offset_bits % 8U);
        NUNAVUT_ASSERT(_pad9_ > 0);
        const int8_t _err21_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad9_);  // Optimize?
        if (_err21_ < 0)
        {
            return _err21_;
        }
        offset_bits += _pad9_;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    }

    {   // reg.udral.service.battery.Technology.0.1 technology
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 8ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes9_ = 1UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes9_) <= capacity_bytes);
        int8_t _err22_ = reg_udral_service_battery_Technology_0_1_serialize_(
            &obj->technology, &buffer[offset_bits / 8U], &_size_bytes9_);
        if (_err22_ < 0)
        {
            return _err22_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes9_ * 8U) == 8ULL);
        offset_bits += _size_bytes9_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }

    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad10_ = (uint8_t)(8U - offset_bits % 8U);
        NUNAVUT_ASSERT(_pad10_ > 0);
        const int8_t _err23_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad10_);  // Optimize?
        if (_err23_ < 0)
        {
            return _err23_;
        }
        offset_bits += _pad10_;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    }

    {   // uavcan.si.unit.voltage.Scalar.1.0 nominal_voltage
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 32ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes10_ = 4UL;  // Nested object (max) size, in bytes.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes10_) <= capacity_bytes);
        int8_t _err24_ = uavcan_si_unit_voltage_Scalar_1_0_serialize_(
            &obj->nominal_voltage, &buffer[offset_bits / 8U], &_size_bytes10_);
        if (_err24_ < 0)
        {
            return _err24_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes10_ * 8U) == 32ULL);
        offset_bits += _size_bytes10_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }

    {   // truncated uint40 unix_manufacture_time
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 40ULL) <= (capacity_bytes * 8U));
        const int8_t _err25_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, obj->unix_manufacture_time, 40U);
        if (_err25_ < 0)
        {
            return _err25_;
        }
        offset_bits += 40U;
    }

    {   // saturated uint8[<=64] name
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 520ULL) <= (capacity_bytes * 8U));
        if (obj->name.count > 64)
        {
            return -NUNAVUT_ERROR_REPRESENTATION_BAD_ARRAY_LENGTH;
        }
        // Array length prefix: truncated uint8
        buffer[offset_bits / 8U] = (uint8_t)(obj->name.count);  // C std, 6.3.1.3 Signed and unsigned integers
        offset_bits += 8U;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        for (size_t _index1_ = 0U; _index1_ < obj->name.count; ++_index1_)
        {
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            NUNAVUT_ASSERT((offset_bits + 8ULL) <= (capacity_bytes * 8U));
            // Saturation code not emitted -- native representation matches the serialized representation.
            buffer[offset_bits / 8U] = (uint8_t)(obj->name.elements[_index1_]);  // C std, 6.3.1.3 Signed and unsigned integers
            offset_bits += 8U;
        }
    }

    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad11_ = (uint8_t)(8U - offset_bits % 8U);
        NUNAVUT_ASSERT(_pad11_ > 0);
        const int8_t _err26_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad11_);  // Optimize?
        if (_err26_ < 0)
        {
            return _err26_;
        }
        offset_bits += _pad11_;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    }
    // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.

    NUNAVUT_ASSERT(offset_bits >= 512ULL);
    NUNAVUT_ASSERT(offset_bits <= 1024ULL);

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
static inline int8_t reg_udral_service_battery_Parameters_0_3_deserialize_(
    reg_udral_service_battery_Parameters_0_3* const out_obj, const uint8_t* buffer, size_t* const inout_buffer_size_bytes)
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

    // truncated uint64 unique_id
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->unique_id = nunavutGetU64(&buffer[0], capacity_bytes, offset_bits, 64);
    offset_bits += 64U;

    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.

    // uavcan.si.unit.mass.Scalar.1.0 mass
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    {
        size_t _size_bytes11_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        const int8_t _err27_ = uavcan_si_unit_mass_Scalar_1_0_deserialize_(
            &out_obj->mass, &buffer[offset_bits / 8U], &_size_bytes11_);
        if (_err27_ < 0)
        {
            return _err27_;
        }
        offset_bits += _size_bytes11_ * 8U;  // Advance by the size of the nested serialized representation.
    }

    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.

    // uavcan.si.unit.electric_charge.Scalar.1.0 design_capacity
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    {
        size_t _size_bytes12_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        const int8_t _err28_ = uavcan_si_unit_electric_charge_Scalar_1_0_deserialize_(
            &out_obj->design_capacity, &buffer[offset_bits / 8U], &_size_bytes12_);
        if (_err28_ < 0)
        {
            return _err28_;
        }
        offset_bits += _size_bytes12_ * 8U;  // Advance by the size of the nested serialized representation.
    }

    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.

    // uavcan.si.unit.voltage.Scalar.1.0[2] design_cell_voltage_min_max
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    for (size_t _index2_ = 0U; _index2_ < 2UL; ++_index2_)
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        {
            size_t _size_bytes13_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
            NUNAVUT_ASSERT(offset_bits % 8U == 0U);
            const int8_t _err29_ = uavcan_si_unit_voltage_Scalar_1_0_deserialize_(
                &out_obj->design_cell_voltage_min_max[_index2_], &buffer[offset_bits / 8U], &_size_bytes13_);
            if (_err29_ < 0)
            {
                return _err29_;
            }
            offset_bits += _size_bytes13_ * 8U;  // Advance by the size of the nested serialized representation.
        }
    }

    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.

    // uavcan.si.unit.electric_current.Scalar.1.0 discharge_current
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    {
        size_t _size_bytes14_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        const int8_t _err30_ = uavcan_si_unit_electric_current_Scalar_1_0_deserialize_(
            &out_obj->discharge_current, &buffer[offset_bits / 8U], &_size_bytes14_);
        if (_err30_ < 0)
        {
            return _err30_;
        }
        offset_bits += _size_bytes14_ * 8U;  // Advance by the size of the nested serialized representation.
    }

    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.

    // uavcan.si.unit.electric_current.Scalar.1.0 discharge_current_burst
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    {
        size_t _size_bytes15_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        const int8_t _err31_ = uavcan_si_unit_electric_current_Scalar_1_0_deserialize_(
            &out_obj->discharge_current_burst, &buffer[offset_bits / 8U], &_size_bytes15_);
        if (_err31_ < 0)
        {
            return _err31_;
        }
        offset_bits += _size_bytes15_ * 8U;  // Advance by the size of the nested serialized representation.
    }

    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.

    // uavcan.si.unit.electric_current.Scalar.1.0 charge_current
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    {
        size_t _size_bytes16_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        const int8_t _err32_ = uavcan_si_unit_electric_current_Scalar_1_0_deserialize_(
            &out_obj->charge_current, &buffer[offset_bits / 8U], &_size_bytes16_);
        if (_err32_ < 0)
        {
            return _err32_;
        }
        offset_bits += _size_bytes16_ * 8U;  // Advance by the size of the nested serialized representation.
    }

    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.

    // uavcan.si.unit.electric_current.Scalar.1.0 charge_current_fast
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    {
        size_t _size_bytes17_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        const int8_t _err33_ = uavcan_si_unit_electric_current_Scalar_1_0_deserialize_(
            &out_obj->charge_current_fast, &buffer[offset_bits / 8U], &_size_bytes17_);
        if (_err33_ < 0)
        {
            return _err33_;
        }
        offset_bits += _size_bytes17_ * 8U;  // Advance by the size of the nested serialized representation.
    }

    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.

    // uavcan.si.unit.electric_current.Scalar.1.0 charge_termination_threshold
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    {
        size_t _size_bytes18_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        const int8_t _err34_ = uavcan_si_unit_electric_current_Scalar_1_0_deserialize_(
            &out_obj->charge_termination_threshold, &buffer[offset_bits / 8U], &_size_bytes18_);
        if (_err34_ < 0)
        {
            return _err34_;
        }
        offset_bits += _size_bytes18_ * 8U;  // Advance by the size of the nested serialized representation.
    }

    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.

    // uavcan.si.unit.voltage.Scalar.1.0 charge_voltage
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    {
        size_t _size_bytes19_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        const int8_t _err35_ = uavcan_si_unit_voltage_Scalar_1_0_deserialize_(
            &out_obj->charge_voltage, &buffer[offset_bits / 8U], &_size_bytes19_);
        if (_err35_ < 0)
        {
            return _err35_;
        }
        offset_bits += _size_bytes19_ * 8U;  // Advance by the size of the nested serialized representation.
    }

    // saturated uint16 cycle_count
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->cycle_count = nunavutGetU16(&buffer[0], capacity_bytes, offset_bits, 16);
    offset_bits += 16U;

    // void8
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    offset_bits += 8;

    // saturated uint8 series_cell_count
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    if ((offset_bits + 8U) <= capacity_bits)
    {
        out_obj->series_cell_count = buffer[offset_bits / 8U] & 255U;
    }
    else
    {
        out_obj->series_cell_count = 0U;
    }
    offset_bits += 8U;

    // saturated uint7 state_of_health_pct
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    if ((offset_bits + 7U) <= capacity_bits)
    {
        out_obj->state_of_health_pct = buffer[offset_bits / 8U] & 127U;
    }
    else
    {
        out_obj->state_of_health_pct = 0U;
    }
    offset_bits += 7U;

    // void1
    offset_bits += 1;

    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.

    // reg.udral.service.battery.Technology.0.1 technology
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    {
        size_t _size_bytes20_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        const int8_t _err36_ = reg_udral_service_battery_Technology_0_1_deserialize_(
            &out_obj->technology, &buffer[offset_bits / 8U], &_size_bytes20_);
        if (_err36_ < 0)
        {
            return _err36_;
        }
        offset_bits += _size_bytes20_ * 8U;  // Advance by the size of the nested serialized representation.
    }

    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.

    // uavcan.si.unit.voltage.Scalar.1.0 nominal_voltage
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    {
        size_t _size_bytes21_ = (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        const int8_t _err37_ = uavcan_si_unit_voltage_Scalar_1_0_deserialize_(
            &out_obj->nominal_voltage, &buffer[offset_bits / 8U], &_size_bytes21_);
        if (_err37_ < 0)
        {
            return _err37_;
        }
        offset_bits += _size_bytes21_ * 8U;  // Advance by the size of the nested serialized representation.
    }

    // truncated uint40 unix_manufacture_time
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->unix_manufacture_time = nunavutGetU64(&buffer[0], capacity_bytes, offset_bits, 40);
    offset_bits += 40U;

    // saturated uint8[<=64] name
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    // Array length prefix: truncated uint8
    if ((offset_bits + 8U) <= capacity_bits)
    {
        out_obj->name.count = buffer[offset_bits / 8U] & 255U;
    }
    else
    {
        out_obj->name.count = 0U;
    }
    offset_bits += 8U;
    if (out_obj->name.count > 64U)
    {
        return -NUNAVUT_ERROR_REPRESENTATION_BAD_ARRAY_LENGTH;
    }
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    for (size_t _index3_ = 0U; _index3_ < out_obj->name.count; ++_index3_)
    {
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        if ((offset_bits + 8U) <= capacity_bits)
        {
            out_obj->name.elements[_index3_] = buffer[offset_bits / 8U] & 255U;
        }
        else
        {
            out_obj->name.elements[_index3_] = 0U;
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
static inline void reg_udral_service_battery_Parameters_0_3_initialize_(reg_udral_service_battery_Parameters_0_3* const out_obj)
{
    if (out_obj != NULL)
    {
        size_t size_bytes = 0;
        const uint8_t buf = 0;
        const int8_t err = reg_udral_service_battery_Parameters_0_3_deserialize_(out_obj, &buf, &size_bytes);
        NUNAVUT_ASSERT(err >= 0);
        (void) err;
    }
}

#ifdef __cplusplus
}
#endif
#endif // REG_UDRAL_SERVICE_BATTERY_PARAMETERS_0_3_INCLUDED_

