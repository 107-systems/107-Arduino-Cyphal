//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.3.1 (serialization was enabled)
// Source file:   /tmp/zubax_dsdl/zubax/bridge/can/Configuration.1.0.dsdl
// Generated at:  2024-03-22 13:17:28.600849 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     zubax.bridge.can.Configuration
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
//     python_version:  3.10.12
//     python_release_level:  final
//     python_build:  ('main', 'Nov 20 2023 15:14:05')
//     python_compiler:  GCC 11.4.0
//     python_revision:
//     python_xoptions:  {}
//     runtime_platform:  Linux-5.15.0-100-generic-x86_64-with-glibc2.35
// Language Options
//     target_endianness:  any
//     omit_float_serialization_support:  False
//     enable_serialization_asserts:  False
//     enable_override_variable_array_capacity:  False
//     std:  c++17
//     cast_format:  static_cast<{type}>({value})
//     variable_array_type_include:  <vector>
//     variable_array_type_template:  std::vector<{TYPE}>
//     variable_array_type_constructor_args:
//     allocator_include:
//     allocator_type:
//     allocator_is_default_constructible:  True
//     ctor_convention:  default
// Uses Language Features
//     Uses std_variant:yes
#ifndef ZUBAX_BRIDGE_CAN_CONFIGURATION_1_0_HPP_INCLUDED
#define ZUBAX_BRIDGE_CAN_CONFIGURATION_1_0_HPP_INCLUDED

#include <nunavut/support/serialization.hpp>
#include <types/zubax/bridge/can/FilterConfig_1_0.hpp>
#include <types/zubax/bridge/can/PhysicalConfig_1_0.hpp>
#include <cstdint>
#include <limits>
#include <vector>

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
              "/tmp/zubax_dsdl/zubax/bridge/can/Configuration.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/zubax_dsdl/zubax/bridge/can/Configuration.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 0,
              "/tmp/zubax_dsdl/zubax/bridge/can/Configuration.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/zubax_dsdl/zubax/bridge/can/Configuration.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 628873475,
              "/tmp/zubax_dsdl/zubax/bridge/can/Configuration.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/zubax_dsdl/zubax/bridge/can/Configuration.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 3320664631,
              "/tmp/zubax_dsdl/zubax/bridge/can/Configuration.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 4227611599,
              "/tmp/zubax_dsdl/zubax/bridge/can/Configuration.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_constructor_args == 0,
              "/tmp/zubax_dsdl/zubax/bridge/can/Configuration.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::allocator_include == 0,
              "/tmp/zubax_dsdl/zubax/bridge/can/Configuration.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::allocator_type == 0,
              "/tmp/zubax_dsdl/zubax/bridge/can/Configuration.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::allocator_is_default_constructible == 1,
              "/tmp/zubax_dsdl/zubax/bridge/can/Configuration.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::ctor_convention == 3814588639,
              "/tmp/zubax_dsdl/zubax/bridge/can/Configuration.1.0.dsdl "
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
/// Generic CAN adapter configuration message.
/// This is a top-level type in this namespace.
///
/// The adapter configuration interface is designed to be fully idempotent. The "master" (a node that controls the
/// adapter) publishes this configuration message periodically; additional out-of-band ad-hoc messages may be
/// inserted as needed. The controlled adapter(s) subscribes to the configuration messages, and whenever a
/// new message is received, it ensures that its current configuration matches that of the message, otherwise
/// the adapter updates its configuration accordingly. Shall an error occur, it is reported via the Status
/// message asynchronously.
///
/// In this description, "adapter" and "bridge" are used interchangeably. The imperative "open the channel" means
/// that the adapter is to enter the active mode where it is bridging the CAN frames between the CAN bus and this
/// UAVCAN interface; likewise, "close the channel" means the return to the idle state, which is the default state.
///
/// While idle, the adapter is required to avoid any activities on the bus.
///
/// If the channel is already open and the new message commands another non-idle configuration with the
/// same bit rate, the adapter shall establish the new configuration without losing any incoming frames
/// or interrupting the transmission of outgoing frames. Practically, this means that the channel should
/// not be closed while the reconfiguration is in progress. If the new bit rate value is different, the
/// adapter is allowed to close the channel before establishing the new configuration. If the new configuration
/// cannot be applied, the adapter should close the channel and update the result code accordingly.
///
/// The adapter shall be able to process a continuous stream of such messages without any adverse effects on its
/// data throughput. A viable tactic is to check each received message against the current configuration early
/// and drop (ignore) messages which command the configuration that is already established.
///
/// A CAN adapter compatible with this subprotocol will have the following subjects:
///
/// Subscriptions:
///
///   - Outgoing frame subject of type FrameTs.
///     The adapter emits every frame received from this subject to the CAN bus.
///     The timestamp of each frame contains the transmission deadline.
///     If the timestamp is UNKNOWN (zero), the behavior is implementation-defined.
///     Transmission of frames whose deadline is exceeded shall be aborted.
///     The accuracy of deadline tracking is implementation-defined.
///     Technically, the edge case where no deadline tracking is performed at all also fits this requirement
///     (infinitely low accuracy).
///     Unsupported frames (e.g. CAN FD on a classic CAN adapter) shall be dropped and reported via the feedback
///     interface (see the dedicated section).
///     The handling of CAN FD frames where the number of data bytes cannot be represented by a valid DLC value
///     is implementation-defined.
///
///   - Standard time synchronization service uavcan.time.Synchronization. The adapter is a time sync slave.
///     This feature ensures consistent timing information across the system.
///     The behavior of the adapter when the time synchronization data is not available is implementation-defined.
///
/// Publications:
///
///   - Incoming frame and error subject of type FrameTs.
///     Every frame received from the bus is published via this subject; also, this subject carries
///     bus error notifications in the form of a CAN frame message where the frame kind is set to "Error".
///
///   - Feedback frame subject of type FrameTs.
///     Every successfully transmitted frame is republished here with the timestamp value indicating
///     the moment of time when the start bit of the frame was delivered to the bus.
///     Every expired and unsupported frame is also republished here with the timestamp value set to UNKNOWN (zero).
///
///   - Bridge status message of type Status defined in this namespace. Read its description for more info.
///
struct Configuration_1_0 final
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
        static constexpr std::size_t ExtentBytes                  = 600UL;
        static constexpr std::size_t SerializationBufferSizeBytes = 556UL;
        static_assert(ExtentBytes >= SerializationBufferSizeBytes, "Internal constraint violation");
        static_assert(ExtentBytes < (std::numeric_limits<std::size_t>::max() / 8U), "This message is too large to be handled by the selected types");

        struct TypeOf
        {
            TypeOf() = delete;
            using physical_config = zubax::bridge::can::PhysicalConfig_1_0;
            using filter_config = std::vector<zubax::bridge::can::FilterConfig_1_0>;
        };
    };

    // +---------------------------------------------------------------------------------------------------------------+
    // | CONSTANTS
    // +---------------------------------------------------------------------------------------------------------------+

    static constexpr std::uint8_t MAX_FILTERS = 32U;

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+
    ///
    /// Physical layer configuration parameters.
    ///
    _traits_::TypeOf::physical_config physical_config{};
    ///
    /// Empty array instructs the adapter to reject all frames.
    /// This field should be ignored if the physical layer configuration commands the channel to be closed.
    /// Silent mode with an empty filter configuration should not be used; otherwise, the behavior is implementation-
    /// defined.
    /// If the underlying hardware does not implement the required number of filters, the missing filters (or all of
    /// them)
    /// shall be implemented by the adapter's software/firmware.
    ///
    _traits_::TypeOf::filter_config filter_config{};
};

inline nunavut::support::SerializeResult serialize(const Configuration_1_0& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    const std::size_t capacity_bits = out_buffer.size();
    if ((static_cast<std::size_t>(capacity_bits)) < 4448UL)
    {
        return -nunavut::support::Error::SerializationBufferTooSmall;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
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
    {   // void56
        auto _result1_ = out_buffer.setZeros(56UL);
        if(not _result1_){
            return -_result1_.error();
        }
        out_buffer.add_offset(56UL);
    }
    {
        const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
        if(not _result0_){
            return -_result0_.error();
        }
    }
    {   // zubax.bridge.can.FilterConfig.1.0[<=32] filter_config
        if (obj.filter_config.size() > 32)
        {
            return -nunavut::support::Error::SerializationBadArrayLength;
        }
        // Array length prefix: truncated uint8
        const auto _result3_ = out_buffer.setUxx(obj.filter_config.size(), 8U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(8U);
        for (std::size_t _index2_ = 0U; _index2_ < obj.filter_config.size(); ++_index2_)
        {
            std::size_t _size_bytes0_ = 9UL;  // Nested object (max) size, in bytes.
            auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
            if(not _subspan0_){
                return -_subspan0_.error();
            }
            auto _err0_ = serialize(obj.filter_config[_index2_], _subspan0_.value());
            if (not _err0_)
            {
                return _err0_;
            }
            _size_bytes0_ = _err0_.value();
            // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
            out_buffer.add_offset(_size_bytes0_ * 8U);
            //
        }
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

inline nunavut::support::SerializeResult deserialize(Configuration_1_0& obj,
                                                     nunavut::support::const_bitspan in_buffer)
{
    const auto capacity_bits = in_buffer.size();
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
    // void56
    in_buffer.add_offset(56);
    in_buffer.align_offset_to<8U>();
    // zubax.bridge.can.FilterConfig.1.0[<=32] filter_config
    {
        // Array length prefix: truncated uint8
    const std::size_t _size0_ = in_buffer.getU8(8U);
    in_buffer.add_offset(8U);
        if ( _size0_ > 32U)
        {
            return -nunavut::support::Error::SerializationBadArrayLength;
        }
        obj.filter_config.reserve(_size0_);
        for (std::size_t _index5_ = 0U; _index5_ < _size0_; ++_index5_)
        {
            zubax::bridge::can::FilterConfig_1_0 _tmp0_ = zubax::bridge::can::FilterConfig_1_0();
            {
            std::size_t _size_bytes1_ = in_buffer.size() / 8U;
            {
                const auto _err1_ = deserialize(_tmp0_, in_buffer.subspan());
                if(_err1_){
                    _size_bytes1_ = _err1_.value();
                }else{
                    return -_err1_.error();
                }
            }
            in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
        }
            obj.filter_config.push_back(std::move(_tmp0_));
        }
    }
    in_buffer.align_offset_to<8U>();
    auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
    return { static_cast<std::size_t>(_bits_got_ / 8U) };
}

} // namespace can
} // namespace bridge
} // namespace zubax

#endif // ZUBAX_BRIDGE_CAN_CONFIGURATION_1_0_HPP_INCLUDED
