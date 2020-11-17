/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_UAVCAN_TYPES_UAVCAN_NODE_ID_1_0_HPP_
#define ARDUINO_UAVCAN_TYPES_UAVCAN_NODE_ID_1_0_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include "ID.1.0.nnvg.h"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID>
class ID_1_0
{

public:

  uavcan_node_ID_1_0 data;

  static constexpr CanardPortID       PORT_ID = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_node_ID_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindMessage;

  ID_1_0();
  ID_1_0(ID_1_0 const & other);

  static ID_1_0 deserialize(CanardTransfer const & transfer);
  size_t encode(uint8_t * payload) const;

};

/**************************************************************************************
 * TEMPLATE SOURCE FILE
 **************************************************************************************/

#include "ID.1.0.ipp"

#endif /* ARDUINO_UAVCAN_TYPES_UAVCAN_NODE_ID_1_0_HPP_ */
