/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef INC_107_ARDUINO_CYPHAL_SERVICE_HPP
#define INC_107_ARDUINO_CYPHAL_SERVICE_HPP

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <memory>

#include "CanardSubscription.h"

#include "libcanard/canard.h"

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

class ServiceBase : public CanardSubscription
{
public:
  ServiceBase() : CanardSubscription{CanardTransferKindRequest} { }
};

template<typename T_REQ, typename T_RSP, typename OnRequestCb>
class Service : public ServiceBase
{
public:
  Service(Node & node_hdl, CanardPortID const port_id, CanardMicrosecond const tx_timeout_usec, OnRequestCb on_request_cb)
  : _node_hdl{node_hdl}
  , _port_id{port_id}
  , _tx_timeout_usec{tx_timeout_usec}
  , _on_request_cb{on_request_cb}
  { }
  virtual ~Service();


  virtual bool onTransferReceived(CanardRxTransfer const & transfer) override;


private:
  Node & _node_hdl;
  CanardPortID const _port_id;
  CanardMicrosecond const _tx_timeout_usec;
  OnRequestCb _on_request_cb;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

using Service = std::shared_ptr<impl::ServiceBase>;

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "Service.ipp"

#endif /* INC_107_ARDUINO_CYPHAL_SERVICE_HPP */
