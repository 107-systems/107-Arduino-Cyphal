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
    auto const req_name = reinterpret_cast<const char *>(req.name.name.cbegin());
    /* Return an empty response, if the repository with the desired
     * name can not be found.
     */
    auto reg_with_metadata = get(std::string_view(req_name));
    if (!reg_with_metadata.has_value())
      return TAccessResponse{};

    /* Pepare the response for this access request. */
    TAccessResponse rsp
    {
      _micros(),
      reg_with_metadata.value().flags.mutable_,
      reg_with_metadata.value().flags.persistent,
      reg_with_metadata.value().value
    };

    /* Try to set the registers value. Note, if this is a RO register
     * this call will fail with SetError::Mutability.
     */
    if (!req.value.is_empty()) {
      if (set(req_name, req.value) == std::nullopt) {
        rsp.value = req.value;
      }
    }

    return rsp;
  }
};

#endif /* __GNUC__ >= 11 */

#endif /* REGISTER_LIST_H_ */
