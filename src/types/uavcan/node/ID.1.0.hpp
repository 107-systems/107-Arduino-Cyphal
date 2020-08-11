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

#include <stdlib.h>

#include <libcanard/canard.h>

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID>
class ID_1_0
{

public:

  static constexpr CanardPortID       PORT_ID = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = 2;
  static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindMessage;


  ID_1_0(uint16_t const id);


  static ID_1_0 create(CanardTransfer const & transfer);
         size_t encode(uint8_t * payload) const;


  inline uint16_t get_id()                  const { return _id; }
  inline void     set_id(uint16_t const id)       { _id = id; }


private:

  uint16_t _id;

};

/**************************************************************************************
 * TEMPLATE SOURCE FILE
 **************************************************************************************/

#include "ID.1.0.ipp"

#endif /* ARDUINO_UAVCAN_TYPES_UAVCAN_NODE_ID_1_0_HPP_ */
