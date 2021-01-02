/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_O1_HEAP_HPP_
#define ARDUINO_O1_HEAP_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <o1heap/o1heap.h>

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <size_t HEAP_SIZE>
class ArduinoO1Heap
{
public:

  ArduinoO1Heap();


  void * allocate(size_t const amount);
  void   free    (void * const pointer);


private:

  uint8_t _base[HEAP_SIZE] __attribute__ ((aligned (O1HEAP_ALIGNMENT)));
  O1HeapInstance * _o1heap_ins;

};

/**************************************************************************************
 * TEMPLATE SOURCE
 **************************************************************************************/

#include "ArduinoO1Heap.ipp"

#endif /* ARDUINO_O1_HEAP_HPP_ */
