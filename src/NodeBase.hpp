/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef ARDUINO_CYPHAL_NODE_BASE_HPP_
#define ARDUINO_CYPHAL_NODE_BASE_HPP_

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

#include "PublisherBase.hpp"
#include "SubscriptionBase.h"
#include "ServiceClientBase.hpp"
#include "ServiceServerBase.hpp"
#include "util/nodeinfo/NodeInfoBase.hpp"
#include "util/registry/registry_impl.hpp"
#include "util/port/PortListPublisherBase.hpp"

#include "libcanard/canard.h"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class NodeBase
{
public:
  typedef std::function<CanardMicrosecond(void)> MicrosFunc;
  typedef std::function<bool(CanardFrame const &)> CanFrameTxFunc;


  static CanardNodeID constexpr DEFAULT_NODE_ID       = 42;
  static size_t       constexpr DEFAULT_TX_QUEUE_SIZE = 64;
  static size_t       constexpr DEFAULT_MTU_SIZE      = CANARD_MTU_CAN_CLASSIC;


  NodeBase(MicrosFunc const micros_func,
       CanFrameTxFunc const tx_func,
       CanardNodeID const node_id,
       size_t const tx_queue_capacity,
       size_t const mtu_bytes);

  NodeBase(MicrosFunc const micros_func, CanFrameTxFunc const tx_func)
  : NodeBase(micros_func, tx_func, DEFAULT_NODE_ID, DEFAULT_TX_QUEUE_SIZE, DEFAULT_MTU_SIZE) { }

  NodeBase(MicrosFunc const micros_func, CanFrameTxFunc const tx_func, CanardNodeID const node_id)
  : NodeBase(micros_func, tx_func, node_id, DEFAULT_TX_QUEUE_SIZE, DEFAULT_MTU_SIZE) { }


  inline void setNodeId(CanardNodeID const node_id) { _canard_hdl.node_id = node_id; }
  inline CanardNodeID getNodeId() const { return _canard_hdl.node_id; }


  template <typename T>
  Publisher<T> create_publisher(CanardMicrosecond const tx_timeout_usec);
  template <typename T>
  Publisher<T> create_publisher(CanardPortID const port_id, CanardMicrosecond const tx_timeout_usec);

  template <typename T, typename OnReceiveCb>
  Subscription create_subscription(OnReceiveCb&& on_receive_cb, CanardMicrosecond const tid_timeout_usec = CANARD_DEFAULT_TRANSFER_ID_TIMEOUT_USEC);
  template <typename T, typename OnReceiveCb>
  Subscription create_subscription(CanardPortID const port_id, OnReceiveCb&& on_receive_cb, CanardMicrosecond const tid_timeout_usec = CANARD_DEFAULT_TRANSFER_ID_TIMEOUT_USEC);

  template <typename T_REQ, typename T_RSP, typename OnRequestCb>
  ServiceServer create_service_server(CanardMicrosecond const tx_timeout_usec, OnRequestCb&& on_request_cb, CanardMicrosecond const tid_timeout_usec = CANARD_DEFAULT_TRANSFER_ID_TIMEOUT_USEC);
  template <typename T_REQ, typename T_RSP, typename OnRequestCb>
  ServiceServer create_service_server(CanardPortID const request_port_id, CanardMicrosecond const tx_timeout_usec, OnRequestCb&& on_request_cb, CanardMicrosecond const tid_timeout_usec = CANARD_DEFAULT_TRANSFER_ID_TIMEOUT_USEC);

  template <typename T_REQ, typename T_RSP, typename OnResponseCb>
  ServiceClient<T_REQ> create_service_client(CanardMicrosecond const tx_timeout_usec, OnResponseCb&& on_response_cb, CanardMicrosecond const tid_timeout_usec = CANARD_DEFAULT_TRANSFER_ID_TIMEOUT_USEC);
  template <typename T_REQ, typename T_RSP, typename OnResponseCb>
  ServiceClient<T_REQ> create_service_client(CanardPortID const response_port_id, CanardMicrosecond const tx_timeout_usec, OnResponseCb&& on_response_cb, CanardMicrosecond const tid_timeout_usec = CANARD_DEFAULT_TRANSFER_ID_TIMEOUT_USEC);

#if !defined(__GNUC__) || (__GNUC__ >= 11)
  Registry create_registry();
#endif

  NodeInfo create_node_info(uint8_t const protocol_major, uint8_t const protocol_minor,
                            uint8_t const hardware_major, uint8_t const hardware_minor,
                            uint8_t const software_major, uint8_t const software_minor,
                            uint64_t const software_vcs_revision_id,
                            std::array<uint8_t, 16> const & unique_id,
                            std::string const & name);

  /* Must be called from the application upon the
   * reception of a can frame.
   */
  void onCanFrameReceived(CanardFrame const & frame) {
    onCanFrameReceived(frame, _micros_func());
  }
  virtual void onCanFrameReceived(CanardFrame const & frame, CanardMicrosecond const rx_timestamp_usec);


  virtual bool enqueue_transfer(CanardMicrosecond const tx_timeout_usec,
                        CanardTransferMetadata const * const transfer_metadata,
                        size_t const payload_buf_size,
                        uint8_t const * const payload_buf);
  void unsubscribe(CanardPortID const port_id, CanardTransferKind const transfer_kind);


protected:
  CanardInstance _canard_hdl;
  MicrosFunc const _micros_func;
  CanFrameTxFunc const _tx_func;
  CanardTxQueue _canard_tx_queue;
  size_t const _mtu_bytes;

  std::optional<PortListPublisher> _opt_port_list_pub;

  static inline void * heap_allocate(CanardInstance * const ins, size_t const amount)
  {
    NodeBase * self = reinterpret_cast<NodeBase *>(ins->user_reference);
    return self->_heap_allocate(amount);
  }
  static inline void heap_free(CanardInstance * const ins, void * const pointer)
  {
    NodeBase * self = reinterpret_cast<NodeBase *>(ins->user_reference);
    self->_heap_free(pointer);
  }

  virtual void * _heap_allocate(size_t const amount)  = 0;
  virtual void   _heap_free    (void * const pointer) = 0;

  void processTxQueue();
  void processPortList();
};

/**************************************************************************************
 * TEMPLATE SOURCE FILE
 **************************************************************************************/

#include "NodeBase.ipp"

#endif /* ARDUINO_CYPHAL_NODE_BASE_HPP_ */
