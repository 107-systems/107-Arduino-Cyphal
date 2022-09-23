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
#include "types/TypeTag.hpp"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class RegisterBase
{
public:
  RegisterBase(char const * name, Register::TypeTag const type_tag);

  inline Register::TypeTag type_tag() const { return _type_tag; }
  uavcan::_register::List_1_0::Response<> toListResponse() const;
  bool operator == (uavcan_register_Name_1_0 const & reg_name);


private:
  uavcan_register_Name_1_0 _name;
  Register::TypeTag const _type_tag;
};

#endif /* REGISTER_BASE_H_ */
