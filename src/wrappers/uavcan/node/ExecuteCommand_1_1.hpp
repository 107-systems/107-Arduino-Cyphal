/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_TRANSFER_UAVCAN_NODE_EXECUTE_COMMAND_1_1_HPP_
#define ARDUINO_TRANSFER_UAVCAN_NODE_EXECUTE_COMMAND_1_1_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include <types/uavcan/node/ExecuteCommand_1_1.h>

#include "../../../utility/convert.hpp"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace uavcan {
namespace node {
namespace ExecuteCommand_1_1 {

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID = uavcan_node_ExecuteCommand_1_1_FIXED_PORT_ID_>
class Request
{

public:

  uavcan_node_ExecuteCommand_Request_1_1 data;

  static constexpr CanardPortID       PORT_ID = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_node_ExecuteCommand_Request_1_1_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindRequest;

  Request()
  {
    uavcan_node_ExecuteCommand_Request_1_1_initialize_(&data);
  }

  Request(Request const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static Request deserialize(CanardTransfer const & transfer)
  {
    Request r;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    uavcan_node_ExecuteCommand_Request_1_1_deserialize_(&r.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return r;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = Request::MAX_PAYLOAD_SIZE;
    return (uavcan_node_ExecuteCommand_Request_1_1_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

template <CanardPortID ID = uavcan_node_ExecuteCommand_1_1_FIXED_PORT_ID_>
class Response
{

public:

  enum class Status : uint8_t
  {
    SUCCESS        = uavcan_node_ExecuteCommand_Response_1_1_STATUS_SUCCESS,
    FAILURE        = uavcan_node_ExecuteCommand_Response_1_1_STATUS_FAILURE,
    NOT_AUTHORIZED = uavcan_node_ExecuteCommand_Response_1_1_STATUS_NOT_AUTHORIZED,
    BAD_COMMAND    = uavcan_node_ExecuteCommand_Response_1_1_STATUS_BAD_COMMAND,
    BAD_PARAMETER  = uavcan_node_ExecuteCommand_Response_1_1_STATUS_BAD_PARAMETER,
    BAD_STATE      = uavcan_node_ExecuteCommand_Response_1_1_STATUS_BAD_STATE,
    INTERNAL_ERROR = uavcan_node_ExecuteCommand_Response_1_1_STATUS_INTERNAL_ERROR,
  };

  uavcan_node_ExecuteCommand_Response_1_1 data;

  static constexpr CanardPortID       PORT_ID = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_node_ExecuteCommand_Response_1_1_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindResponse;

  Response()
  {
    uavcan_node_ExecuteCommand_Response_1_1_initialize_(&data);
  }

  Response(Response const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static Response deserialize(CanardTransfer const & transfer)
  {
    Response r;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    uavcan_node_ExecuteCommand_Response_1_1_deserialize_(&r.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return r;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = Response::MAX_PAYLOAD_SIZE;
    return (uavcan_node_ExecuteCommand_Response_1_1_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }

  void operator = (Status const status)
  {
    data.status = arduino::_107_::uavcan::to_integer(status);
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* uavcan */
} /* node */
} /* ExecuteCommand_1_1 */

#endif /* ARDUINO_TRANSFER_UAVCAN_NODE_EXECUTE_COMMAND_1_1_HPP_ */
