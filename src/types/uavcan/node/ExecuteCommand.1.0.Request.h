/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_TRANSFER_UAVCAN_NODE_EXECUTE_COMMAND_1_0_REQUEST_H_
#define ARDUINO_TRANSFER_UAVCAN_NODE_EXECUTE_COMMAND_1_0_REQUEST_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include "ExecuteCommand.1.0.nnvg.h"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace ExecuteCommand_1_0
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class Request
{

public:

  uavcan_node_ExecuteCommand_1_0_Request data;

  static constexpr CanardPortID       PORT_ID = uavcan_node_ExecuteCommand_1_0_FIXED_PORT_ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_node_ExecuteCommand_1_0_Request_MAX_SERIALIZED_REPRESENTATION_SIZE_BYTES;
  static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindRequest;

  Request();
  Request(Request const & other);

  static Request create(CanardTransfer const & transfer);
  size_t encode(uint8_t * payload) const;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* ExecuteCommand_1_0 */

#endif /* ARDUINO_TRANSFER_UAVCAN_NODE_EXECUTE_COMMAND_1_0_REQUEST_H_ */
