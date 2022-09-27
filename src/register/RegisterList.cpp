/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */


/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "RegisterList.h"

#include <algorithm>

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

RegisterList::RegisterList()
: _reg_last{"", Register::TypeTag::Empty}
{ }

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

void RegisterList::subscribe(Node & node_hdl)
{
  node_hdl.subscribe<uavcan::_register::List_1_0::Request<>>
    ([this](CanardRxTransfer const & transfer, Node & node_hdl) { this->onList_1_0_Request_Received(transfer, node_hdl); });
  node_hdl.subscribe<uavcan::_register::Access_1_0::Request<>>
    ([this](CanardRxTransfer const & transfer, Node & node_hdl) { this->onAccess_1_0_Request_Received(transfer, node_hdl); });
}

/**************************************************************************************
 * PRIVATE MEMBER FUNCTIONS
 **************************************************************************************/

void RegisterList::onList_1_0_Request_Received(CanardRxTransfer const & transfer, Node & node_hdl)
{
  uavcan::_register::List_1_0::Request<>  const req = uavcan::_register::List_1_0::Request<>::deserialize(transfer);
  uavcan::_register::List_1_0::Response<> const rsp =
    (req.data.index < _reg_list.size()) ? toListResponse(_reg_list[req.data.index]->name()) : toListResponse(_reg_last.name());
  node_hdl.respond(rsp, transfer.metadata.remote_node_id, transfer.metadata.transfer_id);
}

void RegisterList::onAccess_1_0_Request_Received(CanardRxTransfer const & transfer, Node & node_hdl)
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
    Register::TypeTag const type_tag = (*iter)->type_tag();

    if (type_tag == Register::TypeTag::String)
    {
      RegisterString * reg_ptr = reinterpret_cast<RegisterString *>(*iter);
      if(uavcan_register_Value_1_0_is_string_(&req.data.value))
        reg_ptr->set(req.data.value);
      rsp = reg_ptr->toAccessResponse();
    }
    else if (type_tag == Register::TypeTag::Bit)
    {
      RegisterBit * reg_ptr = reinterpret_cast<RegisterBit *>(*iter);
      if(uavcan_register_Value_1_0_is_bit_(&req.data.value))
        reg_ptr->set(req.data.value);
      rsp = reg_ptr->toAccessResponse();
    }
    else if (type_tag == Register::TypeTag::Integer8)
    {
      RegisterInteger8 * reg_ptr = reinterpret_cast<RegisterInteger8 *>(*iter);
      if(uavcan_register_Value_1_0_is_integer8_(&req.data.value))
        reg_ptr->set(req.data.value);
      rsp = reg_ptr->toAccessResponse();
    }
    else if (type_tag == Register::TypeTag::Integer16)
    {
      RegisterInteger16 * reg_ptr = reinterpret_cast<RegisterInteger16 *>(*iter);
      if(uavcan_register_Value_1_0_is_integer16_(&req.data.value))
        reg_ptr->set(req.data.value);
      rsp = reg_ptr->toAccessResponse();
    }
    else if (type_tag == Register::TypeTag::Integer32)
    {
      RegisterInteger32 * reg_ptr = reinterpret_cast<RegisterInteger32 *>(*iter);
      if(uavcan_register_Value_1_0_is_integer32_(&req.data.value))
        reg_ptr->set(req.data.value);
      rsp = reg_ptr->toAccessResponse();
    }
    else if (type_tag == Register::TypeTag::Integer64)
    {
      RegisterInteger64 * reg_ptr = reinterpret_cast<RegisterInteger64 *>(*iter);
      if(uavcan_register_Value_1_0_is_integer64_(&req.data.value))
        reg_ptr->set(req.data.value);
      rsp = reg_ptr->toAccessResponse();
    }
    else if (type_tag == Register::TypeTag::Natural8)
    {
      RegisterNatural8 * reg_ptr = reinterpret_cast<RegisterNatural8 *>(*iter);
      if(uavcan_register_Value_1_0_is_natural8_(&req.data.value))
        reg_ptr->set(req.data.value);
      rsp = reg_ptr->toAccessResponse();
    }
    else if (type_tag == Register::TypeTag::Natural16)
    {
      RegisterNatural16 * reg_ptr = reinterpret_cast<RegisterNatural16 *>(*iter);
      if(uavcan_register_Value_1_0_is_natural16_(&req.data.value))
        reg_ptr->set(req.data.value);
      rsp = reg_ptr->toAccessResponse();
    }
    else if (type_tag == Register::TypeTag::Natural32)
    {
      RegisterNatural32 * reg_ptr = reinterpret_cast<RegisterNatural32 *>(*iter);
      if(uavcan_register_Value_1_0_is_natural32_(&req.data.value))
        reg_ptr->set(req.data.value);
      rsp = reg_ptr->toAccessResponse();
    }
    else if (type_tag == Register::TypeTag::Natural64)
    {
      RegisterNatural64 * reg_ptr = reinterpret_cast<RegisterNatural64 *>(*iter);
      if(uavcan_register_Value_1_0_is_natural64_(&req.data.value))
        reg_ptr->set(req.data.value);
      rsp = reg_ptr->toAccessResponse();
    }
    else if (type_tag == Register::TypeTag::Real32)
    {
      RegisterReal32 * reg_ptr = reinterpret_cast<RegisterReal32 *>(*iter);
      if(uavcan_register_Value_1_0_is_real32_(&req.data.value))
        reg_ptr->set(req.data.value);
      rsp = reg_ptr->toAccessResponse();
    }
    else if (type_tag == Register::TypeTag::Real64)
    {
      RegisterReal64 * reg_ptr = reinterpret_cast<RegisterReal64 *>(*iter);
      if(uavcan_register_Value_1_0_is_real64_(&req.data.value))
        reg_ptr->set(req.data.value);
      rsp = reg_ptr->toAccessResponse();
    }
    /* TODO: Do for other types ... Real16  */
  }

  /* Send the actual response. */
  node_hdl.respond(rsp, transfer.metadata.remote_node_id, transfer.metadata.transfer_id);
}

uavcan::_register::List_1_0::Response<> RegisterList::toListResponse(uavcan_register_Name_1_0 const & name)
{
  uavcan::_register::List_1_0::Response<> rsp;
  memcpy(&rsp.data.name.name.elements, name.name.elements, name.name.count);
  rsp.data.name.name.count = name.name.count;
  return rsp;
}