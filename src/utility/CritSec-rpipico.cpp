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
#ifdef ARDUINO_RASPBERRY_PI_PICO
#include "Arduino.h"

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

#endif /* ARDUINO_RASPBERRY_PI_PICO */
