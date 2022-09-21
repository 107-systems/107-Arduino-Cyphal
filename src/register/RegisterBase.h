/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef REGISTER_BASE_H_
#define REGISTER_BASE_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "../Types.h"

#include <algorithm>

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class RegisterBase
{
public:
  enum class AccessType
  {
    ReadWrite, ReadOnly
  };

  RegisterBase(char const * name, AccessType const access_type)
  : _access_type{access_type}
  {
    _name.name.count = std::min(strlen(name), uavcan_register_Name_1_0_name_ARRAY_CAPACITY_);
    memcpy(_name.name.elements, name, _name.name.count);
  }
  virtual ~RegisterBase() { }


  inline AccessType type() const { return _access_type; }

  uavcan::_register::List_1_0::Response<> toListResponse() const
  {
    uavcan::_register::List_1_0::Response<> rsp;
    memcpy(&rsp.data.name.name.elements, _name.name.elements, _name.name.count);
    rsp.data.name.name.count = _name.name.count;
    return rsp;
  }

  virtual uavcan::_register::Access_1_0::Response<> toAccessResponse()
  {
    uavcan::_register::Access_1_0::Response<> rsp;

    uavcan_register_Value_1_0_select_empty_(&rsp.data.value);
    rsp.data.timestamp.microsecond = micros();
    rsp.data._mutable = false;
    rsp.data.persistent = false;

    return rsp;
  }

  bool operator == (uavcan_register_Name_1_0 const & reg_name)
  {
    if (reg_name.name.count != _name.name.count)
      return false;
    else
        return (strncmp(reinterpret_cast<const char *>(_name.name.elements),
                        reinterpret_cast<const char *>(reg_name.name.elements),
                        reg_name.name.count) == 0);
  }

private:
  uavcan_register_Name_1_0 _name;
  AccessType const _access_type;
};

#endif /* REGISTER_BASE_H_ */
