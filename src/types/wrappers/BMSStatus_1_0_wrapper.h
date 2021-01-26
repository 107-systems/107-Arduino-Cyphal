/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_TRANSFER_UAVCAN_NODE_BMSSTATUS_1_0_H_
#define ARDUINO_TRANSFER_UAVCAN_NODE_BMSSTATUS_1_0_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include <reg/drone/sensor/BMSStatus_1_0.h>

#include <utility/convert.hpp>

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class BMSStatus_1_0
{

public:

  reg_drone_sensor_BMSStatus_1_0 data;

  static constexpr CanardPortID       PORT_ID = 42; 
  static constexpr size_t             MAX_PAYLOAD_SIZE = reg_drone_sensor_BMSStatus_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindMessage;

  BMSStatus_1_0()
  {
    reg_drone_sensor_BMSStatus_1_0_initialize_(&data);
  }

  BMSStatus_1_0(BMSStatus_1_0 const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static BMSStatus_1_0 deserialize(CanardTransfer const & transfer)
  {
    BMSStatus_1_0 b;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    reg_drone_sensor_BMSStatus_1_0_deserialize_(&b.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return b;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = BMSStatus_1_0::MAX_PAYLOAD_SIZE;
    return (reg_drone_sensor_BMSStatus_1_0_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }

  /* void operator = (Health const health)
  {
    data.health.value = arduino::_107_::uavcan::to_integer(health);
  } */

  /* void operator = (Mode const mode)
  {
    data.mode.value = arduino::_107_::uavcan::to_integer(mode);
  } */
};

#endif /* ARDUINO_TRANSFER_UAVCAN_NODE_BMSSTATUS_1_0_H_ */
