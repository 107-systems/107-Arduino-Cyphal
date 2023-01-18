//
// This is an AUTO-GENERATED UAVCAN DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-1.9.0 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/reg/udral/service/common/Readiness.0.1.dsdl
// Generated at:  2023-01-18 06:06:51.712352 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     reg.udral.service.common.Readiness
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
#ifndef REG_UDRAL_SERVICE_COMMON_READINESS_0_1_HPP_INCLUDED
#define REG_UDRAL_SERVICE_COMMON_READINESS_0_1_HPP_INCLUDED

#include "nunavut/support/serialization.hpp"
#include <cstdint>

namespace reg
{
namespace udral
{
namespace service
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
              "/tmp/public_regulated_data_types/reg/udral/service/common/Readiness.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/common/Readiness.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 1,
              "/tmp/public_regulated_data_types/reg/udral/service/common/Readiness.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/common/Readiness.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 3161622713,
              "/tmp/public_regulated_data_types/reg/udral/service/common/Readiness.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/common/Readiness.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/common/Readiness.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/public_regulated_data_types/reg/udral/service/common/Readiness.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/common/Readiness.0.1.dsdl "
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
/// The readiness state is used to command or report the availability status of a networked service (subsystem).
/// Any system shall have at least one readiness command subject that acts as a global power switch.
/// Every subsystem controlled in such way would usually report its readiness status back to account for the fact that
/// the transition between different readiness states may not be instantaneous.
/// The readiness status reporting is done by means of the service heartbeat type that is also defined in this
/// namespace;
/// the service heartbeat type is a structural subtype of this type.
///   +------------+
///   | Controller |----------+----------------+----------------+---------...     readiness command subject
///   +------------+          |                |                |
///     ^   ^   ^             v                v                v
///     |   |   |        +---------+      +---------+      +---------+
///     |   |   |        | Service |      | Service |      | Service |    ...
///     |   |   |        +---------+      +---------+      +---------+
///     |   |   |             |                |                |
///     |   |   +-------------+                |                |
///     |   +----------------------------------+                |                 service heartbeat subjects
///     +-------------------------------------------------------+
/// In a less trivial use case there may be an arbitrary number of such readiness command subjects (local power
/// switches)
/// controlling various systems within the vehicle (e.g., propulsion, perception sensors, communication, etc).
/// The publication rate is defined on a per-service basis, but it should never be lower than 1 Hz,
/// excepting services that are in the SLEEP state, in which case it is permitted to cease all network activity.
///
struct Readiness_0_1 final
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

    static constexpr std::size_t EXTENT_BYTES                    =1UL;
    static constexpr std::size_t SERIALIZATION_BUFFER_SIZE_BYTES =1UL;
    static_assert(EXTENT_BYTES >= SERIALIZATION_BUFFER_SIZE_BYTES, "Internal constraint violation");
    static_assert(EXTENT_BYTES < (std::numeric_limits<std::size_t>::max() /8U), "This message is too large to be handled by current types!");

    // +---------------------------------------------------------------------------------------------------------------+
    // | CONSTANTS
    // +---------------------------------------------------------------------------------------------------------------+
    ///
    /// The long-term state of minimal power consumption.
    /// Typically, most subsystems are switched into the SLEEP mode when the vehicle is parked and powered off.
    /// Subsystems that do not support the SLEEP state should treat it as an equivalent of STANDBY.
    /// A subsystem may require a substantial amount of time to exit the sleep mode (for example, time may be needed to
    /// boot the operating system and run the self test procedures).
    /// While in the SLEEP mode, the subsystem is allowed to cease service provision and stop all network activity
    /// regardless of other requirements, except that it shall be able to reactivate itself if a Readiness message is
    /// received commanding any state other than SLEEP.
    ///
    static constexpr std::uint8_t SLEEP = 0U;
    ///
    /// The state of being ready to enter the normal operating mode in a short order.
    /// A subsystem that is in STANDBY state should be able to participate in the normal network activity.
    /// This is the default state that the subsystem should reside in after power-on until explicitly commanded
    /// otherwise.
    ///
    static constexpr std::uint8_t STANDBY = 2U;
    ///
    /// When ENGAGED, the subsystem is performing its main intended function at the nominal performance characteristics.
    /// A subsystem may require a short amount of time, possibly under a few seconds, to switch between the ENGAGED and
    /// STANDBY states (in any direction).
    /// Some subsystems may not differentiate between STANDBY and ENGAGED (e.g., offboard communication hardware).
    /// The subsystem may disengage itself autonomously in the event of a fatal malfunction, in which case
    /// the reported service health status should be WARNING.
    ///
    static constexpr std::uint8_t _eNGAGED = 3U;

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+

    std::uint8_t value;

    nunavut::support::SerializeResult
    serialize(nunavut::support::bitspan out_buffer) const
    {
        const std::size_t capacity_bits = out_buffer.size();
        if ((static_cast<std::size_t>(capacity_bits)) < 8UL)
        {
            return -nunavut::support::Error::SERIALIZATION_BUFFER_TOO_SMALL;
        }
        // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
        // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
        NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
        {   // truncated uint2 value
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(2ULL <= out_buffer.size());
            const auto _result3_ = out_buffer.setUxx(value, 2U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(2U);
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT(out_buffer.offset() == 8ULL);
        NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
        return out_buffer.offset_bytes_ceil();
    }

    nunavut::support::SerializeResult
    deserialize(nunavut::support::const_bitspan in_buffer)
    {
        const auto capacity_bits = in_buffer.size();
        // truncated uint2 value
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        value = in_buffer.getU8(2U);
        in_buffer.add_offset(2U);
        in_buffer.align_offset_to<8U>();
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
        NUNAVUT_ASSERT(capacity_bits >= _bits_got_);
        return { static_cast<std::size_t>(_bits_got_ / 8U) };
    }
};

} // namespace common
} // namespace service
} // namespace udral
} // namespace reg

#endif // REG_UDRAL_SERVICE_COMMON_READINESS_0_1_HPP_INCLUDED