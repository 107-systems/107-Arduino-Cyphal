//
// This is an AUTO-GENERATED UAVCAN DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-1.9.0 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/reg/udral/service/actuator/common/FaultFlags.0.1.dsdl
// Generated at:  2023-01-18 06:06:51.725143 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     reg.udral.service.actuator.common.FaultFlags
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
#ifndef REG_UDRAL_SERVICE_ACTUATOR_COMMON_FAULT_FLAGS_0_1_HPP_INCLUDED
#define REG_UDRAL_SERVICE_ACTUATOR_COMMON_FAULT_FLAGS_0_1_HPP_INCLUDED

#include "nunavut/support/serialization.hpp"

namespace reg
{
namespace udral
{
namespace service
{
namespace actuator
{
namespace common
{
// +-------------------------------------------------------------------------------------------------------------------+
// | LANGUAGE OPTION ASSERTIONS
// |    These static assertions ensure that the header is being used with
// | Nunavut C++ serialization support that is compatible with the language
// | options in effect when that support code was generated.
// +-------------------------------------------------------------------------------------------------------------------+
static_assert( nunavut::support::options::target_endianness == 1693710260,
              "/tmp/public_regulated_data_types/reg/udral/service/actuator/common/FaultFlags.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/actuator/common/FaultFlags.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 1,
              "/tmp/public_regulated_data_types/reg/udral/service/actuator/common/FaultFlags.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/actuator/common/FaultFlags.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 3161622713,
              "/tmp/public_regulated_data_types/reg/udral/service/actuator/common/FaultFlags.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/actuator/common/FaultFlags.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/actuator/common/FaultFlags.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/public_regulated_data_types/reg/udral/service/actuator/common/FaultFlags.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/actuator/common/FaultFlags.0.1.dsdl "
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
/// A collection of detailed fault flags indicating problems detected by the service provider.
/// A fault flag is set when the corresponding parameter exceeds its safe operating area (SOA) as defined by the vendor;
/// see https://en.wikipedia.org/wiki/Safe_operating_area.
/// As long as at least one flag is set, the service health should not be NOMINAL.
///
struct FaultFlags_0_1 final
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

    static constexpr std::size_t EXTENT_BYTES                    =2UL;
    static constexpr std::size_t SERIALIZATION_BUFFER_SIZE_BYTES =2UL;
    static_assert(EXTENT_BYTES >= SERIALIZATION_BUFFER_SIZE_BYTES, "Internal constraint violation");
    static_assert(EXTENT_BYTES < (std::numeric_limits<std::size_t>::max() /8U), "This message is too large to be handled by current types!");

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+
    ///
    /// The load is above SOA or regeneration below the SOA.
    ///
    bool overload;
    ///
    /// Supply voltage is above or below the SOA.
    ///
    bool voltage;

    bool motor_temperature;
    ///
    /// Temperature is above or below the SOA.
    ///
    bool controller_temperature;
    ///
    /// The absolute velocity of the load is above the SOA.
    ///
    bool velocity;
    ///
    /// The load cannot be driven due to a mechanical failure.
    ///
    bool mechanical;
    ///
    /// The mechanical vibration level exceeds the SOA.
    ///
    bool vibration;
    ///
    /// Configuration is missing or invalid.
    ///
    bool configuration;
    ///
    /// The requested control mode is not supported by the actuator.
    ///
    bool control_mode;
    ///
    /// None of the above (vendor-specific).
    ///
    bool other;

    nunavut::support::SerializeResult
    serialize(nunavut::support::bitspan out_buffer) const
    {
        const std::size_t capacity_bits = out_buffer.size();
        if ((static_cast<std::size_t>(capacity_bits)) < 16UL)
        {
            return -nunavut::support::Error::SERIALIZATION_BUFFER_TOO_SMALL;
        }
        // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
        // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
        NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
        {   // saturated bool overload
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(1ULL <= out_buffer.size());
            auto _result2_ = out_buffer.setBit(overload);
            if(not _result2_){
                return -_result2_.error();
            }
            out_buffer.add_offset(1UL);
        }
        {   // saturated bool voltage
            NUNAVUT_ASSERT(1ULL <= out_buffer.size());
            auto _result2_ = out_buffer.setBit(voltage);
            if(not _result2_){
                return -_result2_.error();
            }
            out_buffer.add_offset(1UL);
        }
        {   // saturated bool motor_temperature
            NUNAVUT_ASSERT(1ULL <= out_buffer.size());
            auto _result2_ = out_buffer.setBit(motor_temperature);
            if(not _result2_){
                return -_result2_.error();
            }
            out_buffer.add_offset(1UL);
        }
        {   // saturated bool controller_temperature
            NUNAVUT_ASSERT(1ULL <= out_buffer.size());
            auto _result2_ = out_buffer.setBit(controller_temperature);
            if(not _result2_){
                return -_result2_.error();
            }
            out_buffer.add_offset(1UL);
        }
        {   // saturated bool velocity
            NUNAVUT_ASSERT(1ULL <= out_buffer.size());
            auto _result2_ = out_buffer.setBit(velocity);
            if(not _result2_){
                return -_result2_.error();
            }
            out_buffer.add_offset(1UL);
        }
        {   // saturated bool mechanical
            NUNAVUT_ASSERT(1ULL <= out_buffer.size());
            auto _result2_ = out_buffer.setBit(mechanical);
            if(not _result2_){
                return -_result2_.error();
            }
            out_buffer.add_offset(1UL);
        }
        {   // saturated bool vibration
            NUNAVUT_ASSERT(1ULL <= out_buffer.size());
            auto _result2_ = out_buffer.setBit(vibration);
            if(not _result2_){
                return -_result2_.error();
            }
            out_buffer.add_offset(1UL);
        }
        {   // saturated bool configuration
            NUNAVUT_ASSERT(1ULL <= out_buffer.size());
            auto _result2_ = out_buffer.setBit(configuration);
            if(not _result2_){
                return -_result2_.error();
            }
            out_buffer.add_offset(1UL);
        }
        {   // saturated bool control_mode
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(1ULL <= out_buffer.size());
            auto _result2_ = out_buffer.setBit(control_mode);
            if(not _result2_){
                return -_result2_.error();
            }
            out_buffer.add_offset(1UL);
        }
        {   // void6
            NUNAVUT_ASSERT(6ULL <= out_buffer.size());
            auto _result1_ = out_buffer.setZeros(6UL);
            if(not _result1_){
                return -_result1_.error();
            }
            out_buffer.add_offset(6UL);
        }
        {   // saturated bool other
            NUNAVUT_ASSERT(1ULL <= out_buffer.size());
            auto _result2_ = out_buffer.setBit(other);
            if(not _result2_){
                return -_result2_.error();
            }
            out_buffer.add_offset(1UL);
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT(out_buffer.offset() == 16ULL);
        NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
        return out_buffer.offset_bytes_ceil();
    }

    nunavut::support::SerializeResult
    deserialize(nunavut::support::const_bitspan in_buffer)
    {
        const auto capacity_bits = in_buffer.size();
        // saturated bool overload
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        overload = in_buffer.getBit();
        in_buffer.add_offset(1U);
        // saturated bool voltage
        voltage = in_buffer.getBit();
        in_buffer.add_offset(1U);
        // saturated bool motor_temperature
        motor_temperature = in_buffer.getBit();
        in_buffer.add_offset(1U);
        // saturated bool controller_temperature
        controller_temperature = in_buffer.getBit();
        in_buffer.add_offset(1U);
        // saturated bool velocity
        velocity = in_buffer.getBit();
        in_buffer.add_offset(1U);
        // saturated bool mechanical
        mechanical = in_buffer.getBit();
        in_buffer.add_offset(1U);
        // saturated bool vibration
        vibration = in_buffer.getBit();
        in_buffer.add_offset(1U);
        // saturated bool configuration
        configuration = in_buffer.getBit();
        in_buffer.add_offset(1U);
        // saturated bool control_mode
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        control_mode = in_buffer.getBit();
        in_buffer.add_offset(1U);
        // void6
        in_buffer.add_offset(6);
        // saturated bool other
        other = in_buffer.getBit();
        in_buffer.add_offset(1U);
        in_buffer.align_offset_to<8U>();
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
        NUNAVUT_ASSERT(capacity_bits >= _bits_got_);
        return { static_cast<std::size_t>(_bits_got_ / 8U) };
    }
};

} // namespace common
} // namespace actuator
} // namespace service
} // namespace udral
} // namespace reg

#endif // REG_UDRAL_SERVICE_ACTUATOR_COMMON_FAULT_FLAGS_0_1_HPP_INCLUDED
