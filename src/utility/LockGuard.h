/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_LOCK_GUARD_H_
#define ARDUINO_LOCK_GUARD_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "CritSec.h"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class LockGuard
{
public:
   LockGuard() { crit_sec_enter(); }
  ~LockGuard() { crit_sec_leave(); }
};

#endif /* ARDUINO_LOCK_GUARD_H_ */
