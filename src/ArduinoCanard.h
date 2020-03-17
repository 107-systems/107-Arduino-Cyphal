/**
 * @brief   Arduino library for controlling the Zubax Orel 20.
 * @author  Alexander Entinger, MSc / LXRobotics GmbH
 * @license MIT
 */

#ifndef ARDUINO_CANARD_H_
#define ARDUINO_CANARD_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class ArduinoCanard
{
public:

  ArduinoCanard(uint8_t const node_id, CanardMemoryAllocate const memory_allocate, CanardMemoryFree const memory_free);


private:

  CanardInstance _canard_ins;

};

#endif /* ARDUINO_CANARD_H_ */
