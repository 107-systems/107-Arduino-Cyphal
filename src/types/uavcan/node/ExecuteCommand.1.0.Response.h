/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_TYPES_UAVCAN_NODE_EXECUTECOMMAND_1_0_RESPONSE_H_
#define ARDUINO_TYPES_UAVCAN_NODE_EXECUTECOMMAND_1_0_RESPONSE_H_

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

class Response
{

public:

  enum class Status : uint8_t
  {
    SUCCESS        = uavcan_node_ExecuteCommand_Response_1_0_STATUS_SUCCESS,
    FAILURE        = uavcan_node_ExecuteCommand_Response_1_0_STATUS_FAILURE,
    NOT_AUTHORIZED = uavcan_node_ExecuteCommand_Response_1_0_STATUS_NOT_AUTHORIZED,
    BAD_COMMAND    = uavcan_node_ExecuteCommand_Response_1_0_STATUS_BAD_COMMAND,
    BAD_PARAMETER  = uavcan_node_ExecuteCommand_Response_1_0_STATUS_BAD_PARAMETER,
    BAD_STATE      = uavcan_node_ExecuteCommand_Response_1_0_STATUS_BAD_STATE,
    INTERNAL_ERROR = uavcan_node_ExecuteCommand_Response_1_0_STATUS_INTERNAL_ERROR,
  };

  uavcan_node_ExecuteCommand_Response_1_0 data;

  static constexpr CanardPortID       PORT_ID = uavcan_node_ExecuteCommand_1_0_FIXED_PORT_ID_;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_node_ExecuteCommand_Response_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindResponse;

  Response();
  Response(Response const & other);

  static Response deserialize(CanardTransfer const & transfer);
  size_t encode(uint8_t * payload) const;

  void operator = (Status const status);
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* ExecuteCommand_1_0 */

#endif /* ARDUINO_TYPES_UAVCAN_NODE_EXECUTECOMMAND_1_0_RESPONSE_H_ */
