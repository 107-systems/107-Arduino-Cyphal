/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_CRIT_SEC_H_
#define ARDUINO_CRIT_SEC_H_

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************
 * FUNCTION DECLARATION
 **************************************************************************************/

void crit_sec_enter();
void crit_sec_leave();

#ifdef __cplusplus
}
#endif

#endif /* ARDUINO_CRIT_SEC_H_ */
