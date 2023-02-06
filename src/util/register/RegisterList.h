/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef REGISTER_LIST_H_
#define REGISTER_LIST_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <vector>
#include <functional>

#include "RegisterDerived.hpp"

#include "../../Node.hpp"
#include "../../DSDL_Types.h"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class RegisterList
{
public:
  RegisterList(Node & node_hdl, Register::MicrosFunc const micros)
  : _micros{micros}
  {
    _reg_list_srv = node_hdl.create_service_server<TListRequest, TListResponse>(
      TListRequest::FixedPortId,
      2*1000*1000UL,
      [this](TListRequest const & req)
      {
        return onList_1_0_Request_Received(req);
      });

    _reg_access_srv = node_hdl.create_service_server<TAccessRequest, TAccessResponse>(
      TAccessRequest::FixedPortId,
      2*1000*1000UL,
      [this](TAccessRequest const & req)
      {
        return onAccess_1_0_Request_Received(req);
      });
  }

  template <typename T, Register::Mutable IsMutable, Register::Persistent IsPersistent>
  std::shared_ptr<impl::RegisterDerived<T, IsMutable, IsPersistent>> create(std::string const &name, T const & val);

private:
  Register::MicrosFunc const _micros;
  std::vector<std::shared_ptr<impl::RegisterBase>> _reg_list;

  typedef uavcan::_register::List::Request_1_0  TListRequest;
  typedef uavcan::_register::List::Response_1_0 TListResponse;
  ServiceServer _reg_list_srv;

  TListResponse onList_1_0_Request_Received(TListRequest const & req)
  {
    TListResponse rsp{};

    if (req.index < _reg_list.size())
      std::copy(_reg_list[req.index]->name().name.cbegin(),
                _reg_list[req.index]->name().name.cend(),
                std::back_inserter(rsp.name.name));

    return rsp;
  }

  typedef uavcan::_register::Access::Request_1_0  TAccessRequest;
  typedef uavcan::_register::Access::Response_1_0 TAccessResponse;
  ServiceServer _reg_access_srv;

  TAccessResponse onAccess_1_0_Request_Received(TAccessRequest const & req)
  {
    /* TODO */
    return {};
  }
};

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "RegisterList.ipp"

#endif /* REGISTER_LIST_H_ */
