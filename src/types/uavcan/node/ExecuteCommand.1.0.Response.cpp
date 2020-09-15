/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "ExecuteCommand.1.0.Response.h"

#include "../../../utility/convert.hpp"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace ExecuteCommand_1_0
{

/**************************************************************************************
 * STATIC CONSTEXPR DEFINITION
 **************************************************************************************/

constexpr CanardPortID       Response::PORT_ID;
constexpr size_t             Response::MAX_PAYLOAD_SIZE;
constexpr CanardTransferKind Response::TRANSFER_KIND;

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

Response::Response(uint8_t const status)
: data{status}
{

}

Response::Response(Status const status)
: Response{to_integer(status)}
{

}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

Response Response::create(CanardTransfer const & transfer)
{
  uavcan_node_ExecuteCommand_1_0_Response d;
  uavcan_node_ExecuteCommand_1_0_Response_init(&d);
  uavcan_node_ExecuteCommand_1_0_Response_deserialize(&d, 0, (uint8_t *)(transfer.payload), transfer.payload_size);
  return Response(d.status);
}

size_t Response::encode(uint8_t * payload) const
{
  size_t const offset = uavcan_node_ExecuteCommand_1_0_Response_serialize(&data, 0, payload);
  return (offset / 8);
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* ExecuteCommand_1_0 */
