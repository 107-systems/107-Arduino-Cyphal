//
// This is an AUTO-GENERATED UAVCAN DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-1.9.0 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/uavcan/internet/udp/8174.OutgoingPacket.0.1.dsdl
// Generated at:  2023-01-24 05:52:10.901540 UTC
// Is deprecated: yes
// Fixed port-ID: 8174
// Full name:     uavcan.internet.udp.OutgoingPacket
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
//           _____  ______ _____  _____  ______ _____       _______ ______ _____
//          |  __ `|  ____|  __ `|  __ `|  ____/ ____|   /`|__   __|  ____|  __ `
//          | |  | | |__  | |__) | |__) | |__ | |       /  `  | |  | |__  | |  | |
//          | |  | |  __| |  ___/|  _  /|  __|| |      / /` ` | |  |  __| | |  | |
//          | |__| | |____| |    | | ` `| |___| |____ / ____ `| |  | |____| |__| |
//          |_____/|______|_|    |_|  `_`______`_____/_/    `_`_|  |______|_____/
//
// WARNING: this data type is deprecated and is nearing the end of its life cycle. Seek replacement.
#ifndef UAVCAN_INTERNET_UDP_OUTGOING_PACKET_0_1_HPP_INCLUDED
#define UAVCAN_INTERNET_UDP_OUTGOING_PACKET_0_1_HPP_INCLUDED

#include <nunavut/support/serialization.hpp>
#include <nunavut/support/variable_length_array.hpp>
#include <cstdint>

namespace uavcan
{
namespace internet
{
namespace udp
{
// +-------------------------------------------------------------------------------------------------------------------+
// | LANGUAGE OPTION ASSERTIONS
// |    These static assertions ensure that the header is being used with
// | Nunavut C++ serialization support that is compatible with the language
// | options in effect when that support code was generated.
// +-------------------------------------------------------------------------------------------------------------------+
static_assert( nunavut::support::options::target_endianness == 1693710260,
              "/tmp/public_regulated_data_types/uavcan/internet/udp/8174.OutgoingPacket.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/public_regulated_data_types/uavcan/internet/udp/8174.OutgoingPacket.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 1,
              "/tmp/public_regulated_data_types/uavcan/internet/udp/8174.OutgoingPacket.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/uavcan/internet/udp/8174.OutgoingPacket.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 3161622713,
              "/tmp/public_regulated_data_types/uavcan/internet/udp/8174.OutgoingPacket.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/public_regulated_data_types/uavcan/internet/udp/8174.OutgoingPacket.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/public_regulated_data_types/uavcan/internet/udp/8174.OutgoingPacket.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/public_regulated_data_types/uavcan/internet/udp/8174.OutgoingPacket.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/public_regulated_data_types/uavcan/internet/udp/8174.OutgoingPacket.0.1.dsdl "
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
/// This message carries UDP packets from a node on the local bus to a remote host on the Internet or a LAN.
/// Any node can broadcast a message of this type.
/// All nodes that are capable of communication with the Internet or a LAN should subscribe to messages
/// of this type and forward the payload to the indicated host and port using exactly one UDP datagram
/// per message (i.e. additional fragmentation is to be avoided). Such nodes will be referred to as
/// "modem nodes".
/// It is expected that some systems will have more than one modem node available.
/// Each modem node is supposed to forward every message it sees, which will naturally create
/// some degree of modular redundancy and fault tolerance. The remote host should therefore be able to
/// properly handle possibly duplicated messages from different source addresses, in addition to
/// possible duplications introduced by the UDP/IP protocol itself. There are at least two obvious
/// strategies that can be employed by the remote host:
///   - Accept only the first message, ignore duplicates. This approach requires that the UDP stream
///     should contain some metadata necessary for the remote host to determine the source and ordering
///     of each received datum. This approach works best for periodic data, such as telemetry, where
///     the sender does not expect any responses.
///   - Process all messages, including duplicates. This approach assumes that the remote host acts
///     as a server, processing all received requests and providing responses to each. This arrangement
///     implies that the client may receive duplicated responses. It is therefore the client's
///     responsibility to resolve the possible ambiguity. An obvious solution is to accept the first
///     arrived response and ignore the later ones.
/// Applications are free to choose whatever redundancy management strategy works best for them.
/// If the source node expects that the remote host will send some data back, it shall explicitly notify
/// the modem nodes about this, so that they could prepare to perform reverse forwarding when the
/// expected data arrives from the remote host. The technique of reverse forwarding is known in
/// networking as IP Masquerading, or (in general) Network Address Translation (NAT). The notification
/// is performed by means of setting one of the corresponding flags defined below.
/// In order to be able to match datagrams received from remote hosts and the local nodes they should
/// be forwarded to, modem nodes are required to keep certain metadata about outgoing datagrams. Such
/// metadata is stored in a data structure referred to as "NAT table", where every entry would normally
/// contain at least the following fields:
///   - The local UDP port number that was used to send the outgoing datagram from.
///     Per RFC 4787, the port number is chosen by the modem node automatically.
///   - The node-ID of the local node that has sent the outgoing datagram.
///   - Value of the field session_id defined below.
///   - Possibly some other data, depending on the implementation.
/// The modem nodes are required to keep each NAT table entry for at least NAT_ENTRY_MIN_TTL seconds
/// since the last reverse forwarding action was performed. Should the memory resources of the modem node
/// be exhausted, it is allowed to remove old NAT entries earlier, following the policy of least recent use.
/// Having received a UDP packet from a remote host, the modem node would check the NAT table in order
/// to determine where on the Cyphal bus the received data should be forwarded to. If the NAT table
/// contains no matches, the received data should be silently dropped. If a match is found, the
/// modem node will forward the data to the recipient node using the service HandleIncomingPacket.
/// If the service invocation times out, the modem node is permitted to remove the corresponding entry from
/// the NAT table immediately (but it is not required). This will ensure that the modem nodes will not be
/// tasked with translations for client nodes that are no longer online or are unreachable.
/// Additionally, client nodes will be able to hint the modem nodes to remove translation entries they no
/// longer need by simply refusing to respond to the corresponding service invocation. Please refer to
/// the definition of that service data type for a more in-depth review of the reverse forwarding process.
/// Modem nodes can also perform traffic shaping, if needed, by means of delaying or dropping UDP
/// datagrams that exceed the quota.
/// To summarize, a typical data exchange occurrence should amount to the following actions:
///   - A local Cyphal node broadcasts a message of type OutgoingPacket with the payload it needs
///     to forward. If the node expects the remote host to send any data back, it sets the masquerading flag.
///   - Every modem node on the bus receives the message and performs the following actions:
///       - The domain name is resolved, unless the destination address provided in the message
///         is already an IP address, in which case this step should be skipped.
///       - The domain name to IP address mapping is added to the local DNS cache, although this
///         part is entirely implementation defined and is not required.
///       - The masquerading flag is checked. If it is set, a new entry is added to the NAT table.
///         If such entry already existed, its expiration timeout is reset. If no such entry existed
///         and a new one cannot be added because of memory limitations, the least recently used
///         (i.e. oldest) entry of the NAT table is replaced with the new one.
///       - The payload is forwarded to the determined IP address.
///   - At this point, direct forwarding is complete. Should any of the modem nodes receive an incoming
///     packet, they would attempt to perform a reverse forwarding according to the above provided algorithm.
/// It is recommended to use the lowest transport priority level when broadcasting messages of this type,
/// in order to avoid interference with a real-time traffic on the bus. Usage of higher priority levels is
/// unlikely to be practical because the latency and throughput limitations introduced by the on-board radio
/// communication equipment are likely to vastly exceed those of the local CAN bus.
///
struct OutgoingPacket_0_1 final
{
    // +---------------------------------------------------------------------------------------------------------------+
    // | PORT IDENTIFIERS
    // +---------------------------------------------------------------------------------------------------------------+
    static constexpr bool HasFixedPortID = true;
    static constexpr std::uint16_t FixedPortId = 8174U;
    static constexpr bool IsServiceType = false;

    /// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
    /// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
    /// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
    /// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
    /// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
    /// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
    /// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.

    static constexpr std::size_t EXTENT_BYTES                    =600UL;
    static constexpr std::size_t SERIALIZATION_BUFFER_SIZE_BYTES =313UL;
    static_assert(EXTENT_BYTES >= SERIALIZATION_BUFFER_SIZE_BYTES, "Internal constraint violation");
    static_assert(EXTENT_BYTES < (std::numeric_limits<std::size_t>::max() /8U), "This message is too large to be handled by current types!");

    // +---------------------------------------------------------------------------------------------------------------+
    // | CONSTANTS
    // +---------------------------------------------------------------------------------------------------------------+
    ///
    /// [second]
    /// Modem nodes are required to keep the NAT table entries alive for at least this amount of time, unless the
    /// table is overflowed, in which case they are allowed to remove least recently used entries in favor of
    /// newer ones. Modem nodes are required to be able to accommodate at least 100 entries in the NAT table.
    ///
    static constexpr std::uint32_t NAT_ENTRY_MIN_TTL = 86400UL;

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+
    ///
    /// This field is set to an arbitrary value by the transmitting node in order to be able to match the response
    /// with the locally kept context. The function of this field is virtually identical to that of UDP/IP port
    /// numbers. This value can be set to zero safely if the sending node does not have multiple contexts to
    /// distinguish between.
    ///
    std::uint16_t session_id;
    ///
    /// UDP destination port number.
    ///
    std::uint16_t destination_port;
    ///
    /// Domain name or IP address where the payload should be forwarded to.
    /// Note that broadcast addresses are allowed here, for example, 255.255.255.255.
    /// Broadcasting with masquerading enabled works the same way as unicasting with masquerading enabled: the modem
    /// node should take care to channel all traffic arriving at the opened port from any source to the node that
    /// requested masquerading.
    /// The full domain name length may not exceed 253 octets, according to the DNS specification.
    /// Cyphal imposes a stricter length limit in order to reduce the memory and traffic burden on the bus: 45
    /// characters.
    /// 45 characters is the amount of space that is required to represent the longest possible form of an IPv6 address
    /// (an IPv4-mapped IPv6 address). Examples:
    ///   "forum.opencyphal.org"                          - domain name
    ///   "192.168.1.1"                                   - IPv4 address
    ///   "2001:0db8:85a3:0000:0000:8a2e:0370:7334"       - IPv6 address, full form
    ///   "2001:db8:85a3::8a2e:370:7334"                  - IPv6 address, same as above, short form (preferred)
    ///   "ABCD:ABCD:ABCD:ABCD:ABCD:ABCD:192.168.158.190" - IPv4-mapped IPv6, full form (length limit, 45 characters)
    ///
    nunavut::support::VariableLengthArray<std::uint8_t, 45> destination_address;
    ///
    /// Expect data back (i.e., instruct the modem to use the NAT table).
    ///
    bool use_masquerading;
    ///
    /// Use Datagram Transport Layer Security. Drop the packet if DTLS is not supported.
    /// Option flags.
    ///
    bool use_dtls;
    ///
    /// Effective payload. This data will be forwarded to the remote host verbatim.
    /// UDP packets that contain more than 508 bytes of payload may be dropped by some types of
    /// communication equipment. Refer to RFC 791 and 2460 for an in-depth review.
    /// Cyphal further limits the maximum packet size to reduce the memory and traffic burden on the nodes.
    ///
    nunavut::support::VariableLengthArray<std::uint8_t, 260> payload;

    nunavut::support::SerializeResult
    serialize(nunavut::support::bitspan out_buffer) const
    {
        const std::size_t capacity_bits = out_buffer.size();
        if ((static_cast<std::size_t>(capacity_bits)) < 2504UL)
        {
            return -nunavut::support::Error::SERIALIZATION_BUFFER_TOO_SMALL;
        }
        // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
        // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
        NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
        {   // saturated uint16 session_id
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(16ULL <= out_buffer.size());
            // Saturation code not emitted -- native representation matches the serialized representation.
            const auto _result3_ = out_buffer.setUxx(session_id, 16U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(16U);
        }
        {   // saturated uint16 destination_port
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(16ULL <= out_buffer.size());
            // Saturation code not emitted -- native representation matches the serialized representation.
            const auto _result3_ = out_buffer.setUxx(destination_port, 16U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(16U);
        }
        {   // saturated uint8[<=45] destination_address
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(368ULL <= out_buffer.size());
            if (destination_address.size() > 45)
            {
                return -nunavut::support::Error::REPRESENTATION_BAD_ARRAY_LENGTH;
            }
            // Array length prefix: truncated uint8
            const auto _result3_ = out_buffer.setUxx(destination_address.size(), 8U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(8U);
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            for (size_t _index2_ = 0U; _index2_ < destination_address.size(); ++_index2_)
            {
                NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
                NUNAVUT_ASSERT(8ULL <= out_buffer.size());
                // Saturation code not emitted -- native representation matches the serialized representation.
                const auto _result3_ = out_buffer.setUxx(destination_address[_index2_], 8U);
                if(not _result3_){
                    return -_result3_.error();
                }
                out_buffer.add_offset(8U);
            }
        }
        {   // saturated bool use_masquerading
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(1ULL <= out_buffer.size());
            auto _result2_ = out_buffer.setBit(use_masquerading);
            if(not _result2_){
                return -_result2_.error();
            }
            out_buffer.add_offset(1UL);
        }
        {   // saturated bool use_dtls
            NUNAVUT_ASSERT(1ULL <= out_buffer.size());
            auto _result2_ = out_buffer.setBit(use_dtls);
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
        {   // saturated uint8[<=260] payload
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(2096ULL <= out_buffer.size());
            if (payload.size() > 260)
            {
                return -nunavut::support::Error::REPRESENTATION_BAD_ARRAY_LENGTH;
            }
            // Array length prefix: truncated uint16
            const auto _result3_ = out_buffer.setUxx(payload.size(), 16U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(16U);
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            for (size_t _index2_ = 0U; _index2_ < payload.size(); ++_index2_)
            {
                NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
                NUNAVUT_ASSERT(8ULL <= out_buffer.size());
                // Saturation code not emitted -- native representation matches the serialized representation.
                const auto _result3_ = out_buffer.setUxx(payload[_index2_], 8U);
                if(not _result3_){
                    return -_result3_.error();
                }
                out_buffer.add_offset(8U);
            }
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT(out_buffer.offset() >= 64ULL);
        NUNAVUT_ASSERT(out_buffer.offset() <= 2504ULL);
        NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
        return out_buffer.offset_bytes_ceil();
    }

    nunavut::support::SerializeResult
    deserialize(nunavut::support::const_bitspan in_buffer)
    {
        const auto capacity_bits = in_buffer.size();
        // saturated uint16 session_id
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        session_id = in_buffer.getU16(16U);
        in_buffer.add_offset(16U);
        // saturated uint16 destination_port
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        destination_port = in_buffer.getU16(16U);
        in_buffer.add_offset(16U);
        // saturated uint8[<=45] destination_address
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        {
            // Array length prefix: truncated uint8
        const std::uint8_t _size0_ = in_buffer.getU8(8U);
        in_buffer.add_offset(8U);
            if ( _size0_ > 45U)
            {
                return -nunavut::support::Error::REPRESENTATION_BAD_ARRAY_LENGTH;
            }
            destination_address.reserve(_size0_);
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            for (size_t _index5_ = 0U; _index5_ < _size0_; ++_index5_)
            {
                // TODO This is terribly inefficient. We need to completely refactor this template to use C++ emplace and
                // move semantics instead of assuming C-style containers
                destination_address.push_back();
                NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            destination_address[_index5_] = in_buffer.getU8(8U);
            in_buffer.add_offset(8U);
            }
        }
        // saturated bool use_masquerading
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        use_masquerading = in_buffer.getBit();
        in_buffer.add_offset(1U);
        // saturated bool use_dtls
        use_dtls = in_buffer.getBit();
        in_buffer.add_offset(1U);
        // void6
        in_buffer.add_offset(6);
        // saturated uint8[<=260] payload
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        {
            // Array length prefix: truncated uint16
        const std::uint16_t _size0_ = in_buffer.getU16(16U);
        in_buffer.add_offset(16U);
            if ( _size0_ > 260U)
            {
                return -nunavut::support::Error::REPRESENTATION_BAD_ARRAY_LENGTH;
            }
            payload.reserve(_size0_);
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            for (size_t _index5_ = 0U; _index5_ < _size0_; ++_index5_)
            {
                // TODO This is terribly inefficient. We need to completely refactor this template to use C++ emplace and
                // move semantics instead of assuming C-style containers
                payload.push_back();
                NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            payload[_index5_] = in_buffer.getU8(8U);
            in_buffer.add_offset(8U);
            }
        }
        in_buffer.align_offset_to<8U>();
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
        NUNAVUT_ASSERT(capacity_bits >= _bits_got_);
        return { static_cast<std::size_t>(_bits_got_ / 8U) };
    }
};

} // namespace udp
} // namespace internet
} // namespace uavcan

#endif // UAVCAN_INTERNET_UDP_OUTGOING_PACKET_0_1_HPP_INCLUDED
