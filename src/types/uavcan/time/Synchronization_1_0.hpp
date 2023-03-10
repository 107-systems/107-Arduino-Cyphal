//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.0.9 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/uavcan/time/7168.Synchronization.1.0.dsdl
// Generated at:  2023-03-10 05:17:53.544596 UTC
// Is deprecated: no
// Fixed port-ID: 7168
// Full name:     uavcan.time.Synchronization
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
#ifndef UAVCAN_TIME_SYNCHRONIZATION_1_0_HPP_INCLUDED
#define UAVCAN_TIME_SYNCHRONIZATION_1_0_HPP_INCLUDED

#include <nunavut/support/serialization.hpp>
#include <cstdint>
#include <limits>

namespace uavcan
{
namespace time
{
// +-------------------------------------------------------------------------------------------------------------------+
// | LANGUAGE OPTION ASSERTIONS
// |    These static assertions ensure that the header is being used with
// | Nunavut C++ serialization support that is compatible with the language
// | options in effect when that support code was generated.
// +-------------------------------------------------------------------------------------------------------------------+
static_assert( nunavut::support::options::target_endianness == 1693710260,
              "/tmp/public_regulated_data_types/uavcan/time/7168.Synchronization.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/public_regulated_data_types/uavcan/time/7168.Synchronization.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 0,
              "/tmp/public_regulated_data_types/uavcan/time/7168.Synchronization.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/uavcan/time/7168.Synchronization.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 628873475,
              "/tmp/public_regulated_data_types/uavcan/time/7168.Synchronization.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/public_regulated_data_types/uavcan/time/7168.Synchronization.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/public_regulated_data_types/uavcan/time/7168.Synchronization.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/public_regulated_data_types/uavcan/time/7168.Synchronization.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/public_regulated_data_types/uavcan/time/7168.Synchronization.1.0.dsdl "
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
/// Network-wide time synchronization message.
/// Any node that publishes timestamped data should use this time reference.
///
/// The time synchronization algorithm is based on the work
/// "Implementing a Distributed High-Resolution Real-Time Clock using the CAN-Bus" by M. Gergeleit and H. Streich.
/// The general idea of the algorithm is to have one or more nodes that periodically publish a message of this type
/// containing the exact timestamp of the PREVIOUS transmission of this message.
/// A node that publishes this message periodically is referred to as a "time synchronization master",
/// whereas nodes that synchronize their clocks with the master are referred to as "time synchronization slaves".
///
/// Once a time base is chosen, it cannot be changed as long as at least one node on the network is running.
/// In other words, the time base cannot be changed while the network is operating.
/// An implication of this is that if there are redundant time synchronization masters, they all shall
/// use the same time base.
///
/// The resolution is dependent on the transport and its physical layer, but generally it can be assumed
/// to be close to one bit time but not better than one microsecond (e.g., for a 500 kbps CAN bus,
/// the resolution is two microseconds). The maximum accuracy is achievable only if the transport layer
/// supports precise timestamping in hardware; otherwise, the accuracy may be degraded.
///
/// This algorithm allows the slaves to precisely estimate the difference (i.e., phase error) between their
/// local time and the master clock they are synchronized with. The algorithm for clock rate adjustment
/// is entirely implementation-defined (for example, a simple phase-locked loop or a PID rate controller can be used).
///
/// The network can accommodate more than one time synchronization master for purposes of increased reliability:
/// if one master fails, the others will continue to provide the network with accurate and consistent time information.
/// The risk of undesirable transients while the masters are swapped is mitigated by the requirement that all masters
/// use the same time base at all times, as described above.
///
/// The master with the lowest node-ID is called the "dominant master". The current dominant master ceases to be one
/// if its last synchronization message was published more than 3X seconds ago, where X is the time interval
/// between the last and the previous messages published by it. In this case, the master with the next-higher node-ID
/// will take over as the new dominant master. The current dominant master will be displaced immediately as soon as
/// the first message from a new master with a lower node-ID is seen on the bus.
///
/// In the presence of multiple masters, they all publish their time synchronization messages concurrently at all times.
/// The slaves shall listen to the master with the lowest node-ID and ignore the messages published by masters with
/// higher node-ID values.
///
/// Currently, there is a work underway to develop and validate a highly robust fault-operational time synchronization
/// algorithm where the slaves select the median time base among all available masters rather than using only the
/// one with the lowest node-ID value. Follow the work at https://forum.opencyphal.org. When complete, this algorithm
/// will be added in a backward-compatible way as an option for high-reliability systems.
///
/// For networks with redundant transports, the timestamp value published on different interfaces is likely to be
/// different, since different transports are generally not expected to be synchronized. Synchronization slaves
/// are allowed to use any of the available redundant interfaces for synchronization at their discretion.
///
/// The following pseudocode shows the logic of a time synchronization master. This example assumes that the master
/// does not need to synchronize its own clock with other masters on the bus, which is the case if the current master
/// is the only master, or if all masters synchronize their clocks with a robust external source, e.g., a GNSS system.
/// If several masters need to synchronize their clock through the bus, their logic will be extended with the
/// slave-side behavior explained later.
///
///       // State variables
///       transfer_id := 0;
///       previous_tx_timestamp_per_iface[NUM_IFACES] := {0};
///
///       // This function publishes a message with a specified transfer-ID using only one transport interface.
///       function publishMessage(transfer_id, iface_index, msg);
///
///       // This callback is invoked when the transport layer completes the transmission of a time sync message.
///       // Observe that the time sync message is always a single-frame message by virtue of its small size.
///       // The tx_timestamp argument contains the exact timestamp when the transport frame was delivered to the bus.
///       function messageTxTimestampCallback(iface_index, tx_timestamp)
///       {
///           previous_tx_timestamp_per_iface[iface_index] := tx_timestamp;
///       }
///
///       // Publishes messages of type uavcan.time.Synchronization to each available transport interface.
///       // It is assumed that this function is invoked with a fixed frequency not lower than 1 hertz.
///       function publishTimeSync()
///       {
///           for (i := 0; i < NUM_IFACES; i++)
///           {
///               message := uavcan.time.Synchronization();
///               message.previous_transmission_timestamp_usec := previous_tx_timestamp_per_iface[i];
///               previous_tx_timestamp_per_iface[i] := 0;
///               publishMessage(transfer_id, i, message);
///           }
///           transfer_id++; // Overflow shall be handled correctly
///       }
///
/// (end of the master-side logic pseudocode)
/// The following pseudocode describes the logic of a time synchronization slave.
///
///       // State variables:
///       previous_rx_real_timestamp := 0;            // This clock is being synchronized
///       previous_rx_monotonic_timestamp := 0;       // Monotonic time -- doesn't leap or change rate
///       previous_transfer_id := 0;
///       state := STATE_UPDATE;                      // Variants: STATE_UPDATE, STATE_ADJUST
///       master_node_id := -1;                       // Invalid value
///       iface_index := -1;                          // Invalid value
///
///       // This function adjusts the local clock by the specified amount
///       function adjustLocalTime(phase_error);
///
///       function adjust(message)
///       {
///           // Clock adjustment will be performed every second message
///           local_time_phase_error := previous_rx_real_timestamp - msg.previous_transmission_timestamp_microsecond;
///           adjustLocalTime(local_time_phase_error);
///           state := STATE_UPDATE;
///       }
///
///       function update(message)
///       {
///           // A message is assumed to have two timestamps:
///           //   Real      - sampled from the clock that is being synchronized
///           //   Monotonic - clock that never leaps and never changes rate
///           previous_rx_real_timestamp := message.rx_real_timestamp;
///           previous_rx_monotonic_timestamp := message.rx_monotonic_timestamp;
///           master_node_id := message.source_node_id;
///           iface_index := message.iface_index;
///           previous_transfer_id := message.transfer_id;
///           state := STATE_ADJUST;
///       }
///
///       // Accepts the message of type uavcan.time.Synchronization
///       function handleReceivedTimeSyncMessage(message)
///       {
///           time_since_previous_msg := message.monotonic_timestamp - previous_rx_monotonic_timestamp;
///
///           needs_init := (master_node_id < 0) or (iface_index < 0);
///           switch_master := message.source_node_id < master_node_id;
///
///           // The value publisher_timeout is computed as described in the specification (3x interval)
///           publisher_timed_out := time_since_previous_msg > publisher_timeout;
///
///           if (needs_init or switch_master or publisher_timed_out)
///           {
///               update(message);
///           }
///           else if ((message.iface_index == iface_index) and (message.source_node_id == master_node_id))
///           {
///               // Revert the state to STATE_UPDATE if needed
///               if (state == STATE_ADJUST)
///               {
///                   msg_invalid := message.previous_transmission_timestamp_microsecond == 0;
///                   // Overflow shall be handled correctly
///                   wrong_tid := message.transfer_id != (previous_transfer_id + 1);
///                   wrong_timing := time_since_previous_msg > MAX_PUBLICATION_PERIOD;
///                   if (msg_invalid or wrong_tid or wrong_timing)
///                   {
///                       state := STATE_UPDATE;
///                   }
///               }
///               // Handle the current state
///               if (state == STATE_ADJUST)
///               {
///                   adjust(message);
///               }
///               else
///               {
///                   update(message);
///               }
///           }   // else ignore
///       }
///
/// (end of the slave-side logic pseudocode)
///
struct Synchronization_1_0 final
{
    struct _traits_  // The name is surrounded with underscores to avoid collisions with DSDL attributes.
    {
        _traits_() = delete;
        static constexpr bool HasFixedPortID = true;
        static constexpr std::uint16_t FixedPortId = 7168U;
        static constexpr bool IsServiceType = false;

        /// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
        /// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
        /// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
        /// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
        /// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
        /// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
        /// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.
        static constexpr std::size_t ExtentBytes                  = 7UL;
        static constexpr std::size_t SerializationBufferSizeBytes = 7UL;
        static_assert(ExtentBytes >= SerializationBufferSizeBytes, "Internal constraint violation");
        static_assert(ExtentBytes < (std::numeric_limits<std::size_t>::max() / 8U), "This message is too large to be handled by the selected types");
        struct TypeOf
        {
            TypeOf() = delete;
            using previous_transmission_timestamp_microsecond = std::uint64_t;
        };
    };

    // +---------------------------------------------------------------------------------------------------------------+
    // | CONSTANTS
    // +---------------------------------------------------------------------------------------------------------------+
    ///
    /// [second]
    /// Publication period limits.
    /// A master should not change its publication period while running.
    ///
    static constexpr std::uint8_t MAX_PUBLICATION_PERIOD = 1U;
    ///
    /// Synchronization slaves should normally switch to a new master if the current master was silent
    /// for thrice the interval between the reception of the last two messages published by it.
    /// For example, imagine that the last message was received at the time X, and the previous message
    /// was received at the time (X - 0.5 seconds); the period is 0.5 seconds, and therefore the publisher
    /// timeout is (0.5 seconds * 3) = 1.5 seconds. If there was no message from the current master in
    /// this amount of time, all slaves will synchronize with another master with the next-higher node-ID.
    ///
    static constexpr std::uint8_t PUBLISHER_TIMEOUT_PERIOD_MULTIPLIER = 3U;

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+
    ///
    /// The time when the PREVIOUS message was transmitted from the current publisher, in microseconds.
    /// If this message is published for the first time, or if the previous transmission was more than
    /// one second ago, this field shall be zero.
    ///
    _traits_::TypeOf::previous_transmission_timestamp_microsecond previous_transmission_timestamp_microsecond{};
};

inline nunavut::support::SerializeResult serialize(const Synchronization_1_0& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    const std::size_t capacity_bits = out_buffer.size();
    if ((static_cast<std::size_t>(capacity_bits)) < 56UL)
    {
        return -nunavut::support::Error::SerializationBufferTooSmall;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    {   // truncated uint56 previous_transmission_timestamp_microsecond
        const auto _result3_ = out_buffer.setUxx(obj.previous_transmission_timestamp_microsecond, 56U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(56U);
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

inline nunavut::support::SerializeResult deserialize(Synchronization_1_0& obj,
                                                     nunavut::support::const_bitspan in_buffer)
{
    const auto capacity_bits = in_buffer.size();
    // truncated uint56 previous_transmission_timestamp_microsecond
    obj.previous_transmission_timestamp_microsecond = in_buffer.getU64(56U);
    in_buffer.add_offset(56U);
    in_buffer.align_offset_to<8U>();
    auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
    return { static_cast<std::size_t>(_bits_got_ / 8U) };
}

} // namespace time
} // namespace uavcan

#endif // UAVCAN_TIME_SYNCHRONIZATION_1_0_HPP_INCLUDED
