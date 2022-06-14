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

#ifdef ARDUINO_ARCH_STM32

#include <Arduino.h>

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

static volatile uint32_t primask_bit = 0;

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

extern "C" void crit_sec_enter()
{
  primask_bit = __get_PRIMASK();
  __disable_irq();
}

extern "C" void crit_sec_leave()
{
  __set_PRIMASK(primask_bit);
}

#endif /* ARDUINO_ARCH_STM32 */
