//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.0.9 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/uavcan/node/port/7510.List.0.1.dsdl
// Generated at:  2023-03-10 05:17:53.872975 UTC
// Is deprecated: yes
// Fixed port-ID: 7510
// Full name:     uavcan.node.port.List
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
//           _____  ______ _____  _____  ______ _____       _______ ______ _____
//          |  __ `|  ____|  __ `|  __ `|  ____/ ____|   /`|__   __|  ____|  __ `
//          | |  | | |__  | |__) | |__) | |__ | |       /  `  | |  | |__  | |  | |
//          | |  | |  __| |  ___/|  _  /|  __|| |      / /` ` | |  |  __| | |  | |
//          | |__| | |____| |    | | ` `| |___| |____ / ____ `| |  | |____| |__| |
//          |_____/|______|_|    |_|  `_`______`_____/_/    `_`_|  |______|_____/
//
// WARNING: this data type is deprecated and is nearing the end of its life cycle. Seek replacement.
#ifndef UAVCAN_NODE_PORT_LIST_0_1_HPP_INCLUDED
#define UAVCAN_NODE_PORT_LIST_0_1_HPP_INCLUDED

#include <nunavut/support/serialization.hpp>
#include <types/uavcan/node/port/ServiceIDList_0_1.hpp>
#include <types/uavcan/node/port/SubjectIDList_0_1.hpp>
#include <cstdint>
#include <limits>

namespace uavcan
{
namespace node
{
namespace port
{
// +-------------------------------------------------------------------------------------------------------------------+
// | LANGUAGE OPTION ASSERTIONS
// |    These static assertions ensure that the header is being used with
// | Nunavut C++ serialization support that is compatible with the language
// | options in effect when that support code was generated.
// +-------------------------------------------------------------------------------------------------------------------+
static_assert( nunavut::support::options::target_endianness == 1693710260,
              "/tmp/public_regulated_data_types/uavcan/node/port/7510.List.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/public_regulated_data_types/uavcan/node/port/7510.List.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 0,
              "/tmp/public_regulated_data_types/uavcan/node/port/7510.List.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/uavcan/node/port/7510.List.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 628873475,
              "/tmp/public_regulated_data_types/uavcan/node/port/7510.List.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/public_regulated_data_types/uavcan/node/port/7510.List.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/public_regulated_data_types/uavcan/node/port/7510.List.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/public_regulated_data_types/uavcan/node/port/7510.List.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/public_regulated_data_types/uavcan/node/port/7510.List.0.1.dsdl "
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
/// A list of ports that this node is using:
/// - Subjects published by this node (whether periodically or ad-hoc).
/// - Subjects that this node is subscribed to (a datalogger or a debugger would typically subscribe to all subjects).
/// - RPC services consumed by this node (i.e., service clients).
/// - RPC services provided by this node (i.e., service servers).
///
/// All nodes should implement this capability to provide network introspection and diagnostic capabilities.
/// This message should be published using the fixed subject-ID as follows:
/// - At the OPTIONAL priority level at least every MAX_PUBLICATION_PERIOD seconds.
/// - At the OPTIONAL or SLOW priority level within MAX_PUBLICATION_PERIOD after the port configuration is changed.
///
[[deprecated("uavcan.node.port.List.0.1 is reaching the end of its life; there may be a newer version available")]]
struct List_0_1 final
{
    struct _traits_  // The name is surrounded with underscores to avoid collisions with DSDL attributes.
    {
        _traits_() = delete;
        static constexpr bool HasFixedPortID = true;
        static constexpr std::uint16_t FixedPortId = 7510U;
        static constexpr bool IsServiceType = false;

        /// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
        /// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
        /// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
        /// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
        /// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
        /// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
        /// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.
        static constexpr std::size_t ExtentBytes                  = 8466UL;
        static constexpr std::size_t SerializationBufferSizeBytes = 8466UL;
        static_assert(ExtentBytes >= SerializationBufferSizeBytes, "Internal constraint violation");
        static_assert(ExtentBytes < (std::numeric_limits<std::size_t>::max() / 8U), "This message is too large to be handled by the selected types");
        struct TypeOf
        {
            TypeOf() = delete;
            using publishers = uavcan::node::port::SubjectIDList_0_1;
            using subscribers = uavcan::node::port::SubjectIDList_0_1;
            using clients = uavcan::node::port::ServiceIDList_0_1;
            using servers = uavcan::node::port::ServiceIDList_0_1;
        };
    };

    // +---------------------------------------------------------------------------------------------------------------+
    // | CONSTANTS
    // +---------------------------------------------------------------------------------------------------------------+
    ///
    /// [seconds]
    /// If the port configuration is not updated in this amount of time, the node should publish this message anyway.
    ///
    static constexpr std::uint8_t MAX_PUBLICATION_PERIOD = 10U;

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+

    _traits_::TypeOf::publishers publishers;

    _traits_::TypeOf::subscribers subscribers;

    _traits_::TypeOf::clients clients;

    _traits_::TypeOf::servers servers;
};

inline nunavut::support::SerializeResult serialize(const List_0_1& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    const std::size_t capacity_bits = out_buffer.size();
    if ((static_cast<std::size_t>(capacity_bits)) < 67728UL)
    {
        return -nunavut::support::Error::SerializationBufferTooSmall;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    {   // uavcan.node.port.SubjectIDList.0.1 publishers
        std::size_t _size_bytes0_ = 1025UL;  // Nested object (max) size, in bytes.
        // Reserve space for the delimiter header.
        auto _subspan0_ = out_buffer.subspan(32U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize(obj.publishers, _subspan0_.value());
        if (not _err0_)
        {
            return _err0_;
        }
        _size_bytes0_ = _err0_.value();
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        // Jump back to write the delimiter header after the nested object is serialized and its length is known.
        const auto _result3_ = out_buffer.setUxx(_size_bytes0_, 32U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(32U);
        out_buffer.add_offset(_size_bytes0_ * 8U);
        //
    }
    {
        const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
        if(not _result0_){
            return -_result0_.error();
        }
    }
    {   // uavcan.node.port.SubjectIDList.0.1 subscribers
        std::size_t _size_bytes0_ = 1025UL;  // Nested object (max) size, in bytes.
        // Reserve space for the delimiter header.
        auto _subspan0_ = out_buffer.subspan(32U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize(obj.subscribers, _subspan0_.value());
        if (not _err0_)
        {
            return _err0_;
        }
        _size_bytes0_ = _err0_.value();
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        // Jump back to write the delimiter header after the nested object is serialized and its length is known.
        const auto _result3_ = out_buffer.setUxx(_size_bytes0_, 32U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(32U);
        out_buffer.add_offset(_size_bytes0_ * 8U);
        //
    }
    {
        const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
        if(not _result0_){
            return -_result0_.error();
        }
    }
    {   // uavcan.node.port.ServiceIDList.0.1 clients
        std::size_t _size_bytes0_ = 64UL;  // Nested object (max) size, in bytes.
        // Reserve space for the delimiter header.
        auto _subspan0_ = out_buffer.subspan(32U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize(obj.clients, _subspan0_.value());
        if (not _err0_)
        {
            return _err0_;
        }
        _size_bytes0_ = _err0_.value();
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        // Jump back to write the delimiter header after the nested object is serialized and its length is known.
        const auto _result3_ = out_buffer.setUxx(_size_bytes0_, 32U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(32U);
        out_buffer.add_offset(_size_bytes0_ * 8U);
        //
    }
    {
        const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
        if(not _result0_){
            return -_result0_.error();
        }
    }
    {   // uavcan.node.port.ServiceIDList.0.1 servers
        std::size_t _size_bytes0_ = 64UL;  // Nested object (max) size, in bytes.
        // Reserve space for the delimiter header.
        auto _subspan0_ = out_buffer.subspan(32U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize(obj.servers, _subspan0_.value());
        if (not _err0_)
        {
            return _err0_;
        }
        _size_bytes0_ = _err0_.value();
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        // Jump back to write the delimiter header after the nested object is serialized and its length is known.
        const auto _result3_ = out_buffer.setUxx(_size_bytes0_, 32U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(32U);
        out_buffer.add_offset(_size_bytes0_ * 8U);
        //
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

inline nunavut::support::SerializeResult deserialize(List_0_1& obj,
                                                     nunavut::support::const_bitspan in_buffer)
{
    const auto capacity_bits = in_buffer.size();
    // uavcan.node.port.SubjectIDList.0.1 publishers
    {
        std::size_t _size_bytes1_ = in_buffer.size() / 8U;
        // Delimiter header: truncated uint32
        _size_bytes1_ = in_buffer.getU32(32U);
        in_buffer.add_offset(32U);
        if ((_size_bytes1_ * 8U) > in_buffer.size())
        {
            return -nunavut::support::Error::RepresentationBadDelimiterHeader;
        }
        const std::size_t _dh0_ = _size_bytes1_;
        {
            const auto _err1_ = deserialize(obj.publishers, in_buffer.subspan());
            if(_err1_){
                _size_bytes1_ = _err1_.value();
            }else{
                return -_err1_.error();
            }
        }
        // Advance the offset by the size of the delimiter header, even if the nested deserialization routine
        // consumed fewer bytes of data. This behavior implements the implicit truncation rule for nested objects.
        in_buffer.add_offset(_dh0_ * 8U);
    }
    in_buffer.align_offset_to<8U>();
    // uavcan.node.port.SubjectIDList.0.1 subscribers
    {
        std::size_t _size_bytes1_ = in_buffer.size() / 8U;
        // Delimiter header: truncated uint32
        _size_bytes1_ = in_buffer.getU32(32U);
        in_buffer.add_offset(32U);
        if ((_size_bytes1_ * 8U) > in_buffer.size())
        {
            return -nunavut::support::Error::RepresentationBadDelimiterHeader;
        }
        const std::size_t _dh0_ = _size_bytes1_;
        {
            const auto _err1_ = deserialize(obj.subscribers, in_buffer.subspan());
            if(_err1_){
                _size_bytes1_ = _err1_.value();
            }else{
                return -_err1_.error();
            }
        }
        // Advance the offset by the size of the delimiter header, even if the nested deserialization routine
        // consumed fewer bytes of data. This behavior implements the implicit truncation rule for nested objects.
        in_buffer.add_offset(_dh0_ * 8U);
    }
    in_buffer.align_offset_to<8U>();
    // uavcan.node.port.ServiceIDList.0.1 clients
    {
        std::size_t _size_bytes1_ = in_buffer.size() / 8U;
        // Delimiter header: truncated uint32
        _size_bytes1_ = in_buffer.getU32(32U);
        in_buffer.add_offset(32U);
        if ((_size_bytes1_ * 8U) > in_buffer.size())
        {
            return -nunavut::support::Error::RepresentationBadDelimiterHeader;
        }
        const std::size_t _dh0_ = _size_bytes1_;
        {
            const auto _err1_ = deserialize(obj.clients, in_buffer.subspan());
            if(_err1_){
                _size_bytes1_ = _err1_.value();
            }else{
                return -_err1_.error();
            }
        }
        // Advance the offset by the size of the delimiter header, even if the nested deserialization routine
        // consumed fewer bytes of data. This behavior implements the implicit truncation rule for nested objects.
        in_buffer.add_offset(_dh0_ * 8U);
    }
    in_buffer.align_offset_to<8U>();
    // uavcan.node.port.ServiceIDList.0.1 servers
    {
        std::size_t _size_bytes1_ = in_buffer.size() / 8U;
        // Delimiter header: truncated uint32
        _size_bytes1_ = in_buffer.getU32(32U);
        in_buffer.add_offset(32U);
        if ((_size_bytes1_ * 8U) > in_buffer.size())
        {
            return -nunavut::support::Error::RepresentationBadDelimiterHeader;
        }
        const std::size_t _dh0_ = _size_bytes1_;
        {
            const auto _err1_ = deserialize(obj.servers, in_buffer.subspan());
            if(_err1_){
                _size_bytes1_ = _err1_.value();
            }else{
                return -_err1_.error();
            }
        }
        // Advance the offset by the size of the delimiter header, even if the nested deserialization routine
        // consumed fewer bytes of data. This behavior implements the implicit truncation rule for nested objects.
        in_buffer.add_offset(_dh0_ * 8U);
    }
    in_buffer.align_offset_to<8U>();
    auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
    return { static_cast<std::size_t>(_bits_got_ / 8U) };
}

} // namespace port
} // namespace node
} // namespace uavcan

#endif // UAVCAN_NODE_PORT_LIST_0_1_HPP_INCLUDED
