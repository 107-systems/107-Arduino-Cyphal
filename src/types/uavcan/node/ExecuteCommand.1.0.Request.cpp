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
  uavcan_node_ExecuteCommand_Request_1_0_initialize_(&data);
}

Request::Request(Request const & other)
{
  memcpy(&data, &other.data, sizeof(data));
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

Request Request::deserialize(CanardTransfer const & transfer)
{
  Request r;
  size_t inout_buffer_size_bytes = transfer.payload_size;
  uavcan_node_ExecuteCommand_Request_1_0_deserialize_(&r.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
  return r;
}

size_t Request::serialize(uint8_t * payload) const
{
  size_t inout_buffer_size_bytes = Request::MAX_PAYLOAD_SIZE;

  if (uavcan_node_ExecuteCommand_Request_1_0_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS)
    return 0;
  else
    return inout_buffer_size_bytes;
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* ExecuteCommand_1_0 */
