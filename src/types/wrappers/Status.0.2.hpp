/*
 * Status.0.2.hpp
 *
 * Created: 1/25/2021 12:12:55 PM
 *  Author: Kyle
 */ 

#include <libcanard/canard.h>

#include <reg/drone/service/battery/Status_0_2.h>

#ifndef STATUS_0_2_H_
#define STATUS_0_2_H_

class Status_0_2{
	public:
	reg_drone_service_battery_Status_0_2 data;

	static constexpr CanardPortID       PORT_ID = 43;
	static constexpr size_t             MAX_PAYLOAD_SIZE = reg_drone_service_battery_Status_0_2_SERIALIZATION_BUFFER_SIZE_BYTES_;
	static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindMessage;
	
	Status_0_2()
	{
		reg_drone_service_battery_Status_0_2_initialize_(&data);
	}

	Status_0_2(Status_0_2 const & other)
	{
		memcpy(&data, &other.data, sizeof(data));
	}

	static Status_0_2 deserialize(CanardTransfer const & transfer)
	{
		Status_0_2 b;
		size_t inout_buffer_size_bytes = transfer.payload_size;
		reg_drone_service_battery_Status_0_2_deserialize_(&b.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
		return b;
	}

	size_t serialize(uint8_t * payload) const
	{
		size_t inout_buffer_size_bytes = Status_0_2::MAX_PAYLOAD_SIZE;
		return (reg_drone_service_battery_Status_0_2_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
	}
}; 

#endif // STATUS_0_2_H_