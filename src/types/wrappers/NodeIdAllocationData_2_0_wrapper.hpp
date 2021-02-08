 /*
 * NodeIdAllocationData_2_0_wrapper.hpp
 *
 * Created: 2/7/2021
 *  Author: Nick
 */ 

#include <libcanard/canard.h>

#include <uavcan/pnp/NodeIDAllocationData_2_0.h>

#ifndef NODEIDALLOC_2_0
#define NODEIDALLOC_2_0

class NodeIDAllocationData{
	
	public:
	uavcan_pnp_NodeIDAllocationData_2_0 data;

	static constexpr CanardPortID       PORT_ID = 1;
	static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_pnp_NodeIDAllocationData_2_0_SERIALIZATION_BUFFER_SIZE_BYTES_;
	static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindMessage;
	
	NodeIDAllocationData()
	{
		uavcan_pnp_NodeIDAllocationData_2_0_initialize_(&data);
	}

	NodeIDAllocationData(NodeIDAllocationData const & other)
	{
		memcpy(&data, &other.data, sizeof(data));
	}

	static NodeIDAllocationData deserialize(CanardTransfer const & transfer)
	{
		NodeIDAllocationData al;
		size_t inout_buffer_size_bytes = transfer.payload_size;
		uavcan_pnp_NodeIDAllocationData_2_0_deserialize_(&al.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
		return al;
	}

	size_t serialize(uint8_t * payload) const
	{
		size_t inout_buffer_size_bytes = NodeIDAllocationData::MAX_PAYLOAD_SIZE;
		return (uavcan_pnp_NodeIDAllocationData_2_0_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
	}
};

#endif // NODEIDALLOC_2_0