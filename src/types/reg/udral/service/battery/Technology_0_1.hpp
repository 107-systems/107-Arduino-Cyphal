//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.0.9 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/reg/udral/service/battery/Technology.0.1.dsdl
// Generated at:  2023-03-10 05:17:54.675401 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     reg.udral.service.battery.Technology
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
//     runtime_platform:  Linux-5.19.0-35-generic-x86_64-with-glibc2.35
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
#ifndef REG_UDRAL_SERVICE_BATTERY_TECHNOLOGY_0_1_HPP_INCLUDED
#define REG_UDRAL_SERVICE_BATTERY_TECHNOLOGY_0_1_HPP_INCLUDED

#include <nunavut/support/serialization.hpp>
#include <cstdint>
#include <limits>

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
              "/tmp/public_regulated_data_types/reg/udral/service/battery/Technology.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/Technology.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/Technology.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/Technology.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 628873475,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/Technology.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/Technology.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/Technology.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/Technology.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/Technology.0.1.dsdl "
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
/// Battery chemistry type and its form-factor.
/// Observe that there is no item to represent unknown technology because it is required to be known.
/// This information may be used by charging systems to select the appropriate charging strategy.
/// If the battery is of an uncommon type, it may be preferred to report the closest-matching type listed here
/// instead of OTHER.
///
struct Technology_0_1 final
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
        static constexpr std::size_t ExtentBytes                  = 1UL;
        static constexpr std::size_t SerializationBufferSizeBytes = 1UL;
        static_assert(ExtentBytes >= SerializationBufferSizeBytes, "Internal constraint violation");
        static_assert(ExtentBytes < (std::numeric_limits<std::size_t>::max() / 8U), "This message is too large to be handled by the selected types");
        struct TypeOf
        {
            TypeOf() = delete;
            using value = std::uint8_t;
        };
    };

    // +---------------------------------------------------------------------------------------------------------------+
    // | CONSTANTS
    // +---------------------------------------------------------------------------------------------------------------+
    ///
    /// The technology is not specified in this enumeration. Please submit a pull request.
    ///
    static constexpr std::uint8_t OTHER = 0U;
    ///
    /// Lithium-thionyl chloride (Li-SOCl2)
    ///
    static constexpr std::uint8_t LI_SOCL2 = 10U;
    ///
    /// Lithium-thionyl chloride + bromine chloride (Li-BCX)
    ///
    static constexpr std::uint8_t LI_BCX = 11U;
    ///
    /// Lithium-manganese dioxide (Li-MnO2) (e.g., lithium coin cell, lithium 9V)
    ///
    static constexpr std::uint8_t LI_MNO2 = 12U;
    ///
    /// Zinc-Air
    ///
    static constexpr std::uint8_t ZN_O2 = 20U;
    ///
    /// Aluminum-Air
    ///
    static constexpr std::uint8_t AL_O2 = 21U;
    ///
    /// Zinc-manganese dioxide - ammonium chloride electrolyte (aka zinc-carbon)
    ///
    static constexpr std::uint8_t ZN_MNO2_NH4CL = 30U;
    ///
    /// Zinc-manganese dioxide - zinc chloride electrolyte (aka heavy duty zinc-carbon)
    ///
    static constexpr std::uint8_t ZN_MNO2_ZNCL2 = 31U;
    ///
    /// Zinc-manganese dioxide - potassium hydroxide electrolyte (aka alkaline)
    ///
    static constexpr std::uint8_t ZN_MNO2_KOH = 32U;
    ///
    /// Lithium cobalt oxide (commonly known as just "lithium-ion")
    ///
    static constexpr std::uint8_t LI_LCO = 100U;
    ///
    /// Lithium iron phosphate (LiFePO4)
    ///
    static constexpr std::uint8_t LI_LFP = 101U;
    ///
    /// Lithium nickel manganese cobalt oxide
    ///
    static constexpr std::uint8_t LI_NMC = 102U;
    ///
    /// Lithium nickel cobalt aluminium oxide
    ///
    static constexpr std::uint8_t LI_NCA = 103U;
    ///
    /// Lithium manganese oxide
    ///
    static constexpr std::uint8_t LI_LMO = 104U;
    ///
    /// Lithium-sulfur (LiS)
    ///
    static constexpr std::uint8_t LI_S = 105U;
    ///
    /// LiCoO2 in pouch form factor, commonly known as "lithium-ion polymer" or "LiPo".
    ///
    static constexpr std::uint8_t LI_LCO_POUCH = 110U;
    ///
    /// LiFePO4 in pouch form factor, commonly known as "LiFePO4 polymer".
    ///
    static constexpr std::uint8_t LI_LFP_POUCH = 111U;
    ///
    /// Nickel-metal hydride
    ///
    static constexpr std::uint8_t NI_MH = 120U;
    ///
    /// Nickel-cadmium
    ///
    static constexpr std::uint8_t NI_CD = 121U;
    ///
    /// Nickel-zinc
    ///
    static constexpr std::uint8_t NI_ZN = 122U;
    ///
    /// Nickel-iron
    ///
    static constexpr std::uint8_t NI_FE = 123U;
    ///
    /// Lead acid
    ///
    static constexpr std::uint8_t PB_AC = 130U;
    ///
    /// Also known as SLA
    ///
    static constexpr std::uint8_t PB_AC_SEALED = 131U;
    ///
    /// Electrostatic double-layer capacitor
    ///
    static constexpr std::uint8_t EDLC = 200U;

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+

    _traits_::TypeOf::value value{};
};

inline nunavut::support::SerializeResult serialize(const Technology_0_1& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    const std::size_t capacity_bits = out_buffer.size();
    if ((static_cast<std::size_t>(capacity_bits)) < 8UL)
    {
        return -nunavut::support::Error::SerializationBufferTooSmall;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    {   // saturated uint8 value
        // Saturation code not emitted -- native representation matches the serialized representation.
        const auto _result3_ = out_buffer.setUxx(obj.value, 8U);
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

inline nunavut::support::SerializeResult deserialize(Technology_0_1& obj,
                                                     nunavut::support::const_bitspan in_buffer)
{
    const auto capacity_bits = in_buffer.size();
    // saturated uint8 value
    obj.value = in_buffer.getU8(8U);
    in_buffer.add_offset(8U);
    in_buffer.align_offset_to<8U>();
    auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
    return { static_cast<std::size_t>(_bits_got_ / 8U) };
}

} // namespace battery
} // namespace service
} // namespace udral
} // namespace reg

#endif // REG_UDRAL_SERVICE_BATTERY_TECHNOLOGY_0_1_HPP_INCLUDED
