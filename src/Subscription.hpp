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
  virtual ~SubscriptionBase() { }
  virtual void onTransferReceived(CanardRxTransfer const & transfer) = 0;
};

template <typename T>
class Subscription : public SubscriptionBase
{
public:
  Subscription(std::function<void(T const &)> on_receive_cb, std::function<void(void)> on_destruction_cb)
  : SubscriptionBase{}
  , _on_receive_cb{on_receive_cb}
  , _on_destruction_cb{on_destruction_cb}
  { }
  virtual ~Subscription();

  virtual void onTransferReceived(CanardRxTransfer const & transfer) override;


  inline CanardRxSubscription & canard_rx_subscription() { return _canard_rx_sub; }


private:
  CanardRxSubscription _canard_rx_sub;
  std::function<void(T const &)> _on_receive_cb;
  std::function<void(void)> _on_destruction_cb;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

template <typename T>
using Subscription = std::shared_ptr<impl::Subscription<T>>;

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "Subscription.ipp"

#endif /* INC_107_ARDUINO_CYPHAL_SUBSCRIPTION_HPP */
