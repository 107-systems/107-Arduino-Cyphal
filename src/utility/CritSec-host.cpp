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

#ifdef HOST

#include <mutex>

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

std::mutex mtx;

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

extern "C" void crit_sec_enter()
{
  mtx.lock();
}

extern "C" void crit_sec_leave()
{
  mtx.unlock();
}

#endif /* HOST */
