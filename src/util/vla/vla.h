/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef INC_107_ARDUINO_CYPHAL_VLA_H
#define INC_107_ARDUINO_CYPHAL_VLA_H

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <string>

#include "../../DSDL_Types.h"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace vla
{

/**************************************************************************************
 * FUNCTION DECLARATIONS
 **************************************************************************************/

uavcan::primitive::String_1_0 to_String_1_0(std::string const & str);
uavcan::primitive::String_1_0 to_String_1_0(char const * c_str);

uavcan::_register::Name_1_0 to_Name_1_0(std::string const & str);
uavcan::_register::Name_1_0 to_Name_1_0(char const * c_str);

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* vla */

#endif /* INC_107_ARDUINO_CYPHAL_VLA_H */
