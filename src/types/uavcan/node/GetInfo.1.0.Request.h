/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_TYPES_UAVCAN_NODE_GET_INFO_1_0_REQUEST_H_
#define ARDUINO_TYPES_UAVCAN_NODE_GET_INFO_1_0_REQUEST_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <stdlib.h>

#include <libcanard/canard.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace GetInfo_1_0
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class Request
{

public:

  static constexpr CanardPortID       PORT_ID = 430;
  static constexpr size_t             MAX_PAYLOAD_SIZE = 0;
  static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindRequest;


  Request() { }

  static Request create(CanardTransfer const & /* transfer */) { return Request(); }
         size_t  encode(uint8_t * /* payload */) const { return MAX_PAYLOAD_SIZE; }

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* GetInfo_1_0 */

#endif /* ARDUINO_TYPES_UAVCAN_NODE_GET_INFO_1_0_REQUEST_H_ */
