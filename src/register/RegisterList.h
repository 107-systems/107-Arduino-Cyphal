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
  RegisterList()
  : _reg_last{"", 0}
  { }

  void subscribe(Node & node_hdl)
  {
    node_hdl.subscribe<uavcan::_register::List_1_0::Request<>>
      ([this](CanardRxTransfer const & transfer, Node & node_hdl) { this->onList_1_0_Request_Received(transfer, node_hdl); });
    node_hdl.subscribe<uavcan::_register::Access_1_0::Request<>>
      ([this](CanardRxTransfer const & transfer, Node & node_hdl) { this->onAccess_1_0_Request_Received(transfer, node_hdl); });
  }

  void add(RegisterBase * reg_ptr)
  {
    _reg_list.push_back(reg_ptr);
  }


private:
  std::vector<RegisterBase *> _reg_list;
  RegisterBase const _reg_last;


  void onList_1_0_Request_Received(CanardRxTransfer const & transfer, Node & node_hdl)
  {
    uavcan::_register::List_1_0::Request<>  const req = uavcan::_register::List_1_0::Request<>::deserialize(transfer);
    uavcan::_register::List_1_0::Response<> const rsp =
      (req.data.index < _reg_list.size()) ? _reg_list[req.data.index]->toListResponse() : _reg_last.toListResponse();
    node_hdl.respond(rsp, transfer.metadata.remote_node_id, transfer.metadata.transfer_id);
  }

  void onAccess_1_0_Request_Received(CanardRxTransfer const & transfer, Node & node_hdl)
  {
    uavcan::_register::Access_1_0::Request<> const req = uavcan::_register::Access_1_0::Request<>::deserialize(transfer);

    /* Initialise with an empty response in case we
     * can't find a matching register.
     */
    uavcan::_register::Access_1_0::Response<> rsp = []()
    {
      uavcan::_register::Access_1_0::Response<> r;

      uavcan_register_Value_1_0_select_empty_(&r.data.value);
      r.data.timestamp.microsecond = 0;
      r.data._mutable = false;
      r.data.persistent = false;

      return r;
    } ();

    /* Find a register with the same register name within
     * the register list.
     */
    auto iter = std::find_if(std::begin(_reg_list),
                             std::end  (_reg_list),
                             [req](RegisterBase * reg_ptr)
                             {
                                return ((*reg_ptr) == req.data.name);
                             });

    if (iter != std::end(_reg_list))
    {
      /* Perform a write operation if the value sent in
       * the request is not empty.
       */
      Serial.print("tag = ");
      Serial.println(req.data.value._tag_);

      uint8_t const type_tag = (*iter)->type_tag();

      if (type_tag == 0)
      {
        RegisterDerived<uint8_t> * reg_ptr = reinterpret_cast<RegisterDerived<uint8_t> *>(*iter);
        if(uavcan_register_Value_1_0_is_natural8_(&req.data.value))
          reg_ptr->set(req.data.value);
        rsp = reg_ptr->toAccessResponse();
      }
      if (type_tag == 1)
      {
        RegisterDerived<std::string> * reg_ptr = reinterpret_cast<RegisterDerived<std::string> *>(*iter);
        if(uavcan_register_Value_1_0_is_string_(&req.data.value))
          reg_ptr->set(req.data.value);
        rsp = reg_ptr->toAccessResponse();
      }
      if (type_tag == 2)
      {
        RegisterDerived<uint16_t> * reg_ptr = reinterpret_cast<RegisterDerived<uint16_t> *>(*iter);
        if(uavcan_register_Value_1_0_is_natural16_(&req.data.value))
          reg_ptr->set(req.data.value);
        rsp = reg_ptr->toAccessResponse();
      }
      /* TODO: Do for other types ... */
    }

    /* Send the actual response. */
    node_hdl.respond(rsp, transfer.metadata.remote_node_id, transfer.metadata.transfer_id);
  }

};

#endif /* REGISTER_LIST_H_ */
