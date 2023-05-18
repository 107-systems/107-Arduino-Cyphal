/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "Node.hpp"

#include <cstring>

#include "util/nodeinfo/NodeInfo.hpp"
#include "util/registry/Registry.hpp"
#include "util/port/PortListPublisher.hpp"

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

Node::Node(uint8_t * heap_ptr,
           size_t const heap_size,
           MicrosFunc const micros_func,
           CanFrameTxFunc const tx_func,
           CanardNodeID const node_id,
           size_t const tx_queue_capacity,
           size_t const rx_queue_capacity,
           size_t const mtu_bytes)
: NodeBase(micros_func, tx_func, node_id, tx_queue_capacity, mtu_bytes)
, _o1heap_ins{o1heapInit(heap_ptr, heap_size)}
, _canard_rx_queue{(mtu_bytes == CANARD_MTU_CAN_CLASSIC) ? static_cast<CircularBufferBase *>(new CircularBufferCan(rx_queue_capacity)) : static_cast<CircularBufferBase *>(new CircularBufferCanFd(rx_queue_capacity))}
{
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

void Node::spinSome()
{
  processPortList();
  processRxQueue();
  processTxQueue();
}

void Node::onCanFrameReceived(CanardFrame const & frame, CanardMicrosecond const rx_timestamp_usec)
{
  if (_mtu_bytes == CANARD_MTU_CAN_CLASSIC)
  {
    CanRxQueueItem<CANARD_MTU_CAN_CLASSIC> const rx_queue_item(&frame, rx_timestamp_usec);
    static_cast<CircularBufferCan *>(_canard_rx_queue.get())->enqueue(rx_queue_item);
  }
  else
  {
    CanRxQueueItem<CANARD_MTU_CAN_FD> const rx_queue_item(&frame, rx_timestamp_usec);
    static_cast<CircularBufferCanFd *>(_canard_rx_queue.get())->enqueue(rx_queue_item);
  }
}

/**************************************************************************************
 * PRIVATE MEMBER FUNCTIONS
 **************************************************************************************/

void * Node::_heap_allocate(size_t const amount)
{
  return o1heapAllocate(_o1heap_ins, amount);
}

void Node::_heap_free(void * const pointer)
{
  o1heapFree(_o1heap_ins, pointer);
}

void Node::processRxQueue()
{
  if (_mtu_bytes == CANARD_MTU_CAN_CLASSIC)
  {
    CircularBufferCan * can_rx_queue_ptr = static_cast<CircularBufferCan *>(_canard_rx_queue.get());
    CanRxQueueItem<CANARD_MTU_CAN_CLASSIC> const * rx_queue_item = can_rx_queue_ptr->peek();
    if (!rx_queue_item) return;
    processRxFrame(rx_queue_item);
    can_rx_queue_ptr->pop();
  }
  else
  {
    CircularBufferCanFd * canfd_rx_queue_ptr = static_cast<CircularBufferCanFd *>(_canard_rx_queue.get());
    CanRxQueueItem<CANARD_MTU_CAN_FD> const * rx_queue_item = canfd_rx_queue_ptr->peek();
    if (!rx_queue_item) return;
    processRxFrame(rx_queue_item);
    canfd_rx_queue_ptr->pop();
  }
}
