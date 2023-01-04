/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef ARDUINO_CYPHAL_NODE_HPP_
#define ARDUINO_CYPHAL_NODE_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <stdint.h>

#undef max
#undef min
#include <map>
#include <tuple>
#include <array>
#include <memory>
#include <functional>

#include "Const.h"
#include "Types.h"

#include "Service.hpp"
#include "Publisher.hpp"
#include "Subscription.hpp"

#include "libo1heap/o1heap.h"
#include "libcanard/canard.h"

#include "utility/convert.hpp"
#include "utility/LockGuard.h"
#include "utility/RingBuffer.hpp"

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

template <size_t SIZE>
struct alignas(O1HEAP_ALIGNMENT) CyphalHeap final : public std::array<uint8_t, SIZE> {};

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class Node
{
public:

  static size_t       constexpr DEFAULT_O1HEAP_SIZE   = 4096;
  static CanardNodeID constexpr DEFAULT_NODE_ID       = 42;
  static size_t       constexpr DEFAULT_TX_QUEUE_SIZE = 64;
  static size_t       constexpr DEFAULT_RX_QUEUE_SIZE = 64;
  static size_t       constexpr DEFAULT_MTU_SIZE      = CANARD_MTU_CAN_CLASSIC;


  Node(uint8_t * heap_ptr,
       size_t const heap_size,
       CyphalMicrosFunc const micros_func,
       CanardNodeID const node_id,
       size_t const tx_queue_capacity,
       size_t const rx_queue_capacity,
       size_t const mtu_bytes);

  Node(uint8_t * heap_ptr, size_t const heap_size, CyphalMicrosFunc const micros_func)
  : Node(heap_ptr, heap_size, micros_func, DEFAULT_NODE_ID, DEFAULT_TX_QUEUE_SIZE, DEFAULT_RX_QUEUE_SIZE, DEFAULT_MTU_SIZE) { }

  Node(uint8_t * heap_ptr, size_t const heap_size, CyphalMicrosFunc const micros_func, CanardNodeID const node_id)
  : Node(heap_ptr, heap_size, micros_func, node_id, DEFAULT_TX_QUEUE_SIZE, DEFAULT_RX_QUEUE_SIZE, DEFAULT_MTU_SIZE) { }


  inline void setNodeId(CanardNodeID const node_id) { _canard_hdl.node_id = node_id; }
  inline CanardNodeID getNodeId() const { return _canard_hdl.node_id; }

  template <typename T>
  Publisher<T> create_publisher(CanardPortID const port_id,
                                CanardMicrosecond const tx_timeout_usec);

  template <typename T, typename OnReceiveCb>
  Subscription<T, OnReceiveCb> create_subscription(CanardPortID const port_id,
                                                   CanardMicrosecond const rx_timeout_usec,
                                                   OnReceiveCb&& on_receive_cb);

  template <typename T_REQ, typename T_RSP, typename OnRequestCb>
  Service<T_REQ, T_RSP, OnRequestCb> create_service(CanardPortID const port_id,
                                                    CanardMicrosecond const tx_timeout_usec,
                                                    OnRequestCb&& on_request_cb);

  /* Must be called from the application to process
   * all received CAN frames.
   */
  void spinSome(CyphalCanFrameTxFunc const tx_func);
  /* Must be called from the application upon the
   * reception of a can frame.
   */
  void onCanFrameReceived(CanardFrame const & frame, CanardMicrosecond const & rx_timestamp_us);


  void unsubscribe_message(CanardPortID const port_id);
  void unsubscribe_request(CanardPortID const port_id);


private:
  O1HeapInstance * _o1heap_ins;
  CanardInstance _canard_hdl;
  CyphalMicrosFunc const _micros_func;
  CanardTxQueue _canard_tx_queue;
  arduino::_107_::opencyphal::ThreadsafeRingBuffer<std::tuple<uint32_t, size_t, std::array<uint8_t, 8>, CanardMicrosecond>> _canard_rx_queue;
  std::map<CanardPortID, std::shared_ptr<impl::SubscriptionBase>> _msg_subscription_map;
  std::map<CanardPortID, std::shared_ptr<impl::ServiceBase>> _req_subscription_map;

  static void * o1heap_allocate(CanardInstance * const ins, size_t const amount);
  static void   o1heap_free    (CanardInstance * const ins, void * const pointer);

  void processRxQueue();
  void processTxQueue(CyphalCanFrameTxFunc const tx_func);
};

/**************************************************************************************
 * TEMPLATE SOURCE FILE
 **************************************************************************************/

#include "Node.ipp"

#endif /* ARDUINO_CYPHAL_NODE_HPP_ */
