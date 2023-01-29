//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.0.0 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/reg/udral/service/actuator/servo/_.0.1.dsdl
// Generated at:  2023-01-29 16:46:56.749265 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     reg.udral.service.actuator.servo._
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
#ifndef REG_UDRAL_SERVICE_ACTUATOR_SERVO___0_1_HPP_INCLUDED
#define REG_UDRAL_SERVICE_ACTUATOR_SERVO___0_1_HPP_INCLUDED

#include <nunavut/support/serialization.hpp>

namespace reg
{
namespace udral
{
namespace service
{
namespace actuator
{
namespace servo
{
// +-------------------------------------------------------------------------------------------------------------------+
// | LANGUAGE OPTION ASSERTIONS
// |    These static assertions ensure that the header is being used with
// | Nunavut C++ serialization support that is compatible with the language
// | options in effect when that support code was generated.
// +-------------------------------------------------------------------------------------------------------------------+
static_assert( nunavut::support::options::target_endianness == 1693710260,
              "/tmp/public_regulated_data_types/reg/udral/service/actuator/servo/_.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/actuator/servo/_.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 1,
              "/tmp/public_regulated_data_types/reg/udral/service/actuator/servo/_.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/actuator/servo/_.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 3161622713,
              "/tmp/public_regulated_data_types/reg/udral/service/actuator/servo/_.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/actuator/servo/_.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/actuator/servo/_.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/public_regulated_data_types/reg/udral/service/actuator/servo/_.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/public_regulated_data_types/reg/udral/service/actuator/servo/_.0.1.dsdl "
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
/// A servo can actuate either a translational or rotary load using electric power from the high-voltage DC bus.
/// The type of load (translational or rotational) dictates which type is used for commanding the setpoint and reporting
/// the status:
///   - reg.udral.physics.dynamics.rotation.Planar[Ts]
///   - reg.udral.physics.dynamics.translation.Linear[Ts]
/// For generality, either or both of these types are referred to as "timestamped dynamics" or "non-timestamped
/// dynamics".
/// The default readiness state is STANDBY. While in this state, the servo is not allowed to apply force to the load,
/// and the setpoint subject is ignored. The servo shall enter the STANDBY state automatically if the readiness subject
/// is not updated for CONTROL_TIMEOUT.
/// The subjects defined by this service are shown on the following canvas. Implementers are encouraged to add
/// custom subjects with additional data. Notice that the physics subjects are timestamped.
///                  SUBJECT NAME                         SUBJECT TYPE                                    RATE
///   +------------+ setpoint             +------------+  (non-timestamped dynamics) (see below)          R
///   |            |--------------------->|            |
///   |            | readiness            |            |  reg.udral.service.common.Readiness              any
///   |            |--------------------->|            |
///   |            | feedback             |            |  reg.udral.service.actuator.common.Feedback      R
///   |            |<---------------------|            |
///   | Controller | status               |   Servo    |  reg.udral.service.actuator.common.Status        any
///   |            |<---------------------|            |
///   |            | power                |            |  reg.udral.physics.electricity.PowerTs           R
///   |            |<---------------------|            |
///   |            | dynamics             |            |  (timestamped dynamics)                          R
///   |            |<---------------------|            |
///   +------------+                      +------------+
/// Should it be necessary to control a group of servos in lockstep, an arbitrary number of them may subscribe
/// to the same setpoint subject (their published subjects would be different of course).
/// If the servo is ENGAGED, setpoint messages are processed as follows: the first field of the kinematic setpoint type
/// that contains a finite value is taken as the commanded setpoint. The following non-negative finite fields define
/// the motion profile, where negative and non-finite values are ignored.
/// For example, a translational dynamics message containing the following values:
///   position     = +0.35
///   velocity     = NaN
///   acceleration = NaN
///   force        = 30
/// ...is interpreted as follows: position the load at 0.35 meters relative to the neutral, limit the force to 30
/// newton,
/// do not limit the velocity and acceleration. Here is another example:
///   angular position     = NaN
///   angular velocity     = +400
///   angular acceleration = NaN
///   torque               = 50
/// which is interpreted as follows: reach the angular velocity of 400 radian/second in the forward direction,
/// limit the torque to 50 newton*meters, do not limit the acceleration.
/// The motion profile parameters that are not supported are to be silently ignored by the servo. If the commanded
/// parameter cannot be controlled by the servo, the setpoint is to be ignored. For example, in the second example
/// above,
/// if the servo does not support angular velocity control, the setpoint message would be discarded.
/// The above describes the typical use case where each servo is controlled over a dedicated setpoint
/// subject independently (or a group of servos are controlled in lockstep using the same setpoint subject).
/// Some applications may require synchronous independent control of multiple servos in a group, similar to ESC.
/// To address this, a compliant servo should support another operating mode where the controlled quantity
/// (position, velocity, force, etc.) is selected statically along with the motion profile (using the register API),
/// and the servo subscribes to the setpoint subject of type <types/reg.udral.service.actuator.common.sp.*".
/// Having its index in the group configured statically, the servo fetches the setpoint from the appropriate
/// index in the setpoint array.
/// The resulting topology closely resembles that of the ESC service:
///                                                   SUBJECT NAME            SUBJECT TYPE
///  +----------------+
///  |   Controller   |---------+------------+----... setpoint                reg.udral.service.actuator.common.sp.*
///  |                |-------+-)----------+-)----... readiness               reg.udral.service.common.Readiness
///  +----------------+       | |          | |
///   ^ ^ ^ ^  ^ ^ ^ ^        v v          v v
///   | | | |  | | | |   +---------+  +---------+
///   | | | |  | | | |   |Servo i=0|  |Servo i=1| ...
///   | | | |  | | | |   +---------+  +---------+
///   | | | |  | | | |     | | | |      | | | |
///   | | | |  | | | +-----+ | | |      | | | |       feedback                reg.udral.service.actuator.common.Feedback
///   | | | |  | | +---------+ | |      | | | |       status                  reg.udral.service.actuator.common.Status
///   | | | |  | +-------------+ |      | | | |       power                   reg.udral.physics.electricity.PowerTs
///   | | | |  +-----------------+      | | | |       dynamics                (timestamped dynamics)
///   | | | |                           | | | |
///   | | | +---------------------------+ | | |
///   | | +-------------------------------+ | |
///   | +-----------------------------------+ |
///   +---------------------------------------+
/// If the selected readiness state is SLEEP, the behavior is implementation-defined. Implementations are recommended to
/// power off the high-voltage circuitry and all non-essential components (e.g., LED indication, sensors, etc.)
/// to minimize the power consumption. The publication rate requirements do not apply if the state is SLEEP.
/// The worst-case readiness state transition latency is not defined.
/// The following subjects shall be published immediately after a new setpoint is applied even if the servo is STANDBY:
///   SUBJECT NAME        RECOMMENDED PRIORITY
///   ---------------------------------------------
///   feedback            same as the setpoint
///   power               second to the setpoint
///   dynamics            second to the setpoint
/// If no setpoint is being published, these subjects should continue being updated at least at
/// 1/MAX_PUBLICATION_PERIOD.
/// If the setpoint publication rate exceeds 50 Hz, implementations are allowed (but not required) to throttle these
/// subjects by dropping some of the messages such that the publication rate of each subject does not exceed 50 Hz.
/// Implementations operating over Classic CAN are recommended to do this.
/// The other subjects may be published at an implementation-defined rate and priority,
/// which should be consistent across the group.
/// The measurements carried by the published messages should be low-pass filtered with an adequate cutoff frequency to
/// avoid aliasing effects. Implementations should strive to sample all parameters simultaneously.
/// It is assumed that the servo is powered from a DC electric power supply network. A positive electric current
/// represents current flowing from the DC network into the servo (negative represents regeneration).
/// Excepting edge cases and transients, torque/force and current are generally of the same sign (barring the difference
/// introduced by the power dissipated by the servo itself).
///                                   +velocity
///                                       ^
///                               braking,| forward,
///                               negative| positive
///                               power   | power
///                            -----------+---------->  +torque/force/current
///                               reverse,| braking,
///                               positive| negative
///                               power   | power
/// An example implementation is available at https://github.com/OpenCyphal/demos
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

} // namespace servo
} // namespace actuator
} // namespace service
} // namespace udral
} // namespace reg

#endif // REG_UDRAL_SERVICE_ACTUATOR_SERVO___0_1_HPP_INCLUDED
