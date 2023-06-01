/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef INC_107_ARDUINO_CYPHAL_SUBSCRIPTION_HPP
#define INC_107_ARDUINO_CYPHAL_SUBSCRIPTION_HPP

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "SubscriptionBase.h"

#include "Node.hpp"
#include "util/transfer_metadata.hpp"


/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace impl
{

// #if LIBCANARD
// #define CanardNodeID CyphalNodeID;
// #elif LIBUDPARD
// #define UdpardNodeID CyphalNodeID;
// #else
// # error "We only support CAN or UDP as Cyphal transport layer"
// #endif


/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <typename T>

class Subscription final : public SubscriptionBase
{

public:
  using OnReceiveCallback_Default= std::function<void(T const &)>;
  using OnReceiveCallback_Ext = std::function<void(T const &, TransferMetadata const &)>;
  Subscription(Node & node_hdl, CanardPortID const port_id, OnReceiveCallback_Default const & on_receive_cb)
  : SubscriptionBase{CanardTransferKindMessage}
  , _node_hdl{node_hdl}
  , _port_id{port_id}
  , _on_receive_cb{on_receive_cb}
  { }

  Subscription(Node & node_hdl, CanardPortID const port_id, OnReceiveCallback_Ext const & on_receive_cb_ext)
  : SubscriptionBase{CanardTransferKindMessage}
  , _node_hdl{node_hdl}
  , _port_id{port_id}
  , _on_receive_cb_ext{on_receive_cb_ext}
  {
    return_metadata = true;
   }
  virtual ~Subscription();


  bool onTransferReceived(CanardRxTransfer const & transfer) override;


private:
  Node & _node_hdl;
  CanardPortID const _port_id;
  OnReceiveCallback_Default _on_receive_cb;
  OnReceiveCallback_Ext _on_receive_cb_ext;
  bool return_metadata = false;

  TransferMetadata fillMetadata(CanardRxTransfer const & transfer);
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "Subscription.ipp"

#endif /* INC_107_ARDUINO_CYPHAL_SUBSCRIPTION_HPP */
