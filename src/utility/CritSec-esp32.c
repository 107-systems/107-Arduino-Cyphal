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

#ifdef ARDUINO_ARCH_ESP32

#include <Arduino.h>

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

static portMUX_TYPE mtx = portMUX_INITIALIZER_UNLOCKED;

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

void crit_sec_enter()
{
  portENTER_CRITICAL(&mtx);
}

void crit_sec_leave()
{
  portEXIT_CRITICAL(&mtx);
}

#endif /* ARDUINO_ARCH_ESP32 */
