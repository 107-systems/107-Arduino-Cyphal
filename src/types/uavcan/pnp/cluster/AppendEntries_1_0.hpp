//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.0.9 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/uavcan/pnp/cluster/390.AppendEntries.1.0.dsdl
// Generated at:  2023-03-10 05:17:53.757079 UTC
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
#ifndef UAVCAN_PNP_CLUSTER_APPEND_ENTRIES_1_0_HPP_INCLUDED
#define UAVCAN_PNP_CLUSTER_APPEND_ENTRIES_1_0_HPP_INCLUDED

#include <nunavut/support/serialization.hpp>
#include <nunavut/support/variable_length_array.hpp>
#include <types/uavcan/pnp/cluster/Entry_1_0.hpp>
#include <cstdint>
#include <limits>

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
static_assert( nunavut::support::options::enable_serialization_asserts == 0,
              "/tmp/public_regulated_data_types/uavcan/pnp/cluster/390.AppendEntries.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/uavcan/pnp/cluster/390.AppendEntries.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 628873475,
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
// | This implementation uses the C++17 standard library variant type with wrappers for the emplace and
// | get_if methods to support forward-compatibility with the C++14 version of this object. The union_value type
// | extends std::variant and can be used with the entire set of variant methods. Using std::variant directly does mean
// | your code will not be backwards compatible with the C++14 version of this object.
// +-------------------------------------------------------------------------------------------------------------------+
///
/// This type is a part of the Raft consensus algorithm. The Raft consensus is used for the maintenance of the
/// distributed allocation table between redundant allocators. The following description is focused on the exchanges
/// between redundant PnP node-ID allocators. It does not apply to the case of non-redundant allocators, because
/// in that case the allocation table is stored locally and the process of node-ID allocation is trivial and fully
/// local.
/// Exchanges between allocatees and allocators are documented in the appropriate message type definition.
///
/// The algorithm used for replication of the allocation table across redundant allocators is a fairly direct
/// implementation of the Raft consensus algorithm, as published in the paper
/// "In Search of an Understandable Consensus Algorithm (Extended Version)" by Diego Ongaro and John Ousterhout.
/// The following text assumes that the reader is familiar with the paper.
///
/// The Raft log contains entries of type Entry (in the same namespace), where every entry contains the Raft term
/// number, the unique-ID, and the corresponding node-ID value (or zeros if it could not be requested from a static
/// node). Therefore, the Raft log is the allocation table itself.
///
/// Since the maximum number of entries in the allocation table is limited by the range of node-ID values, the log
/// capacity is bounded. Therefore, the snapshot transfer and log compaction functions are not required,
/// so they are not used in this implementation of the Raft algorithm.
///
/// When an allocator becomes the leader of the Raft cluster, it checks if the Raft log contains an entry for its own
/// node-ID, and if it doesn't, the leader adds its own allocation entry to the log (the unique-ID can be replaced with
/// zeros at the discretion of the implementer). This behavior guarantees that the Raft log always contains at least
/// one entry, therefore it is not necessary to support negative log indices, as proposed by the Raft paper.
///
/// Since the log is write-only and limited in growth, all allocations are permanent. This restriction is acceptable,
/// since Cyphal is a vehicle bus, and configuration of vehicle's components is not expected to change frequently.
/// Old allocations can be removed in order to free node-IDs for new allocations by clearing the Raft log on all
/// allocators; such clearing shall be performed simultaneously while the network is down, otherwise the Raft cluster
/// will automatically attempt to restore the lost state on the allocators where the table was cleared.
///
/// The allocators need to be aware of each other's node-ID in order to form a cluster. In order to learn each other's
/// node-ID values, the allocators broadcast messages of type Discovery (in the same namespace) until the cluster is
/// fully discovered and all allocators know of each other's node-ID. This extension to the Raft algorithm makes the
/// cluster almost configuration-free - the only parameter that shall be configured on all allocators of the cluster
/// is the number of nodes in the cluster (everything else will be auto-detected).
///
/// Runtime cluster membership changes are not supported, since they are not needed for a vehicle bus.
///
/// As has been explained in the general description of the PnP node-ID allocation feature, allocators shall watch for
/// unknown static nodes appearing on the bus. In the case of a non-redundant allocator, the task is trivial, since the
/// allocation table can be updated locally. In the case of a Raft cluster, however, the network monitoring task shall
/// be performed by the leader only, since other cluster members cannot commit to the shared allocation table (i.e.,
/// the Raft log) anyway. Redundant allocators should not attempt to obtain the true unique-ID of the newly detected
/// static nodes (use zeros instead), because the allocation table is write-only: if the unique-ID of a static node
/// ever changes (e.g., a replacement unit is installed, or network configuration is changed manually), the change
/// will be impossible to reflect in the allocation table.
///
/// Only the current Raft leader can process allocation requests and engage in communication with allocatees.
/// An allocator is allowed to send allocation responses only if both conditions are met:
///
///   - The allocator is currently the Raft leader.
///   - Its replica of the Raft log does not contain uncommitted entries (i.e. the last allocation request has been
///     completed successfully).
///
/// All cluster maintenance traffic should normally use either the lowest or the next-to-lowest transfer priority level.
///
struct Request_1_0 final
{
    struct _traits_  // The name is surrounded with underscores to avoid collisions with DSDL attributes.
    {
        _traits_() = delete;
        static constexpr bool HasFixedPortID = true;
        static constexpr std::uint16_t FixedPortId = 390U;
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
        static constexpr std::size_t ExtentBytes                  = 96UL;
        static constexpr std::size_t SerializationBufferSizeBytes = 35UL;
        static_assert(ExtentBytes >= SerializationBufferSizeBytes, "Internal constraint violation");
        static_assert(ExtentBytes < (std::numeric_limits<std::size_t>::max() / 8U), "This message is too large to be handled by the selected types");
        struct TypeOf
        {
            TypeOf() = delete;
            using term = std::uint32_t;
            using prev_log_term = std::uint32_t;
            using prev_log_index = std::uint16_t;
            using leader_commit = std::uint16_t;
            using entries = nunavut::support::VariableLengthArray<uavcan::pnp::cluster::Entry_1_0, 1>;
        };
    };

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
    ///
    ///   max recommended request interval = (min election timeout) / 2 requests / (cluster size - 1)
    ///
    /// The equation assumes that the Leader requests one Follower at a time, so that there's at most one pending call
    /// at any moment. Such behavior is optimal as it creates a uniform bus load, although it is implementation-
    /// specific.
    /// Obviously, the request interval can be lower than that if needed, but higher values are not recommended as they
    /// may
    /// cause Followers to initiate premature elections in case of frame losses or delays.
    ///
    /// The timeout value is randomized in the range (MIN, MAX], according to the Raft paper. The randomization
    /// granularity
    /// should be at least one millisecond or higher.
    ///
    static constexpr std::uint8_t DEFAULT_MAX_ELECTION_TIMEOUT = 4U;

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+

    _traits_::TypeOf::term term{};

    _traits_::TypeOf::prev_log_term prev_log_term{};

    _traits_::TypeOf::prev_log_index prev_log_index{};
    ///
    /// Refer to the Raft paper for explanation.
    ///
    _traits_::TypeOf::leader_commit leader_commit{};
    ///
    /// Worst case replication time per Follower can be computed as:
    ///
    ///   worst replication time = (node-ID capacity) * (2 trips of next_index) * (request interval per Follower)
    ///
    /// E.g., given the request interval of 0.5 seconds, the worst case replication time for CAN bus is:
    ///
    ///   128 nodes * 2 trips * 0.5 seconds = 128 seconds.
    ///
    /// This is the amount of time it will take for a new Follower to reconstruct a full replica of the distributed log.
    ///
    _traits_::TypeOf::entries entries{};
};

inline nunavut::support::SerializeResult serialize(const Request_1_0& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    const std::size_t capacity_bits = out_buffer.size();
    if ((static_cast<std::size_t>(capacity_bits)) < 280UL)
    {
        return -nunavut::support::Error::SerializationBufferTooSmall;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    {   // saturated uint32 term
        // Saturation code not emitted -- native representation matches the serialized representation.
        const auto _result3_ = out_buffer.setUxx(obj.term, 32U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(32U);
    }
    {   // saturated uint32 prev_log_term
        // Saturation code not emitted -- native representation matches the serialized representation.
        const auto _result3_ = out_buffer.setUxx(obj.prev_log_term, 32U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(32U);
    }
    {   // saturated uint16 prev_log_index
        // Saturation code not emitted -- native representation matches the serialized representation.
        const auto _result3_ = out_buffer.setUxx(obj.prev_log_index, 16U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(16U);
    }
    {   // saturated uint16 leader_commit
        // Saturation code not emitted -- native representation matches the serialized representation.
        const auto _result3_ = out_buffer.setUxx(obj.leader_commit, 16U);
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
        if (obj.entries.size() > 1)
        {
            return -nunavut::support::Error::SerializationBadArrayLength;
        }
        // Array length prefix: truncated uint8
        const auto _result3_ = out_buffer.setUxx(obj.entries.size(), 8U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(8U);
        for (std::size_t _index2_ = 0U; _index2_ < obj.entries.size(); ++_index2_)
        {
            std::size_t _size_bytes0_ = 22UL;  // Nested object (max) size, in bytes.
            auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
            if(not _subspan0_){
                return -_subspan0_.error();
            }
            auto _err0_ = serialize(obj.entries[_index2_], _subspan0_.value());
            if (not _err0_)
            {
                return _err0_;
            }
            _size_bytes0_ = _err0_.value();
            // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
            out_buffer.add_offset(_size_bytes0_ * 8U);
            //
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

inline nunavut::support::SerializeResult deserialize(Request_1_0& obj,
                                                     nunavut::support::const_bitspan in_buffer)
{
    const auto capacity_bits = in_buffer.size();
    // saturated uint32 term
    obj.term = in_buffer.getU32(32U);
    in_buffer.add_offset(32U);
    // saturated uint32 prev_log_term
    obj.prev_log_term = in_buffer.getU32(32U);
    in_buffer.add_offset(32U);
    // saturated uint16 prev_log_index
    obj.prev_log_index = in_buffer.getU16(16U);
    in_buffer.add_offset(16U);
    // saturated uint16 leader_commit
    obj.leader_commit = in_buffer.getU16(16U);
    in_buffer.add_offset(16U);
    in_buffer.align_offset_to<8U>();
    // uavcan.pnp.cluster.Entry.1.0[<=1] entries
    {
        // Array length prefix: truncated uint8
    const std::size_t _size0_ = in_buffer.getU8(8U);
    in_buffer.add_offset(8U);
        if ( _size0_ > 1U)
        {
            return -nunavut::support::Error::SerializationBadArrayLength;
        }
        obj.entries.reserve(_size0_);
        for (std::size_t _index5_ = 0U; _index5_ < _size0_; ++_index5_)
        {
            // TODO This is terribly inefficient. We need to completely refactor this template to use C++ emplace and
            // move semantics instead of assuming C-style containers
            obj.entries.push_back();
            {
            std::size_t _size_bytes1_ = in_buffer.size() / 8U;
            {
                const auto _err1_ = deserialize(obj.entries[_index5_], in_buffer.subspan());
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
    auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
    return { static_cast<std::size_t>(_bits_got_ / 8U) };
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
        static constexpr std::uint16_t FixedPortId = 390U;
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
        static constexpr std::size_t ExtentBytes                  = 48UL;
        static constexpr std::size_t SerializationBufferSizeBytes = 5UL;
        static_assert(ExtentBytes >= SerializationBufferSizeBytes, "Internal constraint violation");
        static_assert(ExtentBytes < (std::numeric_limits<std::size_t>::max() / 8U), "This message is too large to be handled by the selected types");
        struct TypeOf
        {
            TypeOf() = delete;
            using term = std::uint32_t;
            using success = bool;
        };
    };

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+

    _traits_::TypeOf::term term{};
    ///
    /// Refer to the Raft paper for explanation.
    ///
    _traits_::TypeOf::success success{};
};

inline nunavut::support::SerializeResult serialize(const Response_1_0& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    const std::size_t capacity_bits = out_buffer.size();
    if ((static_cast<std::size_t>(capacity_bits)) < 40UL)
    {
        return -nunavut::support::Error::SerializationBufferTooSmall;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    {   // saturated uint32 term
        // Saturation code not emitted -- native representation matches the serialized representation.
        const auto _result3_ = out_buffer.setUxx(obj.term, 32U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(32U);
    }
    {   // saturated bool success
        auto _result2_ = out_buffer.setBit(obj.success);
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
    return out_buffer.offset_bytes_ceil();
}

inline nunavut::support::SerializeResult deserialize(Response_1_0& obj,
                                                     nunavut::support::const_bitspan in_buffer)
{
    const auto capacity_bits = in_buffer.size();
    // saturated uint32 term
    obj.term = in_buffer.getU32(32U);
    in_buffer.add_offset(32U);
    // saturated bool success
    obj.success = in_buffer.getBit();
    in_buffer.add_offset(1U);
    in_buffer.align_offset_to<8U>();
    auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
    return { static_cast<std::size_t>(_bits_got_ / 8U) };
}

}  // namespace AppendEntries

struct AppendEntries_1_0
{
    AppendEntries_1_0() = delete;

    using Request  = AppendEntries::Request_1_0;
    using Response = AppendEntries::Response_1_0;

    struct _traits_
    {
        _traits_() = delete;

        static constexpr bool IsServiceType = true;
        static constexpr bool IsService = true;
        static constexpr bool IsRequest = false;
        static constexpr bool IsResponse = false;
    };
};

} // namespace cluster
} // namespace pnp
} // namespace uavcan

#endif // UAVCAN_PNP_CLUSTER_APPEND_ENTRIES_1_0_HPP_INCLUDED
