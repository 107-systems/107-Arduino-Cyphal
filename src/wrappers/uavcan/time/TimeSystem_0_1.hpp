/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_UAVCAN_TYPES_UAVCAN_TIME_TIMESYSTEM_0_1_HPP_
#define ARDUINO_UAVCAN_TYPES_UAVCAN_TIME_TIMESYSTEM_0_1_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include <types/uavcan/time/TimeSystem_0_1.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace uavcan {
namespace time {

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID>
class TimeSystem_0_1
{

public:

  uavcan_time_TimeSystem_0_1 data;

  static constexpr CanardPortID       PORT_ID          = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_time_TimeSystem_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND    = CanardTransferKindMessage;

  TimeSystem_0_1()
  {
    uavcan_time_TimeSystem_0_1_initialize_(&data);
  }

  TimeSystem_0_1(TimeSystem_0_1 const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static TimeSystem_0_1 deserialize(CanardTransfer const & transfer)
  {
    TimeSystem_0_1<ID> i;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    uavcan_time_TimeSystem_0_1_deserialize_(&i.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return i;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = TimeSystem_0_1<ID>::MAX_PAYLOAD_SIZE;
    return (uavcan_time_TimeSystem_0_1_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* time */
} /* uavcan */

#endif /* ARDUINO_UAVCAN_TYPES_UAVCAN_TIME_TIMESYSTEM_0_1_HPP_ */
