//
// This is an AUTO-GENERATED UAVCAN DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-1.9.0 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/uavcan/file/408.Read.1.1.dsdl
// Generated at:  2023-01-18 06:33:55.863277 UTC
// Is deprecated: no
// Fixed port-ID: 408
// Full name:     uavcan.file.Read
// Type Version:  1.1
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
#ifndef UAVCAN_FILE_READ_1_1_HPP_INCLUDED
#define UAVCAN_FILE_READ_1_1_HPP_INCLUDED

#include "nunavut/support/serialization.hpp"
#include "uavcan/file/Error_1_0.hpp"
#include "uavcan/file/Path_2_0.hpp"
#include "uavcan/primitive/Unstructured_1_0.hpp"
#include <cstdint>

namespace uavcan
{
namespace file
{
// +-------------------------------------------------------------------------------------------------------------------+
// | LANGUAGE OPTION ASSERTIONS
// |    These static assertions ensure that the header is being used with
// | Nunavut C++ serialization support that is compatible with the language
// | options in effect when that support code was generated.
// +-------------------------------------------------------------------------------------------------------------------+
static_assert( nunavut::support::options::target_endianness == 1693710260,
              "/tmp/public_regulated_data_types/uavcan/file/408.Read.1.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/public_regulated_data_types/uavcan/file/408.Read.1.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 1,
              "/tmp/public_regulated_data_types/uavcan/file/408.Read.1.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/uavcan/file/408.Read.1.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 3161622713,
              "/tmp/public_regulated_data_types/uavcan/file/408.Read.1.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/public_regulated_data_types/uavcan/file/408.Read.1.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/public_regulated_data_types/uavcan/file/408.Read.1.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/public_regulated_data_types/uavcan/file/408.Read.1.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/public_regulated_data_types/uavcan/file/408.Read.1.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );

namespace Read
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
/// Read file from a remote node.
/// There are two possible outcomes of a successful call:
///  1. Data array size equals its capacity. This means that the end of the file is not reached yet.
///  2. Data array size is less than its capacity, possibly zero. This means that the end of the file is reached.
/// Thus, if the client needs to fetch the entire file, it should repeatedly call this service while increasing the
/// offset, until a non-full data array is returned.
/// If the object pointed by 'path' cannot be read (e.g. it is a directory or it does not exist), an appropriate error
/// code will be returned, and the data array will be empty.
/// It is easy to see that this protocol is prone to race conditions because the remote file can be modified
/// between read operations which might result in the client obtaining a damaged file. To combat this,
/// application designers are recommended to adhere to the following convention. Let every file whose integrity
/// is of interest have a hash or a digital signature, which is stored in an adjacent file under the same name
/// suffixed with the appropriate extension according to the type of hash or digital signature used.
/// For example, let there be file "image.bin", integrity of which shall be ensured by the client upon downloading.
/// Suppose that the file is hashed using SHA-256, so the appropriate file extension for the hash would be
/// ".sha256". Following this convention, the hash of "image.bin" would be stored in "image.bin.sha256".
/// After downloading the file, the client would read the hash (being small, the hash can be read in a single
/// request) and check it against a locally computed value. Some servers may opt to generate such hash files
/// automatically as necessary; for example, if such file is requested but it does not exist, the server would
/// compute the necessary signature or hash (the type of hash/signature can be deduced from the requested file
/// extension) and return it as if the file existed. Obviously, this would be impractical for very large files;
/// in that case, hash/signature should be pre-computed and stored in a real file. If this approach is followed,
/// implementers are advised to use only SHA-256 for hashing, in order to reduce the number of fielded
/// incompatible implementations.
///
struct Request_1_1 final
{
    // +---------------------------------------------------------------------------------------------------------------+
    // | PORT IDENTIFIERS
    // +---------------------------------------------------------------------------------------------------------------+
    static constexpr bool HasFixedPortID = true;
    static constexpr std::uint16_t FixedPortId = 408U;
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

    static constexpr std::size_t EXTENT_BYTES                    =300UL;
    static constexpr std::size_t SERIALIZATION_BUFFER_SIZE_BYTES =261UL;
    static_assert(EXTENT_BYTES >= SERIALIZATION_BUFFER_SIZE_BYTES, "Internal constraint violation");
    static_assert(EXTENT_BYTES < (std::numeric_limits<std::size_t>::max() /8U), "This message is too large to be handled by current types!");

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+

    std::uint64_t offset;

    uavcan::file::Path_2_0 path;

    nunavut::support::SerializeResult
    serialize(nunavut::support::bitspan out_buffer) const
    {
        const std::size_t capacity_bits = out_buffer.size();
        if ((static_cast<std::size_t>(capacity_bits)) < 2088UL)
        {
            return -nunavut::support::Error::SERIALIZATION_BUFFER_TOO_SMALL;
        }
        // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
        // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
        NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
        {   // truncated uint40 offset
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(40ULL <= out_buffer.size());
            const auto _result3_ = out_buffer.setUxx(offset, 40U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(40U);
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        {   // uavcan.file.Path.2.0 path
            NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(2048ULL <= out_buffer.size());
            std::size_t _size_bytes0_ = 256UL;  // Nested object (max) size, in bytes.
            auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
            if(not _subspan0_){
                return -_subspan0_.error();
            }
            NUNAVUT_ASSERT(_subspan0_->offset_alings_to_byte());
            auto _err0_ = path.serialize(_subspan0_.value());
            if (not _err0_)
            {
                return _err0_;
            }
            _size_bytes0_ = _err0_.value();
            // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
            NUNAVUT_ASSERT((_size_bytes0_ * 8U) >= 8ULL);
            NUNAVUT_ASSERT((_size_bytes0_ * 8U) <= 2048ULL);
            out_buffer.add_offset(_size_bytes0_ * 8U);
            // NUNAVUT_ASSERT(out_buffer.size() >= 0);
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT(out_buffer.offset() >= 48ULL);
        NUNAVUT_ASSERT(out_buffer.offset() <= 2088ULL);
        NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
        return out_buffer.offset_bytes_ceil();
    }

    nunavut::support::SerializeResult
    deserialize(nunavut::support::const_bitspan in_buffer)
    {
        const auto capacity_bits = in_buffer.size();
        // truncated uint40 offset
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        offset = in_buffer.getU64(40U);
        in_buffer.add_offset(40U);
        in_buffer.align_offset_to<8U>();
        // uavcan.file.Path.2.0 path
        NUNAVUT_ASSERT(in_buffer.offset_alings_to(8U));
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        {
            std::size_t _size_bytes1_ = in_buffer.size() / 8U;
            NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            {
                const auto _err1_ = path.deserialize(in_buffer.subspan());
                if(_err1_){
                    _size_bytes1_ = _err1_.value();
                }else{
                    return -_err1_.error();
                }
            }
            in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
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

struct Response_1_1 final
{
    // +---------------------------------------------------------------------------------------------------------------+
    // | PORT IDENTIFIERS
    // +---------------------------------------------------------------------------------------------------------------+
    static constexpr bool HasFixedPortID = true;
    static constexpr std::uint16_t FixedPortId = 408U;
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

    static constexpr std::size_t EXTENT_BYTES                    =300UL;
    static constexpr std::size_t SERIALIZATION_BUFFER_SIZE_BYTES =260UL;
    static_assert(EXTENT_BYTES >= SERIALIZATION_BUFFER_SIZE_BYTES, "Internal constraint violation");
    static_assert(EXTENT_BYTES < (std::numeric_limits<std::size_t>::max() /8U), "This message is too large to be handled by current types!");

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+

    uavcan::file::Error_1_0 _error;

    uavcan::primitive::Unstructured_1_0 data;

    nunavut::support::SerializeResult
    serialize(nunavut::support::bitspan out_buffer) const
    {
        const std::size_t capacity_bits = out_buffer.size();
        if ((static_cast<std::size_t>(capacity_bits)) < 2080UL)
        {
            return -nunavut::support::Error::SERIALIZATION_BUFFER_TOO_SMALL;
        }
        // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
        // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
        NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
        {   // uavcan.file.Error.1.0 error
            NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(16ULL <= out_buffer.size());
            std::size_t _size_bytes0_ = 2UL;  // Nested object (max) size, in bytes.
            auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
            if(not _subspan0_){
                return -_subspan0_.error();
            }
            NUNAVUT_ASSERT(_subspan0_->offset_alings_to_byte());
            auto _err0_ = _error.serialize(_subspan0_.value());
            if (not _err0_)
            {
                return _err0_;
            }
            _size_bytes0_ = _err0_.value();
            // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
            NUNAVUT_ASSERT((_size_bytes0_ * 8U) == 16ULL);
            out_buffer.add_offset(_size_bytes0_ * 8U);
            // NUNAVUT_ASSERT(out_buffer.size() >= 0);
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        {   // uavcan.primitive.Unstructured.1.0 data
            NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(2064ULL <= out_buffer.size());
            std::size_t _size_bytes0_ = 258UL;  // Nested object (max) size, in bytes.
            auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
            if(not _subspan0_){
                return -_subspan0_.error();
            }
            NUNAVUT_ASSERT(_subspan0_->offset_alings_to_byte());
            auto _err0_ = data.serialize(_subspan0_.value());
            if (not _err0_)
            {
                return _err0_;
            }
            _size_bytes0_ = _err0_.value();
            // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
            NUNAVUT_ASSERT((_size_bytes0_ * 8U) >= 16ULL);
            NUNAVUT_ASSERT((_size_bytes0_ * 8U) <= 2064ULL);
            out_buffer.add_offset(_size_bytes0_ * 8U);
            // NUNAVUT_ASSERT(out_buffer.size() >= 0);
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT(out_buffer.offset() >= 32ULL);
        NUNAVUT_ASSERT(out_buffer.offset() <= 2080ULL);
        NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
        return out_buffer.offset_bytes_ceil();
    }

    nunavut::support::SerializeResult
    deserialize(nunavut::support::const_bitspan in_buffer)
    {
        const auto capacity_bits = in_buffer.size();
        // uavcan.file.Error.1.0 error
        NUNAVUT_ASSERT(in_buffer.offset_alings_to(8U));
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        {
            std::size_t _size_bytes1_ = in_buffer.size() / 8U;
            NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            {
                const auto _err1_ = _error.deserialize(in_buffer.subspan());
                if(_err1_){
                    _size_bytes1_ = _err1_.value();
                }else{
                    return -_err1_.error();
                }
            }
            in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
        }
        in_buffer.align_offset_to<8U>();
        // uavcan.primitive.Unstructured.1.0 data
        NUNAVUT_ASSERT(in_buffer.offset_alings_to(8U));
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        {
            std::size_t _size_bytes1_ = in_buffer.size() / 8U;
            NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            {
                const auto _err1_ = data.deserialize(in_buffer.subspan());
                if(_err1_){
                    _size_bytes1_ = _err1_.value();
                }else{
                    return -_err1_.error();
                }
            }
            in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
        }
        in_buffer.align_offset_to<8U>();
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
        NUNAVUT_ASSERT(capacity_bits >= _bits_got_);
        return { static_cast<std::size_t>(_bits_got_ / 8U) };
    }
};

struct Service_1_1 {
    static constexpr bool IsServiceType = true;
    static constexpr bool IsService = true;
    static constexpr bool IsRequest = false;
    static constexpr bool IsResponse = false;

    using Request = Request_1_1;
    using Response = Response_1_1;
};

} // namespace Read_1_1

} // namespace file
} // namespace uavcan

#endif // UAVCAN_FILE_READ_1_1_HPP_INCLUDED
