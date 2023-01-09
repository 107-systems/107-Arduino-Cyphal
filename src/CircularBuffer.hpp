/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef ARDUINO_CYPHAL_UTILITY_RINGBUFFER_H_
#define ARDUINO_CYPHAL_UTILITY_RINGBUFFER_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <cstdlib>

#include <array>

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <typename T>
class CircularBuffer
{
public:
  template <size_t SIZE>
  struct Heap final : public std::array<T, SIZE> {};


   CircularBuffer(T * heap_ptr, size_t const heap_size);
  ~CircularBuffer();


  void enqueue(T const & val);
  T dequeue();


  size_t available() const { return _num_elems; }
  bool isFull() const { return (_num_elems == _size); }
  bool isEmpty() const { return (_num_elems == 0); }


private:
  T * _buffer;
  size_t _size, _head, _tail, _num_elems;

  size_t nextIndex(size_t const index) { return ((index + 1) % _size); }
};

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "CircularBuffer.ipp"

#endif /* ARDUINO_CYPHAL_UTILITY_RINGBUFFER_H_ */
