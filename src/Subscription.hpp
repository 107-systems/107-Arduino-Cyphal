/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef INC_107_ARDUINO_CYPHAL_SUBSCRIPTION_HPP
#define INC_107_ARDUINO_CYPHAL_SUBSCRIPTION_HPP

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <memory>

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
           SubscriptionBase() { }
  virtual ~SubscriptionBase() { }
           SubscriptionBase(SubscriptionBase const &) = delete;
           SubscriptionBase(SubscriptionBase &&) = delete;

  SubscriptionBase & operator = (SubscriptionBase const &) = delete;
  SubscriptionBase & operator = (SubscriptionBase &&) = delete;

  virtual void onTransferReceived(CanardRxTransfer const & transfer) = 0;
};

template <typename T, typename OnReceiveCb, typename OnDestructionCb>
class Subscription : public SubscriptionBase
{
public:
  Subscription(OnReceiveCb const & on_receive_cb, OnDestructionCb const & on_destruction_cb)
  : SubscriptionBase{}
  , _on_receive_cb{on_receive_cb}
  , _on_destruction_cb{on_destruction_cb}
  { }
  virtual ~Subscription();

  virtual void onTransferReceived(CanardRxTransfer const & transfer) override;


  CanardRxSubscription & canard_rx_subscription() { return _canard_rx_sub; }


private:
  CanardRxSubscription _canard_rx_sub;
  OnReceiveCb _on_receive_cb;
  OnDestructionCb _on_destruction_cb;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

template <typename T>
using Subscription = std::shared_ptr<impl::Subscription<T, std::function<void(T const &)>, std::function<void(void)>>>;

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "Subscription.ipp"

#endif /* INC_107_ARDUINO_CYPHAL_SUBSCRIPTION_HPP */
