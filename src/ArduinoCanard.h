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

#include <ArduinoO1Heap.h>

#include <libcanard/canard.h>

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class ArduinoCanard
{
public:

  ArduinoCanard(uint8_t const node_id);


private:

  ArduinoO1Heap _o1heap;
  CanardInstance _canard_ins;

  static void * o1heap_allocate(CanardInstance * const ins, size_t const amount);
  static void   o1heap_free    (CanardInstance * const ins, void * const pointer);

};

#endif /* ARDUINO_CANARD_H_ */
