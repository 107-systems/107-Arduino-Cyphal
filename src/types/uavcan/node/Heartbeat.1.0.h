/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_TRANSFER_UAVCAN_NODE_HEARTBEAT_1_0_H_
#define ARDUINO_TRANSFER_UAVCAN_NODE_HEARTBEAT_1_0_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include "Heartbeat.1.0.nnvg.h"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class Heartbeat_1_0
{

public:

  enum class Health : uint8_t
  {
    NOMINAL  = uavcan_node_Heartbeat_1_0_HEALTH_NOMINAL,
    ADVISORY = uavcan_node_Heartbeat_1_0_HEALTH_ADVISORY,
    CAUTION  = uavcan_node_Heartbeat_1_0_HEALTH_CAUTION,
    WARNING  = uavcan_node_Heartbeat_1_0_HEALTH_WARNING,
  };

  enum class Mode : uint8_t
  {
    OPERATIONAL      = uavcan_node_Heartbeat_1_0_MODE_OPERATIONAL,
    INITIALIZATION   = uavcan_node_Heartbeat_1_0_MODE_INITIALIZATION,
    MAINTENANCE      = uavcan_node_Heartbeat_1_0_MODE_MAINTENANCE,
    SOFTWARE_UPDATE  = uavcan_node_Heartbeat_1_0_MODE_SOFTWARE_UPDATE,
    OFFLINE          = uavcan_node_Heartbeat_1_0_MODE_OFFLINE,
  };

  uavcan_node_Heartbeat_1_0 data;

  static constexpr CanardPortID       PORT_ID = uavcan_node_Heartbeat_1_0_FIXED_PORT_ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_node_Heartbeat_1_0_MAX_SERIALIZED_REPRESENTATION_SIZE_BYTES;
  static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindMessage;

  Heartbeat_1_0(uint32_t const uptime, uint8_t const health, uint8_t const mode, uint32_t const vssc);
  Heartbeat_1_0(uint32_t const uptime, Health const health, Mode const mode, uint32_t const vssc);

  static Heartbeat_1_0 create(CanardTransfer const & transfer);
  size_t encode(uint8_t * payload) const;

};

#endif /* ARDUINO_TRANSFER_UAVCAN_NODE_HEARTBEAT_1_0_H_ */
