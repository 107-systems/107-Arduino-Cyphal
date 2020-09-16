/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "ExecuteCommand.1.0.Request.h"

#include <libcanard/canard_dsdl.h>

#undef max
#undef min
#include <algorithm>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace ExecuteCommand_1_0
{

/**************************************************************************************
 * STATIC CONSTEXPR DEFINITION
 **************************************************************************************/

constexpr CanardPortID       Request::PORT_ID;
constexpr size_t             Request::MAX_PAYLOAD_SIZE;
constexpr CanardTransferKind Request::TRANSFER_KIND;

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

Request::Request()
{
  uavcan_node_ExecuteCommand_1_0_Request_init(&data);
}

Request::Request(Request const & other)
{
  memcpy(&data, &other.data, sizeof(data));
}

Request::Request(uint16_t const command, uint8_t const * parameter, size_t const parameter_length)
{
  data.command = command;
  data.parameter_length = std::min(parameter_length, static_cast<size_t>(uavcan_node_ExecuteCommand_1_0_Request_parameter_array_capacity()));
  std::copy(parameter, parameter + data.parameter_length, data.parameter);
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

Request Request::create(CanardTransfer const & transfer)
{
  Request r;
  uavcan_node_ExecuteCommand_1_0_Request_deserialize(&r.data, 0, (uint8_t *)(transfer.payload), transfer.payload_size);
  return r;
}

size_t Request::encode(uint8_t * payload) const
{
  size_t const offset = uavcan_node_ExecuteCommand_1_0_Request_serialize(&data, 0, payload);
  return (offset / 8);
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* ExecuteCommand_1_0 */
