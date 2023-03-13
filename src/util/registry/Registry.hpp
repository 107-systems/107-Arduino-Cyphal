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

#include "../vla/vla.h"
#include "../../Node.hpp"
#include "../../DSDL_Types.h"

#include "registry_impl.hpp"

#if __GNUC__ >= 11

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class Registry final : public registry::Registry
{
public:
  typedef std::function<uint64_t(void)> MicrosFunc;
  Registry(Node & node_hdl, MicrosFunc const micros)
  : _micros{micros}
  {
    _reg_list_srv = node_hdl.create_service_server<TListRequest, TListResponse>(
      TListRequest::_traits_::FixedPortId,
      2*1000*1000UL,
      [this](TListRequest const & req)
      {
        return onList_1_0_Request_Received(req);
      });

    _reg_access_srv = node_hdl.create_service_server<TAccessRequest, TAccessResponse>(
      TAccessRequest::_traits_::FixedPortId,
      2*1000*1000UL,
      [this](TAccessRequest const & req)
      {
        return onAccess_1_0_Request_Received(req);
      });
  }

private:
  MicrosFunc const _micros;

  typedef uavcan::_register::List::Request_1_0  TListRequest;
  typedef uavcan::_register::List::Response_1_0 TListResponse;
  ServiceServer _reg_list_srv;

  TListResponse onList_1_0_Request_Received(TListRequest const & req)
  {
    TListResponse rsp{};

    if (req.index < size())
    {
      auto const name = index(req.index);
      std::copy(name.name.cbegin(), name.name.cend(), std::back_inserter(rsp.name.name));
    }

    return rsp;
  }

  typedef uavcan::_register::Access::Request_1_0  TAccessRequest;
  typedef uavcan::_register::Access::Response_1_0 TAccessResponse;
  ServiceServer _reg_access_srv;

  TAccessResponse onAccess_1_0_Request_Received(TAccessRequest const & req)
  {
    if (!get(vla::toStr(req.name)))
      return TAccessResponse{};

    return TAccessResponse{}; // TODO: FIXME: This is just to quell Werror=return-type .
  }
};

#endif /* __GNUC__ >= 11 */

#endif /* REGISTER_LIST_H_ */
