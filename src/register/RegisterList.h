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

#include <vector>

#include "Node.h"
#include "RegisterDerived.hpp"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class RegisterList
{
public:
  RegisterList();

  void subscribe(Node & node_hdl);

  template <typename T> inline void add(RegisterDerived<T> & reg_ptr) {
    _reg_list.push_back(reinterpret_cast<RegisterBase *>(&reg_ptr));
  }


private:
  std::vector<RegisterBase *> _reg_list;
  RegisterBase const _reg_last;

  void onList_1_0_Request_Received(CanardRxTransfer const & transfer, Node & node_hdl);
  void onAccess_1_0_Request_Received(CanardRxTransfer const & transfer, Node & node_hdl);
};

#endif /* REGISTER_LIST_H_ */
