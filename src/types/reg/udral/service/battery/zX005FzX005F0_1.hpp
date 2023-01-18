//
// This is an AUTO-GENERATED UAVCAN DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-1.9.0 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/reg/udral/service/battery/_.0.1.dsdl
// Generated at:  2023-01-18 06:33:57.022283 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     reg.udral.service.battery._
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
#ifndef REG_UDRAL_SERVICE_BATTERY___0_1_HPP_INCLUDED
#define REG_UDRAL_SERVICE_BATTERY___0_1_HPP_INCLUDED

#include "nunavut/support/serialization.hpp"

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
              "/tmp/public_regulated_data_types/reg/udral/service/battery/_.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/_.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 1,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/_.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/_.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 3161622713,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/_.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/_.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/_.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/_.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/battery/_.0.1.dsdl "
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
/// This is the smart battery monitoring service. A smart battery is required to publish on the following subjects:
///   SUBJECT                         TYPE                                            TYP. RATE [Hz]
///   energy_source                   reg.udral.physics.electricity.SourceTs          1...100
///   status                          reg.udral.service.battery.Status                ~1
///   parameters                      reg.udral.service.battery.Parameters            ~0.2
/// Observe that only the first subject can be used for estimating the endurance of the power source. The other subjects
/// are designed for monitoring, diagnostics, and maintenance.
/// Optionally, the battery service can subscribe to a readiness control subject (see
/// reg.udral.service.common.Readiness),
/// which enables the following two optional capabilities:
///   - SLEEP mode: when the readiness subject commands the sleep state, the battery management system may enter a
///     low power consumption state, possibly deactivating some of its capabilities.
///   - STANDBY mode: the battery management system may implement additional safety protections that may otherwise
///     interfere with the normal operation of the vehicle. For example, the traction battery may limit the maximum
///     load current and the depth of discharge unless the commanded state is ENGAGED. By doing so, the battery can
///     protect itself and the supplied high-voltage DC network from accidental damage while the vehicle is parked.
///     Limiting the output power or discharge of the traction battery might lead to catastrophic consequences in
///     an aerial vehicle, hence such safety checks are to be disabled once the battery is commanded into the ENGAGED
///     state.
/// If readiness state selection is not supported, the battery may not subscribe to the readiness control subject,
/// in which case it should permanently report its state as ENGAGED unless the battery is unfit for use (e.g., due
/// to degradation or a failure).
/// By convention, positive current flows from the DC network into the battery. Therefore, the current is
/// negative when the battery powers the system, and positive when it is being charged.
/// Systems that leverage multiple battery packs simultaneously should be configured to publish the status of each
/// pack on a separate subject.
/// Published quantities should be low-pass filtered to avoid aliasing effects.
/// Publishers should strive to sample all parameters atomically.
/// The reported quantities are focused on the amount of energy that can be reclaimed from the battery. In a
/// simplified view, this can be seen as the amount of energy that is "stored" in the battery; however, this
/// interpretation is not strictly correct because the amount of retrievable energy may be dependent on external
/// factors such as the temperature of the battery or the load current. Energy estimation is hard and requires
/// accurate modeling of the state of the battery, which may be impossible to do without precise tracking of each
/// charging cycle. Despite the complications, this is considered to be a superior approach compared to the commonly
/// used alternative where the state estimation is focused on the electric charge, because the latter cannot be used
/// directly to predict the endurance of the system.
/// The methods of energy estimation are implementation-defined.
///
struct zX005FzX005F0_1 final
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

    static constexpr std::size_t EXTENT_BYTES                    =0UL;
    static constexpr std::size_t SERIALIZATION_BUFFER_SIZE_BYTES =0UL;
    static_assert(EXTENT_BYTES >= SERIALIZATION_BUFFER_SIZE_BYTES, "Internal constraint violation");
    static_assert(EXTENT_BYTES < (std::numeric_limits<std::size_t>::max() /8U), "This message is too large to be handled by current types!");

    nunavut::support::SerializeResult
    serialize(nunavut::support::bitspan out_buffer) const
    {
        (void)(out_buffer);
        return 0U;
    }

    nunavut::support::SerializeResult
    deserialize(nunavut::support::const_bitspan in_buffer)
    {
        (void)(in_buffer);
        return 0;
    }
};

} // namespace battery
} // namespace service
} // namespace udral
} // namespace reg

#endif // REG_UDRAL_SERVICE_BATTERY___0_1_HPP_INCLUDED
