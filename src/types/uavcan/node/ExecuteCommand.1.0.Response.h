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
    SUCCESS        = 0,
    FAILURE        = 1,
    NOT_AUTHORIZED = 2,
    BAD_COMMAND    = 3,
    BAD_PARAMETER  = 4,
    BAD_STATE      = 5,
    INTERNAL_ERROR = 6,
  };

  uavcan_node_ExecuteCommand_1_0_Response data;

  static constexpr CanardPortID       PORT_ID = uavcan_node_ExecuteCommand_1_0_FIXED_PORT_ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_node_ExecuteCommand_1_0_Response_MAX_SERIALIZED_REPRESENTATION_SIZE_BYTES;
  static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindResponse;

  Response();
  Response(Response const & other);

  static Response create(CanardTransfer const & transfer);
  size_t encode(uint8_t * payload) const;

  void operator = (Status const status);
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* ExecuteCommand_1_0 */

#endif /* ARDUINO_TYPES_UAVCAN_NODE_EXECUTECOMMAND_1_0_RESPONSE_H_ */
