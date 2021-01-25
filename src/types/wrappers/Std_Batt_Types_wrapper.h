/*
 * Std_Batt_Types_wrapper.h
 *
 * Created: 1/25/2021 12:12:55 PM
 *  Author: Kyle
 */ 

#include <types/reg/drone/physics/electricity/SourceTs_0_1.h>
#include <types/reg/drone/service/battery/Status_0_1.h>
#include <types/reg/drone/service/battery/Parameters_0_1.h>

#ifndef STD_BATT_TYPES_WRAPPER_H_
#define STD_BATT_TYPES_WRAPPER_H_

class SourceTs_0_1{
	
	public:
		reg_drone_physics_electricity_SourceTs_0_1 data;

		static constexpr CanardPortID       PORT_ID = 42;
		static constexpr size_t             MAX_PAYLOAD_SIZE = reg_drone_physics_electricity_SourceTs_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_;
		static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindMessage;
		
		SourceTs_0_1()
		{
			reg_drone_physics_electricity_SourceTs_0_1_initialize_(&data);
		}

		SourceTs_0_1(SourceTs_0_1 const & other)
		{
			memcpy(&data, &other.data, sizeof(data));
		}

		static SourceTs_0_1 deserialize(CanardTransfer const & transfer)
		{
			SourceTs_0_1 b;
			size_t inout_buffer_size_bytes = transfer.payload_size;
			reg_drone_physics_electricity_SourceTs_0_1_deserialize_(&b.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
			return b;
		}

		size_t serialize(uint8_t * payload) const
		{
			size_t inout_buffer_size_bytes = SourceTs_0_1::MAX_PAYLOAD_SIZE;
			return (reg_drone_physics_electricity_SourceTs_0_1_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
		}
};

class Status_0_1{
	public:
		reg_drone_service_battery_Status_0_1 data;

		static constexpr CanardPortID       PORT_ID = 43;
		static constexpr size_t             MAX_PAYLOAD_SIZE = reg_drone_service_battery_Status_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_;
		static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindMessage;
		
		Status_0_1()
		{
			reg_drone_service_battery_Status_0_1_initialize_(&data);
		}

		Status_0_1(Status_0_1 const & other)
		{
			memcpy(&data, &other.data, sizeof(data));
		}

		static Status_0_1 deserialize(CanardTransfer const & transfer)
		{
			Status_0_1 b;
			size_t inout_buffer_size_bytes = transfer.payload_size;
			reg_drone_service_battery_Status_0_1_deserialize_(&b.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
			return b;
		}

		size_t serialize(uint8_t * payload) const
		{
			size_t inout_buffer_size_bytes = Status_0_1::MAX_PAYLOAD_SIZE;
			return (reg_drone_service_battery_Status_0_1_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
		}
};

class Parameters_0_1{
	public:
		reg_drone_service_battery_Parameters_0_1 data;

		static constexpr CanardPortID       PORT_ID = 44;
		static constexpr size_t             MAX_PAYLOAD_SIZE = reg_drone_service_battery_Parameters_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_;
		static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindMessage;
		
		Parameters_0_1()
		{
			reg_drone_service_battery_Parameters_0_1_initialize_(&data);
		}

		Parameters_0_1(Parameters_0_1 const & other)
		{
			memcpy(&data, &other.data, sizeof(data));
		}

		static Parameters_0_1 deserialize(CanardTransfer const & transfer)
		{
			Parameters_0_1 b;
			size_t inout_buffer_size_bytes = transfer.payload_size;
			reg_drone_service_battery_Parameters_0_1_deserialize_(&b.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
			return b;
		}

		size_t serialize(uint8_t * payload) const
		{
			size_t inout_buffer_size_bytes = Parameters_0_1::MAX_PAYLOAD_SIZE;
			return (reg_drone_service_battery_Parameters_0_1_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
		}	
};

#endif /* STD_BATT_TYPES_WRAPPER_H_ */