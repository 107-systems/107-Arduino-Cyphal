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

class NodeBase
{
public:
  NodeBase() { }
  virtual ~NodeBase() { }
  NodeBase(NodeBase const &) = delete;
  NodeBase(NodeBase &&) = delete;
  NodeBase &operator=(NodeBase const &) = delete;
  NodeBase &operator=(NodeBase &&) = delete;


  virtual bool enqueue_transfer(CanardMicrosecond const tx_timeout_usec,
                                CanardTransferMetadata const * const transfer_metadata,
                                size_t const payload_buf_size,
                                uint8_t const * const payload_buf) = 0;
  virtual void unsubscribe(CanardPortID const port_id, CanardTransferKind const transfer_kind) = 0;
};

template <size_t MTU_BYTES>
class Node : public NodeBase
{
public:

  typedef std::function<CanardMicrosecond(void)> MicrosFunc;
  typedef std::function<bool(CanardFrame const &)> CanFrameTxFunc;

  template <size_t SIZE>
  struct alignas(O1HEAP_ALIGNMENT) Heap final : public std::array<uint8_t, SIZE> {};

  typedef std::tuple<uint32_t, size_t, std::array<uint8_t, MTU_BYTES>, CanardMicrosecond> TReceiveCircularBuffer;

  static size_t       constexpr DEFAULT_O1HEAP_SIZE   = 4096;
  static CanardNodeID constexpr DEFAULT_NODE_ID       = 42;
  static size_t       constexpr DEFAULT_RX_QUEUE_SIZE = 64;
  static size_t       constexpr DEFAULT_TX_QUEUE_SIZE = 64;


  Node(uint8_t * heap_ptr,
       size_t const heap_size,
       TReceiveCircularBuffer * rx_queue_heap_ptr,
       size_t const rx_queue_heap_size,
       MicrosFunc const micros_func,
       CanardNodeID const node_id,
       size_t const tx_queue_capacity);

  Node(uint8_t * heap_ptr, size_t const heap_size, TReceiveCircularBuffer * rx_queue_heap_ptr, size_t const rx_queue_heap_size, MicrosFunc const micros_func)
  : Node(heap_ptr, heap_size, rx_queue_heap_ptr, rx_queue_heap_size, micros_func, DEFAULT_NODE_ID, DEFAULT_TX_QUEUE_SIZE) { }

  Node(uint8_t * heap_ptr, size_t const heap_size, TReceiveCircularBuffer * rx_queue_heap_ptr, size_t const rx_queue_heap_size, MicrosFunc const micros_func, CanardNodeID const node_id)
  : Node(heap_ptr, heap_size, rx_queue_heap_ptr, rx_queue_heap_size, micros_func, node_id, DEFAULT_TX_QUEUE_SIZE) { }

  virtual ~Node() { }

  inline void setNodeId(CanardNodeID const node_id) { _canard_hdl.node_id = node_id; }
  inline CanardNodeID getNodeId() const { return _canard_hdl.node_id; }


  template <typename T>
  Publisher<T> create_publisher(CanardPortID const port_id,
                                CanardMicrosecond const tx_timeout_usec)
  {
    return std::make_shared<impl::Publisher<T>>(
      *this,
      port_id,
      tx_timeout_usec
    );
  }

  template <typename T, typename OnReceiveCb>
  Subscription create_subscription(CanardPortID const port_id,
                                   CanardMicrosecond const rx_timeout_usec,
                                   OnReceiveCb&& on_receive_cb)
  {
    auto sub = std::make_shared<impl::Subscription<T, OnReceiveCb>>(
      *this,
      port_id,
      std::forward<OnReceiveCb>(on_receive_cb)
    );

    int8_t const rc = canardRxSubscribe(&_canard_hdl,
                                        CanardTransferKindMessage,
                                        port_id,
                                        T::MAX_PAYLOAD_SIZE,
                                        rx_timeout_usec,
                                        &(sub->canard_rx_subscription()));
    if (rc < 0)
      return nullptr;

    return sub;
  }

  template <typename T_REQ, typename T_RSP, typename OnRequestCb>
  ServiceServer create_service_server(CanardPortID const port_id,
                                      CanardMicrosecond const tx_timeout_usec,
                                      OnRequestCb&& on_request_cb)
  {
    auto srv = std::make_shared<impl::ServiceServer<T_REQ, T_RSP, OnRequestCb>>(
      *this,
      port_id,
      tx_timeout_usec,
      std::forward<OnRequestCb>(on_request_cb)
    );

    int8_t const rc = canardRxSubscribe(&_canard_hdl,
                                        CanardTransferKindRequest,
                                        port_id,
                                        T_REQ::MAX_PAYLOAD_SIZE,
                                        CANARD_DEFAULT_TRANSFER_ID_TIMEOUT_USEC,
                                        &(srv->canard_rx_subscription()));
    if (rc < 0)
      return nullptr;

    return srv;
  }

  template <typename T_REQ, typename T_RSP, typename OnResponseCb>
  ServiceClient<T_REQ> create_service_client(CanardPortID const port_id,
                                             CanardMicrosecond const tx_timeout_usec,
                                             OnResponseCb&& on_response_cb)
  {
    auto clt = std::make_shared<impl::ServiceClient<T_REQ, T_RSP, OnResponseCb>>(
      *this,
      port_id,
      tx_timeout_usec,
      std::forward<OnResponseCb>(on_response_cb)
    );

    int8_t const rc = canardRxSubscribe(&_canard_hdl,
                                        CanardTransferKindResponse,
                                        port_id,
                                        T_RSP::MAX_PAYLOAD_SIZE,
                                        CANARD_DEFAULT_TRANSFER_ID_TIMEOUT_USEC,
                                        &(clt->canard_rx_subscription()));
    if (rc < 0)
      return nullptr;

    return clt;
  }

  /* Must be called from the application to process
   * all received CAN frames.
   */
  void spinSome(CanFrameTxFunc const tx_func);
  /* Must be called from the application upon the
   * reception of a can frame.
   */
  void onCanFrameReceived(CanardFrame const & frame);


  virtual bool enqueue_transfer(CanardMicrosecond const tx_timeout_usec,
                                CanardTransferMetadata const * const transfer_metadata,
                                size_t const payload_buf_size,
                                uint8_t const * const payload_buf) override;
  virtual void unsubscribe(CanardPortID const port_id, CanardTransferKind const transfer_kind) override;


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

/**************************************************************************************
 * TYPEDEFS
 **************************************************************************************/

typedef Node<CANARD_MTU_CAN_CLASSIC> CanNode;
typedef Node<CANARD_MTU_CAN_FD>      CanFdNode;

#endif /* ARDUINO_CYPHAL_NODE_HPP_ */
