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
  RegisterBase(char const * name)
  : _name
  {
    [name]() -> uavcan_register_Name_1_0
    {
      uavcan_register_Name_1_0 n;
      n.name.count = std::min(strlen(name), uavcan_register_Name_1_0_name_ARRAY_CAPACITY_);
      memcpy(n.name.elements, name, n.name.count);
      return n;
    } ()
  }
  { }

  uavcan::_register::List_1_0::Response<> toListResponse() const
  {
    uavcan::_register::List_1_0::Response<> rsp;
    memcpy(&rsp.data.name.name.elements, _name.name.elements, _name.name.count);
    rsp.data.name.name.count = _name.name.count;
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
};

#endif /* REGISTER_BASE_H_ */
