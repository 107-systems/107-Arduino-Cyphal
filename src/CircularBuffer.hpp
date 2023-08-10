/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#pragma once

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <cstdlib>

#include <array>
#include <memory>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace cyphal
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class CircularBufferBase
{
public:
  CircularBufferBase() { }
  virtual ~CircularBufferBase() { }
  CircularBufferBase(CircularBufferBase const &) = delete;
  CircularBufferBase(CircularBufferBase &&) = delete;
  CircularBufferBase &operator=(CircularBufferBase const &) = delete;
  CircularBufferBase &operator=(CircularBufferBase &&) = delete;
};

template <typename T>
class CircularBuffer : public CircularBufferBase
{
public:
  CircularBuffer(size_t const heap_size);
  virtual ~CircularBuffer();


  void enqueue(T const & val);
  T * peek();
  void pop();



private:
  std::unique_ptr<T> _buffer;
  size_t _size, _head, _tail, _num_elems;

  bool isFull() const { return (_num_elems == _size); }
  bool isEmpty() const { return (_num_elems == 0); }
  size_t nextIndex(size_t const index) { return ((index + 1) % _size); }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* cyphal */

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "CircularBuffer.ipp"
