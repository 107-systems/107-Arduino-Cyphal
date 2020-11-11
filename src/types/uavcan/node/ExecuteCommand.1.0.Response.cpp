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
  uavcan_node_ExecuteCommand_Response_1_0_initialize_(&data);
}

Response::Response(Response const & other)
{
  memcpy(&data, &other.data, sizeof(data));
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

Response Response::create(CanardTransfer const & transfer)
{
  Response r;
  size_t inout_buffer_size_bytes = transfer.payload_size;
  uavcan_node_ExecuteCommand_Response_1_0_deserialize_(&r.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
  return r;
}

size_t Response::encode(uint8_t * payload) const
{
  size_t inout_buffer_size_bytes = Response::MAX_PAYLOAD_SIZE;

  if (uavcan_node_ExecuteCommand_Response_1_0_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS)
    return 0;
  else
    return inout_buffer_size_bytes;
}

void Response::operator = (Status const status)
{
  data.status = arduino::_107_::uavcan::to_integer(status);
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* ExecuteCommand_1_0 */
