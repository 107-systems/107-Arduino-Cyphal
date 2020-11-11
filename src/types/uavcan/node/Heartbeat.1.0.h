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
    NOMINAL  = uavcan_node_Health_1_0_NOMINAL,
    ADVISORY = uavcan_node_Health_1_0_ADVISORY,
    CAUTION  = uavcan_node_Health_1_0_CAUTION,
    WARNING  = uavcan_node_Health_1_0_WARNING,
  };

  enum class Mode : uint8_t
  {
    OPERATIONAL      = uavcan_node_Mode_1_0_OPERATIONAL,
    INITIALIZATION   = uavcan_node_Mode_1_0_INITIALIZATION,
    MAINTENANCE      = uavcan_node_Mode_1_0_MAINTENANCE,
    SOFTWARE_UPDATE  = uavcan_node_Mode_1_0_SOFTWARE_UPDATE,
  };

  uavcan_node_Heartbeat_1_0 data;

  static constexpr CanardPortID       PORT_ID = uavcan_node_Heartbeat_1_0_FIXED_PORT_ID_;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_node_Health_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindMessage;

  Heartbeat_1_0();
  Heartbeat_1_0(Heartbeat_1_0 const & other);

  static Heartbeat_1_0 create(CanardTransfer const & transfer);
  size_t encode(uint8_t * payload) const;

  void operator = (Health const health);
  void operator = (Mode const mode);
};

#endif /* ARDUINO_TRANSFER_UAVCAN_NODE_HEARTBEAT_1_0_H_ */
