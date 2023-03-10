//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.0.9 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/uavcan/pnp/8165.NodeIDAllocationData.2.0.dsdl
// Generated at:  2023-03-10 05:17:53.747239 UTC
// Is deprecated: no
// Fixed port-ID: 8165
// Full name:     uavcan.pnp.NodeIDAllocationData
// Type Version:  2.0
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
#ifndef UAVCAN_PNP_NODE_ID_ALLOCATION_DATA_2_0_HPP_INCLUDED
#define UAVCAN_PNP_NODE_ID_ALLOCATION_DATA_2_0_HPP_INCLUDED

#include <nunavut/support/serialization.hpp>
#include <types/uavcan/node/ID_1_0.hpp>
#include <array>
#include <cstdint>
#include <limits>

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
              "/tmp/public_regulated_data_types/uavcan/pnp/8165.NodeIDAllocationData.2.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/public_regulated_data_types/uavcan/pnp/8165.NodeIDAllocationData.2.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 0,
              "/tmp/public_regulated_data_types/uavcan/pnp/8165.NodeIDAllocationData.2.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/uavcan/pnp/8165.NodeIDAllocationData.2.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 628873475,
              "/tmp/public_regulated_data_types/uavcan/pnp/8165.NodeIDAllocationData.2.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/public_regulated_data_types/uavcan/pnp/8165.NodeIDAllocationData.2.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/public_regulated_data_types/uavcan/pnp/8165.NodeIDAllocationData.2.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/public_regulated_data_types/uavcan/pnp/8165.NodeIDAllocationData.2.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/public_regulated_data_types/uavcan/pnp/8165.NodeIDAllocationData.2.0.dsdl "
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
/// In order to be able to operate in a Cyphal network, a node shall have a node-ID that is unique within the network.
/// Typically, a valid node-ID can be configured manually for each node; however, in certain use cases the manual
/// approach is either undesirable or impossible, therefore Cyphal defines the high-level feature of plug-and-play
/// nodes that allows nodes to obtain a node-ID value automatically upon connection to the network. When combined
/// with automatic physical layer configuration (such as auto bit rate detection), this feature allows one to implement
/// nodes that can join a Cyphal network without any prior manual configuration whatsoever. Such nodes are referred to
/// as "plug-and-play nodes" (or "PnP nodes" for brevity).
///
/// The feature is fundamentally non-deterministic and is likely to be unfit for some high-reliability systems;
/// the designers need to carefully consider the trade-offs involved before deciding to rely on this feature.
/// Normally, static node-ID settings should be preferred.
///
/// This feature relies on the concept of "anonymous message transfers", please consult with the Cyphal transport
/// layer specification for details.
///
/// The process of plug-and-play node-ID allocation always involves two types of nodes: "allocators", which serve
/// allocation requests; and "allocatees", which request PnP node-ID from allocators. A Cyphal network may implement
/// the following configurations of allocators:
///
///   - Zero allocators, in which case plug-and-play node-ID allocation cannot be used, only nodes with statically
///     configured node-ID can communicate.
///
///   - One allocator, in which case the feature of plug-and-play node-ID allocation will become unavailable
///     if the allocator fails. In this configuration, the role of the allocator can be performed even by a very
///     resource-constrained system, e.g., a low-end microcontroller.
///
///   - Three allocators, in which case the allocators will be using a replicated allocation table via a
///     distributed consensus algorithm. In this configuration, the network can tolerate the loss of one
///     allocator and continue to serve allocation requests. This configuration requires the allocators to
///     maintain large data structures for the needs of the distributed consensus algorithm, and may therefore
///     require a slightly more sophisticated computational platform, e.g., a high-end microcontroller.
///
///   - Five allocators, it is the same as the three allocator configuration reviewed above except that the network
///     can tolerate the loss of two allocators and still continue to serve allocation requests.
///
/// In order to get a PnP node-ID, an allocatee shall have a globally unique 128-bit integer identifier, known as
/// unique-ID (where "globally unique" means that the probability of having two nodes anywhere in the world that share
/// the same unique-ID is negligibly low). This is the same value that is used in the field unique_id of the data type
/// uavcan.node.GetInfo. All PnP nodes shall support the service uavcan.node.GetInfo, and they shall use the same
/// unique-ID value when requesting node-ID allocation and when responding to the GetInfo requests (there may exist
/// other usages of the unique-ID value, but they lie outside of the scope of the PnP protocol).
///
/// During allocation, the allocatee communicates its unique-ID to the allocator (or allocators in the case of a
/// redundant allocator configuration), which then use it to produce an appropriate allocation response. Unique-ID
/// values are kept by allocators in the "allocation table" - a data structure that contains the mapping between
/// unique-ID and the corresponding node-ID values. The allocation table is a write-only data structure that can
/// only expand. When a new allocatee requests a PnP node-ID, its unique-ID is recorded in the allocation table,
/// and all subsequent allocation requests from the same allocatee will be served with the same node-ID value.
///
/// In configurations with redundant allocators, every allocator maintains a replica of the same allocation table
/// (a Cyphal network cannot contain more than one allocation table, regardless of the number of allocators employed).
/// While the allocation table is a write-only data structure that can only grow, it is still possible to wipe the
/// table completely (as long as it is removed from all redundant allocators on the network simultaneously),
/// forcing the allocators to forget known nodes and perform all future allocations anew.
///
/// In the context of the following description, nodes that use a manually-configured node-ID will be referred to as
/// "static nodes". It is assumed that allocators are always static nodes themselves since there is no other authority
/// on the network that can grant a PnP node-ID, so allocators are unable to request a PnP node-ID for themselves.
/// Excepting allocators, it is not recommended to mix PnP and static nodes on the same network; i.e., normally,
/// a Cyphal network should contain either all static nodes, or all PnP nodes (excepting allocators). If this
/// recommendation cannot be followed, the following rules of safe co-existence of PnP nodes with static nodes should
/// be adopted:
///   - It is safe to connect PnP nodes to the bus at any time.
///   - A static node can be connected to the bus if the allocator (allocators) is (are) already aware of it.
///     I.e., the static node is already listed in the allocation table.
///   - A new static node (i.e., a node that does not meet the above criterion) can be connected to the bus only if
///     no PnP allocation requests are happening at the moment.
///
/// Due to the possibility of coexistence of static nodes with PnP nodes, allocators are tasked with monitoring
/// the nodes present in the network. If the allocator detects an online node in the network the node-ID of which is
/// not found in the allocation table (or the local copy thereof in the case of redundant allocators), the allocator
/// shall create a new mock entry where the node-ID matches that of the newly detected node and the unique-ID is set to
/// zero (i.e., a 128-bit long sequence of zero bits). This behavior ensures that PnP nodes will never be granted
/// node-ID values that are already taken by static nodes. Allocators are allowed to request the true unique-ID of the
/// newly detected nodes by issuing requests uavcan.node.GetInfo instead of using mock zero unique-IDs, but this is not
/// required for the sake of simplicity and determinism (some nodes may fail to respond to the GetInfo request, e.g.,
/// if this service is not supported). Note that in the case of redundant allocators, some of them may be relieved of
/// this task due to the intrinsic properties of the distributed consensus algorithm; please refer to the documentation
/// for the data type uavcan.pnp.cluster.AppendEntries for more information.
///
/// The unique-ID & node-ID pair of each allocator shall be kept in the allocation table as well. It is allowed to
/// replace
/// the unique-ID values of allocators with zeros at the discretion of the implementer.
///
/// As can be inferred from the above, the process of PnP node-ID allocation involves up to two types of communications:
///
///   - "Allocatee-allocator exchange" - this communication is used when an allocatee requests a PnP node-ID from the
///     allocator (or redundant allocators), and also when the allocator transmits a response back to the allocatee.
///     This communication is invariant to the allocator configuration used, i.e., the allocatees are not aware of
///     how many allocators are available on the network and how they are configured. In configurations with
///     non-redundant (i.e., single) allocator, this is the only type of PnP allocation exchanges.
///
///   - "Allocator-allocator exchange" - this communication is used by redundant allocators for the maintenance of
///     the replicated allocation table and for other needs of the distributed consensus algorithm. Allocatees are
///     completely isolated and are unaware of these exchanges. This communication is not used with the single-allocator
///     configuration, since there is only one server and the allocation table is not distributed. The data types
///     used for the allocator-allocator exchanges are defined in the namespace uavcan.pnp.cluster.
///
/// As has been said earlier, the logic used for communication between allocators (for the needs of the maintenance of
/// the distributed allocation table) is completely unrelated to the allocatees. The allocatees are unaware of these
/// exchanges, and they are also unaware of the allocator configuration used on the network: single or redundant.
/// As such, the documentation you're currently reading does not describe the logic and requirements of the
/// allocator-allocator exchanges for redundant configurations; for that, please refer to the documentation for the
/// data type uavcan.pnp.cluster.AppendEntries.
///
/// Allocatee-allocator exchanges are performed using only this message type uavcan.pnp.NodeIDAllocationData. Allocators
/// use it with regular message transfers; allocatees use it with anonymous message transfers. The specification and
/// usage info for this data type is provided below.
///
/// The general idea of the allocatee-allocator exchanges is that the allocatee communicates to the allocator its
/// unique-ID and, if applicable, the preferred node-ID value that it would like to have. The allocatee uses
/// anonymous message transfers of this type. The allocator performs the allocation and sends a response using
/// the same message type, where the field for unique-ID is populated with the unique-ID of the requesting node
/// and the field for node-ID is populated with the allocated node-ID. All exchanges from allocatee to allocator use
/// single-frame transfers only (see the specification for more information on the limitations of anonymous messages).
///
/// The allocatee-allocator exchange logic differs between allocators and allocatees. For allocators, the logic is
/// trivial: upon reception of a request, the allocator performs an allocation and sends a response back. If the
/// allocation could not be performed for any reason (e.g., the allocation table is full, or there was a failure),
/// no response is sent back (i.e., the request is simply ignored); the recommended strategy for the allocatee is to
/// continue sending new allocation requests until a response is granted or a higher-level system (e.g., a maintenance
/// technician or some automation) intervenes to rectify the problem (e.g., by purging the allocation table).
/// The allocator that could not complete an allocation for any reason is recommended to emit a diagnostic message
/// with a human-readable description of the problem. For allocatees, the logic is described below.
///
/// This message is used for PnP node-ID allocation on all transports where the maximum transmission unit size is
/// sufficiently large. For low-MTU transports such as Classic CAN there is an older version of the definition (v1)
/// that takes the low MTU into account (the unique-ID value is replaced with a short hash in order to fit the data
/// into one 7-byte-long transfer).
///
/// Generally, the randomly chosen values of the request period (Trequest) should be in the range from 0 to 1 seconds.
/// Applications that are not concerned about the allocation time are recommended to pick higher values, as it will
/// reduce interference with other nodes where faster allocations may be desirable. The random interval shall be chosen
/// anew per transmission, whereas the pseudo node-ID value is allowed to stay constant per node.
///
/// The source of random data for Trequest shall be likely to yield different values for participating nodes, avoiding
/// common sequences. This implies that the time since boot alone is not a sufficiently robust source of randomness,
/// as that would be probable to cause nodes powered up at the same time to emit colliding messages repeatedly.
///
/// The response timeout is not explicitly defined for this protocol, as the allocatee will request a new allocation
/// Trequest units of time later again, unless an allocation has been granted. Since the request and response messages
/// are fully idempotent, accidentally repeated messages (e.g., due to benign race conditions that are inherent to this
/// protocol) are harmless.
///
/// On the allocatee's side the protocol is defined through the following set of rules:
///
///   Rule A. On initialization:
///     1. The allocatee subscribes to this message.
///     2. The allocatee starts the Request Timer with a random interval of Trequest.
///
///   Rule B. On expiration of the Request Timer:
///     1. Request Timer restarts with a random interval of Trequest (chosen anew).
///     2. The allocatee broadcasts an allocation request message, where the fields are populated as follows:
///        node_id   - the preferred node-ID, or the highest valid value if the allocatee doesn't have any preference.
///        unique_id - the 128-bit unique-ID of the allocatee, same value that is reported via uavcan.node.GetInfo.
///
///   Rule C. On an allocation message WHERE (source node-ID is non-anonymous, i.e., regular allocation response)
///                                    AND   (the field unique_id matches the allocatee's unique-ID):
///     1. Request Timer stops.
///     2. The allocatee initializes its node-ID with the received value.
///     3. The allocatee terminates its subscription to allocation messages.
///     4. Exit.
///
/// As can be seen, the algorithm assumes that the allocatee will continue to emit requests at random intervals
/// until an allocation is granted or the allocatee is disconnected.
///
struct NodeIDAllocationData_2_0 final
{
    struct _traits_  // The name is surrounded with underscores to avoid collisions with DSDL attributes.
    {
        _traits_() = delete;
        static constexpr bool HasFixedPortID = true;
        static constexpr std::uint16_t FixedPortId = 8165U;
        static constexpr bool IsServiceType = false;

        /// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
        /// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
        /// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
        /// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
        /// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
        /// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
        /// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.
        static constexpr std::size_t ExtentBytes                  = 48UL;
        static constexpr std::size_t SerializationBufferSizeBytes = 18UL;
        static_assert(ExtentBytes >= SerializationBufferSizeBytes, "Internal constraint violation");
        static_assert(ExtentBytes < (std::numeric_limits<std::size_t>::max() / 8U), "This message is too large to be handled by the selected types");
        struct TypeOf
        {
            TypeOf() = delete;
            using node_id = uavcan::node::ID_1_0;
            using unique_id = std::array<std::uint8_t,16>;
        };
    };

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+
    ///
    /// If the message transfer is anonymous (i.e., allocation request), this is the preferred ID.
    /// If the message transfer is non-anonymous (i.e., allocation response), this is the allocated ID.
    ///
    /// If the allocatee does not have any preference, it should request the highest possible node-ID. Keep in mind that
    /// the two highest node-ID values are reserved for network maintenance tools; requesting those is not prohibited,
    /// but the allocator is recommended to avoid granting these node-ID, using nearest available lower value instead.
    /// The allocator will traverse the allocation table starting from the preferred node-ID upward,
    /// until a free node-ID is found (or the first ID reserved for network maintenance tools is reached).
    /// If a free node-ID could not be found, the allocator will restart the search from the preferred node-ID
    /// downward, until a free node-ID is found.
    ///
    _traits_::TypeOf::node_id node_id;
    ///
    /// The unique-ID of the allocatee. This is the SAME value that is reported via uavcan.node.GetInfo.
    /// The value is subjected to the same set of constraints; e.g., it can't be changed while the node is running,
    /// and the same value should be unlikely to be used by any two different nodes anywhere in the world.
    ///
    /// If this is a non-anonymous transfer (i.e., allocation response), allocatees will match this value against their
    /// own unique-ID, and ignore the message if there is no match. If the IDs match, then the field node_id contains
    /// the allocated node-ID value for this node.
    ///
    _traits_::TypeOf::unique_id unique_id{};
};

inline nunavut::support::SerializeResult serialize(const NodeIDAllocationData_2_0& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    const std::size_t capacity_bits = out_buffer.size();
    if ((static_cast<std::size_t>(capacity_bits)) < 144UL)
    {
        return -nunavut::support::Error::SerializationBufferTooSmall;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    {   // uavcan.node.ID.1.0 node_id
        std::size_t _size_bytes0_ = 2UL;  // Nested object (max) size, in bytes.
        auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize(obj.node_id, _subspan0_.value());
        if (not _err0_)
        {
            return _err0_;
        }
        _size_bytes0_ = _err0_.value();
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        out_buffer.add_offset(_size_bytes0_ * 8U);
        //
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
    {
        const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
        if(not _result0_){
            return -_result0_.error();
        }
    }
    // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
    return out_buffer.offset_bytes_ceil();
}

inline nunavut::support::SerializeResult deserialize(NodeIDAllocationData_2_0& obj,
                                                     nunavut::support::const_bitspan in_buffer)
{
    const auto capacity_bits = in_buffer.size();
    // uavcan.node.ID.1.0 node_id
    {
        std::size_t _size_bytes1_ = in_buffer.size() / 8U;
        {
            const auto _err1_ = deserialize(obj.node_id, in_buffer.subspan());
            if(_err1_){
                _size_bytes1_ = _err1_.value();
            }else{
                return -_err1_.error();
            }
        }
        in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
    }
    // saturated uint8[16] unique_id
    for (std::size_t _index4_ = 0U; _index4_ < 16UL; ++_index4_)
    {
        obj.unique_id[_index4_] = in_buffer.getU8(8U);
        in_buffer.add_offset(8U);
    }
    in_buffer.align_offset_to<8U>();
    auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
    return { static_cast<std::size_t>(_bits_got_ / 8U) };
}

} // namespace pnp
} // namespace uavcan

#endif // UAVCAN_PNP_NODE_ID_ALLOCATION_DATA_2_0_HPP_INCLUDED
