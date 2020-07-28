/**
 * @brief   Arduino library for providing a convenient C++ interface for accessing UAVCAN.
 * @license MIT
 */

#ifndef ARDUINO_TYPES_UAVCAN_NODE_EXECUTECOMMAND_1_0_RESPONSE_H_
#define ARDUINO_TYPES_UAVCAN_NODE_EXECUTECOMMAND_1_0_RESPONSE_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <stdlib.h>

#include <libcanard/canard.h>

#include "ExecuteCommand.1.0.Request.h"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class ExecuteCommand_1_0_Response
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

  static constexpr CanardPortID PORT_ID = ExecuteCommand_1_0_Request::PORT_ID;
  static constexpr size_t       MAX_PAYLOAD_SIZE = 7;

  ExecuteCommand_1_0_Response(Status const status);

  static ExecuteCommand_1_0_Response create(CanardTransfer const & transfer);

  inline Status status() const { return _status; }


private:

  Status _status;

};

#endif /* ARDUINO_TYPES_UAVCAN_NODE_EXECUTECOMMAND_1_0_RESPONSE_H_ */
