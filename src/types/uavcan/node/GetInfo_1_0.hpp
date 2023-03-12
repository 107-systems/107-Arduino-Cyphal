//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.0.9 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/uavcan/node/430.GetInfo.1.0.dsdl
// Generated at:  2023-03-10 05:17:53.840605 UTC
// Is deprecated: no
// Fixed port-ID: 430
// Full name:     uavcan.node.GetInfo
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
#ifndef UAVCAN_NODE_GET_INFO_1_0_HPP_INCLUDED
#define UAVCAN_NODE_GET_INFO_1_0_HPP_INCLUDED

#include <nunavut/support/serialization.hpp>
#include <nunavut/support/variable_length_array.hpp>
#include <types/uavcan/node/Version_1_0.hpp>
#include <array>
#include <cstdint>
#include <limits>

namespace uavcan
{
namespace node
{
// +-------------------------------------------------------------------------------------------------------------------+
// | LANGUAGE OPTION ASSERTIONS
// |    These static assertions ensure that the header is being used with
// | Nunavut C++ serialization support that is compatible with the language
// | options in effect when that support code was generated.
// +-------------------------------------------------------------------------------------------------------------------+
static_assert( nunavut::support::options::target_endianness == 1693710260,
              "/tmp/public_regulated_data_types/uavcan/node/430.GetInfo.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/public_regulated_data_types/uavcan/node/430.GetInfo.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 0,
              "/tmp/public_regulated_data_types/uavcan/node/430.GetInfo.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/uavcan/node/430.GetInfo.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 628873475,
              "/tmp/public_regulated_data_types/uavcan/node/430.GetInfo.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/public_regulated_data_types/uavcan/node/430.GetInfo.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/public_regulated_data_types/uavcan/node/430.GetInfo.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/public_regulated_data_types/uavcan/node/430.GetInfo.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/public_regulated_data_types/uavcan/node/430.GetInfo.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );

namespace GetInfo
{

// +-------------------------------------------------------------------------------------------------------------------+
// | This implementation uses the C++17 standard library variant type with wrappers for the emplace and
// | get_if methods to support forward-compatibility with the C++14 version of this object. The union_value type
// | extends std::variant and can be used with the entire set of variant methods. Using std::variant directly does mean
// | your code will not be backwards compatible with the C++14 version of this object.
// +-------------------------------------------------------------------------------------------------------------------+
///
/// Full node info request.
/// All of the returned information shall be static (unchanged) while the node is running.
/// It is highly recommended to support this service on all nodes.
///
struct Request_1_0 final
{
    struct _traits_  // The name is surrounded with underscores to avoid collisions with DSDL attributes.
    {
        _traits_() = delete;
        static constexpr bool HasFixedPortID = true;
        static constexpr std::uint16_t FixedPortId = 430U;
        static constexpr bool IsServiceType  = true;
        static constexpr bool IsService      = false;
        static constexpr bool IsRequest      = true;
        static constexpr bool IsResponse     = false;
        /// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
        /// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
        /// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
        /// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
        /// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
        /// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
        /// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.
        static constexpr std::size_t ExtentBytes                  = 0UL;
        static constexpr std::size_t SerializationBufferSizeBytes = 0UL;
        static_assert(ExtentBytes >= SerializationBufferSizeBytes, "Internal constraint violation");
        static_assert(ExtentBytes < (std::numeric_limits<std::size_t>::max() / 8U), "This message is too large to be handled by the selected types");
    };
};

inline nunavut::support::SerializeResult serialize(const Request_1_0& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    (void)(out_buffer);
    (void)(obj);
    return 0U;
}

inline nunavut::support::SerializeResult deserialize(Request_1_0& obj,
                                                     nunavut::support::const_bitspan in_buffer)
{
    (void)(in_buffer);
    (void)(obj);
    return 0;
}

// +-------------------------------------------------------------------------------------------------------------------+
// | This implementation uses the C++17 standard library variant type with wrappers for the emplace and
// | get_if methods to support forward-compatibility with the C++14 version of this object. The union_value type
// | extends std::variant and can be used with the entire set of variant methods. Using std::variant directly does mean
// | your code will not be backwards compatible with the C++14 version of this object.
// +-------------------------------------------------------------------------------------------------------------------+

struct Response_1_0 final
{
    struct _traits_  // The name is surrounded with underscores to avoid collisions with DSDL attributes.
    {
        _traits_() = delete;
        static constexpr bool HasFixedPortID = true;
        static constexpr std::uint16_t FixedPortId = 430U;
        static constexpr bool IsServiceType  = true;
        static constexpr bool IsService      = false;
        static constexpr bool IsRequest      = false;
        static constexpr bool IsResponse     = true;
        /// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
        /// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
        /// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
        /// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
        /// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
        /// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
        /// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.
        static constexpr std::size_t ExtentBytes                  = 448UL;
        static constexpr std::size_t SerializationBufferSizeBytes = 313UL;
        static_assert(ExtentBytes >= SerializationBufferSizeBytes, "Internal constraint violation");
        static_assert(ExtentBytes < (std::numeric_limits<std::size_t>::max() / 8U), "This message is too large to be handled by the selected types");
        struct TypeOf
        {
            TypeOf() = delete;
            using protocol_version = uavcan::node::Version_1_0;
            using hardware_version = uavcan::node::Version_1_0;
            using software_version = uavcan::node::Version_1_0;
            using software_vcs_revision_id = std::uint64_t;
            using unique_id = std::array<std::uint8_t,16>;
            using name = nunavut::support::VariableLengthArray<std::uint8_t, 50>;
            using software_image_crc = nunavut::support::VariableLengthArray<std::uint64_t, 1>;
            using certificate_of_authenticity = nunavut::support::VariableLengthArray<std::uint8_t, 222>;
        };
    };

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+
    ///
    /// The Cyphal protocol version implemented on this node, both major and minor.
    /// Not to be changed while the node is running.
    ///
    _traits_::TypeOf::protocol_version protocol_version;

    _traits_::TypeOf::hardware_version hardware_version;
    ///
    /// The version information shall not be changed while the node is running.
    /// The correct hardware version shall be reported at all times, excepting software-only nodes, in which
    /// case it should be set to zeros.
    /// If the node is equipped with a Cyphal-capable bootloader, the bootloader should report the software
    /// version of the installed application, if there is any; if no application is found, zeros should be reported.
    ///
    _traits_::TypeOf::software_version software_version;
    ///
    /// A version control system (VCS) revision number or hash. Not to be changed while the node is running.
    /// For example, this field can be used for reporting the short git commit hash of the current
    /// software revision.
    /// Set to zero if not used.
    ///
    _traits_::TypeOf::software_vcs_revision_id software_vcs_revision_id{};
    ///
    /// The unique-ID (UID) is a 128-bit long sequence that is likely to be globally unique per node.
    /// The vendor shall ensure that the probability of a collision with any other node UID globally is negligibly low.
    /// UID is defined once per hardware unit and should never be changed.
    /// All zeros is not a valid UID.
    /// If the node is equipped with a Cyphal-capable bootloader, the bootloader shall use the same UID.
    ///
    _traits_::TypeOf::unique_id unique_id{};
    ///
    /// Human-readable non-empty ASCII node name. An empty name is not permitted.
    /// The name shall not be changed while the node is running.
    /// Allowed characters are: a-z (lowercase ASCII letters) 0-9 (decimal digits) . (dot) - (dash) _ (underscore).
    /// Node name is a reversed Internet domain name (like Java packages), e.g. "com.manufacturer.project.product".
    ///
    _traits_::TypeOf::name name{};
    ///
    /// The value of an arbitrary hash function applied to the software image. Not to be changed while the node is
    /// running.
    /// This field can be used to detect whether the software or firmware running on the node is an exact
    /// same version as a certain specific revision. This field provides a very strong identity guarantee,
    /// unlike the version fields above, which can be the same for different builds of the software.
    /// As can be seen from its definition, this field is optional.
    ///
    /// The exact hash function and the methods of its application are implementation-defined.
    /// However, implementations are recommended to adhere to the following guidelines, fully or partially:
    ///   - The hash function should be CRC-64-WE.
    ///   - The hash function should be applied to the entire application image padded to 8 bytes.
    ///   - If the computed image CRC is stored within the software image itself, the value of
    ///     the hash function becomes ill-defined, because it becomes recursively dependent on itself.
    ///     In order to circumvent this issue, while computing or checking the CRC, its value stored
    ///     within the image should be zeroed out.
    ///
    _traits_::TypeOf::software_image_crc software_image_crc{};
    ///
    /// The certificate of authenticity (COA) of the node, 222 bytes max, optional. This field can be used for
    /// reporting digital signatures (e.g., RSA-1776, or ECDSA if a higher degree of cryptographic strength is desired).
    /// Leave empty if not used. Not to be changed while the node is running.
    ///
    _traits_::TypeOf::certificate_of_authenticity certificate_of_authenticity{};
};

inline nunavut::support::SerializeResult serialize(const Response_1_0& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    const std::size_t capacity_bits = out_buffer.size();
    if ((static_cast<std::size_t>(capacity_bits)) < 2504UL)
    {
        return -nunavut::support::Error::SerializationBufferTooSmall;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    {   // uavcan.node.Version.1.0 protocol_version
        std::size_t _size_bytes0_ = 2UL;  // Nested object (max) size, in bytes.
        auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize(obj.protocol_version, _subspan0_.value());
        if (not _err0_)
        {
            return _err0_;
        }
        _size_bytes0_ = _err0_.value();
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        out_buffer.add_offset(_size_bytes0_ * 8U);
        //
    }
    {
        const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
        if(not _result0_){
            return -_result0_.error();
        }
    }
    {   // uavcan.node.Version.1.0 hardware_version
        std::size_t _size_bytes0_ = 2UL;  // Nested object (max) size, in bytes.
        auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize(obj.hardware_version, _subspan0_.value());
        if (not _err0_)
        {
            return _err0_;
        }
        _size_bytes0_ = _err0_.value();
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        out_buffer.add_offset(_size_bytes0_ * 8U);
        //
    }
    {
        const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
        if(not _result0_){
            return -_result0_.error();
        }
    }
    {   // uavcan.node.Version.1.0 software_version
        std::size_t _size_bytes0_ = 2UL;  // Nested object (max) size, in bytes.
        auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize(obj.software_version, _subspan0_.value());
        if (not _err0_)
        {
            return _err0_;
        }
        _size_bytes0_ = _err0_.value();
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        out_buffer.add_offset(_size_bytes0_ * 8U);
        //
    }
    {   // saturated uint64 software_vcs_revision_id
        // Saturation code not emitted -- native representation matches the serialized representation.
        const auto _result3_ = out_buffer.setUxx(obj.software_vcs_revision_id, 64U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(64U);
    }
    {   // saturated uint8[16] unique_id
        const std::size_t _origin0_ = out_buffer.offset();
        for (std::size_t _index1_ = 0U; _index1_ < 16UL; ++_index1_)
        {
            // Saturation code not emitted -- native representation matches the serialized representation.
            const auto _result3_ = out_buffer.setUxx(obj.unique_id[_index1_], 8U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(8U);
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        (void) _origin0_;
    }
    {   // saturated uint8[<=50] name
        if (obj.name.size() > 50)
        {
            return -nunavut::support::Error::SerializationBadArrayLength;
        }
        // Array length prefix: truncated uint8
        const auto _result3_ = out_buffer.setUxx(obj.name.size(), 8U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(8U);
        for (std::size_t _index2_ = 0U; _index2_ < obj.name.size(); ++_index2_)
        {
            // Saturation code not emitted -- native representation matches the serialized representation.
            const auto _result3_ = out_buffer.setUxx(obj.name[_index2_], 8U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(8U);
        }
    }
    {   // saturated uint64[<=1] software_image_crc
        if (obj.software_image_crc.size() > 1)
        {
            return -nunavut::support::Error::SerializationBadArrayLength;
        }
        // Array length prefix: truncated uint8
        const auto _result3_ = out_buffer.setUxx(obj.software_image_crc.size(), 8U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(8U);
        for (std::size_t _index2_ = 0U; _index2_ < obj.software_image_crc.size(); ++_index2_)
        {
            // Saturation code not emitted -- native representation matches the serialized representation.
            const auto _result3_ = out_buffer.setUxx(obj.software_image_crc[_index2_], 64U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(64U);
        }
    }
    {   // saturated uint8[<=222] certificate_of_authenticity
        if (obj.certificate_of_authenticity.size() > 222)
        {
            return -nunavut::support::Error::SerializationBadArrayLength;
        }
        // Array length prefix: truncated uint8
        const auto _result3_ = out_buffer.setUxx(obj.certificate_of_authenticity.size(), 8U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(8U);
        for (std::size_t _index2_ = 0U; _index2_ < obj.certificate_of_authenticity.size(); ++_index2_)
        {
            // Saturation code not emitted -- native representation matches the serialized representation.
            const auto _result3_ = out_buffer.setUxx(obj.certificate_of_authenticity[_index2_], 8U);
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
    return out_buffer.offset_bytes_ceil();
}

inline nunavut::support::SerializeResult deserialize(Response_1_0& obj,
                                                     nunavut::support::const_bitspan in_buffer)
{
    const auto capacity_bits = in_buffer.size();
    // uavcan.node.Version.1.0 protocol_version
    {
        std::size_t _size_bytes1_ = in_buffer.size() / 8U;
        {
            const auto _err1_ = deserialize(obj.protocol_version, in_buffer.subspan());
            if(_err1_){
                _size_bytes1_ = _err1_.value();
            }else{
                return -_err1_.error();
            }
        }
        in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
    }
    in_buffer.align_offset_to<8U>();
    // uavcan.node.Version.1.0 hardware_version
    {
        std::size_t _size_bytes1_ = in_buffer.size() / 8U;
        {
            const auto _err1_ = deserialize(obj.hardware_version, in_buffer.subspan());
            if(_err1_){
                _size_bytes1_ = _err1_.value();
            }else{
                return -_err1_.error();
            }
        }
        in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
    }
    in_buffer.align_offset_to<8U>();
    // uavcan.node.Version.1.0 software_version
    {
        std::size_t _size_bytes1_ = in_buffer.size() / 8U;
        {
            const auto _err1_ = deserialize(obj.software_version, in_buffer.subspan());
            if(_err1_){
                _size_bytes1_ = _err1_.value();
            }else{
                return -_err1_.error();
            }
        }
        in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
    }
    // saturated uint64 software_vcs_revision_id
    obj.software_vcs_revision_id = in_buffer.getU64(64U);
    in_buffer.add_offset(64U);
    // saturated uint8[16] unique_id
    for (std::size_t _index4_ = 0U; _index4_ < 16UL; ++_index4_)
    {
        obj.unique_id[_index4_] = in_buffer.getU8(8U);
        in_buffer.add_offset(8U);
    }
    // saturated uint8[<=50] name
    {
        // Array length prefix: truncated uint8
    const std::size_t _size0_ = in_buffer.getU8(8U);
    in_buffer.add_offset(8U);
        if ( _size0_ > 50U)
        {
            return -nunavut::support::Error::SerializationBadArrayLength;
        }
        obj.name.reserve(_size0_);
        for (std::size_t _index5_ = 0U; _index5_ < _size0_; ++_index5_)
        {
            // TODO This is terribly inefficient. We need to completely refactor this template to use C++ emplace and
            // move semantics instead of assuming C-style containers
            obj.name.push_back();
            obj.name[_index5_] = in_buffer.getU8(8U);
        in_buffer.add_offset(8U);
        }
    }
    // saturated uint64[<=1] software_image_crc
    {
        // Array length prefix: truncated uint8
    const std::size_t _size0_ = in_buffer.getU8(8U);
    in_buffer.add_offset(8U);
        if ( _size0_ > 1U)
        {
            return -nunavut::support::Error::SerializationBadArrayLength;
        }
        obj.software_image_crc.reserve(_size0_);
        for (std::size_t _index5_ = 0U; _index5_ < _size0_; ++_index5_)
        {
            // TODO This is terribly inefficient. We need to completely refactor this template to use C++ emplace and
            // move semantics instead of assuming C-style containers
            obj.software_image_crc.push_back();
            obj.software_image_crc[_index5_] = in_buffer.getU64(64U);
        in_buffer.add_offset(64U);
        }
    }
    // saturated uint8[<=222] certificate_of_authenticity
    {
        // Array length prefix: truncated uint8
    const std::size_t _size0_ = in_buffer.getU8(8U);
    in_buffer.add_offset(8U);
        if ( _size0_ > 222U)
        {
            return -nunavut::support::Error::SerializationBadArrayLength;
        }
        obj.certificate_of_authenticity.reserve(_size0_);
        for (std::size_t _index5_ = 0U; _index5_ < _size0_; ++_index5_)
        {
            // TODO This is terribly inefficient. We need to completely refactor this template to use C++ emplace and
            // move semantics instead of assuming C-style containers
            obj.certificate_of_authenticity.push_back();
            obj.certificate_of_authenticity[_index5_] = in_buffer.getU8(8U);
        in_buffer.add_offset(8U);
        }
    }
    in_buffer.align_offset_to<8U>();
    auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
    return { static_cast<std::size_t>(_bits_got_ / 8U) };
}

}  // namespace GetInfo

struct GetInfo_1_0
{
    GetInfo_1_0() = delete;

    using Request  = GetInfo::Request_1_0;
    using Response = GetInfo::Response_1_0;

    struct _traits_
    {
        _traits_() = delete;

        static constexpr bool IsServiceType = true;
        static constexpr bool IsService = true;
        static constexpr bool IsRequest = false;
        static constexpr bool IsResponse = false;
    };
};

} // namespace node
} // namespace uavcan

#endif // UAVCAN_NODE_GET_INFO_1_0_HPP_INCLUDED
