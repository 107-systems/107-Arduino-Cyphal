//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.0.0 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/uavcan/metatransport/udp/Endpoint.0.1.dsdl
// Generated at:  2023-01-29 16:46:55.333563 UTC
// Is deprecated: yes
// Fixed port-ID: None
// Full name:     uavcan.metatransport.udp.Endpoint
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
#ifndef UAVCAN_METATRANSPORT_UDP_ENDPOINT_0_1_HPP_INCLUDED
#define UAVCAN_METATRANSPORT_UDP_ENDPOINT_0_1_HPP_INCLUDED

#include <nunavut/support/serialization.hpp>
#include <array>
#include <cstdint>

namespace uavcan
{
namespace metatransport
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
              "/tmp/public_regulated_data_types/uavcan/metatransport/udp/Endpoint.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/public_regulated_data_types/uavcan/metatransport/udp/Endpoint.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 1,
              "/tmp/public_regulated_data_types/uavcan/metatransport/udp/Endpoint.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/uavcan/metatransport/udp/Endpoint.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 3161622713,
              "/tmp/public_regulated_data_types/uavcan/metatransport/udp/Endpoint.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/public_regulated_data_types/uavcan/metatransport/udp/Endpoint.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/public_regulated_data_types/uavcan/metatransport/udp/Endpoint.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/public_regulated_data_types/uavcan/metatransport/udp/Endpoint.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/public_regulated_data_types/uavcan/metatransport/udp/Endpoint.0.1.dsdl "
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
/// A UDP/IP endpoint address specification.
///
struct Endpoint_0_1 final
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

    static constexpr std::size_t EXTENT_BYTES                    =32UL;
    static constexpr std::size_t SERIALIZATION_BUFFER_SIZE_BYTES =32UL;
    static_assert(EXTENT_BYTES >= SERIALIZATION_BUFFER_SIZE_BYTES, "Internal constraint violation");
    static_assert(EXTENT_BYTES < (std::numeric_limits<std::size_t>::max() /8U), "This message is too large to be handled by current types!");

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+
    ///
    /// The IP address of the host in the network byte order (big endian).
    /// IPv6 addresses are represented as-is.
    /// IPv4 addresses are represented using IPv4-mapped IPv6 addresses.
    ///
    std::array<std::uint8_t,16> ip_address{};
    ///
    /// MAC address of the host in the network byte order (big endian).
    ///
    std::array<std::uint8_t,6> mac_address{};
    ///
    /// The UDP port number.
    ///
    std::uint16_t port{};

    nunavut::support::SerializeResult
    serialize(nunavut::support::bitspan out_buffer) const
    {
        const std::size_t capacity_bits = out_buffer.size();
        if ((static_cast<std::size_t>(capacity_bits)) < 256UL)
        {
            return -nunavut::support::Error::SERIALIZATION_BUFFER_TOO_SMALL;
        }
        // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
        // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
        NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
        {   // saturated uint8[16] ip_address
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(128ULL <= out_buffer.size());
            const std::size_t _origin0_ = out_buffer.offset();
            for (size_t _index1_ = 0U; _index1_ < 16UL; ++_index1_)
            {
                NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
                NUNAVUT_ASSERT(8ULL <= out_buffer.size());
                // Saturation code not emitted -- native representation matches the serialized representation.
                const auto _result3_ = out_buffer.setUxx(ip_address[_index1_], 8U);
                if(not _result3_){
                    return -_result3_.error();
                }
                out_buffer.add_offset(8U);
            }
            // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
            NUNAVUT_ASSERT((out_buffer.offset() - _origin0_) == 128ULL);
            (void) _origin0_;
        }
        {   // saturated uint8[6] mac_address
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(48ULL <= out_buffer.size());
            const std::size_t _origin0_ = out_buffer.offset();
            for (size_t _index1_ = 0U; _index1_ < 6UL; ++_index1_)
            {
                NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
                NUNAVUT_ASSERT(8ULL <= out_buffer.size());
                // Saturation code not emitted -- native representation matches the serialized representation.
                const auto _result3_ = out_buffer.setUxx(mac_address[_index1_], 8U);
                if(not _result3_){
                    return -_result3_.error();
                }
                out_buffer.add_offset(8U);
            }
            // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
            NUNAVUT_ASSERT((out_buffer.offset() - _origin0_) == 48ULL);
            (void) _origin0_;
        }
        {   // saturated uint16 port
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(16ULL <= out_buffer.size());
            // Saturation code not emitted -- native representation matches the serialized representation.
            const auto _result3_ = out_buffer.setUxx(port, 16U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(16U);
        }
        {   // void64
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(64ULL <= out_buffer.size());
            auto _result1_ = out_buffer.setZeros(64UL);
            if(not _result1_){
                return -_result1_.error();
            }
            out_buffer.add_offset(64UL);
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT(out_buffer.offset() == 256ULL);
        NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
        return out_buffer.offset_bytes_ceil();
    }

    nunavut::support::SerializeResult
    deserialize(nunavut::support::const_bitspan in_buffer)
    {
        const auto capacity_bits = in_buffer.size();
        // saturated uint8[16] ip_address
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        for (size_t _index4_ = 0U; _index4_ < 16UL; ++_index4_)
        {
            NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            ip_address[_index4_] = in_buffer.getU8(8U);
            in_buffer.add_offset(8U);
        }
        // saturated uint8[6] mac_address
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        for (size_t _index4_ = 0U; _index4_ < 6UL; ++_index4_)
        {
            NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            mac_address[_index4_] = in_buffer.getU8(8U);
            in_buffer.add_offset(8U);
        }
        // saturated uint16 port
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        port = in_buffer.getU16(16U);
        in_buffer.add_offset(16U);
        // void64
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        in_buffer.add_offset(64);
        in_buffer.align_offset_to<8U>();
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
        NUNAVUT_ASSERT(capacity_bits >= _bits_got_);
        return { static_cast<std::size_t>(_bits_got_ / 8U) };
    }
};

} // namespace udp
} // namespace metatransport
} // namespace uavcan

#endif // UAVCAN_METATRANSPORT_UDP_ENDPOINT_0_1_HPP_INCLUDED
