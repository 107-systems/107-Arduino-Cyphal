/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 generationmake.
 * Author: Bernhard Mayer
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_TRANSFER_UAVCAN_NODE_BIT_1_0_H_
#define ARDUINO_TRANSFER_UAVCAN_NODE_BIT_1_0_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>
#include "Heartbeat.1.0.nnvg.h"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class Bit_1_0
{

public:

  bool data;

  static constexpr CanardPortID       PORT_ID = 1620U;
  static constexpr size_t             MAX_PAYLOAD_SIZE = 1UL;
  static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindMessage;

  Bit_1_0();
  Bit_1_0(Bit_1_0 const & other);

  static Bit_1_0 deserialize(CanardTransfer const & transfer);
  size_t serialize(uint8_t * payload) const;
};

#endif /* ARDUINO_TRANSFER_UAVCAN_NODE_BIT_1_0_H_ */
