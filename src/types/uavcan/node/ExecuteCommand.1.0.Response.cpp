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

Response::Response()
{
  uavcan_node_ExecuteCommand_1_0_Response_init(&data);
}

Response::Response(Response const & other)
{
  memcpy(&data, &other.data, sizeof(data));
}

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
  Response r;
  uavcan_node_ExecuteCommand_1_0_Response_deserialize(&r.data, 0, (uint8_t *)(transfer.payload), transfer.payload_size);
  return r;
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
