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
 * NAMESPACE
 **************************************************************************************/

namespace cyphal
{

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
: _o1heap_ins{o1heapInit(heap_ptr, heap_size)}
, _canard_hdl{canardInit(Node::o1heap_allocate, Node::o1heap_free)}
, _micros_func{micros_func}
, _tx_func{tx_func}
, _canard_tx_queue{canardTxInit(tx_queue_capacity, mtu_bytes)}
, _canard_rx_queue{(mtu_bytes == CANARD_MTU_CAN_CLASSIC) ? static_cast<CircularBufferBase *>(new CircularBufferCan(rx_queue_capacity)) : static_cast<CircularBufferBase *>(new CircularBufferCanFd(rx_queue_capacity))}
, _mtu_bytes{mtu_bytes}
, _opt_port_list_pub{std::nullopt}
{
  _canard_hdl.node_id = node_id;
  _canard_hdl.user_reference = static_cast<void *>(_o1heap_ins);

  _opt_port_list_pub = std::make_shared<impl::PortListPublisher>(*this, _micros_func);
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

#if !defined(__GNUC__) || (__GNUC__ >= 11)
Registry Node::create_registry()
{
  return std::make_shared<impl::Registry>(*this, _micros_func);
}
#endif

NodeInfo Node::create_node_info(uint8_t const protocol_major, uint8_t const protocol_minor,
                          uint8_t const hardware_major, uint8_t const hardware_minor,
                          uint8_t const software_major, uint8_t const software_minor,
                          uint64_t const software_vcs_revision_id,
                          std::array<uint8_t, 16> const & unique_id,
                          std::string const & name)
{
  return std::make_shared<impl::NodeInfo>(*this,
                                          protocol_major, protocol_minor,
                                          hardware_major, hardware_minor,
                                          software_major, software_minor,
                                          software_vcs_revision_id,
                                          unique_id,
                                          name);
}

void Node::spinSome()
{
  processPortList();
  processRxQueue();
  processTxQueue();
}

void Node::processPortList()
{
  if (_opt_port_list_pub.has_value())
    _opt_port_list_pub.value()->update();
}


void Node::onCanFrameReceived(CanardFrame const & frame)
{
  if (_mtu_bytes == CANARD_MTU_CAN_CLASSIC)
  {
    CanRxQueueItem<CANARD_MTU_CAN_CLASSIC> const rx_queue_item(&frame, _micros_func());
    static_cast<CircularBufferCan *>(_canard_rx_queue.get())->enqueue(rx_queue_item);
  }
  else
  {
    CanRxQueueItem<CANARD_MTU_CAN_FD> const rx_queue_item(&frame, _micros_func());
    static_cast<CircularBufferCanFd *>(_canard_rx_queue.get())->enqueue(rx_queue_item);
  }
}

bool Node::enqueue_transfer(CanardMicrosecond const tx_timeout_usec,
                            CanardTransferMetadata const * const transfer_metadata,
                            size_t const payload_buf_size,
                            uint8_t const * const payload_buf)
{
  int32_t const rc = canardTxPush(&_canard_tx_queue,
                                  &_canard_hdl,
                                  _micros_func() + tx_timeout_usec,
                                  transfer_metadata,
                                  payload_buf_size,
                                  payload_buf);

  bool const success = (rc >= 0);
  return success;
}

void Node::unsubscribe(CanardPortID const port_id, CanardTransferKind const transfer_kind)
{
  canardRxUnsubscribe(&_canard_hdl,
                      transfer_kind,
                      port_id);
}

/**************************************************************************************
 * PRIVATE MEMBER FUNCTIONS
 **************************************************************************************/

void * Node::o1heap_allocate(CanardInstance * const ins, size_t const amount)
{
  O1HeapInstance * o1heap = reinterpret_cast<O1HeapInstance *>(ins->user_reference);
  return o1heapAllocate(o1heap, amount);
}

void Node::o1heap_free(CanardInstance * const ins, void * const pointer)
{
  O1HeapInstance * o1heap = reinterpret_cast<O1HeapInstance *>(ins->user_reference);
  o1heapFree(o1heap, pointer);
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

void Node::processTxQueue()
{
  for(CanardTxQueueItem * tx_queue_item = const_cast<CanardTxQueueItem *>(canardTxPeek(&_canard_tx_queue));
      tx_queue_item != nullptr;
      tx_queue_item = const_cast<CanardTxQueueItem *>(canardTxPeek(&_canard_tx_queue)))
  {
    /* Discard the frame if the transmit deadline has expired. */
    if (_micros_func() > tx_queue_item->tx_deadline_usec) {
      _canard_hdl.memory_free(&_canard_hdl, canardTxPop(&_canard_tx_queue, tx_queue_item));
      continue;
    }

    /* Attempt to transmit the frame via CAN. */
    if (_tx_func(tx_queue_item->frame)) {
      _canard_hdl.memory_free(&_canard_hdl, canardTxPop(&_canard_tx_queue, tx_queue_item));
      continue;
    }

    return;
  }
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* cyphal */
