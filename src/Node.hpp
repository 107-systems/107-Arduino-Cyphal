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
#include <tuple>
#include <array>
#include <memory>
#include <functional>

#include "Publisher.hpp"
#include "Subscription.hpp"
#include "ServiceClient.hpp"
#include "ServiceServer.hpp"
#include "CircularBuffer.hpp"

#include "libo1heap/o1heap.h"
#include "libcanard/canard.h"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class Node
{
public:

  typedef std::function<CanardMicrosecond(void)> MicrosFunc;
  typedef std::function<bool(CanardFrame const &)> CanFrameTxFunc;

  template <size_t SIZE>
  struct alignas(O1HEAP_ALIGNMENT) Heap final : public std::array<uint8_t, SIZE> {};

  typedef std::tuple<uint32_t, size_t, std::array<uint8_t, 8>, CanardMicrosecond> TReceiveCircularBuffer;

  static size_t       constexpr DEFAULT_O1HEAP_SIZE   = 4096;
  static CanardNodeID constexpr DEFAULT_NODE_ID       = 42;
  static size_t       constexpr DEFAULT_RX_QUEUE_SIZE = 64;
  static size_t       constexpr DEFAULT_TX_QUEUE_SIZE = 64;
  static size_t       constexpr DEFAULT_MTU_SIZE      = CANARD_MTU_CAN_CLASSIC;


  Node(uint8_t * heap_ptr,
       size_t const heap_size,
       TReceiveCircularBuffer * rx_queue_heap_ptr,
       size_t const rx_queue_heap_size,
       MicrosFunc const micros_func,
       CanardNodeID const node_id,
       size_t const tx_queue_capacity,
       size_t const mtu_bytes);

  Node(uint8_t * heap_ptr, size_t const heap_size, TReceiveCircularBuffer * rx_queue_heap_ptr, size_t const rx_queue_heap_size, MicrosFunc const micros_func)
  : Node(heap_ptr, heap_size, rx_queue_heap_ptr, rx_queue_heap_size, micros_func, DEFAULT_NODE_ID, DEFAULT_TX_QUEUE_SIZE, DEFAULT_MTU_SIZE) { }

  Node(uint8_t * heap_ptr, size_t const heap_size, TReceiveCircularBuffer * rx_queue_heap_ptr, size_t const rx_queue_heap_size, MicrosFunc const micros_func, CanardNodeID const node_id)
  : Node(heap_ptr, heap_size, rx_queue_heap_ptr, rx_queue_heap_size, micros_func, node_id, DEFAULT_TX_QUEUE_SIZE, DEFAULT_MTU_SIZE) { }


  inline void setNodeId(CanardNodeID const node_id) { _canard_hdl.node_id = node_id; }
  inline CanardNodeID getNodeId() const { return _canard_hdl.node_id; }

  template <typename T>
  Publisher<T> create_publisher(CanardPortID const port_id,
                                CanardMicrosecond const tx_timeout_usec);

  template <typename T, typename OnReceiveCb>
  Subscription create_subscription(CanardPortID const port_id,
                                   CanardMicrosecond const rx_timeout_usec,
                                   OnReceiveCb&& on_receive_cb);

  template <typename T_REQ, typename T_RSP, typename OnRequestCb>
  ServiceServer create_service_server(CanardPortID const port_id,
                                      CanardMicrosecond const tx_timeout_usec,
                                      OnRequestCb&& on_request_cb);

  template <typename T_REQ, typename T_RSP, typename OnResponseCb>
  ServiceClient<T_REQ> create_service_client(CanardPortID const port_id,
                                             CanardMicrosecond const tx_timeout_usec,
                                             OnResponseCb&& on_response_cb);

  /* Must be called from the application to process
   * all received CAN frames.
   */
  void spinSome(CanFrameTxFunc const tx_func);
  /* Must be called from the application upon the
   * reception of a can frame.
   */
  void onCanFrameReceived(CanardFrame const & frame, CanardMicrosecond const & rx_timestamp_us);


  bool enqueue_transfer(CanardMicrosecond const tx_timeout_usec,
                        CanardTransferMetadata const * const transfer_metadata,
                        size_t const payload_buf_size,
                        uint8_t const * const payload_buf);
  void unsubscribe(CanardPortID const port_id, CanardTransferKind const transfer_kind);


private:
  O1HeapInstance * _o1heap_ins;
  CanardInstance _canard_hdl;
  MicrosFunc const _micros_func;
  CanardTxQueue _canard_tx_queue;
  CircularBuffer<TReceiveCircularBuffer> _canard_rx_queue;

  static void * o1heap_allocate(CanardInstance * const ins, size_t const amount);
  static void   o1heap_free    (CanardInstance * const ins, void * const pointer);

  void processRxQueue();
  void processTxQueue(CanFrameTxFunc const tx_func);
};

/**************************************************************************************
 * TEMPLATE SOURCE FILE
 **************************************************************************************/

#include "Node.ipp"

#endif /* ARDUINO_CYPHAL_NODE_HPP_ */
