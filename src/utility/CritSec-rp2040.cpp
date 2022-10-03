/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "CritSec.h"

#if defined(ARDUINO_ARCH_RP2040) && !defined(ARDUINO_ARDUINO_NANO_RP2040_CONNECT)
#include <Arduino.h>

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

extern "C" void crit_sec_enter()
{
  noInterrupts();
}

extern "C" void crit_sec_leave()
{
  interrupts();
}

#endif /* defined(ARDUINO_ARCH_RP2040) && !defined(ARDUINO_ARDUINO_NANO_RP2040_CONNECT) */
