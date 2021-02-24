/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_UAVCAN_TYPES_UAVCAN_NODE_VERSION_1_0_HPP_
#define ARDUINO_UAVCAN_TYPES_UAVCAN_NODE_VERSION_1_0_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include <types/uavcan/node/Version_1_0.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace uavcan {
namespace node {

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID>
class Version_1_0
{

public:

  uavcan_node_Version_1_0 data;

  static constexpr CanardPortID       PORT_ID = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_node_Version_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindMessage;

  Version_1_0()
  {
    uavcan_node_Version_1_0_initialize_(&data);
  }

  Version_1_0(Version_1_0 const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static Version_1_0 deserialize(CanardTransfer const & transfer)
  {
    Version_1_0<ID> v;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    uavcan_node_Version_1_0_deserialize_(&v.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return v;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = Version_1_0<ID>::MAX_PAYLOAD_SIZE;
    return (uavcan_node_Version_1_0_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* uavcan */
} /* node */

#endif /* ARDUINO_UAVCAN_TYPES_UAVCAN_NODE_VERSION_1_0_HPP_ */
