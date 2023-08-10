/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#pragma once

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <cstdlib>

#include "libcanard/canard.h"

#include <array>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace cyphal
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template<size_t MTU_BYTES>
class CanRxQueueItem
{
  static_assert((MTU_BYTES
  == CANARD_MTU_CAN_CLASSIC) || (MTU_BYTES == CANARD_MTU_CAN_FD),
  "CanRxQueueItem can only have an MTU size of either 8 (CANARD_MTU_CAN_CLASSIC) or 64 (CANARD_MTU_CAN_FD).");
public:
  CanRxQueueItem()
    : _extended_can_id{0}, _payload_size{0}, _payload_buf{}, _rx_timestamp_usec{0}
  {}

  CanRxQueueItem(CanardFrame const *const frame, CanardMicrosecond const rx_timestamp_usec)
    : _extended_can_id{frame->extended_can_id}, _payload_size{frame->payload_size},
      _payload_buf{fromCanardFrame(frame)}, _rx_timestamp_usec{rx_timestamp_usec}
  {}


  [[nodiscard]] uint32_t extended_can_id() const
  { return _extended_can_id; }

  [[nodiscard]] size_t payload_size() const
  { return _payload_size; }

  [[nodiscard]] std::array <uint8_t, MTU_BYTES> const &payload_buf() const
  { return _payload_buf; }

  [[nodiscard]] CanardMicrosecond rx_timestamp_usec() const
  { return _rx_timestamp_usec; }


private:
  uint32_t _extended_can_id;
  size_t _payload_size;
  std::array <uint8_t, MTU_BYTES> _payload_buf;
  CanardMicrosecond _rx_timestamp_usec;

  static std::array <uint8_t, MTU_BYTES> fromCanardFrame(CanardFrame const *const frame)
  {
    std::array <uint8_t, MTU_BYTES> payload_buf{};
    std::copy(static_cast<uint8_t const *>(frame->payload),
              static_cast<uint8_t const *>(frame->payload) + std::min(frame->payload_size, MTU_BYTES),
              payload_buf.begin());
    return payload_buf;
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* cyphal */
