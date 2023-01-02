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
 * FORWARD DECLARATION
 **************************************************************************************/

class Node;

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

template <typename T, typename OnReceiveCb>
class Subscription : public SubscriptionBase
{
public:
  Subscription(Node & node_hdl, CanardPortID const port_id, OnReceiveCb const & on_receive_cb)
  : SubscriptionBase{}
  , _node_hdl{node_hdl}
  , _port_id{port_id}
  , _on_receive_cb{on_receive_cb}
  { }
  virtual ~Subscription();

  virtual void onTransferReceived(CanardRxTransfer const & transfer) override;


  CanardRxSubscription & canard_rx_subscription() { return _canard_rx_sub; }


private:
  Node & _node_hdl;
  CanardPortID const _port_id;
  CanardRxSubscription _canard_rx_sub;
  OnReceiveCb _on_receive_cb;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

template <typename T, typename OnReceiveCb>
using Subscription = std::shared_ptr<impl::Subscription<T, OnReceiveCb>>;

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "Subscription.ipp"

#endif /* INC_107_ARDUINO_CYPHAL_SUBSCRIPTION_HPP */
