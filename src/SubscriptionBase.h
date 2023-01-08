/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef INC_107_ARDUINO_CYPHAL_CANARDSUBSCRIPTION_H
#define INC_107_ARDUINO_CYPHAL_CANARDSUBSCRIPTION_H

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "libcanard/canard.h"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace impl
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class SubscriptionBase
{
public:
  SubscriptionBase(CanardTransferKind const transfer_kind)
  : _transfer_kind{transfer_kind}
  {
    _canard_rx_sub.user_reference = static_cast<void *>(this);
  }
  virtual ~SubscriptionBase() { }
  SubscriptionBase(SubscriptionBase const &) = delete;
  SubscriptionBase(SubscriptionBase &&) = delete;
  SubscriptionBase &operator=(SubscriptionBase const &) = delete;
  SubscriptionBase &operator=(SubscriptionBase &&) = delete;


  virtual bool onTransferReceived(CanardRxTransfer const & transfer) = 0;


  [[nodiscard]] CanardTransferKind canard_transfer_kind() const { return _transfer_kind; }
  [[nodiscard]] CanardRxSubscription &canard_rx_subscription() { return _canard_rx_sub; }


private:
  CanardTransferKind const _transfer_kind;
  CanardRxSubscription _canard_rx_sub;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */

#endif /* INC_107_ARDUINO_CYPHAL_CANARDSUBSCRIPTION_H */
