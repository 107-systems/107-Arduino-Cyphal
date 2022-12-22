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

#include "Types.h"

#include "Publisher.hpp"

#include "libo1heap/o1heap.h"
#include "libcanard/canard.h"

#include "utility/convert.hpp"
#include "utility/LockGuard.h"
#include "utility/RingBuffer.hpp"

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

class Node;
typedef std::function<void(CanardRxTransfer const &, Node &)> OnTransferReceivedFunc;
typedef std::function<bool(CanardFrame const &)> CanFrameTransmitFunc;
typedef std::function<CanardMicrosecond(void)> TransferTimestampFunc;

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
       CanardNodeID const node_id,
       size_t const tx_queue_capacity,
       size_t const rx_queue_capacity,
       size_t const mtu_bytes);

  Node(uint8_t * heap_ptr, size_t const heap_size)
  : Node(heap_ptr, heap_size, DEFAULT_NODE_ID, DEFAULT_TX_QUEUE_SIZE, DEFAULT_RX_QUEUE_SIZE, DEFAULT_MTU_SIZE) { }

  Node(uint8_t * heap_ptr, size_t const heap_size, CanardNodeID const node_id)
  : Node(heap_ptr, heap_size, node_id, DEFAULT_TX_QUEUE_SIZE, DEFAULT_RX_QUEUE_SIZE, DEFAULT_MTU_SIZE) { }


  inline void setNodeId(CanardNodeID const node_id) { _canard_hdl.node_id = node_id; }
  inline CanardNodeID getNodeId() const { return _canard_hdl.node_id; }

  template <typename T>
  Publisher<T> create_publisher(CanardPortID const port_id,
                                CanardMicrosecond const tx_timeout_usec,
                                std::function<CanardMicrosecond(void)> const micros_func);

  /* Must be called from the application to process
   * all received CAN frames.
   */
  void spinSome(CanFrameTransmitFunc const tx_func, TransferTimestampFunc const micros_func);
  /* Must be called from the application upon the
   * reception of a can frame.
   */
  void onCanFrameReceived(CanardFrame const & frame, CanardMicrosecond const & rx_timestamp_us);


  template <typename T>                     bool subscribe       (OnTransferReceivedFunc func);
  template <typename T>                     bool unsubscribe     ();

  /* request/response API for "service" data exchange paradigm */
  template <typename T_RSP>                 bool respond         (T_RSP const & rsp, CanardNodeID const remote_node_id, CanardTransferID const transfer_id);
  template <typename T_REQ, typename T_RSP> bool request         (T_REQ const & req, CanardNodeID const remote_node_id, OnTransferReceivedFunc func);


private:

  typedef struct
  {
    CanardRxSubscription canard_rx_sub;
    OnTransferReceivedFunc transfer_complete_callback;
  } RxTransferData;

  O1HeapInstance * _o1heap_ins;
  CanardInstance _canard_hdl;
  CanardTxQueue _canard_tx_queue;
  arduino::_107_::opencyphal::ThreadsafeRingBuffer<std::tuple<uint32_t, size_t, std::array<uint8_t, 8>, CanardMicrosecond>> _canard_rx_queue;
  std::map<CanardPortID, RxTransferData> _rx_transfer_map;
  std::map<CanardPortID, CanardTransferID> _tx_transfer_map;

  static void * o1heap_allocate(CanardInstance * const ins, size_t const amount);
  static void   o1heap_free    (CanardInstance * const ins, void * const pointer);

  void processRxQueue();
  void processTxQueue(CanFrameTransmitFunc const tx_func, TransferTimestampFunc const micros_func);

  CanardTransferID getNextTransferId(CanardPortID const port_id);
  bool             subscribe        (CanardTransferKind const transfer_kind, CanardPortID const port_id, size_t const payload_size_max, OnTransferReceivedFunc func);
  bool             unsubscribe      (CanardTransferKind const transfer_kind, CanardPortID const port_id);
  bool             enqeueTransfer   (CanardNodeID const remote_node_id, CanardTransferKind const transfer_kind, CanardPortID const port_id, size_t const payload_size, void * payload, CanardTransferID const transfer_id);
};

/**************************************************************************************
 * TEMPLATE SOURCE FILE
 **************************************************************************************/

#include "Node.ipp"

#endif /* ARDUINO_CYPHAL_NODE_HPP_ */
