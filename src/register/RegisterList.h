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
#include "RegisterBase.h"
#include "RegisterReadOnly.hpp"
#include "RegisterReadWrite.hpp"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class RegisterList
{
public:
  RegisterList()
  : _reg_last{"", RegisterBase::AccessType::ReadOnly}
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

    /* Find a register with the same register name within
     * the register list.
     */
    auto iter = std::find_if(std::begin(_reg_list),
                             std::end  (_reg_list),
                             [req](RegisterBase * reg_ptr)
                             {
                                return ((*reg_ptr) == req.data.name);
                             });

    uavcan::_register::Access_1_0::Response<> rsp;

    /* If not register can be found return
     * an empty response.
     */
    if (iter == std::end(_reg_list))
    {
      uavcan_register_Value_1_0_select_empty_(&rsp.data.value);
      rsp.data.timestamp.microsecond = micros();
      rsp.data._mutable = false;
      rsp.data.persistent = false;
      Serial.println("no find entry");

      node_hdl.respond(rsp, transfer.metadata.remote_node_id, transfer.metadata.transfer_id);
      return;
    }

    /* Retrieve the content of the iterator for better
     * understanding of the underlying code operation.
     */
    RegisterBase * reg_ptr = *iter;

    /* If its a RO register, directly form the response
     * and send it back.
     */
    if (reg_ptr->type() == RegisterBase::AccessType::ReadOnly)
    {
      Serial.println("RO");
    }

    /* Perform a write operation if the value sent in
     * the request is not empty.
     */
    if (reg_ptr->type() == RegisterBase::AccessType::ReadWrite)
    {
      Serial.println("RW");

      if(uavcan_register_Value_1_0_is_natural8_(&req.data.value))
      {
        Serial.println("RW uint8_t");
        RegisterReadWrite<uint8_t> * rw_reg_ptr = reinterpret_cast<RegisterReadWrite<uint8_t> *>(reg_ptr);
        rw_reg_ptr->set(req.data.value);
        rsp = rw_reg_ptr->toAccessResponse();
      }
      /* TODO: Implement for all the other types ... */ 
    }

    /* Send the actual response. */
    node_hdl.respond(rsp, transfer.metadata.remote_node_id, transfer.metadata.transfer_id);
  }

};

#endif /* REGISTER_LIST_H_ */