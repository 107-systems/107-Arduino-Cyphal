/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Bernhard Mayer <bernard@generationmake.de>, Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_UAVCAN_TYPES_UAVCAN_PNP_NODEIDALLOCATIONDATA_1_0_HPP_
#define ARDUINO_UAVCAN_TYPES_UAVCAN_PNP_NODEIDALLOCATIONDATA_1_0_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include <types/uavcan/pnp/NodeIDAllocationData_1_0.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace uavcan {
namespace pnp {

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID = uavcan_pnp_NodeIDAllocationData_1_0_FIXED_PORT_ID_>
class NodeIDAllocationData_1_0
{

public:

  uavcan_pnp_NodeIDAllocationData_1_0 data;

  static constexpr CanardPortID       PORT_ID          = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_pnp_NodeIDAllocationData_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND    = CanardTransferKindMessage;

  NodeIDAllocationData_1_0()
  {
    uavcan_pnp_NodeIDAllocationData_1_0_initialize_(&data);
  }

  NodeIDAllocationData_1_0(NodeIDAllocationData_1_0 const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static NodeIDAllocationData_1_0 deserialize(CanardTransfer const & transfer)
  {
    NodeIDAllocationData_1_0<ID> b;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    uavcan_pnp_NodeIDAllocationData_1_0_deserialize_(&b.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return b;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = NodeIDAllocationData_1_0::MAX_PAYLOAD_SIZE;
    return (uavcan_pnp_NodeIDAllocationData_1_0_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* pnp */
} /* uavcan */

#endif /* ARDUINO_UAVCAN_TYPES_UAVCAN_PNP_NODEIDALLOCATIONDATA_1_0_HPP_ */
