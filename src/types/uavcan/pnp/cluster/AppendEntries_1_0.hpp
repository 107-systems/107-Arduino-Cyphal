//
// This is an AUTO-GENERATED UAVCAN DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-1.9.0 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/uavcan/pnp/cluster/390.AppendEntries.1.0.dsdl
// Generated at:  2023-01-18 06:06:50.356272 UTC
// Is deprecated: no
// Fixed port-ID: 390
// Full name:     uavcan.pnp.cluster.AppendEntries
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
#ifndef UAVCAN_PNP_CLUSTER_APPEND_ENTRIES_1_0_HPP_INCLUDED
#define UAVCAN_PNP_CLUSTER_APPEND_ENTRIES_1_0_HPP_INCLUDED

#include "nunavut/support/serialization.hpp"
#include "nunavut/support/variable_length_array.hpp"
#include "uavcan/pnp/cluster/Entry_1_0.hpp"
#include <cstdint>

namespace uavcan
{
namespace pnp
{
namespace cluster
{
// +-------------------------------------------------------------------------------------------------------------------+
// | LANGUAGE OPTION ASSERTIONS
// |    These static assertions ensure that the header is being used with
// | Nunavut C++ serialization support that is compatible with the language
// | options in effect when that support code was generated.
// +-------------------------------------------------------------------------------------------------------------------+
static_assert( nunavut::support::options::target_endianness == 1693710260,
              "/tmp/public_regulated_data_types/uavcan/pnp/cluster/390.AppendEntries.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/public_regulated_data_types/uavcan/pnp/cluster/390.AppendEntries.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 1,
              "/tmp/public_regulated_data_types/uavcan/pnp/cluster/390.AppendEntries.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/uavcan/pnp/cluster/390.AppendEntries.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 3161622713,
              "/tmp/public_regulated_data_types/uavcan/pnp/cluster/390.AppendEntries.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/public_regulated_data_types/uavcan/pnp/cluster/390.AppendEntries.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/public_regulated_data_types/uavcan/pnp/cluster/390.AppendEntries.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/public_regulated_data_types/uavcan/pnp/cluster/390.AppendEntries.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/public_regulated_data_types/uavcan/pnp/cluster/390.AppendEntries.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );

namespace AppendEntries
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
/// This type is a part of the Raft consensus algorithm. The Raft consensus is used for the maintenance of the
/// distributed allocation table between redundant allocators. The following description is focused on the exchanges
/// between redundant PnP node-ID allocators. It does not apply to the case of non-redundant allocators, because
/// in that case the allocation table is stored locally and the process of node-ID allocation is trivial and fully
/// local.
/// Exchanges between allocatees and allocators are documented in the appropriate message type definition.
/// The algorithm used for replication of the allocation table across redundant allocators is a fairly direct
/// implementation of the Raft consensus algorithm, as published in the paper
/// "In Search of an Understandable Consensus Algorithm (Extended Version)" by Diego Ongaro and John Ousterhout.
/// The following text assumes that the reader is familiar with the paper.
/// The Raft log contains entries of type Entry (in the same namespace), where every entry contains the Raft term
/// number, the unique-ID, and the corresponding node-ID value (or zeros if it could not be requested from a static
/// node). Therefore, the Raft log is the allocation table itself.
/// Since the maximum number of entries in the allocation table is limited by the range of node-ID values, the log
/// capacity is bounded. Therefore, the snapshot transfer and log compaction functions are not required,
/// so they are not used in this implementation of the Raft algorithm.
/// When an allocator becomes the leader of the Raft cluster, it checks if the Raft log contains an entry for its own
/// node-ID, and if it doesn't, the leader adds its own allocation entry to the log (the unique-ID can be replaced with
/// zeros at the discretion of the implementer). This behavior guarantees that the Raft log always contains at least
/// one entry, therefore it is not necessary to support negative log indices, as proposed by the Raft paper.
/// Since the log is write-only and limited in growth, all allocations are permanent. This restriction is acceptable,
/// since Cyphal is a vehicle bus, and configuration of vehicle's components is not expected to change frequently.
/// Old allocations can be removed in order to free node-IDs for new allocations by clearing the Raft log on all
/// allocators; such clearing shall be performed simultaneously while the network is down, otherwise the Raft cluster
/// will automatically attempt to restore the lost state on the allocators where the table was cleared.
/// The allocators need to be aware of each other's node-ID in order to form a cluster. In order to learn each other's
/// node-ID values, the allocators broadcast messages of type Discovery (in the same namespace) until the cluster is
/// fully discovered and all allocators know of each other's node-ID. This extension to the Raft algorithm makes the
/// cluster almost configuration-free - the only parameter that shall be configured on all allocators of the cluster
/// is the number of nodes in the cluster (everything else will be auto-detected).
/// Runtime cluster membership changes are not supported, since they are not needed for a vehicle bus.
/// As has been explained in the general description of the PnP node-ID allocation feature, allocators shall watch for
/// unknown static nodes appearing on the bus. In the case of a non-redundant allocator, the task is trivial, since the
/// allocation table can be updated locally. In the case of a Raft cluster, however, the network monitoring task shall
/// be performed by the leader only, since other cluster members cannot commit to the shared allocation table (i.e.,
/// the Raft log) anyway. Redundant allocators should not attempt to obtain the true unique-ID of the newly detected
/// static nodes (use zeros instead), because the allocation table is write-only: if the unique-ID of a static node
/// ever changes (e.g., a replacement unit is installed, or network configuration is changed manually), the change
/// will be impossible to reflect in the allocation table.
/// Only the current Raft leader can process allocation requests and engage in communication with allocatees.
/// An allocator is allowed to send allocation responses only if both conditions are met:
///   - The allocator is currently the Raft leader.
///   - Its replica of the Raft log does not contain uncommitted entries (i.e. the last allocation request has been
///     completed successfully).
/// All cluster maintenance traffic should normally use either the lowest or the next-to-lowest transfer priority level.
///
struct Request_1_0 final
{
    // +---------------------------------------------------------------------------------------------------------------+
    // | PORT IDENTIFIERS
    // +---------------------------------------------------------------------------------------------------------------+
    static constexpr bool HasFixedPortID = true;
    static constexpr std::uint16_t FixedPortId = 390U;
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

    static constexpr std::size_t EXTENT_BYTES                    =96UL;
    static constexpr std::size_t SERIALIZATION_BUFFER_SIZE_BYTES =35UL;
    static_assert(EXTENT_BYTES >= SERIALIZATION_BUFFER_SIZE_BYTES, "Internal constraint violation");
    static_assert(EXTENT_BYTES < (std::numeric_limits<std::size_t>::max() /8U), "This message is too large to be handled by current types!");

    // +---------------------------------------------------------------------------------------------------------------+
    // | CONSTANTS
    // +---------------------------------------------------------------------------------------------------------------+
    ///
    /// [second]
    ///
    static constexpr std::uint8_t DEFAULT_MIN_ELECTION_TIMEOUT = 2U;
    ///
    /// [second]
    /// Given the minimum election timeout and the cluster size,
    /// the maximum recommended request interval can be derived as follows:
    ///   max recommended request interval = (min election timeout) / 2 requests / (cluster size - 1)
    /// The equation assumes that the Leader requests one Follower at a time, so that there's at most one pending call
    /// at any moment. Such behavior is optimal as it creates a uniform bus load, although it is implementation-
    /// specific.
    /// Obviously, the request interval can be lower than that if needed, but higher values are not recommended as they
    /// may
    /// cause Followers to initiate premature elections in case of frame losses or delays.
    /// The timeout value is randomized in the range (MIN, MAX], according to the Raft paper. The randomization
    /// granularity
    /// should be at least one millisecond or higher.
    ///
    static constexpr std::uint8_t DEFAULT_MAX_ELECTION_TIMEOUT = 4U;

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+

    std::uint32_t term;

    std::uint32_t prev_log_term;

    std::uint16_t prev_log_index;
    ///
    /// Refer to the Raft paper for explanation.
    ///
    std::uint16_t leader_commit;
    ///
    /// Worst case replication time per Follower can be computed as:
    ///   worst replication time = (node-ID capacity) * (2 trips of next_index) * (request interval per Follower)
    /// E.g., given the request interval of 0.5 seconds, the worst case replication time for CAN bus is:
    ///   128 nodes * 2 trips * 0.5 seconds = 128 seconds.
    /// This is the amount of time it will take for a new Follower to reconstruct a full replica of the distributed log.
    ///
    nunavut::support::VariableLengthArray<types/uavcan::pnp::cluster::Entry_1_0, 1> entries;

    nunavut::support::SerializeResult
    serialize(nunavut::support::bitspan out_buffer) const
    {
        const std::size_t capacity_bits = out_buffer.size();
        if ((static_cast<std::size_t>(capacity_bits)) < 280UL)
        {
            return -nunavut::support::Error::SERIALIZATION_BUFFER_TOO_SMALL;
        }
        // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
        // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
        NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
        {   // saturated uint32 term
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(32ULL <= out_buffer.size());
            // Saturation code not emitted -- native representation matches the serialized representation.
            const auto _result3_ = out_buffer.setUxx(term, 32U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(32U);
        }
        {   // saturated uint32 prev_log_term
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(32ULL <= out_buffer.size());
            // Saturation code not emitted -- native representation matches the serialized representation.
            const auto _result3_ = out_buffer.setUxx(prev_log_term, 32U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(32U);
        }
        {   // saturated uint16 prev_log_index
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(16ULL <= out_buffer.size());
            // Saturation code not emitted -- native representation matches the serialized representation.
            const auto _result3_ = out_buffer.setUxx(prev_log_index, 16U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(16U);
        }
        {   // saturated uint16 leader_commit
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(16ULL <= out_buffer.size());
            // Saturation code not emitted -- native representation matches the serialized representation.
            const auto _result3_ = out_buffer.setUxx(leader_commit, 16U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(16U);
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        {   // uavcan.pnp.cluster.Entry.1.0[<=1] entries
            NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(184ULL <= out_buffer.size());
            if (entries.size() > 1)
            {
                return -nunavut::support::Error::REPRESENTATION_BAD_ARRAY_LENGTH;
            }
            // Array length prefix: truncated uint8
            const auto _result3_ = out_buffer.setUxx(entries.size(), 8U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(8U);
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            for (size_t _index2_ = 0U; _index2_ < entries.size(); ++_index2_)
            {
                NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
                NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
                NUNAVUT_ASSERT(176ULL <= out_buffer.size());
                std::size_t _size_bytes0_ = 22UL;  // Nested object (max) size, in bytes.
                auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
                if(not _subspan0_){
                    return -_subspan0_.error();
                }
                NUNAVUT_ASSERT(_subspan0_->offset_alings_to_byte());
                auto _err0_ = entries[_index2_].serialize(_subspan0_.value());
                if (not _err0_)
                {
                    return _err0_;
                }
                _size_bytes0_ = _err0_.value();
                // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
                NUNAVUT_ASSERT((_size_bytes0_ * 8U) == 176ULL);
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
        NUNAVUT_ASSERT(out_buffer.offset() >= 104ULL);
        NUNAVUT_ASSERT(out_buffer.offset() <= 280ULL);
        NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
        return out_buffer.offset_bytes_ceil();
    }

    nunavut::support::SerializeResult
    deserialize(nunavut::support::const_bitspan in_buffer)
    {
        const auto capacity_bits = in_buffer.size();
        // saturated uint32 term
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        term = in_buffer.getU32(32U);
        in_buffer.add_offset(32U);
        // saturated uint32 prev_log_term
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        prev_log_term = in_buffer.getU32(32U);
        in_buffer.add_offset(32U);
        // saturated uint16 prev_log_index
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        prev_log_index = in_buffer.getU16(16U);
        in_buffer.add_offset(16U);
        // saturated uint16 leader_commit
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        leader_commit = in_buffer.getU16(16U);
        in_buffer.add_offset(16U);
        in_buffer.align_offset_to<8U>();
        // uavcan.pnp.cluster.Entry.1.0[<=1] entries
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
            entries.reserve(_size0_);
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            for (size_t _index5_ = 0U; _index5_ < _size0_; ++_index5_)
            {
                // TODO This is terribly inefficient. We need to completely refactor this template to use C++ emplace and
                // move semantics instead of assuming C-style containers
                entries.push_back();
                NUNAVUT_ASSERT(in_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            {
                std::size_t _size_bytes1_ = in_buffer.size() / 8U;
                NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
                {
                    const auto _err1_ = entries[_index5_].deserialize(in_buffer.subspan());
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

struct Response_1_0 final
{
    // +---------------------------------------------------------------------------------------------------------------+
    // | PORT IDENTIFIERS
    // +---------------------------------------------------------------------------------------------------------------+
    static constexpr bool HasFixedPortID = true;
    static constexpr std::uint16_t FixedPortId = 390U;
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

    static constexpr std::size_t EXTENT_BYTES                    =48UL;
    static constexpr std::size_t SERIALIZATION_BUFFER_SIZE_BYTES =5UL;
    static_assert(EXTENT_BYTES >= SERIALIZATION_BUFFER_SIZE_BYTES, "Internal constraint violation");
    static_assert(EXTENT_BYTES < (std::numeric_limits<std::size_t>::max() /8U), "This message is too large to be handled by current types!");

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+

    std::uint32_t term;
    ///
    /// Refer to the Raft paper for explanation.
    ///
    bool success;

    nunavut::support::SerializeResult
    serialize(nunavut::support::bitspan out_buffer) const
    {
        const std::size_t capacity_bits = out_buffer.size();
        if ((static_cast<std::size_t>(capacity_bits)) < 40UL)
        {
            return -nunavut::support::Error::SERIALIZATION_BUFFER_TOO_SMALL;
        }
        // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
        // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
        NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
        {   // saturated uint32 term
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(32ULL <= out_buffer.size());
            // Saturation code not emitted -- native representation matches the serialized representation.
            const auto _result3_ = out_buffer.setUxx(term, 32U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(32U);
        }
        {   // saturated bool success
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(1ULL <= out_buffer.size());
            auto _result2_ = out_buffer.setBit(success);
            if(not _result2_){
                return -_result2_.error();
            }
            out_buffer.add_offset(1UL);
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT(out_buffer.offset() == 40ULL);
        NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
        return out_buffer.offset_bytes_ceil();
    }

    nunavut::support::SerializeResult
    deserialize(nunavut::support::const_bitspan in_buffer)
    {
        const auto capacity_bits = in_buffer.size();
        // saturated uint32 term
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        term = in_buffer.getU32(32U);
        in_buffer.add_offset(32U);
        // saturated bool success
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        success = in_buffer.getBit();
        in_buffer.add_offset(1U);
        in_buffer.align_offset_to<8U>();
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
        NUNAVUT_ASSERT(capacity_bits >= _bits_got_);
        return { static_cast<std::size_t>(_bits_got_ / 8U) };
    }
};

struct Service_1_0 {
    static constexpr bool IsServiceType = true;
    static constexpr bool IsService = true;
    static constexpr bool IsRequest = false;
    static constexpr bool IsResponse = false;

    using Request = Request_1_0;
    using Response = Response_1_0;
};

} // namespace AppendEntries_1_0

} // namespace cluster
} // namespace pnp
} // namespace uavcan

#endif // UAVCAN_PNP_CLUSTER_APPEND_ENTRIES_1_0_HPP_INCLUDED
