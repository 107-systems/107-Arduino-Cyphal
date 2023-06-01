/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef ARDUINO_CYPHAL_TRANSFER_METADATA_HPP_
#define ARDUINO_CYPHAL_TRANSFER_METADATA_HPP_

#if defined __has_include
#  if __has_include (<libcanard/canard.h>)
  using CyphalNodeID = CanardNodeID;
#  elif __has_include (<lipudpard/udpard.h>)
  using CyphalNodeID = UdpardNodeID;
#  endif
#else
# error "We only support CAN or UDP as Cyphal transport layer"
#endif

struct TransferMetadata final
{
  CyphalNodeID node_id;
  // More stuff may appear here in the future!
};

#endif // ARDUINO_CYPHAL_TRANSFER_METADATA_HPP_
