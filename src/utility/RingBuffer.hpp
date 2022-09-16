/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef ARDUINO_CYPHAL_UTILITY_RINGBUFFER_H_
#define ARDUINO_CYPHAL_UTILITY_RINGBUFFER_H_

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace arduino
{
namespace _107_
{
namespace opencyphal
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <class T>
class Ringbuffer
{
public:
  Ringbuffer(size_t const size)
  : _buffer{new T[size]}
  , _size{size}
  , _head{0}
  , _tail{0}
  , _num_elems{0}
  { }

  ~Ringbuffer()
  {
    delete[] _buffer;
    _size = 0;
    _head = 0;
    _tail = 0;
    _num_elems = 0;
  }

  void enqueue(T const & val)
  {
    if (isFull()) return;
    _buffer[_head] = val;
    _head = nextIndex(_head);
    _num_elems++;
  }

  T dequeue()
  {
    if (isEmpty()) return T{};
    T const val = _buffer[_tail];
    _tail = nextIndex(_tail);
    _num_elems--;
    return val;
  }

  size_t available() const
  {
    return _num_elems;
  }

  bool isFull() const
  {
    return (_num_elems == _size);
  }

  bool isEmpty() const
  {
    return (_num_elems == 0);
  }

private:
  T * _buffer;
  size_t _size, _head, _tail, _num_elems;

  size_t nextIndex(size_t const index)
  {
    return ((index + 1) % _size);
  }
};

template <class T>
class ThreadsafeRingBuffer : private Ringbuffer<T>
{
public:
  ThreadsafeRingBuffer(size_t const size) : Ringbuffer<T>(size) { }

  void enqueue(T const & val)
  {
    LockGuard lock;
    Ringbuffer<T>::enqueue(val);
  }

  T dequeue()
  {
    LockGuard lock;
    return Ringbuffer<T>::dequeue();
  }

  size_t available() const
  {
    LockGuard lock;
    return Ringbuffer<T>::available();
  }

  bool isFull() const
  {
    LockGuard lock;
    return Ringbuffer<T>::isFull();
  }

  bool isEmpty() const
  {
    LockGuard lock;
    return Ringbuffer<T>::isEmpty();
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* arduino */
} /* _107_ */
} /* opencyphal */

#endif /* ARDUINO_CYPHAL_UTILITY_RINGBUFFER_H_ */
