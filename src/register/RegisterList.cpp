/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */


/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "RegisterList.h"

#include <algorithm>

#include "util/AccessRequest.hpp"
#include "util/AccessResponse.hpp"

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

RegisterList::RegisterList(Node & node_hdl)
: _reg_last{"", Register::TypeTag::Empty, false, false}
{
  _on_access_request_handler_map[Register::TypeTag::Empty] =
  [](uavcan::_register::Access::Request_1_0 const &, RegisterBase *)
  {
    return uavcan::_register::Access::Response_1_0{};
  };

  _on_access_request_handler_map[Register::TypeTag::String] =
  [](uavcan::_register::Access::Request_1_0 const & req, RegisterBase * reg_base_ptr)
  {
    RegisterString * reg_ptr = reinterpret_cast<RegisterString *>(reg_base_ptr);
    if(req.value.index() == uavcan::_register::Value_1_0::VariantType::IndexOf::empty)
      reg_ptr->onReadRequest();
    if(uavcan_register_Value_1_0_is_string_(&req.value) && reg_ptr->isMutable())
    {
      /* Limitation makes no sense for 'std::string' */
      reg_ptr->set(AccessRequest::toRegisterValue<std::string>(req.value));
      reg_ptr->onWriteRequest();
    }
    return AccessResponse::create(*reg_ptr);
  };

  _on_access_request_handler_map[Register::TypeTag::Bit] =
  [](uavcan::_register::Access::Request_1_0 const & req, RegisterBase * reg_base_ptr)
  {
    RegisterBit * reg_ptr = reinterpret_cast<RegisterBit *>(reg_base_ptr);
    if(req.value.index() == uavcan::_register::Value_1_0::VariantType::IndexOf::empty)
      reg_ptr->onReadRequest();
    if(uavcan_register_Value_1_0_is_bit_(&req.value) && reg_ptr->isMutable())
    {
      /* Limitation makes no sense for 'bool' */
      reg_ptr->set(AccessRequest::toRegisterValue<bool>(req.value));
      reg_ptr->onWriteRequest();
    }
    return AccessResponse::create(*reg_ptr);
  };

  _on_access_request_handler_map[Register::TypeTag::Integer8] =
  [](uavcan::_register::Access::Request_1_0 const & req, RegisterBase * reg_base_ptr)
  {
    RegisterInteger8 * reg_ptr = reinterpret_cast<RegisterInteger8 *>(reg_base_ptr);
    if(req.value.index() == uavcan::_register::Value_1_0::VariantType::IndexOf::empty)
      reg_ptr->onReadRequest();
    if(uavcan_register_Value_1_0_is_integer8_(&req.value) && reg_ptr->isMutable())
    {
      int8_t const reg_val = AccessRequest::toRegisterValue<int8_t>(req.value);
      int8_t const limited_reg_val = reg_ptr->limitValue(reg_val);
      reg_ptr->set(limited_reg_val);
      reg_ptr->onWriteRequest();
    }
    return AccessResponse::create(*reg_ptr);
  };

  _on_access_request_handler_map[Register::TypeTag::Integer16] =
  [](uavcan::_register::Access::Request_1_0 const & req, RegisterBase * reg_base_ptr)
  {
    RegisterInteger16 * reg_ptr = reinterpret_cast<RegisterInteger16 *>(reg_base_ptr);
    if(req.value.index() == uavcan::_register::Value_1_0::VariantType::IndexOf::empty)
      reg_ptr->onReadRequest();
    if(uavcan_register_Value_1_0_is_integer16_(&req.value) && reg_ptr->isMutable())
    {
      int16_t const reg_val = AccessRequest::toRegisterValue<int16_t>(req.value);
      int16_t const limited_reg_val = reg_ptr->limitValue(reg_val);
      reg_ptr->set(limited_reg_val);
      reg_ptr->onWriteRequest();
    }
    return AccessResponse::create(*reg_ptr);
  };

  _on_access_request_handler_map[Register::TypeTag::Integer32] =
  [](uavcan::_register::Access::Request_1_0 const & req, RegisterBase * reg_base_ptr)
  {
    RegisterInteger32 * reg_ptr = reinterpret_cast<RegisterInteger32 *>(reg_base_ptr);
    if(req.value.index() == uavcan::_register::Value_1_0::VariantType::IndexOf::empty)
      reg_ptr->onReadRequest();
    if(uavcan_register_Value_1_0_is_integer32_(&req.value) && reg_ptr->isMutable())
    {
      int32_t const reg_val = AccessRequest::toRegisterValue<int32_t>(req.value);
      int32_t const limited_reg_val = reg_ptr->limitValue(reg_val);
      reg_ptr->set(limited_reg_val);
      reg_ptr->onWriteRequest();
    }
    return AccessResponse::create(*reg_ptr);
  };

  _on_access_request_handler_map[Register::TypeTag::Integer64] =
  [](uavcan::_register::Access::Request_1_0 const & req, RegisterBase * reg_base_ptr)
  {
    RegisterInteger64 * reg_ptr = reinterpret_cast<RegisterInteger64 *>(reg_base_ptr);
    if(req.value.index() == uavcan::_register::Value_1_0::VariantType::IndexOf::empty)
      reg_ptr->onReadRequest();
    if(uavcan_register_Value_1_0_is_integer64_(&req.value) && reg_ptr->isMutable())
    {
      int64_t const reg_val = AccessRequest::toRegisterValue<int64_t>(req.value);
      int64_t const limited_reg_val = reg_ptr->limitValue(reg_val);
      reg_ptr->set(limited_reg_val);
      reg_ptr->onWriteRequest();
    }
    return AccessResponse::create(*reg_ptr);
  };

  _on_access_request_handler_map[Register::TypeTag::Natural8] =
  [](uavcan::_register::Access::Request_1_0 const & req, RegisterBase * reg_base_ptr)
  {
    RegisterNatural8 * reg_ptr = reinterpret_cast<RegisterNatural8 *>(reg_base_ptr);
    if(req.value.index() == uavcan::_register::Value_1_0::VariantType::IndexOf::empty)
      reg_ptr->onReadRequest();
    if(uavcan_register_Value_1_0_is_natural8_(&req.value) && reg_ptr->isMutable())
    {
      uint8_t const reg_val = AccessRequest::toRegisterValue<uint8_t>(req.value);
      uint8_t const limited_reg_val = reg_ptr->limitValue(reg_val);
      reg_ptr->set(limited_reg_val);
      reg_ptr->onWriteRequest();
    }
    return AccessResponse::create(*reg_ptr);
  };

  _on_access_request_handler_map[Register::TypeTag::Natural16] =
  [](uavcan::_register::Access::Request_1_0 const & req, RegisterBase * reg_base_ptr)
  {
    RegisterNatural16 * reg_ptr = reinterpret_cast<RegisterNatural16 *>(reg_base_ptr);
    if(req.value.index() == uavcan::_register::Value_1_0::VariantType::IndexOf::empty)
      reg_ptr->onReadRequest();
    if(uavcan_register_Value_1_0_is_natural16_(&req.value) && reg_ptr->isMutable())
    {
      uint16_t const reg_val = AccessRequest::toRegisterValue<uint16_t>(req.value);
      uint16_t const limited_reg_val = reg_ptr->limitValue(reg_val);
      reg_ptr->set(limited_reg_val);
      reg_ptr->onWriteRequest();
    }
    return AccessResponse::create(*reg_ptr);
  };

  _on_access_request_handler_map[Register::TypeTag::Natural32] =
  [](uavcan::_register::Access::Request_1_0 const & req, RegisterBase * reg_base_ptr)
  {
    RegisterNatural32 * reg_ptr = reinterpret_cast<RegisterNatural32 *>(reg_base_ptr);
    if(req.value.index() == uavcan::_register::Value_1_0::VariantType::IndexOf::empty)
      reg_ptr->onReadRequest();
    if(uavcan_register_Value_1_0_is_natural32_(&req.value) && reg_ptr->isMutable())
    {
      uint32_t const reg_val = AccessRequest::toRegisterValue<uint32_t>(req.value);
      uint32_t const limited_reg_val = reg_ptr->limitValue(reg_val);
      reg_ptr->set(limited_reg_val);
      reg_ptr->onWriteRequest();
    }
    return AccessResponse::create(*reg_ptr);
  };

  _on_access_request_handler_map[Register::TypeTag::Natural64] =
  [](uavcan::_register::Access::Request_1_0 const & req, RegisterBase * reg_base_ptr)
  {
    RegisterNatural64 * reg_ptr = reinterpret_cast<RegisterNatural64 *>(reg_base_ptr);
    if(req.value.index() == uavcan::_register::Value_1_0::VariantType::IndexOf::empty)
      reg_ptr->onReadRequest();
    if(uavcan_register_Value_1_0_is_natural64_(&req.value) && reg_ptr->isMutable())
    {
      uint64_t const reg_val = AccessRequest::toRegisterValue<uint64_t>(req.value);
      uint64_t const limited_reg_val = reg_ptr->limitValue(reg_val);
      reg_ptr->set(limited_reg_val);
      reg_ptr->onWriteRequest();
    }
    return AccessResponse::create(*reg_ptr);
  };

  _on_access_request_handler_map[Register::TypeTag::Real32] =
  [](uavcan::_register::Access::Request_1_0 const & req, RegisterBase * reg_base_ptr)
  {
    RegisterReal32 * reg_ptr = reinterpret_cast<RegisterReal32 *>(reg_base_ptr);
    if(req.value.index() == uavcan::_register::Value_1_0::VariantType::IndexOf::empty)
      reg_ptr->onReadRequest();
    if(uavcan_register_Value_1_0_is_real32_(&req.value) && reg_ptr->isMutable())
    {
      float const reg_val = AccessRequest::toRegisterValue<float>(req.value);
      float const limited_reg_val = reg_ptr->limitValue(reg_val);
      reg_ptr->set(limited_reg_val);
      reg_ptr->onWriteRequest();
    }
    return AccessResponse::create(*reg_ptr);
  };

  _on_access_request_handler_map[Register::TypeTag::Real64] =
  [](uavcan::_register::Access::Request_1_0 const & req, RegisterBase * reg_base_ptr)
  {
    RegisterReal64 * reg_ptr = reinterpret_cast<RegisterReal64 *>(reg_base_ptr);
    if(req.value.index() == uavcan::_register::Value_1_0::VariantType::IndexOf::empty)
      reg_ptr->onReadRequest();
    if(uavcan_register_Value_1_0_is_real64_(&req.value) && reg_ptr->isMutable())
    {
      double const reg_val = AccessRequest::toRegisterValue<double>(req.value);
      double const limited_reg_val = reg_ptr->limitValue(reg_val);
      reg_ptr->set(limited_reg_val);
      reg_ptr->onWriteRequest();
    }
    return AccessResponse::create(*reg_ptr);
  };


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
      return onAccess_Request_Received(req);
    });
}

/**************************************************************************************
* PRIVATE MEMBER FUNCTIONS
**************************************************************************************/

RegisterList::TListResponse RegisterList::onList_1_0_Request_Received(TListRequest const & req)
{
  TListResponse const rsp =
    (req.index < _reg_list.size()) ? ListResponse::create(_reg_list[req.index]->name()) : ListResponse::create(_reg_last.name());
  return rsp;
}

RegisterList::TAccessResponse RegisterList::onAccess_Request_Received(TAccessRequest const & req)
{
  /* Find a register with the same register name within
   * the register list.
   */
  auto iter = std::find_if(std::begin(_reg_list),
                           std::end  (_reg_list),
                           [req](RegisterBase * reg_ptr)
                           {
                             if (reg_ptr->name().name.count != req.name.name.count)
                               return false;

                             return (strncmp(reinterpret_cast<const char *>(reg_ptr->name().name.elements),
                                     reinterpret_cast<const char *>(req.name.name.elements),
                                     reg_ptr->name().name.count) == 0);
                           });

  if (iter != std::end(_reg_list))
  {
    /* Store in separate variable for better clarity. */
    RegisterBase * reg_base_ptr = *iter;
    /* Determine the actual type of the register. */
    Register::TypeTag const type_tag = reg_base_ptr->type_tag();
    /* Call the appropriate callback handler. */
    auto const citer = _on_access_request_handler_map.find(type_tag);
    if (citer != std::end(_on_access_request_handler_map))
      citer->second(req, reg_base_ptr);
  }

  return {};
}
