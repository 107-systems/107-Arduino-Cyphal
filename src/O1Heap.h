/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef ARDUINO_O1_HEAP_H_
#define ARDUINO_O1_HEAP_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <o1heap/o1heap.h>

/**************************************************************************************
 * DEFINE
 **************************************************************************************/

#define CYPHAL_DECLARE_HEAP(name,size) \
  static uint8_t name[size] __attribute__ ((aligned (O1HEAP_ALIGNMENT)))

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class O1Heap
{
public:
  O1Heap(uint8_t * heap_ptr, size_t const heap_size)
  : _o1heap_ins{o1heapInit(heap_ptr, heap_size)}
  { }


  void * allocate(size_t const amount) {
    return o1heapAllocate(_o1heap_ins, amount);
  }
  void free (void * const pointer) {
    o1heapFree(_o1heap_ins, pointer);
  }


private:
  O1HeapInstance * _o1heap_ins;
};

#endif /* ARDUINO_O1_HEAP_H_ */
