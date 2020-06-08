/**
 * @brief   Arduino library for providing a convenient C++ interface for accessing UAVCAN.
 * @license MIT
 */

#ifndef ARDUINO_O1_HEAP_H_
#define ARDUINO_O1_HEAP_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <o1heap/o1heap.h>

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class ArduinoO1Heap
{
public:

  ArduinoO1Heap();


  void * allocate(size_t const amount);
  void   free    (void * const pointer);


private:

  static size_t constexpr HEAP_SIZE = 4096;

  uint8_t _base[HEAP_SIZE] __attribute__ ((aligned (O1HEAP_ALIGNMENT)));
  O1HeapInstance * _o1heap_ins;

};

#endif /* ARDUINO_O1_HEAP_H_ */
