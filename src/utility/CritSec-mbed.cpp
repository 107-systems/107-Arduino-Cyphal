/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "CritSec.h"

#ifdef ARDUINO_ARCH_MBED

#include <CriticalSectionLock.h>

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

extern "C" void crit_sec_enter()
{
  mbed::CriticalSectionLock::enable();
}

extern "C" void crit_sec_leave()
{
  mbed::CriticalSectionLock::disable();
}

#endif /* ARDUINO_ARCH_MBED */
