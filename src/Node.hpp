/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef ARDUINO_CYPHAL_NODE_HPP_
#define ARDUINO_CYPHAL_NODE_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <cstdint>

#undef max
#undef min
#include <array>
#include <memory>
#include <optional>
#include <functional>

#include "NodeBase.hpp"
#include "PublisherBase.hpp"
#include "SubscriptionBase.h"
#include "CircularBuffer.hpp"
#include "ServiceClientBase.hpp"
#include "ServiceServerBase.hpp"
#include "CanRxQueueItem.hpp"
#include "util/nodeinfo/NodeInfoBase.hpp"
#include "util/registry/registry_impl.hpp"
#include "util/port/PortListPublisherBase.hpp"

#include "libo1heap/o1heap.h"
#include "libcanard/canard.h"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class Node : public NodeBase
{
public:
  typedef std::function<CanardMicrosecond(void)> MicrosFunc;
  typedef std::function<bool(CanardFrame const &)> CanFrameTxFunc;

  template <size_t SIZE>
  struct alignas(O1HEAP_ALIGNMENT) Heap final : public std::array<uint8_t, SIZE> {};


  static size_t       constexpr DEFAULT_O1HEAP_SIZE   = 16384UL;
  static size_t       constexpr DEFAULT_RX_QUEUE_SIZE = 64;
  static size_t       constexpr DEFAULT_MTU_SIZE      = CANARD_MTU_CAN_CLASSIC;


  Node(uint8_t * heap_ptr,
       size_t const heap_size,
       MicrosFunc const micros_func,
       CanFrameTxFunc const tx_func,
       CanardNodeID const node_id,
       size_t const tx_queue_capacity,
       size_t const rx_queue_capacity,
       size_t const mtu_bytes);

  Node(uint8_t * heap_ptr, size_t const heap_size, MicrosFunc const micros_func, CanFrameTxFunc const tx_func)
  : Node(heap_ptr, heap_size, micros_func, tx_func, DEFAULT_NODE_ID, DEFAULT_TX_QUEUE_SIZE, DEFAULT_RX_QUEUE_SIZE, DEFAULT_MTU_SIZE) { }

  Node(uint8_t * heap_ptr, size_t const heap_size, MicrosFunc const micros_func, CanFrameTxFunc const tx_func, CanardNodeID const node_id)
  : Node(heap_ptr, heap_size, micros_func, tx_func, node_id, DEFAULT_TX_QUEUE_SIZE, DEFAULT_RX_QUEUE_SIZE, DEFAULT_MTU_SIZE) { }

  /* Must be called from the application to process
   * all received CAN frames.
   */
  void spinSome();
  /* Must be called from the application upon the
   * reception of a can frame.
   */
  using NodeBase::onCanFrameReceived;
  void onCanFrameReceived(CanardFrame const & frame, CanardMicrosecond const rx_timestamp_usec) override final;


private:
  typedef CircularBuffer<CanRxQueueItem<CANARD_MTU_CAN_CLASSIC>> CircularBufferCan;
  typedef CircularBuffer<CanRxQueueItem<CANARD_MTU_CAN_FD>>      CircularBufferCanFd;

  O1HeapInstance * _o1heap_ins;
  std::shared_ptr<CircularBufferBase> _canard_rx_queue;

  void * _heap_allocate(size_t const amount)  override final;
  void   _heap_free    (void * const pointer) override final;

  void processRxQueue();
  template<size_t MTU_BYTES>
  void processRxFrame(CanRxQueueItem<MTU_BYTES> const * const rx_queue_item);
};

/**************************************************************************************
 * TEMPLATE SOURCE FILE
 **************************************************************************************/

#include "Node.ipp"

#endif /* ARDUINO_CYPHAL_NODE_HPP_ */
