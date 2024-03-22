//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.0.9 (serialization was enabled)
// Source file:   /tmp/zubax_dsdl/zubax/bridge/can/FrameCounters.1.0.dsdl
// Generated at:  2024-03-22 12:34:33.175269 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     zubax.bridge.can.FrameCounters
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
#ifndef ZUBAX_BRIDGE_CAN_FRAME_COUNTERS_1_0_HPP_INCLUDED
#define ZUBAX_BRIDGE_CAN_FRAME_COUNTERS_1_0_HPP_INCLUDED

#include <nunavut/support/serialization.hpp>
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
              "/tmp/zubax_dsdl/zubax/bridge/can/FrameCounters.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/zubax_dsdl/zubax/bridge/can/FrameCounters.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 0,
              "/tmp/zubax_dsdl/zubax/bridge/can/FrameCounters.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/zubax_dsdl/zubax/bridge/can/FrameCounters.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 628873475,
              "/tmp/zubax_dsdl/zubax/bridge/can/FrameCounters.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/zubax_dsdl/zubax/bridge/can/FrameCounters.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/zubax_dsdl/zubax/bridge/can/FrameCounters.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/zubax_dsdl/zubax/bridge/can/FrameCounters.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/zubax_dsdl/zubax/bridge/can/FrameCounters.1.0.dsdl "
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
/// CAN frame statistics.
///
struct FrameCounters_1_0 final
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
        static constexpr std::size_t ExtentBytes                  = 48UL;
        static constexpr std::size_t SerializationBufferSizeBytes = 48UL;
        static_assert(ExtentBytes >= SerializationBufferSizeBytes, "Internal constraint violation");
        static_assert(ExtentBytes < (std::numeric_limits<std::size_t>::max() / 8U), "This message is too large to be handled by the selected types");
        struct TypeOf
        {
            TypeOf() = delete;
            using in_success = std::uint64_t;
            using in_overrun = std::uint64_t;
            using out_success = std::uint64_t;
            using out_expired = std::uint64_t;
            using out_overrun = std::uint64_t;
            using out_unsupported = std::uint64_t;
        };
    };

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+
    ///
    /// Valid CAN frames received from the bus (data or RTR).
    ///
    _traits_::TypeOf::in_success in_success{};
    ///
    /// Received frames that had to be dropped due to buffer overruns.
    ///
    _traits_::TypeOf::in_overrun in_overrun{};
    ///
    /// CAN frames successfully emitted onto the bus before the deadline has expired.
    ///
    _traits_::TypeOf::out_success out_success{};
    ///
    /// CAN frames that could not be transmitted before the deadline and have been aborted.
    ///
    _traits_::TypeOf::out_expired out_expired{};
    ///
    /// Outgoing frames that had to be dropped due to buffer overruns.
    ///
    _traits_::TypeOf::out_overrun out_overrun{};
    ///
    /// Frames that could not be transmitted because they are not supported by the hardware.
    ///
    _traits_::TypeOf::out_unsupported out_unsupported{};
};

inline nunavut::support::SerializeResult serialize(const FrameCounters_1_0& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    const std::size_t capacity_bits = out_buffer.size();
    if ((static_cast<std::size_t>(capacity_bits)) < 384UL)
    {
        return -nunavut::support::Error::SerializationBufferTooSmall;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    {   // saturated uint48 in_success
        std::uint64_t _sat0_ = obj.in_success;
        if (_sat0_ > 281474976710655ULL)
        {
            _sat0_ = 281474976710655ULL;
        }
        const auto _result3_ = out_buffer.setUxx(_sat0_, 48U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(48U);
    }
    {   // saturated uint48 in_overrun
        std::uint64_t _sat0_ = obj.in_overrun;
        if (_sat0_ > 281474976710655ULL)
        {
            _sat0_ = 281474976710655ULL;
        }
        const auto _result3_ = out_buffer.setUxx(_sat0_, 48U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(48U);
    }
    {   // void48
        auto _result1_ = out_buffer.setZeros(48UL);
        if(not _result1_){
            return -_result1_.error();
        }
        out_buffer.add_offset(48UL);
    }
    {   // saturated uint48 out_success
        std::uint64_t _sat0_ = obj.out_success;
        if (_sat0_ > 281474976710655ULL)
        {
            _sat0_ = 281474976710655ULL;
        }
        const auto _result3_ = out_buffer.setUxx(_sat0_, 48U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(48U);
    }
    {   // saturated uint48 out_expired
        std::uint64_t _sat0_ = obj.out_expired;
        if (_sat0_ > 281474976710655ULL)
        {
            _sat0_ = 281474976710655ULL;
        }
        const auto _result3_ = out_buffer.setUxx(_sat0_, 48U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(48U);
    }
    {   // saturated uint48 out_overrun
        std::uint64_t _sat0_ = obj.out_overrun;
        if (_sat0_ > 281474976710655ULL)
        {
            _sat0_ = 281474976710655ULL;
        }
        const auto _result3_ = out_buffer.setUxx(_sat0_, 48U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(48U);
    }
    {   // saturated uint48 out_unsupported
        std::uint64_t _sat0_ = obj.out_unsupported;
        if (_sat0_ > 281474976710655ULL)
        {
            _sat0_ = 281474976710655ULL;
        }
        const auto _result3_ = out_buffer.setUxx(_sat0_, 48U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(48U);
    }
    {   // void48
        auto _result1_ = out_buffer.setZeros(48UL);
        if(not _result1_){
            return -_result1_.error();
        }
        out_buffer.add_offset(48UL);
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

inline nunavut::support::SerializeResult deserialize(FrameCounters_1_0& obj,
                                                     nunavut::support::const_bitspan in_buffer)
{
    const auto capacity_bits = in_buffer.size();
    // saturated uint48 in_success
    obj.in_success = in_buffer.getU64(48U);
    in_buffer.add_offset(48U);
    // saturated uint48 in_overrun
    obj.in_overrun = in_buffer.getU64(48U);
    in_buffer.add_offset(48U);
    // void48
    in_buffer.add_offset(48);
    // saturated uint48 out_success
    obj.out_success = in_buffer.getU64(48U);
    in_buffer.add_offset(48U);
    // saturated uint48 out_expired
    obj.out_expired = in_buffer.getU64(48U);
    in_buffer.add_offset(48U);
    // saturated uint48 out_overrun
    obj.out_overrun = in_buffer.getU64(48U);
    in_buffer.add_offset(48U);
    // saturated uint48 out_unsupported
    obj.out_unsupported = in_buffer.getU64(48U);
    in_buffer.add_offset(48U);
    // void48
    in_buffer.add_offset(48);
    in_buffer.align_offset_to<8U>();
    auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
    return { static_cast<std::size_t>(_bits_got_ / 8U) };
}

} // namespace can
} // namespace bridge
} // namespace zubax

#endif // ZUBAX_BRIDGE_CAN_FRAME_COUNTERS_1_0_HPP_INCLUDED
