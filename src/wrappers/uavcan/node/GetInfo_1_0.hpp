/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_TRANSFER_UAVCAN_NODE_GETINFO_1_0_HPP_
#define ARDUINO_TRANSFER_UAVCAN_NODE_GETINFO_1_0_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include <types/uavcan/node/GetInfo_1_0.h>

#include "../../../utility/convert.hpp"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace uavcan {
namespace node {
namespace GetInfo_1_0 {

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID = uavcan_node_GetInfo_1_0_FIXED_PORT_ID_>
class Request
{

public:

  uavcan_node_GetInfo_Request_1_0 data;

  static constexpr CanardPortID       PORT_ID = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_node_GetInfo_Request_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindRequest;

  Request()
  {
    uavcan_node_GetInfo_Request_1_0_initialize_(&data);
  }

  Request(Request const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static Request deserialize(CanardTransfer const & transfer)
  {
    Request r;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    uavcan_node_GetInfo_Request_1_0_deserialize_(&r.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return r;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = Request::MAX_PAYLOAD_SIZE;
    return (uavcan_node_GetInfo_Request_1_0_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

template <CanardPortID ID = uavcan_node_GetInfo_1_0_FIXED_PORT_ID_>
class Response
{

public:

  uavcan_node_GetInfo_Response_1_0 data;

  static constexpr CanardPortID       PORT_ID = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_node_GetInfo_Response_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindResponse;

  Response()
  {
    uavcan_node_GetInfo_Response_1_0_initialize_(&data);
  }

  Response(Response const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static Response deserialize(CanardTransfer const & transfer)
  {
    Response r;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    uavcan_node_GetInfo_Response_1_0_deserialize_(&r.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return r;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = Response::MAX_PAYLOAD_SIZE;
    return (uavcan_node_GetInfo_Response_1_0_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* uavcan */
} /* node */
} /* GetInfo_1_0 */

#endif /* ARDUINO_TRANSFER_UAVCAN_NODE_GETINFO_1_0_HPP_ */
