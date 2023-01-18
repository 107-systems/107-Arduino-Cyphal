//
// This is an AUTO-GENERATED UAVCAN DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-1.9.0 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/uavcan/pnp/8166.NodeIDAllocationData.1.0.dsdl
// Generated at:  2023-01-18 06:33:55.785520 UTC
// Is deprecated: no
// Fixed port-ID: 8166
// Full name:     uavcan.pnp.NodeIDAllocationData
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
#ifndef UAVCAN_PNP_NODE_ID_ALLOCATION_DATA_1_0_HPP_INCLUDED
#define UAVCAN_PNP_NODE_ID_ALLOCATION_DATA_1_0_HPP_INCLUDED

#include "nunavut/support/serialization.hpp"
#include "nunavut/support/variable_length_array.hpp"
#include "uavcan/node/ID_1_0.hpp"
#include <cstdint>

namespace uavcan
{
namespace pnp
{
// +-------------------------------------------------------------------------------------------------------------------+
// | LANGUAGE OPTION ASSERTIONS
// |    These static assertions ensure that the header is being used with
// | Nunavut C++ serialization support that is compatible with the language
// | options in effect when that support code was generated.
// +-------------------------------------------------------------------------------------------------------------------+
static_assert( nunavut::support::options::target_endianness == 1693710260,
              "/tmp/public_regulated_data_types/uavcan/pnp/8166.NodeIDAllocationData.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/public_regulated_data_types/uavcan/pnp/8166.NodeIDAllocationData.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 1,
              "/tmp/public_regulated_data_types/uavcan/pnp/8166.NodeIDAllocationData.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/uavcan/pnp/8166.NodeIDAllocationData.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 3161622713,
              "/tmp/public_regulated_data_types/uavcan/pnp/8166.NodeIDAllocationData.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/public_regulated_data_types/uavcan/pnp/8166.NodeIDAllocationData.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/public_regulated_data_types/uavcan/pnp/8166.NodeIDAllocationData.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/public_regulated_data_types/uavcan/pnp/8166.NodeIDAllocationData.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/public_regulated_data_types/uavcan/pnp/8166.NodeIDAllocationData.1.0.dsdl "
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
/// This definition of the allocation message is intended for use with transports where anonymous transfers are limited
/// to 7 bytes of payload, such as Classic CAN. The definition is carried over from the original UAVCAN v0 specification
/// with some modifications. For transports other than Classic CAN (e.g., CAN FD, serial, etc.) there is a more
/// general, more capable definition NodeIDAllocationData v2.0. The PnP protocol itself is described in the
/// documentation
/// for the v2 definition. The documentation provided here builds upon the general case, so read that first please.
/// The full 128-bit unique-ID can't be accommodated in a single-frame anonymous message transfer over Classic CAN, so
/// this definition substitutes the full 128-bit ID with a smaller 48-bit hash of it. The 48-bit hash is obtained by
/// applying an arbitrary hash function to the unique-ID that outputs at least 48 bit of data. The recommended hash
/// function is the standard CRC-64WE where only the lowest 48 bit of the result are used.
/// Allocators that support allocation messages of different versions should maintain a shared allocation table for all.
/// Requests received via the v1 message obviously do not contain the full unique-ID; the allocators are recommended
/// to left-zero-pad the small 48-bit hash in order to obtain a "pseudo unique-ID", and use this value in the
/// allocation table as a substitute for the real unique-ID. It is recognized that this behavior will have certain
/// side effects, such as the same allocatee obtaining different allocated node-ID values depending on which version
/// of the message is used, but they are considered tolerable.
/// Allocatees that may need to operate over Classic CAN along with high-MTU transports may choose to use
/// only this constrained method of allocation for consistency and simplification.
/// In order to save space for the hash, the preferred node-ID is removed from the request. The allocated node-ID
/// is provided in the response, however; this is achieved by means of an optional field that is not populated in
/// the request but is populated in the response. This implies that the response may be a multi-frame transfer,
/// which is acceptable since responses are sent by allocators, which are regular nodes, and therefore they are
/// allowed to use regular message transfers rather than being limited to anonymous message transfers as allocatees are.
/// On the allocatee's side the protocol is defined through the following set of rules:
///   Rule A. On initialization:
///     1. The allocatee subscribes to this message.
///     2. The allocatee starts the Request Timer with a random interval of Trequest.
///   Rule B. On expiration of the Request Timer (started as per rules A, B, or C):
///     1. Request Timer restarts with a random interval of Trequest (chosen anew).
///     2. The allocatee broadcasts an allocation request message, where the fields are populated as follows:
///        unique_id_hash    - a 48-bit hash of the unique-ID of the allocatee.
///        allocated_node_id - empty (not populated).
///   Rule C. On any allocation message, even if other rules also match:
///     1. Request Timer restarts with a random interval of Trequest (chosen anew).
///   Rule D. On an allocation message WHERE (source node-ID is non-anonymous, i.e., regular allocation response)
///                                    AND   (the field unique_id_hash matches the allocatee's 48-bit unique-ID hash)
///                                    AND   (the field allocated_node_id is populated):
///     1. Request Timer stops.
///     2. The allocatee initializes its node-ID with the received value.
///     3. The allocatee terminates its subscription to allocation messages.
///     4. Exit.
///
struct NodeIDAllocationData_1_0 final
{
    // +---------------------------------------------------------------------------------------------------------------+
    // | PORT IDENTIFIERS
    // +---------------------------------------------------------------------------------------------------------------+
    static constexpr bool HasFixedPortID = true;
    static constexpr std::uint16_t FixedPortId = 8166U;
    static constexpr bool IsServiceType = false;

    /// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
    /// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
    /// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
    /// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
    /// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
    /// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
    /// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.

    static constexpr std::size_t EXTENT_BYTES                    =9UL;
    static constexpr std::size_t SERIALIZATION_BUFFER_SIZE_BYTES =9UL;
    static_assert(EXTENT_BYTES >= SERIALIZATION_BUFFER_SIZE_BYTES, "Internal constraint violation");
    static_assert(EXTENT_BYTES < (std::numeric_limits<std::size_t>::max() /8U), "This message is too large to be handled by current types!");

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+
    ///
    /// An arbitrary 48-bit hash of the unique-ID of the local node.
    ///
    std::uint64_t unique_id_hash;
    ///
    /// Shall be empty in request messages.
    /// Shall be populated in response messages.
    ///
    nunavut::support::VariableLengthArray<types/uavcan::node::ID_1_0, 1> allocated_node_id;

    nunavut::support::SerializeResult
    serialize(nunavut::support::bitspan out_buffer) const
    {
        const std::size_t capacity_bits = out_buffer.size();
        if ((static_cast<std::size_t>(capacity_bits)) < 72UL)
        {
            return -nunavut::support::Error::SERIALIZATION_BUFFER_TOO_SMALL;
        }
        // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
        // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
        NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
        {   // truncated uint48 unique_id_hash
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(48ULL <= out_buffer.size());
            const auto _result3_ = out_buffer.setUxx(unique_id_hash, 48U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(48U);
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        {   // uavcan.node.ID.1.0[<=1] allocated_node_id
            NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(24ULL <= out_buffer.size());
            if (allocated_node_id.size() > 1)
            {
                return -nunavut::support::Error::REPRESENTATION_BAD_ARRAY_LENGTH;
            }
            // Array length prefix: truncated uint8
            const auto _result3_ = out_buffer.setUxx(allocated_node_id.size(), 8U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(8U);
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            for (size_t _index2_ = 0U; _index2_ < allocated_node_id.size(); ++_index2_)
            {
                NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
                NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
                NUNAVUT_ASSERT(16ULL <= out_buffer.size());
                std::size_t _size_bytes0_ = 2UL;  // Nested object (max) size, in bytes.
                auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
                if(not _subspan0_){
                    return -_subspan0_.error();
                }
                NUNAVUT_ASSERT(_subspan0_->offset_alings_to_byte());
                auto _err0_ = allocated_node_id[_index2_].serialize(_subspan0_.value());
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
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT(out_buffer.offset() >= 56ULL);
        NUNAVUT_ASSERT(out_buffer.offset() <= 72ULL);
        NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
        return out_buffer.offset_bytes_ceil();
    }

    nunavut::support::SerializeResult
    deserialize(nunavut::support::const_bitspan in_buffer)
    {
        const auto capacity_bits = in_buffer.size();
        // truncated uint48 unique_id_hash
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        unique_id_hash = in_buffer.getU64(48U);
        in_buffer.add_offset(48U);
        in_buffer.align_offset_to<8U>();
        // uavcan.node.ID.1.0[<=1] allocated_node_id
        NUNAVUT_ASSERT(in_buffer.offset_alings_to(8U));
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        {
            // Array length prefix: truncated uint8
        const std::uint8_t _size0_ = in_buffer.getU8(8U);
        in_buffer.add_offset(8U);
            if ( _size0_ > 1U)
            {
                return -nunavut::support::Error::REPRESENTATION_BAD_ARRAY_LENGTH;
            }
            allocated_node_id.reserve(_size0_);
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            for (size_t _index5_ = 0U; _index5_ < _size0_; ++_index5_)
            {
                // TODO This is terribly inefficient. We need to completely refactor this template to use C++ emplace and
                // move semantics instead of assuming C-style containers
                allocated_node_id.push_back();
                NUNAVUT_ASSERT(in_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            {
                std::size_t _size_bytes1_ = in_buffer.size() / 8U;
                NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
                {
                    const auto _err1_ = allocated_node_id[_index5_].deserialize(in_buffer.subspan());
                    if(_err1_){
                        _size_bytes1_ = _err1_.value();
                    }else{
                        return -_err1_.error();
                    }
                }
                in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
            }
            }
        }
        in_buffer.align_offset_to<8U>();
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
        NUNAVUT_ASSERT(capacity_bits >= _bits_got_);
        return { static_cast<std::size_t>(_bits_got_ / 8U) };
    }
};

} // namespace pnp
} // namespace uavcan

#endif // UAVCAN_PNP_NODE_ID_ALLOCATION_DATA_1_0_HPP_INCLUDED
