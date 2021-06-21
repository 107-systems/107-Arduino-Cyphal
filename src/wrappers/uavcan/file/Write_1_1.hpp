/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_UAVCAN_TYPES_UAVCAN_FILE_WRITE_1_1_HPP_
#define ARDUINO_UAVCAN_TYPES_UAVCAN_FILE_WRITE_1_1_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include <types/uavcan/file/Write_1_1.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace uavcan {
namespace file {
namespace Write_1_1 {

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID = uavcan_file_Write_1_1_FIXED_PORT_ID_>
class Request
{

public:

  uavcan_file_Write_Request_1_1 data;

  static constexpr CanardPortID       PORT_ID          = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_file_Write_Request_1_1_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND    = CanardTransferKindMessage;

  Request()
  {
    uavcan_file_Write_Request_1_1_initialize_(&data);
  }

  Request(Request const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static Request deserialize(CanardTransfer const & transfer)
  {
    Request<ID> i;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    uavcan_file_Write_Request_1_1_deserialize_(&i.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return i;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = Request<ID>::MAX_PAYLOAD_SIZE;
    return (uavcan_file_Write_Request_1_1_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

template <CanardPortID ID = uavcan_file_Write_1_1_FIXED_PORT_ID_>
class Response
{

public:

  uavcan_file_Write_Response_1_1 data;

  static constexpr CanardPortID       PORT_ID          = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_file_Write_Response_1_1_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND    = CanardTransferKindMessage;

  Response()
  {
    uavcan_file_Write_Response_1_1_initialize_(&data);
  }

  Response(Response const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static Response deserialize(CanardTransfer const & transfer)
  {
    Response<ID> i;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    uavcan_file_Write_Response_1_1_deserialize_(&i.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return i;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = Response<ID>::MAX_PAYLOAD_SIZE;
    return (uavcan_file_Write_Response_1_1_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* Write_1_1 */
} /* file */
} /* uavcan */

#endif /* ARDUINO_UAVCAN_TYPES_UAVCAN_FILE_WRITE_1_1_HPP_ */
