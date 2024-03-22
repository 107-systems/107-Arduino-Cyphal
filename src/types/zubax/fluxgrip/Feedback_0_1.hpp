//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.0.9 (serialization was enabled)
// Source file:   /tmp/zubax_dsdl/zubax/fluxgrip/Feedback.0.1.dsdl
// Generated at:  2024-03-22 12:34:33.145943 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     zubax.fluxgrip.Feedback
// Type Version:  0.1
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
#ifndef ZUBAX_FLUXGRIP_FEEDBACK_0_1_HPP_INCLUDED
#define ZUBAX_FLUXGRIP_FEEDBACK_0_1_HPP_INCLUDED

#include <nunavut/support/serialization.hpp>
#include <array>
#include <cstdint>
#include <limits>

namespace zubax
{
namespace fluxgrip
{
// +-------------------------------------------------------------------------------------------------------------------+
// | LANGUAGE OPTION ASSERTIONS
// |    These static assertions ensure that the header is being used with
// | Nunavut C++ serialization support that is compatible with the language
// | options in effect when that support code was generated.
// +-------------------------------------------------------------------------------------------------------------------+
static_assert( nunavut::support::options::target_endianness == 1693710260,
              "/tmp/zubax_dsdl/zubax/fluxgrip/Feedback.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/zubax_dsdl/zubax/fluxgrip/Feedback.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 0,
              "/tmp/zubax_dsdl/zubax/fluxgrip/Feedback.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/zubax_dsdl/zubax/fluxgrip/Feedback.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 628873475,
              "/tmp/zubax_dsdl/zubax/fluxgrip/Feedback.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/zubax_dsdl/zubax/fluxgrip/Feedback.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/zubax_dsdl/zubax/fluxgrip/Feedback.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/zubax_dsdl/zubax/fluxgrip/Feedback.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/zubax_dsdl/zubax/fluxgrip/Feedback.0.1.dsdl "
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
/// Zubax EPM status feedback message.
/// This type is a structural subtype of uavcan.primitive.scalar.Bit.
///
struct Feedback_0_1 final
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
        static constexpr std::size_t ExtentBytes                  = 63UL;
        static constexpr std::size_t SerializationBufferSizeBytes = 7UL;
        static_assert(ExtentBytes >= SerializationBufferSizeBytes, "Internal constraint violation");
        static_assert(ExtentBytes < (std::numeric_limits<std::size_t>::max() / 8U), "This message is too large to be handled by the selected types");
        struct TypeOf
        {
            TypeOf() = delete;
            using magnetized = bool;
            using remagnetization_state = std::int8_t;
            using cycles_on_off = std::array<std::uint32_t,2>;
        };
    };

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+
    ///
    /// True if the magnet is currently turned on.
    /// The value is a best guess if remagnetization is currently in progress.
    ///
    _traits_::TypeOf::magnetized magnetized{};
    ///
    /// -1 -- the magnet is being demagnetized (turning off).
    ///  0 -- the magnet is idle.
    /// +1 -- the magnet is being magnetized (turning on).
    ///
    _traits_::TypeOf::remagnetization_state remagnetization_state{};
    ///
    /// The number of magnetization and demagnetization cycles commenced, respectively, since the device was powered on.
    /// The values are incremented immediately at the commencement of the cycle.
    ///
    _traits_::TypeOf::cycles_on_off cycles_on_off{};
};

inline nunavut::support::SerializeResult serialize(const Feedback_0_1& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    const std::size_t capacity_bits = out_buffer.size();
    if ((static_cast<std::size_t>(capacity_bits)) < 56UL)
    {
        return -nunavut::support::Error::SerializationBufferTooSmall;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    {   // saturated bool magnetized
        auto _result2_ = out_buffer.setBit(obj.magnetized);
        if(not _result2_){
            return -_result2_.error();
        }
        out_buffer.add_offset(1UL);
    }
    {   // saturated int3 remagnetization_state
        std::int8_t _sat0_ = obj.remagnetization_state;
        if (_sat0_ < -4)
        {
            _sat0_ = -4;
        }
        if (_sat0_ > 3)
        {
            _sat0_ = 3;
        }
        const auto _result3_ = out_buffer.setIxx(_sat0_, 3U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(3U);
    }
    {   // void4
        auto _result1_ = out_buffer.setZeros(4UL);
        if(not _result1_){
            return -_result1_.error();
        }
        out_buffer.add_offset(4UL);
    }
    {   // saturated uint24[2] cycles_on_off
        const std::size_t _origin0_ = out_buffer.offset();
        for (std::size_t _index1_ = 0U; _index1_ < 2UL; ++_index1_)
        {
            std::uint32_t _sat0_ = obj.cycles_on_off[_index1_];
            if (_sat0_ > 16777215UL)
            {
                _sat0_ = 16777215UL;
            }
            const auto _result3_ = out_buffer.setUxx(_sat0_, 24U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(24U);
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        (void) _origin0_;
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

inline nunavut::support::SerializeResult deserialize(Feedback_0_1& obj,
                                                     nunavut::support::const_bitspan in_buffer)
{
    const auto capacity_bits = in_buffer.size();
    // saturated bool magnetized
    obj.magnetized = in_buffer.getBit();
    in_buffer.add_offset(1U);
    // saturated int3 remagnetization_state
    obj.remagnetization_state = in_buffer.getI8(3U);
    in_buffer.add_offset(3U);
    // void4
    in_buffer.add_offset(4);
    // saturated uint24[2] cycles_on_off
    for (std::size_t _index4_ = 0U; _index4_ < 2UL; ++_index4_)
    {
        obj.cycles_on_off[_index4_] = in_buffer.getU32(24U);
        in_buffer.add_offset(24U);
    }
    in_buffer.align_offset_to<8U>();
    auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
    return { static_cast<std::size_t>(_bits_got_ / 8U) };
}

} // namespace fluxgrip
} // namespace zubax

#endif // ZUBAX_FLUXGRIP_FEEDBACK_0_1_HPP_INCLUDED
