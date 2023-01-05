/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef REGISTER_LIST_H_
#define REGISTER_LIST_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <map>
#include <vector>

#include "Node.hpp"
#include "RegisterDerived.hpp"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class RegisterList
{
public:
  RegisterList(Node & node_hdl);


  template <typename T> inline void add(RegisterDerived<T> & reg_ptr) {
    _reg_list.push_back(reinterpret_cast<RegisterBase *>(&reg_ptr));
  }


private:
  std::vector<RegisterBase *> _reg_list;
  RegisterBase const _reg_last;
  typedef std::function<uavcan::_register::Access_1_0::Response<>(uavcan::_register::Access_1_0::Request<> const &, RegisterBase *)> OnAccessRequestHandlerFunc;
  std::map<Register::TypeTag, OnAccessRequestHandlerFunc> _on_access_request_handler_map;

  typedef uavcan::_register::List_1_0::Request<>  TListRequest;
  typedef uavcan::_register::List_1_0::Response<> TListResponse;
  Service _reg_list_srv;
  TListResponse onList_1_0_Request_Received(TListRequest const & req);

  typedef uavcan::_register::Access_1_0::Request<>  TAccessRequest;
  typedef uavcan::_register::Access_1_0::Response<> TAccessResponse;
  Service _reg_access_srv;
  TAccessResponse onAccess_1_0_Request_Received(TAccessRequest const & req);
};

#endif /* REGISTER_LIST_H_ */
