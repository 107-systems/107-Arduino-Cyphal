/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef INC_107_ARDUINO_CYPHAL_CONST_H
#define INC_107_ARDUINO_CYPHAL_CONST_H

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <functional>

#include "libcanard/canard.h"

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef std::function<CanardMicrosecond(void)> CyphalMicrosFunc;
typedef std::function<bool(CanardFrame const &)> CyphalCanFrameTxFunc;

#endif /* INC_107_ARDUINO_CYPHAL_CONST_H */
