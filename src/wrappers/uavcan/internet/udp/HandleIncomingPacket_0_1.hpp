/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_UAVCAN_TYPES_UAVCAN_INTERNET_UDP_HANDLEINCOMINGPACKET_0_1_HPP_
#define ARDUINO_UAVCAN_TYPES_UAVCAN_INTERNET_UDP_HANDLEINCOMINGPACKET_0_1_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include <types/uavcan/internet/udp/HandleIncomingPacket_0_1.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace uavcan {
namespace internet {
namespace udp {
namespace HandleIncomingPacket_0_1 {

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID = uavcan_internet_udp_HandleIncomingPacket_0_1_FIXED_PORT_ID_>
class Request
{

public:

  uavcan_internet_udp_HandleIncomingPacket_Request_0_1 data;

  static constexpr CanardPortID       PORT_ID          = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_internet_udp_HandleIncomingPacket_Request_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND    = CanardTransferKindMessage;

  Request()
  {
    uavcan_internet_udp_HandleIncomingPacket_Request_0_1_initialize_(&data);
  }

  Request(Request const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static Request deserialize(CanardTransfer const & transfer)
  {
    Request<ID> i;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    uavcan_internet_udp_HandleIncomingPacket_Request_0_1_deserialize_(&i.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return i;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = Request<ID>::MAX_PAYLOAD_SIZE;
    return (uavcan_internet_udp_HandleIncomingPacket_Request_0_1_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

template <CanardPortID ID = uavcan_internet_udp_HandleIncomingPacket_0_1_FIXED_PORT_ID_>
class Response
{

public:

  uavcan_internet_udp_HandleIncomingPacket_Response_0_1 data;

  static constexpr CanardPortID       PORT_ID          = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_internet_udp_HandleIncomingPacket_Response_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND    = CanardTransferKindMessage;

  Response()
  {
    uavcan_internet_udp_HandleIncomingPacket_Response_0_1_initialize_(&data);
  }

  Response(Response const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static Response deserialize(CanardTransfer const & transfer)
  {
    Response<ID> i;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    uavcan_internet_udp_HandleIncomingPacket_Response_0_1_deserialize_(&i.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return i;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = Response<ID>::MAX_PAYLOAD_SIZE;
    return (uavcan_internet_udp_HandleIncomingPacket_Response_0_1_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* HandleIncomingPacket_0_1 */
} /* udp */
} /* internet */
} /* uavcan */

#endif /* ARDUINO_UAVCAN_TYPES_UAVCAN_INTERNET_UDP_HANDLEINCOMINGPACKET_0_1_HPP_ */
