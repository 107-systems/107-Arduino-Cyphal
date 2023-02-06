//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.0.0 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/uavcan/internet/udp/500.HandleIncomingPacket.0.2.dsdl
// Generated at:  2023-01-29 16:46:55.699460 UTC
// Is deprecated: no
// Fixed port-ID: 500
// Full name:     uavcan.internet.udp.HandleIncomingPacket
// Type Version:  0.2
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
#ifndef UAVCAN_INTERNET_UDP_HANDLE_INCOMING_PACKET_0_2_HPP_INCLUDED
#define UAVCAN_INTERNET_UDP_HANDLE_INCOMING_PACKET_0_2_HPP_INCLUDED

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
              "/tmp/public_regulated_data_types/uavcan/internet/udp/500.HandleIncomingPacket.0.2.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/public_regulated_data_types/uavcan/internet/udp/500.HandleIncomingPacket.0.2.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 1,
              "/tmp/public_regulated_data_types/uavcan/internet/udp/500.HandleIncomingPacket.0.2.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/uavcan/internet/udp/500.HandleIncomingPacket.0.2.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 3161622713,
              "/tmp/public_regulated_data_types/uavcan/internet/udp/500.HandleIncomingPacket.0.2.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/public_regulated_data_types/uavcan/internet/udp/500.HandleIncomingPacket.0.2.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/public_regulated_data_types/uavcan/internet/udp/500.HandleIncomingPacket.0.2.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/public_regulated_data_types/uavcan/internet/udp/500.HandleIncomingPacket.0.2.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/public_regulated_data_types/uavcan/internet/udp/500.HandleIncomingPacket.0.2.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );

namespace HandleIncomingPacket
{

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
/// This message carries UDP packets sent from a remote host on the Internet or a LAN to a node on the local Cyphal bus.
/// Please refer to the definition of the message type OutgoingPacket for a general overview of the packet forwarding
/// logic.
/// This data type has been made a service type rather than a message type in order to make its transfers addressable,
/// allowing nodes to employ hardware acceptance filters for filtering out forwarded datagrams that are not addressed
/// to them. Additionally, requiring the destination nodes to always respond upon reception of the forwarded datagram
/// opens interesting opportunities for future extensions of the forwarding protocol. If the service invocation times
/// out, the modem node is permitted to remove the corresponding entry from the NAT table immediately, not waiting
/// for its TTL to expire.
/// It should be noted that this data type definition intentionally leaves out the source address. This is done in
/// order to simplify the implementation, reduce the bus traffic overhead, and because the nature of the
/// communication patterns proposed by this set of messages does not provide a valid way to implement server hosts
/// on the local Cyphal bus. It is assumed that local nodes can be only clients, and therefore, they will be able to
/// determine the address of the sender simply by mapping the field session_id to their internally maintained states.
/// Furthermore, it is uncertain what is the optimal way of representing the source address for
/// client nodes: it is assumed that the local nodes will mostly use DNS names rather than IP addresses, so if there
/// was a source address field, modem nodes would have to perform reverse mapping from the IP address they received
/// the datagram from to the corresponding DNS name that was used by the local node with the outgoing message. This
/// approach creates a number of troubling corner cases and adds a fair amount of hidden complexities to the
/// implementation of modem nodes.
/// It is recommended to perform service invocations at the same transfer priority level as was used for broadcasting
/// the latest matching message of type OutgoingPacket. However, meeting this recommendation would require the modem
/// node to implement additional logic, which may be undesirable. Therefore, implementers are free to deviate from
/// this recommendation and resort to a fixed priority level instead. In the case of a fixed priority level, it is
/// advised to use the lowest transfer priority level.
///
struct Request_0_2 final
{
    // +---------------------------------------------------------------------------------------------------------------+
    // | PORT IDENTIFIERS
    // +---------------------------------------------------------------------------------------------------------------+
    static constexpr bool HasFixedPortID = true;
    static constexpr std::uint16_t FixedPortId = 500U;
    static constexpr bool IsServiceType = true;
    static constexpr bool IsService = false;
    static constexpr bool IsRequest = true;
    static constexpr bool IsResponse = false;
    /// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
    /// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
    /// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
    /// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
    /// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
    /// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
    /// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.

    static constexpr std::size_t EXTENT_BYTES                    =600UL;
    static constexpr std::size_t SERIALIZATION_BUFFER_SIZE_BYTES =512UL;
    static_assert(EXTENT_BYTES >= SERIALIZATION_BUFFER_SIZE_BYTES, "Internal constraint violation");
    static_assert(EXTENT_BYTES < (std::numeric_limits<std::size_t>::max() /8U), "This message is too large to be handled by current types!");

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+
    ///
    /// This field shall contain the same value that was used by the local node when sending the corresponding outgoing
    /// packet using the message type OutgoingPacket. This value will be used by the local node to match the response
    /// with its local context.
    ///
    std::uint16_t session_id{};
    ///
    /// Effective payload. This data will be forwarded from the remote host verbatim.
    /// UDP packets that contain more than 508 bytes of payload may be dropped by some types of
    /// communication equipment. Refer to RFC 791 and 2460 for an in-depth review.
    /// Datagrams that exceed the capacity of this field should be discarded by the modem node.
    ///
    nunavut::support::VariableLengthArray<std::uint8_t, 508> payload{};

    nunavut::support::SerializeResult
    serialize(nunavut::support::bitspan out_buffer) const
    {
        const std::size_t capacity_bits = out_buffer.size();
        if ((static_cast<std::size_t>(capacity_bits)) < 4096UL)
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
        {   // saturated uint8[<=508] payload
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(4080ULL <= out_buffer.size());
            if (payload.size() > 508)
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
        NUNAVUT_ASSERT(out_buffer.offset() >= 32ULL);
        NUNAVUT_ASSERT(out_buffer.offset() <= 4096ULL);
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
        // saturated uint8[<=508] payload
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        {
            // Array length prefix: truncated uint16
        const std::uint16_t _size0_ = in_buffer.getU16(16U);
        in_buffer.add_offset(16U);
            if ( _size0_ > 508U)
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

struct Response_0_2 final
{
    // +---------------------------------------------------------------------------------------------------------------+
    // | PORT IDENTIFIERS
    // +---------------------------------------------------------------------------------------------------------------+
    static constexpr bool HasFixedPortID = true;
    static constexpr std::uint16_t FixedPortId = 500U;
    static constexpr bool IsServiceType = true;
    static constexpr bool IsService = false;
    static constexpr bool IsRequest = false;
    static constexpr bool IsResponse = true;
    /// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
    /// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
    /// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
    /// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
    /// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
    /// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
    /// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.

    static constexpr std::size_t EXTENT_BYTES                    =63UL;
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

struct Service_0_2 {
    static constexpr bool IsServiceType = true;
    static constexpr bool IsService = true;
    static constexpr bool IsRequest = false;
    static constexpr bool IsResponse = false;

    using Request = Request_0_2;
    using Response = Response_0_2;
};

} // namespace HandleIncomingPacket_0_2

} // namespace udp
} // namespace internet
} // namespace uavcan

#endif // UAVCAN_INTERNET_UDP_HANDLE_INCOMING_PACKET_0_2_HPP_INCLUDED
