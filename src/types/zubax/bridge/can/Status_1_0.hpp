//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.0.9 (serialization was enabled)
// Source file:   /tmp/zubax_dsdl/zubax/bridge/can/Status.1.0.dsdl
// Generated at:  2024-03-22 12:34:33.187807 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     zubax.bridge.can.Status
// Type Version:  1.0
// Support
//    Support Namespace: nunavut.lang.cpp.support
//    Support Version:   (1, 0, 0)
// Template Set (package)
//    priority: 0
//    package:  nunavut.lang.cpp.templates
//    version:  (1, 0, 0)
// Platform
//     python_implementation:  CPython
//     python_version:  3.8.10
//     python_release_level:  final
//     python_build:  ('default', 'Nov 22 2023 10:22:35')
//     python_compiler:  GCC 9.4.0
//     python_revision:
//     python_xoptions:  {}
//     runtime_platform:  Linux-5.15.0-100-generic-x86_64-with-glibc2.29
// Language Options
//     target_endianness:  any
//     omit_float_serialization_support:  False
//     enable_serialization_asserts:  False
//     enable_override_variable_array_capacity:  False
//     std:  c++17
//     variable_array_type_template:
//     variable_array_type_include:
//     cast_format:  static_cast<{type}>({value})
//     enable_allocator_support:  False
// Uses Language Features
//     Uses std_variant:yes
#ifndef ZUBAX_BRIDGE_CAN_STATUS_1_0_HPP_INCLUDED
#define ZUBAX_BRIDGE_CAN_STATUS_1_0_HPP_INCLUDED

#include <nunavut/support/serialization.hpp>
#include <types/uavcan/time/SynchronizedTimestamp_1_0.hpp>
#include <types/zubax/bridge/can/BusErrorCounters_1_0.hpp>
#include <types/zubax/bridge/can/ConfigResult_1_0.hpp>
#include <types/zubax/bridge/can/FaultConfinementStatus_1_0.hpp>
#include <types/zubax/bridge/can/FrameCounters_1_0.hpp>
#include <types/zubax/bridge/can/PhysicalConfig_1_0.hpp>
#include <cstdint>
#include <limits>

namespace zubax
{
namespace bridge
{
namespace can
{
// +-------------------------------------------------------------------------------------------------------------------+
// | LANGUAGE OPTION ASSERTIONS
// |    These static assertions ensure that the header is being used with
// | Nunavut C++ serialization support that is compatible with the language
// | options in effect when that support code was generated.
// +-------------------------------------------------------------------------------------------------------------------+
static_assert( nunavut::support::options::target_endianness == 1693710260,
              "/tmp/zubax_dsdl/zubax/bridge/can/Status.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/zubax_dsdl/zubax/bridge/can/Status.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 0,
              "/tmp/zubax_dsdl/zubax/bridge/can/Status.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/zubax_dsdl/zubax/bridge/can/Status.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 628873475,
              "/tmp/zubax_dsdl/zubax/bridge/can/Status.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/zubax_dsdl/zubax/bridge/can/Status.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/zubax_dsdl/zubax/bridge/can/Status.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/zubax_dsdl/zubax/bridge/can/Status.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/zubax_dsdl/zubax/bridge/can/Status.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );

// +-------------------------------------------------------------------------------------------------------------------+
// | This implementation uses the C++17 standard library variant type with wrappers for the emplace and
// | get_if methods to support forward-compatibility with the C++14 version of this object. The union_value type
// | extends std::variant and can be used with the entire set of variant methods. Using std::variant directly does mean
// | your code will not be backwards compatible with the C++14 version of this object.
// +-------------------------------------------------------------------------------------------------------------------+
///
/// Generic CAN adapter status message.
/// This is a top-level type in this namespace.
///
/// This message is to be published periodically; the recommended frequency is 1 Hz or higher.
/// It is recommended to additionally publish this message out-of-band (perhaps at a lower priority value)
/// immediately after each reconfiguration.
///
struct Status_1_0 final
{
    struct _traits_  // The name is surrounded with underscores to avoid collisions with DSDL attributes.
    {
        _traits_() = delete;
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
        static constexpr std::size_t ExtentBytes                  = 512UL;
        static constexpr std::size_t SerializationBufferSizeBytes = 367UL;
        static_assert(ExtentBytes >= SerializationBufferSizeBytes, "Internal constraint violation");
        static_assert(ExtentBytes < (std::numeric_limits<std::size_t>::max() / 8U), "This message is too large to be handled by the selected types");
        struct TypeOf
        {
            TypeOf() = delete;
            using timestamp = uavcan::time::SynchronizedTimestamp_1_0;
            using fault_confinement_status = zubax::bridge::can::FaultConfinementStatus_1_0;
            using frame_counters = zubax::bridge::can::FrameCounters_1_0;
            using bus_error_counters = zubax::bridge::can::BusErrorCounters_1_0;
            using reconfiguration_count = std::uint32_t;
            using bus_load_percent = std::uint8_t;
            using bus_load_contributed_percent = std::uint8_t;
            using physical_config = zubax::bridge::can::PhysicalConfig_1_0;
            using config_result = zubax::bridge::can::ConfigResult_1_0;
        };
    };

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+
    ///
    /// This is intended for adapter diagnostics. If the time is not synchronized, this value should be UNKNOWN (zero).
    ///
    _traits_::TypeOf::timestamp timestamp;
    ///
    /// The error state per the CAN specification obtained directly from the CAN controller hardware.
    ///
    _traits_::TypeOf::fault_confinement_status fault_confinement_status;

    _traits_::TypeOf::frame_counters frame_counters;
    ///
    /// The counters shall be reset back to zero when the channel is opened.
    ///
    _traits_::TypeOf::bus_error_counters bus_error_counters;
    ///
    /// Incremented by one whenever the adapter receives a new configuration message where the commanded
    /// configuration is different from the current configuration. Never reset while the adapter is running.
    ///
    _traits_::TypeOf::reconfiguration_count reconfiguration_count{};

    _traits_::TypeOf::bus_load_percent bus_load_percent{};

    _traits_::TypeOf::bus_load_contributed_percent bus_load_contributed_percent{};
    ///
    /// Physical layer configuration parameters.
    /// These are not the commanded values but the actual properties configured by the adapter.
    /// For example, if the requested sample point location is 80% but the adapter could only configure 83%,
    /// the latter value will be reported here.
    ///
    _traits_::TypeOf::physical_config physical_config;
    ///
    /// The result of the last reconfiguration.
    /// Normally, if the channel is open, the result should be SUCCESS, since the channel should be closed
    /// on bad configuration.
    /// If the channel has been commanded to be closed, the result would be SUCCESS, since closing can't fail.
    ///
    _traits_::TypeOf::config_result config_result;
};

inline nunavut::support::SerializeResult serialize(const Status_1_0& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    const std::size_t capacity_bits = out_buffer.size();
    if ((static_cast<std::size_t>(capacity_bits)) < 2936UL)
    {
        return -nunavut::support::Error::SerializationBufferTooSmall;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    {   // uavcan.time.SynchronizedTimestamp.1.0 timestamp
        std::size_t _size_bytes0_ = 7UL;  // Nested object (max) size, in bytes.
        auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize(obj.timestamp, _subspan0_.value());
        if (not _err0_)
        {
            return _err0_;
        }
        _size_bytes0_ = _err0_.value();
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        out_buffer.add_offset(_size_bytes0_ * 8U);
        //
    }
    {
        const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
        if(not _result0_){
            return -_result0_.error();
        }
    }
    {   // zubax.bridge.can.FaultConfinementStatus.1.0 fault_confinement_status
        std::size_t _size_bytes0_ = 7UL;  // Nested object (max) size, in bytes.
        auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize(obj.fault_confinement_status, _subspan0_.value());
        if (not _err0_)
        {
            return _err0_;
        }
        _size_bytes0_ = _err0_.value();
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        out_buffer.add_offset(_size_bytes0_ * 8U);
        //
    }
    {
        const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
        if(not _result0_){
            return -_result0_.error();
        }
    }
    {   // zubax.bridge.can.FrameCounters.1.0 frame_counters
        std::size_t _size_bytes0_ = 48UL;  // Nested object (max) size, in bytes.
        auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize(obj.frame_counters, _subspan0_.value());
        if (not _err0_)
        {
            return _err0_;
        }
        _size_bytes0_ = _err0_.value();
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        out_buffer.add_offset(_size_bytes0_ * 8U);
        //
    }
    {
        const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
        if(not _result0_){
            return -_result0_.error();
        }
    }
    {   // zubax.bridge.can.BusErrorCounters.1.0 bus_error_counters
        std::size_t _size_bytes0_ = 36UL;  // Nested object (max) size, in bytes.
        auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize(obj.bus_error_counters, _subspan0_.value());
        if (not _err0_)
        {
            return _err0_;
        }
        _size_bytes0_ = _err0_.value();
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        out_buffer.add_offset(_size_bytes0_ * 8U);
        //
    }
    {   // saturated uint32 reconfiguration_count
        // Saturation code not emitted -- native representation matches the serialized representation.
        const auto _result3_ = out_buffer.setUxx(obj.reconfiguration_count, 32U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(32U);
    }
    {   // saturated uint7 bus_load_percent
        std::uint8_t _sat0_ = obj.bus_load_percent;
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
        auto _result1_ = out_buffer.setZeros(1UL);
        if(not _result1_){
            return -_result1_.error();
        }
        out_buffer.add_offset(1UL);
    }
    {   // saturated uint7 bus_load_contributed_percent
        std::uint8_t _sat0_ = obj.bus_load_contributed_percent;
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
    {   // zubax.bridge.can.PhysicalConfig.1.0 physical_config
        std::size_t _size_bytes0_ = 9UL;  // Nested object (max) size, in bytes.
        // Reserve space for the delimiter header.
        auto _subspan0_ = out_buffer.subspan(32U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize(obj.physical_config, _subspan0_.value());
        if (not _err0_)
        {
            return _err0_;
        }
        _size_bytes0_ = _err0_.value();
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        // Jump back to write the delimiter header after the nested object is serialized and its length is known.
        const auto _result3_ = out_buffer.setUxx(_size_bytes0_, 32U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(32U);
        out_buffer.add_offset(_size_bytes0_ * 8U);
        //
    }
    {   // void16
        auto _result1_ = out_buffer.setZeros(16UL);
        if(not _result1_){
            return -_result1_.error();
        }
        out_buffer.add_offset(16UL);
    }
    {
        const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
        if(not _result0_){
            return -_result0_.error();
        }
    }
    {   // zubax.bridge.can.ConfigResult.1.0 config_result
        std::size_t _size_bytes0_ = 1UL;  // Nested object (max) size, in bytes.
        auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize(obj.config_result, _subspan0_.value());
        if (not _err0_)
        {
            return _err0_;
        }
        _size_bytes0_ = _err0_.value();
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        out_buffer.add_offset(_size_bytes0_ * 8U);
        //
    }
    {
        const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
        if(not _result0_){
            return -_result0_.error();
        }
    }
    // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
    return out_buffer.offset_bytes_ceil();
}

inline nunavut::support::SerializeResult deserialize(Status_1_0& obj,
                                                     nunavut::support::const_bitspan in_buffer)
{
    const auto capacity_bits = in_buffer.size();
    // uavcan.time.SynchronizedTimestamp.1.0 timestamp
    {
        std::size_t _size_bytes1_ = in_buffer.size() / 8U;
        {
            const auto _err1_ = deserialize(obj.timestamp, in_buffer.subspan());
            if(_err1_){
                _size_bytes1_ = _err1_.value();
            }else{
                return -_err1_.error();
            }
        }
        in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
    }
    in_buffer.align_offset_to<8U>();
    // zubax.bridge.can.FaultConfinementStatus.1.0 fault_confinement_status
    {
        std::size_t _size_bytes1_ = in_buffer.size() / 8U;
        {
            const auto _err1_ = deserialize(obj.fault_confinement_status, in_buffer.subspan());
            if(_err1_){
                _size_bytes1_ = _err1_.value();
            }else{
                return -_err1_.error();
            }
        }
        in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
    }
    in_buffer.align_offset_to<8U>();
    // zubax.bridge.can.FrameCounters.1.0 frame_counters
    {
        std::size_t _size_bytes1_ = in_buffer.size() / 8U;
        {
            const auto _err1_ = deserialize(obj.frame_counters, in_buffer.subspan());
            if(_err1_){
                _size_bytes1_ = _err1_.value();
            }else{
                return -_err1_.error();
            }
        }
        in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
    }
    in_buffer.align_offset_to<8U>();
    // zubax.bridge.can.BusErrorCounters.1.0 bus_error_counters
    {
        std::size_t _size_bytes1_ = in_buffer.size() / 8U;
        {
            const auto _err1_ = deserialize(obj.bus_error_counters, in_buffer.subspan());
            if(_err1_){
                _size_bytes1_ = _err1_.value();
            }else{
                return -_err1_.error();
            }
        }
        in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
    }
    // saturated uint32 reconfiguration_count
    obj.reconfiguration_count = in_buffer.getU32(32U);
    in_buffer.add_offset(32U);
    // saturated uint7 bus_load_percent
    obj.bus_load_percent = in_buffer.getU8(7U);
    in_buffer.add_offset(7U);
    // void1
    in_buffer.add_offset(1);
    // saturated uint7 bus_load_contributed_percent
    obj.bus_load_contributed_percent = in_buffer.getU8(7U);
    in_buffer.add_offset(7U);
    // void1
    in_buffer.add_offset(1);
    in_buffer.align_offset_to<8U>();
    // zubax.bridge.can.PhysicalConfig.1.0 physical_config
    {
        std::size_t _size_bytes1_ = in_buffer.size() / 8U;
        // Delimiter header: truncated uint32
        _size_bytes1_ = in_buffer.getU32(32U);
        in_buffer.add_offset(32U);
        if ((_size_bytes1_ * 8U) > in_buffer.size())
        {
            return -nunavut::support::Error::RepresentationBadDelimiterHeader;
        }
        const std::size_t _dh0_ = _size_bytes1_;
        {
            const auto _err1_ = deserialize(obj.physical_config, in_buffer.subspan());
            if(_err1_){
                _size_bytes1_ = _err1_.value();
            }else{
                return -_err1_.error();
            }
        }
        // Advance the offset by the size of the delimiter header, even if the nested deserialization routine
        // consumed fewer bytes of data. This behavior implements the implicit truncation rule for nested objects.
        in_buffer.add_offset(_dh0_ * 8U);
    }
    // void16
    in_buffer.add_offset(16);
    in_buffer.align_offset_to<8U>();
    // zubax.bridge.can.ConfigResult.1.0 config_result
    {
        std::size_t _size_bytes1_ = in_buffer.size() / 8U;
        {
            const auto _err1_ = deserialize(obj.config_result, in_buffer.subspan());
            if(_err1_){
                _size_bytes1_ = _err1_.value();
            }else{
                return -_err1_.error();
            }
        }
        in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
    }
    in_buffer.align_offset_to<8U>();
    auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
    return { static_cast<std::size_t>(_bits_got_ / 8U) };
}

} // namespace can
} // namespace bridge
} // namespace zubax

#endif // ZUBAX_BRIDGE_CAN_STATUS_1_0_HPP_INCLUDED
