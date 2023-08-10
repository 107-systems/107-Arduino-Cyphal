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

#include "ServiceServerBase.hpp"

#include "Node.hpp"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace cyphal
{

namespace impl
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template<typename T_REQ, typename T_RSP, typename OnRequestCb>
class ServiceServer final : public ServiceServerBase
{
public:
  ServiceServer(Node & node_hdl, CanardPortID const request_port_id, CanardMicrosecond const tx_timeout_usec, OnRequestCb on_request_cb)
  : _node_hdl{node_hdl}
  , _request_port_id{request_port_id}
  , _tx_timeout_usec{tx_timeout_usec}
  , _on_request_cb{on_request_cb}
  { }
  virtual ~ServiceServer();


  bool onTransferReceived(CanardRxTransfer const & transfer) override;


private:
  Node & _node_hdl;
  CanardPortID const _request_port_id;
  CanardMicrosecond const _tx_timeout_usec;
  OnRequestCb _on_request_cb;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */
} /* cyphal */

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "ServiceServer.ipp"
