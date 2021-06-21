/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_UAVCAN_TYPES_UAVCAN_TIME_SYNCHRONIZATION_1_0_HPP_
#define ARDUINO_UAVCAN_TYPES_UAVCAN_TIME_SYNCHRONIZATION_1_0_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include <types/uavcan/time/Synchronization_1_0.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace uavcan {
namespace time {

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID = uavcan_time_Synchronization_1_0_FIXED_PORT_ID_>
class Synchronization_1_0
{

public:

  uavcan_time_Synchronization_1_0 data;

  static constexpr CanardPortID       PORT_ID          = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_time_Synchronization_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND    = CanardTransferKindMessage;

  Synchronization_1_0()
  {
    uavcan_time_Synchronization_1_0_initialize_(&data);
  }

  Synchronization_1_0(Synchronization_1_0 const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static Synchronization_1_0 deserialize(CanardTransfer const & transfer)
  {
    Synchronization_1_0<ID> i;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    uavcan_time_Synchronization_1_0_deserialize_(&i.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return i;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = Synchronization_1_0<ID>::MAX_PAYLOAD_SIZE;
    return (uavcan_time_Synchronization_1_0_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* time */
} /* uavcan */

#endif /* ARDUINO_UAVCAN_TYPES_UAVCAN_TIME_SYNCHRONIZATION_1_0_HPP_ */
