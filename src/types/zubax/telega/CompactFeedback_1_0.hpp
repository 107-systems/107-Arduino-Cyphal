//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.3.1 (serialization was enabled)
// Source file:   /tmp/zubax_dsdl/zubax/telega/CompactFeedback.1.0.dsdl
// Generated at:  2024-03-22 13:17:28.689465 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     zubax.telega.CompactFeedback
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
#ifndef ZUBAX_TELEGA_COMPACT_FEEDBACK_1_0_HPP_INCLUDED
#define ZUBAX_TELEGA_COMPACT_FEEDBACK_1_0_HPP_INCLUDED

#include <nunavut/support/serialization.hpp>
#include <cstdint>
#include <limits>

namespace zubax
{
namespace telega
{
// +-------------------------------------------------------------------------------------------------------------------+
// | LANGUAGE OPTION ASSERTIONS
// |    These static assertions ensure that the header is being used with
// | Nunavut C++ serialization support that is compatible with the language
// | options in effect when that support code was generated.
// +-------------------------------------------------------------------------------------------------------------------+
static_assert( nunavut::support::options::target_endianness == 1693710260,
              "/tmp/zubax_dsdl/zubax/telega/CompactFeedback.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/zubax_dsdl/zubax/telega/CompactFeedback.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 0,
              "/tmp/zubax_dsdl/zubax/telega/CompactFeedback.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/zubax_dsdl/zubax/telega/CompactFeedback.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 628873475,
              "/tmp/zubax_dsdl/zubax/telega/CompactFeedback.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/zubax_dsdl/zubax/telega/CompactFeedback.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 3320664631,
              "/tmp/zubax_dsdl/zubax/telega/CompactFeedback.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 4227611599,
              "/tmp/zubax_dsdl/zubax/telega/CompactFeedback.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_constructor_args == 0,
              "/tmp/zubax_dsdl/zubax/telega/CompactFeedback.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::allocator_include == 0,
              "/tmp/zubax_dsdl/zubax/telega/CompactFeedback.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::allocator_type == 0,
              "/tmp/zubax_dsdl/zubax/telega/CompactFeedback.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::allocator_is_default_constructible == 1,
              "/tmp/zubax_dsdl/zubax/telega/CompactFeedback.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::ctor_convention == 3814588639,
              "/tmp/zubax_dsdl/zubax/telega/CompactFeedback.1.0.dsdl "
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
/// This message is designed to provide low-resolution but high-frequency feedback from the ESC using very low
/// bandwidth.
///
struct CompactFeedback_1_0 final
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
            using dc_voltage = std::uint16_t;
            using dc_current = std::int16_t;
            using phase_current_amplitude = std::int16_t;
            using velocity = std::int16_t;
            using demand_factor_pct = std::int8_t;
        };
    };

    // +---------------------------------------------------------------------------------------------------------------+
    // | CONSTANTS
    // +---------------------------------------------------------------------------------------------------------------+

    static constexpr float AMPERE_PER_LSB = static_cast<float>((1.0 / 5.0));

    static constexpr float VOLT_PER_LSB = static_cast<float>((1.0 / 5.0));

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+
    ///
    /// [    0,+2047] * 0.2 = [     0,+409.4] volt
    ///
    _traits_::TypeOf::dc_voltage dc_voltage{};
    ///
    /// [-2048,+2047] * 0.2 = [-409.6,+409.4] ampere
    ///
    _traits_::TypeOf::dc_current dc_current{};
    ///
    /// ditto
    ///
    _traits_::TypeOf::phase_current_amplitude phase_current_amplitude{};
    ///
    /// [-4096,+4095] radian/second (approx. [-39114,+39104] RPM)
    ///
    _traits_::TypeOf::velocity velocity{};
    ///
    /// [ -128, +127] percent
    ///
    _traits_::TypeOf::demand_factor_pct demand_factor_pct{};
};

inline nunavut::support::SerializeResult serialize(const CompactFeedback_1_0& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    const std::size_t capacity_bits = out_buffer.size();
    if ((static_cast<std::size_t>(capacity_bits)) < 56UL)
    {
        return -nunavut::support::Error::SerializationBufferTooSmall;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    {   // saturated uint11 dc_voltage
        std::uint16_t _sat0_ = obj.dc_voltage;
        if (_sat0_ > 2047U)
        {
            _sat0_ = 2047U;
        }
        const auto _result3_ = out_buffer.setUxx(_sat0_, 11U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(11U);
    }
    {   // saturated int12 dc_current
        std::int16_t _sat0_ = obj.dc_current;
        if (_sat0_ < -2048)
        {
            _sat0_ = -2048;
        }
        if (_sat0_ > 2047)
        {
            _sat0_ = 2047;
        }
        const auto _result3_ = out_buffer.setIxx(_sat0_, 12U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(12U);
    }
    {   // saturated int12 phase_current_amplitude
        std::int16_t _sat0_ = obj.phase_current_amplitude;
        if (_sat0_ < -2048)
        {
            _sat0_ = -2048;
        }
        if (_sat0_ > 2047)
        {
            _sat0_ = 2047;
        }
        const auto _result3_ = out_buffer.setIxx(_sat0_, 12U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(12U);
    }
    {   // saturated int13 velocity
        std::int16_t _sat0_ = obj.velocity;
        if (_sat0_ < -4096)
        {
            _sat0_ = -4096;
        }
        if (_sat0_ > 4095)
        {
            _sat0_ = 4095;
        }
        const auto _result3_ = out_buffer.setIxx(_sat0_, 13U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(13U);
    }
    {   // saturated int8 demand_factor_pct
        // Saturation code not emitted -- native representation matches the serialized representation.
        const auto _result3_ = out_buffer.setIxx(obj.demand_factor_pct, 8U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(8U);
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

inline nunavut::support::SerializeResult deserialize(CompactFeedback_1_0& obj,
                                                     nunavut::support::const_bitspan in_buffer)
{
    const auto capacity_bits = in_buffer.size();
    // saturated uint11 dc_voltage
    obj.dc_voltage = in_buffer.getU16(11U);
    in_buffer.add_offset(11U);
    // saturated int12 dc_current
    obj.dc_current = in_buffer.getI16(12U);
    in_buffer.add_offset(12U);
    // saturated int12 phase_current_amplitude
    obj.phase_current_amplitude = in_buffer.getI16(12U);
    in_buffer.add_offset(12U);
    // saturated int13 velocity
    obj.velocity = in_buffer.getI16(13U);
    in_buffer.add_offset(13U);
    // saturated int8 demand_factor_pct
    obj.demand_factor_pct = in_buffer.getI8(8U);
    in_buffer.add_offset(8U);
    in_buffer.align_offset_to<8U>();
    auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
    return { static_cast<std::size_t>(_bits_got_ / 8U) };
}

} // namespace telega
} // namespace zubax

#endif // ZUBAX_TELEGA_COMPACT_FEEDBACK_1_0_HPP_INCLUDED
