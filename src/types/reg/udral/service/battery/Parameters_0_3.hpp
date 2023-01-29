//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.0.0 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/reg/udral/service/battery/Parameters.0.3.dsdl
// Generated at:  2023-01-29 16:46:56.799524 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     reg.udral.service.battery.Parameters
// Type Version:  0.3
// Support
//    Support Namespace: nunavut.lang.cpp.support
//    Support Version:   (1, 0, 0)
// Template Set (package)
//    priority: 0
//    package:  nunavut.lang.cpp.templates
//    version:  (1, 0, 0)
// Platform
//     python_implementation:  CPython
//     python_version:  3.10.6
//     python_release_level:  final
//     python_build:  ('main', 'Nov 14 2022 16:10:14')
//     python_compiler:  GCC 11.3.0
//     python_revision:
//     python_xoptions:  {}
//     runtime_platform:  Linux-5.15.0-58-generic-x86_64-with-glibc2.35
// Language Options
//     target_endianness:  any
//     omit_float_serialization_support:  False
//     enable_serialization_asserts:  True
//     enable_override_variable_array_capacity:  False
//     std:  c++14
//     variable_array_type_template:
//     variable_array_type_include:
//     cast_format:  static_cast<{type}>({value})
//     enable_allocator_support:  False
// Uses Language Features
//     Uses std_variant:no
#ifndef REG_UDRAL_SERVICE_BATTERY_PARAMETERS_0_3_HPP_INCLUDED
#define REG_UDRAL_SERVICE_BATTERY_PARAMETERS_0_3_HPP_INCLUDED

#include <nunavut/support/serialization.hpp>
#include <nunavut/support/variable_length_array.hpp>
#include <types/reg/udral/service/battery/Technology_0_1.hpp>
#include <types/uavcan/si/unit/electric_charge/Scalar_1_0.hpp>
#include <types/uavcan/si/unit/electric_current/Scalar_1_0.hpp>
#include <types/uavcan/si/unit/mass/Scalar_1_0.hpp>
#include <types/uavcan/si/unit/voltage/Scalar_1_0.hpp>
#include <array>
#include <cstdint>

namespace reg
{
namespace udral
{
namespace service
{
namespace battery
{
// +-------------------------------------------------------------------------------------------------------------------+
// | LANGUAGE OPTION ASSERTIONS
// |    These static assertions ensure that the header is being used with
// | Nunavut C++ serialization support that is compatible with the language
// | options in effect when that support code was generated.
// +-------------------------------------------------------------------------------------------------------------------+
static_assert( nunavut::support::options::target_endianness == 1693710260,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/Parameters.0.3.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/Parameters.0.3.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 1,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/Parameters.0.3.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/Parameters.0.3.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 3161622713,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/Parameters.0.3.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/Parameters.0.3.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/Parameters.0.3.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/Parameters.0.3.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/Parameters.0.3.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );

// +-------------------------------------------------------------------------------------------------------------------+
// | This implementation uses a minimal variant implementation that is forward-compatible with the same types generated
// | using the C++17 variant type in the standard library. This minimal variant implementation is limited in the
// | following ways:
// |    1. Supports only emplace and get_if.
// |    2. Only support access by index (see the IndexOf property of the VariantType).
// |    3. This object cannot be copy-constructed nor move-constructed.
// |    4. There is an O(n) lookup in this object's destructor and in the
// |       emplace method.
// |
// | The C++17 version of this object will define the same emplace and get_if wrappers so code written against this
// | version will be fully-forward compatible, but the C++17 version exposes the variant type directly allowing full
// | use of that standard library feature – it is therefore not backwards-compatible.
// +-------------------------------------------------------------------------------------------------------------------+
///
/// Smart battery parameter message. It is mostly intended for automated battery charging and maintenance systems.
/// This message is modeled after the Smart Battery Data Specification (SBS) and the MAVLink battery status messages.
/// The values carried by this message are either constant or slow-changing, so, generally, the publishing frequency
/// should not be higher than 0.2 Hz, and the priority should be either OPTIONAL or SLOW.
/// All parameters are required unless specifically stated otherwise.
/// For non-rechargeable batteries all "charge_*" parameters should be NaN.
///
struct Parameters_0_3 final
{
    // +---------------------------------------------------------------------------------------------------------------+
    // | PORT IDENTIFIERS
    // +---------------------------------------------------------------------------------------------------------------+
    /// This type does not have a fixed port-ID. See https://forum.opencyphal.org/t/choosing-message-and-service-ids/889
    static constexpr bool HasFixedPortID = false;

    static constexpr bool IsServiceType = false;

    /// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
    /// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
    /// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
    /// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
    /// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
    /// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
    /// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.

    static constexpr std::size_t EXTENT_BYTES                    =300UL;
    static constexpr std::size_t SERIALIZATION_BUFFER_SIZE_BYTES =128UL;
    static_assert(EXTENT_BYTES >= SERIALIZATION_BUFFER_SIZE_BYTES, "Internal constraint violation");
    static_assert(EXTENT_BYTES < (std::numeric_limits<std::size_t>::max() /8U), "This message is too large to be handled by current types!");

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+
    ///
    /// A statistically unique number that can be used to identify this exact battery for logging and diagnostic
    /// purposes.
    /// This value should be invariant to the identity of the reporting node unless it is an integral part of the
    /// battery.
    /// If the battery supports SBS, the recommended way to populate this field is from two CRC-32C (Castagnoli) values
    /// as:
    ///   - 32 most significant bits identify the vendor as:   CRC32C(ManufacturerName)
    ///   - 32 least significant bits identify the battery as: CRC32C(DeviceName + ManufactureDate + SerialNumber)
    /// If the battery does not support SBS, the vendor may choose arbitrary random numbers.
    /// Note that these are mere recommendations. The only hard requirement for this field is to be statistically
    /// unique.
    ///
    std::uint64_t unique_id{};
    ///
    /// The total mass of the battery, including the packaging, electronics, cabling, and all auxiliary items, if any.
    /// May be used for predicting the kinematic parameters of the vehicle.
    /// NaN if unknown.
    ///
    uavcan::si::unit::mass::Scalar_1_0 mass;
    ///
    /// The maximum total charge of the pack, at 100% SoH, specified by the manufacturer.
    ///
    uavcan::si::unit::electric_charge::Scalar_1_0 design_capacity;
    ///
    /// The minimum (end of discharge) and the maximum (end of charge) resting cell voltage specified by the
    /// manufacturer
    /// at 100% SoH. Example: {2.8, 4.2} V. These voltages correspond to resting voltages; i.e., the stabilized voltages
    /// after
    /// the discharge/charge has been terminated. Voltage below the min may be observed during discharge due to the
    /// cell's
    /// internal resistance. Voltage above the max voltage may be observed during regenerative braking/charging etc due
    /// to
    /// the cell's internal resistance.
    ///
    std::array<uavcan::si::unit::voltage::Scalar_1_0,2> design_cell_voltage_min_max{};
    ///
    /// Recommended continuous discharge current of the battery.
    ///
    uavcan::si::unit::electric_current::Scalar_1_0 discharge_current;
    ///
    /// Maximum current that may be safely discharged at least for 5 seconds.
    ///
    uavcan::si::unit::electric_current::Scalar_1_0 discharge_current_burst;
    ///
    /// Recommended continuous charge current of the battery.
    ///
    uavcan::si::unit::electric_current::Scalar_1_0 charge_current;
    ///
    /// Recommended safest highest continuous charge current for the battery.
    /// This may cause accelerated aging of the battery.
    ///
    uavcan::si::unit::electric_current::Scalar_1_0 charge_current_fast;
    ///
    /// End-of-charging current threshold. Charging may be terminated when the current falls below this threshold.
    ///
    uavcan::si::unit::electric_current::Scalar_1_0 charge_termination_threshold;
    ///
    /// The total voltage (not per-cell) that may be used by the charger to charge the battery pack.
    ///
    uavcan::si::unit::voltage::Scalar_1_0 charge_voltage;
    ///
    /// The number of charge-discharge cycles. Zero if the battery is new. May increase at runtime.
    /// What constitutes a charge-discharge cycle is implementation-defined.
    ///
    std::uint16_t cycle_count{};
    ///
    /// The number of cells connected in series. This value should match the array of cell voltages reported via Status.
    ///
    std::uint8_t series_cell_count{};
    ///
    /// [percent]
    /// The SoH of the battery, or best guess thereof; ranges from 0 (unusable) to 100 (new).
    ///
    std::uint8_t state_of_health_pct{};
    ///
    /// The battery technology information may be leveraged by the charger to choose the appropriate charging strategy.
    ///
    reg::udral::service::battery::Technology_0_1 technology;
    ///
    /// The nominal voltage of the battery pack (not per-cell) as defined by the vendor.
    /// E.g., a typical 22S LiCoO2 pack would usually report 81.4 V here.
    ///
    uavcan::si::unit::voltage::Scalar_1_0 nominal_voltage;
    ///
    /// The approximate UNIX Epoch time when the battery was manufactured, zero if unknown.
    ///
    std::uint64_t unix_manufacture_time{};
    ///
    /// An arbitrary human-readable textual description of this battery. Empty if unknown/unused.
    /// Batteries that support SBS are recommended to report the manufacturer name and the device name here.
    ///
    nunavut::support::VariableLengthArray<std::uint8_t, 64> name{};

    nunavut::support::SerializeResult
    serialize(nunavut::support::bitspan out_buffer) const
    {
        const std::size_t capacity_bits = out_buffer.size();
        if ((static_cast<std::size_t>(capacity_bits)) < 1024UL)
        {
            return -nunavut::support::Error::SERIALIZATION_BUFFER_TOO_SMALL;
        }
        // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
        // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
        NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
        {   // truncated uint64 unique_id
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(64ULL <= out_buffer.size());
            const auto _result3_ = out_buffer.setUxx(unique_id, 64U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(64U);
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        {   // uavcan.si.unit.mass.Scalar.1.0 mass
            NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(32ULL <= out_buffer.size());
            std::size_t _size_bytes0_ = 4UL;  // Nested object (max) size, in bytes.
            auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
            if(not _subspan0_){
                return -_subspan0_.error();
            }
            NUNAVUT_ASSERT(_subspan0_->offset_alings_to_byte());
            auto _err0_ = mass.serialize(_subspan0_.value());
            if (not _err0_)
            {
                return _err0_;
            }
            _size_bytes0_ = _err0_.value();
            // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
            NUNAVUT_ASSERT((_size_bytes0_ * 8U) == 32ULL);
            out_buffer.add_offset(_size_bytes0_ * 8U);
            // NUNAVUT_ASSERT(out_buffer.size() >= 0);
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        {   // uavcan.si.unit.electric_charge.Scalar.1.0 design_capacity
            NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(32ULL <= out_buffer.size());
            std::size_t _size_bytes0_ = 4UL;  // Nested object (max) size, in bytes.
            auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
            if(not _subspan0_){
                return -_subspan0_.error();
            }
            NUNAVUT_ASSERT(_subspan0_->offset_alings_to_byte());
            auto _err0_ = design_capacity.serialize(_subspan0_.value());
            if (not _err0_)
            {
                return _err0_;
            }
            _size_bytes0_ = _err0_.value();
            // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
            NUNAVUT_ASSERT((_size_bytes0_ * 8U) == 32ULL);
            out_buffer.add_offset(_size_bytes0_ * 8U);
            // NUNAVUT_ASSERT(out_buffer.size() >= 0);
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        {   // uavcan.si.unit.voltage.Scalar.1.0[2] design_cell_voltage_min_max
            NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(64ULL <= out_buffer.size());
            const std::size_t _origin0_ = out_buffer.offset();
            for (size_t _index1_ = 0U; _index1_ < 2UL; ++_index1_)
            {
                NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
                NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
                NUNAVUT_ASSERT(32ULL <= out_buffer.size());
                std::size_t _size_bytes0_ = 4UL;  // Nested object (max) size, in bytes.
                auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
                if(not _subspan0_){
                    return -_subspan0_.error();
                }
                NUNAVUT_ASSERT(_subspan0_->offset_alings_to_byte());
                auto _err0_ = design_cell_voltage_min_max[_index1_].serialize(_subspan0_.value());
                if (not _err0_)
                {
                    return _err0_;
                }
                _size_bytes0_ = _err0_.value();
                // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
                NUNAVUT_ASSERT((_size_bytes0_ * 8U) == 32ULL);
                out_buffer.add_offset(_size_bytes0_ * 8U);
                // NUNAVUT_ASSERT(out_buffer.size() >= 0);
            }
            // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
            NUNAVUT_ASSERT((out_buffer.offset() - _origin0_) == 64ULL);
            (void) _origin0_;
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        {   // uavcan.si.unit.electric_current.Scalar.1.0 discharge_current
            NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(32ULL <= out_buffer.size());
            std::size_t _size_bytes0_ = 4UL;  // Nested object (max) size, in bytes.
            auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
            if(not _subspan0_){
                return -_subspan0_.error();
            }
            NUNAVUT_ASSERT(_subspan0_->offset_alings_to_byte());
            auto _err0_ = discharge_current.serialize(_subspan0_.value());
            if (not _err0_)
            {
                return _err0_;
            }
            _size_bytes0_ = _err0_.value();
            // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
            NUNAVUT_ASSERT((_size_bytes0_ * 8U) == 32ULL);
            out_buffer.add_offset(_size_bytes0_ * 8U);
            // NUNAVUT_ASSERT(out_buffer.size() >= 0);
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        {   // uavcan.si.unit.electric_current.Scalar.1.0 discharge_current_burst
            NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(32ULL <= out_buffer.size());
            std::size_t _size_bytes0_ = 4UL;  // Nested object (max) size, in bytes.
            auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
            if(not _subspan0_){
                return -_subspan0_.error();
            }
            NUNAVUT_ASSERT(_subspan0_->offset_alings_to_byte());
            auto _err0_ = discharge_current_burst.serialize(_subspan0_.value());
            if (not _err0_)
            {
                return _err0_;
            }
            _size_bytes0_ = _err0_.value();
            // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
            NUNAVUT_ASSERT((_size_bytes0_ * 8U) == 32ULL);
            out_buffer.add_offset(_size_bytes0_ * 8U);
            // NUNAVUT_ASSERT(out_buffer.size() >= 0);
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        {   // uavcan.si.unit.electric_current.Scalar.1.0 charge_current
            NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(32ULL <= out_buffer.size());
            std::size_t _size_bytes0_ = 4UL;  // Nested object (max) size, in bytes.
            auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
            if(not _subspan0_){
                return -_subspan0_.error();
            }
            NUNAVUT_ASSERT(_subspan0_->offset_alings_to_byte());
            auto _err0_ = charge_current.serialize(_subspan0_.value());
            if (not _err0_)
            {
                return _err0_;
            }
            _size_bytes0_ = _err0_.value();
            // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
            NUNAVUT_ASSERT((_size_bytes0_ * 8U) == 32ULL);
            out_buffer.add_offset(_size_bytes0_ * 8U);
            // NUNAVUT_ASSERT(out_buffer.size() >= 0);
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        {   // uavcan.si.unit.electric_current.Scalar.1.0 charge_current_fast
            NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(32ULL <= out_buffer.size());
            std::size_t _size_bytes0_ = 4UL;  // Nested object (max) size, in bytes.
            auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
            if(not _subspan0_){
                return -_subspan0_.error();
            }
            NUNAVUT_ASSERT(_subspan0_->offset_alings_to_byte());
            auto _err0_ = charge_current_fast.serialize(_subspan0_.value());
            if (not _err0_)
            {
                return _err0_;
            }
            _size_bytes0_ = _err0_.value();
            // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
            NUNAVUT_ASSERT((_size_bytes0_ * 8U) == 32ULL);
            out_buffer.add_offset(_size_bytes0_ * 8U);
            // NUNAVUT_ASSERT(out_buffer.size() >= 0);
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        {   // uavcan.si.unit.electric_current.Scalar.1.0 charge_termination_threshold
            NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(32ULL <= out_buffer.size());
            std::size_t _size_bytes0_ = 4UL;  // Nested object (max) size, in bytes.
            auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
            if(not _subspan0_){
                return -_subspan0_.error();
            }
            NUNAVUT_ASSERT(_subspan0_->offset_alings_to_byte());
            auto _err0_ = charge_termination_threshold.serialize(_subspan0_.value());
            if (not _err0_)
            {
                return _err0_;
            }
            _size_bytes0_ = _err0_.value();
            // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
            NUNAVUT_ASSERT((_size_bytes0_ * 8U) == 32ULL);
            out_buffer.add_offset(_size_bytes0_ * 8U);
            // NUNAVUT_ASSERT(out_buffer.size() >= 0);
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        {   // uavcan.si.unit.voltage.Scalar.1.0 charge_voltage
            NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(32ULL <= out_buffer.size());
            std::size_t _size_bytes0_ = 4UL;  // Nested object (max) size, in bytes.
            auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
            if(not _subspan0_){
                return -_subspan0_.error();
            }
            NUNAVUT_ASSERT(_subspan0_->offset_alings_to_byte());
            auto _err0_ = charge_voltage.serialize(_subspan0_.value());
            if (not _err0_)
            {
                return _err0_;
            }
            _size_bytes0_ = _err0_.value();
            // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
            NUNAVUT_ASSERT((_size_bytes0_ * 8U) == 32ULL);
            out_buffer.add_offset(_size_bytes0_ * 8U);
            // NUNAVUT_ASSERT(out_buffer.size() >= 0);
        }
        {   // saturated uint16 cycle_count
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(16ULL <= out_buffer.size());
            // Saturation code not emitted -- native representation matches the serialized representation.
            const auto _result3_ = out_buffer.setUxx(cycle_count, 16U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(16U);
        }
        {   // void8
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(8ULL <= out_buffer.size());
            auto _result1_ = out_buffer.setZeros(8UL);
            if(not _result1_){
                return -_result1_.error();
            }
            out_buffer.add_offset(8UL);
        }
        {   // saturated uint8 series_cell_count
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(8ULL <= out_buffer.size());
            // Saturation code not emitted -- native representation matches the serialized representation.
            const auto _result3_ = out_buffer.setUxx(series_cell_count, 8U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(8U);
        }
        {   // saturated uint7 state_of_health_pct
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(7ULL <= out_buffer.size());
            std::uint8_t _sat0_ = state_of_health_pct;
            if (_sat0_ > 127U)
            {
                _sat0_ = 127U;
            }
            const auto _result3_ = out_buffer.setUxx(_sat0_, 7U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(7U);
        }
        {   // void1
            NUNAVUT_ASSERT(1ULL <= out_buffer.size());
            auto _result1_ = out_buffer.setZeros(1UL);
            if(not _result1_){
                return -_result1_.error();
            }
            out_buffer.add_offset(1UL);
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        {   // reg.udral.service.battery.Technology.0.1 technology
            NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(8ULL <= out_buffer.size());
            std::size_t _size_bytes0_ = 1UL;  // Nested object (max) size, in bytes.
            auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
            if(not _subspan0_){
                return -_subspan0_.error();
            }
            NUNAVUT_ASSERT(_subspan0_->offset_alings_to_byte());
            auto _err0_ = technology.serialize(_subspan0_.value());
            if (not _err0_)
            {
                return _err0_;
            }
            _size_bytes0_ = _err0_.value();
            // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
            NUNAVUT_ASSERT((_size_bytes0_ * 8U) == 8ULL);
            out_buffer.add_offset(_size_bytes0_ * 8U);
            // NUNAVUT_ASSERT(out_buffer.size() >= 0);
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        {   // uavcan.si.unit.voltage.Scalar.1.0 nominal_voltage
            NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(32ULL <= out_buffer.size());
            std::size_t _size_bytes0_ = 4UL;  // Nested object (max) size, in bytes.
            auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
            if(not _subspan0_){
                return -_subspan0_.error();
            }
            NUNAVUT_ASSERT(_subspan0_->offset_alings_to_byte());
            auto _err0_ = nominal_voltage.serialize(_subspan0_.value());
            if (not _err0_)
            {
                return _err0_;
            }
            _size_bytes0_ = _err0_.value();
            // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
            NUNAVUT_ASSERT((_size_bytes0_ * 8U) == 32ULL);
            out_buffer.add_offset(_size_bytes0_ * 8U);
            // NUNAVUT_ASSERT(out_buffer.size() >= 0);
        }
        {   // truncated uint40 unix_manufacture_time
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(40ULL <= out_buffer.size());
            const auto _result3_ = out_buffer.setUxx(unix_manufacture_time, 40U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(40U);
        }
        {   // saturated uint8[<=64] name
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(520ULL <= out_buffer.size());
            if (name.size() > 64)
            {
                return -nunavut::support::Error::REPRESENTATION_BAD_ARRAY_LENGTH;
            }
            // Array length prefix: truncated uint8
            const auto _result3_ = out_buffer.setUxx(name.size(), 8U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(8U);
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            for (size_t _index2_ = 0U; _index2_ < name.size(); ++_index2_)
            {
                NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
                NUNAVUT_ASSERT(8ULL <= out_buffer.size());
                // Saturation code not emitted -- native representation matches the serialized representation.
                const auto _result3_ = out_buffer.setUxx(name[_index2_], 8U);
                if(not _result3_){
                    return -_result3_.error();
                }
                out_buffer.add_offset(8U);
            }
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT(out_buffer.offset() >= 512ULL);
        NUNAVUT_ASSERT(out_buffer.offset() <= 1024ULL);
        NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
        return out_buffer.offset_bytes_ceil();
    }

    nunavut::support::SerializeResult
    deserialize(nunavut::support::const_bitspan in_buffer)
    {
        const auto capacity_bits = in_buffer.size();
        // truncated uint64 unique_id
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        unique_id = in_buffer.getU64(64U);
        in_buffer.add_offset(64U);
        in_buffer.align_offset_to<8U>();
        // uavcan.si.unit.mass.Scalar.1.0 mass
        NUNAVUT_ASSERT(in_buffer.offset_alings_to(8U));
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        {
            std::size_t _size_bytes1_ = in_buffer.size() / 8U;
            NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            {
                const auto _err1_ = mass.deserialize(in_buffer.subspan());
                if(_err1_){
                    _size_bytes1_ = _err1_.value();
                }else{
                    return -_err1_.error();
                }
            }
            in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
        }
        in_buffer.align_offset_to<8U>();
        // uavcan.si.unit.electric_charge.Scalar.1.0 design_capacity
        NUNAVUT_ASSERT(in_buffer.offset_alings_to(8U));
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        {
            std::size_t _size_bytes1_ = in_buffer.size() / 8U;
            NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            {
                const auto _err1_ = design_capacity.deserialize(in_buffer.subspan());
                if(_err1_){
                    _size_bytes1_ = _err1_.value();
                }else{
                    return -_err1_.error();
                }
            }
            in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
        }
        in_buffer.align_offset_to<8U>();
        // uavcan.si.unit.voltage.Scalar.1.0[2] design_cell_voltage_min_max
        NUNAVUT_ASSERT(in_buffer.offset_alings_to(8U));
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        for (size_t _index4_ = 0U; _index4_ < 2UL; ++_index4_)
        {
            NUNAVUT_ASSERT(in_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            {
                std::size_t _size_bytes1_ = in_buffer.size() / 8U;
                NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
                {
                    const auto _err1_ = design_cell_voltage_min_max[_index4_].deserialize(in_buffer.subspan());
                    if(_err1_){
                        _size_bytes1_ = _err1_.value();
                    }else{
                        return -_err1_.error();
                    }
                }
                in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
            }
        }
        in_buffer.align_offset_to<8U>();
        // uavcan.si.unit.electric_current.Scalar.1.0 discharge_current
        NUNAVUT_ASSERT(in_buffer.offset_alings_to(8U));
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        {
            std::size_t _size_bytes1_ = in_buffer.size() / 8U;
            NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            {
                const auto _err1_ = discharge_current.deserialize(in_buffer.subspan());
                if(_err1_){
                    _size_bytes1_ = _err1_.value();
                }else{
                    return -_err1_.error();
                }
            }
            in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
        }
        in_buffer.align_offset_to<8U>();
        // uavcan.si.unit.electric_current.Scalar.1.0 discharge_current_burst
        NUNAVUT_ASSERT(in_buffer.offset_alings_to(8U));
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        {
            std::size_t _size_bytes1_ = in_buffer.size() / 8U;
            NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            {
                const auto _err1_ = discharge_current_burst.deserialize(in_buffer.subspan());
                if(_err1_){
                    _size_bytes1_ = _err1_.value();
                }else{
                    return -_err1_.error();
                }
            }
            in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
        }
        in_buffer.align_offset_to<8U>();
        // uavcan.si.unit.electric_current.Scalar.1.0 charge_current
        NUNAVUT_ASSERT(in_buffer.offset_alings_to(8U));
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        {
            std::size_t _size_bytes1_ = in_buffer.size() / 8U;
            NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            {
                const auto _err1_ = charge_current.deserialize(in_buffer.subspan());
                if(_err1_){
                    _size_bytes1_ = _err1_.value();
                }else{
                    return -_err1_.error();
                }
            }
            in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
        }
        in_buffer.align_offset_to<8U>();
        // uavcan.si.unit.electric_current.Scalar.1.0 charge_current_fast
        NUNAVUT_ASSERT(in_buffer.offset_alings_to(8U));
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        {
            std::size_t _size_bytes1_ = in_buffer.size() / 8U;
            NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            {
                const auto _err1_ = charge_current_fast.deserialize(in_buffer.subspan());
                if(_err1_){
                    _size_bytes1_ = _err1_.value();
                }else{
                    return -_err1_.error();
                }
            }
            in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
        }
        in_buffer.align_offset_to<8U>();
        // uavcan.si.unit.electric_current.Scalar.1.0 charge_termination_threshold
        NUNAVUT_ASSERT(in_buffer.offset_alings_to(8U));
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        {
            std::size_t _size_bytes1_ = in_buffer.size() / 8U;
            NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            {
                const auto _err1_ = charge_termination_threshold.deserialize(in_buffer.subspan());
                if(_err1_){
                    _size_bytes1_ = _err1_.value();
                }else{
                    return -_err1_.error();
                }
            }
            in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
        }
        in_buffer.align_offset_to<8U>();
        // uavcan.si.unit.voltage.Scalar.1.0 charge_voltage
        NUNAVUT_ASSERT(in_buffer.offset_alings_to(8U));
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        {
            std::size_t _size_bytes1_ = in_buffer.size() / 8U;
            NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            {
                const auto _err1_ = charge_voltage.deserialize(in_buffer.subspan());
                if(_err1_){
                    _size_bytes1_ = _err1_.value();
                }else{
                    return -_err1_.error();
                }
            }
            in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
        }
        // saturated uint16 cycle_count
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        cycle_count = in_buffer.getU16(16U);
        in_buffer.add_offset(16U);
        // void8
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        in_buffer.add_offset(8);
        // saturated uint8 series_cell_count
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        series_cell_count = in_buffer.getU8(8U);
        in_buffer.add_offset(8U);
        // saturated uint7 state_of_health_pct
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        state_of_health_pct = in_buffer.getU8(7U);
        in_buffer.add_offset(7U);
        // void1
        in_buffer.add_offset(1);
        in_buffer.align_offset_to<8U>();
        // reg.udral.service.battery.Technology.0.1 technology
        NUNAVUT_ASSERT(in_buffer.offset_alings_to(8U));
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        {
            std::size_t _size_bytes1_ = in_buffer.size() / 8U;
            NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            {
                const auto _err1_ = technology.deserialize(in_buffer.subspan());
                if(_err1_){
                    _size_bytes1_ = _err1_.value();
                }else{
                    return -_err1_.error();
                }
            }
            in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
        }
        in_buffer.align_offset_to<8U>();
        // uavcan.si.unit.voltage.Scalar.1.0 nominal_voltage
        NUNAVUT_ASSERT(in_buffer.offset_alings_to(8U));
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        {
            std::size_t _size_bytes1_ = in_buffer.size() / 8U;
            NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            {
                const auto _err1_ = nominal_voltage.deserialize(in_buffer.subspan());
                if(_err1_){
                    _size_bytes1_ = _err1_.value();
                }else{
                    return -_err1_.error();
                }
            }
            in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
        }
        // truncated uint40 unix_manufacture_time
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        unix_manufacture_time = in_buffer.getU64(40U);
        in_buffer.add_offset(40U);
        // saturated uint8[<=64] name
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        {
            // Array length prefix: truncated uint8
        const std::uint8_t _size0_ = in_buffer.getU8(8U);
        in_buffer.add_offset(8U);
            if ( _size0_ > 64U)
            {
                return -nunavut::support::Error::REPRESENTATION_BAD_ARRAY_LENGTH;
            }
            name.reserve(_size0_);
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            for (size_t _index5_ = 0U; _index5_ < _size0_; ++_index5_)
            {
                // TODO This is terribly inefficient. We need to completely refactor this template to use C++ emplace and
                // move semantics instead of assuming C-style containers
                name.push_back();
                NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            name[_index5_] = in_buffer.getU8(8U);
            in_buffer.add_offset(8U);
            }
        }
        in_buffer.align_offset_to<8U>();
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
        NUNAVUT_ASSERT(capacity_bits >= _bits_got_);
        return { static_cast<std::size_t>(_bits_got_ / 8U) };
    }
};

} // namespace battery
} // namespace service
} // namespace udral
} // namespace reg

#endif // REG_UDRAL_SERVICE_BATTERY_PARAMETERS_0_3_HPP_INCLUDED
