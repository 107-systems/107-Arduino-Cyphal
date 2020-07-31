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

#include <stdlib.h>

#include <libcanard/canard.h>

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

  static constexpr CanardPortID       PORT_ID = 435;
  static constexpr size_t             MAX_PAYLOAD_SIZE = 2 + 112;
  static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindRequest;


  Request(uint16_t const command, uint8_t const * param, size_t const param_len);

  static Request create(CanardTransfer const & transfer);

  size_t encode(uint8_t * payload) const;


  inline uint16_t  command  ()                       const { return _command; }
  inline void      command  (uint16_t const command)       { _command = command; }
  inline uint8_t * param    ()                             { return _param; }
  inline size_t    param_len()                       const { return _param_len; }


private:

  uint16_t _command;
  uint8_t _param[112];
  size_t _param_len;

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* ExecuteCommand_1_0 */

#endif /* ARDUINO_TRANSFER_UAVCAN_NODE_EXECUTE_COMMAND_1_0_REQUEST_H_ */
