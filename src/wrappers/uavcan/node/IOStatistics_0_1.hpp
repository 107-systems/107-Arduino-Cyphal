/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_TRANSFER_UAVCAN_NODE_IOSTATISTICS_0_1_HPP_
#define ARDUINO_TRANSFER_UAVCAN_NODE_IOSTATISTICS_0_1_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include <types/uavcan/node/IOStatistics_0_1.h>

#include <utility/convert.hpp>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace uavcan {
namespace node {

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID>
class IOStatistics_0_1
{

public:

  uavcan_node_IOStatistics_0_1 data;

  static constexpr CanardPortID       PORT_ID = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_node_IOStatistics_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindMessage;

  IOStatistics_0_1()
  {
    uavcan_node_IOStatistics_0_1_initialize_(&data);
  }

  IOStatistics_0_1(IOStatistics_0_1 const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static IOStatistics_0_1 deserialize(CanardTransfer const & transfer)
  {
    IOStatistics_0_1 h;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    uavcan_node_IOStatistics_0_1_deserialize_(&h.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return h;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = IOStatistics_0_1::MAX_PAYLOAD_SIZE;
    return (uavcan_node_IOStatistics_0_1_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* uavcan */
} /* node */

#endif /* ARDUINO_TRANSFER_UAVCAN_NODE_IOSTATISTICS_0_1_HPP_ */
