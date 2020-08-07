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

#include <stdlib.h>

#include <libcanard/canard.h>

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID>
class Version_1_0
{

public:

  static constexpr CanardPortID       PORT_ID = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = 2;
  static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindMessage;


  Version_1_0(uint8_t const major, uint8_t const minor);

  static Version_1_0 create(CanardTransfer const & transfer);


  size_t encode(uint8_t * payload) const;


  inline uint8_t get_major() const { return _major; }
  inline uint8_t get_minor() const { return _minor; }

  inline void    set_major(uint8_t const major) { _major = major; }
  inline void    set_minor(uint8_t const minor) { _minor = minor; }


private:

  uint8_t _major, _minor;

};

/**************************************************************************************
 * TEMPLATE SOURCE FILE
 **************************************************************************************/

#include "Version.1.0.ipp"

#endif /* ARDUINO_UAVCAN_TYPES_UAVCAN_NODE_VERSION_1_0_HPP_ */
