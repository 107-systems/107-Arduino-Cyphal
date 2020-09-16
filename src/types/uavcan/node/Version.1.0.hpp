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

#include "Version.1.0.nnvg.h"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID>
class Version_1_0
{

public:

  uavcan_node_Version_1_0 data;

  static constexpr CanardPortID       PORT_ID = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_node_Version_1_0_MAX_SERIALIZED_REPRESENTATION_SIZE_BYTES;
  static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindMessage;

  Version_1_0();
  Version_1_0(Version_1_0 const & other);

  static Version_1_0 create(CanardTransfer const & transfer);
  size_t encode(uint8_t * payload) const;

};

/**************************************************************************************
 * TEMPLATE SOURCE FILE
 **************************************************************************************/

#include "Version.1.0.ipp"

#endif /* ARDUINO_UAVCAN_TYPES_UAVCAN_NODE_VERSION_1_0_HPP_ */
