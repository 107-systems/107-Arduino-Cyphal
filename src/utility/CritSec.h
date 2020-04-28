/**
 * @brief   Arduino library for controlling the Zubax Orel 20.
 * @license MIT
 */

#ifndef ARDUINO_CRIT_SEC_H_
#define ARDUINO_CRIT_SEC_H_

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************
 * FUNCTION DECLARATION
 **************************************************************************************/

void crit_sec_enter() __attribute__((always_inline));
void crit_sec_leave() __attribute__((always_inline));

#ifdef __cplusplus
}
#endif

#endif /* ARDUINO_CRIT_SEC_H_ */
