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

#ifdef ARDUINO_ARCH_SAMD

#include <Arduino.h>

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

static uint8_t irestore = 0;

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

void crit_sec_enter()
{
  irestore = (__get_PRIMASK() ? 0 : 1);
  noInterrupts();
}

void crit_sec_leave()
{
  if (irestore)
  {
    interrupts();
  }
}

#endif /* ARDUINO_ARCH_SAMD */
