/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef ARDUINO_UAVCAN_H_
#define ARDUINO_UAVCAN_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <stdint.h>

#undef max
#undef min
#include <map>
#include <tuple>
#include <memory>
#include <functional>

#include "Types.h"
#include "O1Heap.hpp"

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

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class Node
{
public:

  static size_t       constexpr DEFAULT_O1HEAP_SIZE   = 4096;
  static size_t       constexpr DEFAULT_TX_QUEUE_SIZE = 100;
  static size_t       constexpr DEFAULT_RX_QUEUE_SIZE = 32;
  static size_t       constexpr DEFAULT_MTU_SIZE      = CANARD_MTU_CAN_CLASSIC;
  static CanardNodeID constexpr DEFAULT_NODE_ID       = 42;


  Node(CanFrameTransmitFunc transmit_func,
       CanardNodeID const node_id,
       size_t const tx_queue_capacity,
       size_t const mtu_bytes);

  Node(CanFrameTransmitFunc transmit_func)
  : Node(transmit_func, DEFAULT_NODE_ID, DEFAULT_TX_QUEUE_SIZE, DEFAULT_MTU_SIZE) { }

  Node(CanFrameTransmitFunc transmit_func, CanardNodeID const node_id)
  : Node(transmit_func, node_id, DEFAULT_TX_QUEUE_SIZE, DEFAULT_MTU_SIZE) { }


  void setNodeId(CanardNodeID const node_id);
  CanardNodeID getNodeId() const;

  /* Must be called from the application to process
   * all received CAN frames.
   */
  void spin();
  /* Must be called from the application upon the
   * reception of a can frame.
   */
  void onCanFrameReceived(CanardFrame const & frame, CanardMicrosecond const & rx_timestamp_us);


  template <typename T>                     bool subscribe       (OnTransferReceivedFunc func);
  template <typename T>                     bool unsubscribe     ();

  /* publish/subscribe API for "message" data exchange paradigm */
  template <typename T_MSG>                 bool publish         (T_MSG const & msg);

  /* request/response API for "service" data exchange paradigm */
  template <typename T_RSP>                 bool respond         (T_RSP const & rsp, CanardNodeID const remote_node_id, CanardTransferID const transfer_id);
  template <typename T_REQ, typename T_RSP> bool request         (T_REQ const & req, CanardNodeID const remote_node_id, OnTransferReceivedFunc func);


private:

  typedef O1Heap<DEFAULT_O1HEAP_SIZE> O1HeapLibcanard;

  typedef struct
  {
    CanardRxSubscription canard_rx_sub;
    OnTransferReceivedFunc transfer_complete_callback;
  } RxTransferData;

  O1HeapLibcanard _o1heap_hdl;
  CanardInstance _canard_hdl;
  CanardTxQueue _canard_tx_queue;
  arduino::_107_::opencyphal::ThreadsafeRingBuffer<std::tuple<uint32_t, size_t, std::array<uint8_t, 8>, CanardMicrosecond>> _canard_rx_queue;
  CanFrameTransmitFunc _transmit_func;
  std::map<CanardPortID, RxTransferData> _rx_transfer_map;
  std::map<CanardPortID, CanardTransferID> _tx_transfer_map;

  static void * o1heap_allocate(CanardInstance * const ins, size_t const amount);
  static void   o1heap_free    (CanardInstance * const ins, void * const pointer);

  void processRxQueue();
  void processTxQueue();

  CanardTransferID getNextTransferId(CanardPortID const port_id);
  bool             subscribe        (CanardTransferKind const transfer_kind, CanardPortID const port_id, size_t const payload_size_max, OnTransferReceivedFunc func);
  bool             unsubscribe      (CanardTransferKind const transfer_kind, CanardPortID const port_id);
  bool             enqeueTransfer   (CanardNodeID const remote_node_id, CanardTransferKind const transfer_kind, CanardPortID const port_id, size_t const payload_size, void * payload, CanardTransferID const transfer_id);

};

/**************************************************************************************
 * TEMPLATE SOURCE FILE
 **************************************************************************************/

#include "Node.ipp"

#endif /* ARDUINO_UAVCAN_H_ */
