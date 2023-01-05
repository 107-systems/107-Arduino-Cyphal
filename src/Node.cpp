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

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

Node::Node(uint8_t * heap_ptr,
           size_t const heap_size,
           MicrosFunc const micros_func,
           CanardNodeID const node_id,
           size_t const tx_queue_capacity,
           size_t const rx_queue_capacity,
           size_t const mtu_bytes)
: _o1heap_ins{o1heapInit(heap_ptr, heap_size)}
, _canard_hdl{canardInit(Node::o1heap_allocate, Node::o1heap_free)}
, _micros_func{micros_func}
, _canard_tx_queue{canardTxInit(tx_queue_capacity, mtu_bytes)}
, _canard_rx_queue{rx_queue_capacity}
{
  _canard_hdl.node_id = node_id;
  _canard_hdl.user_reference = static_cast<void *>(_o1heap_ins);
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

void Node::spinSome(CanFrameTxFunc const tx_func)
{
  processRxQueue();
  processTxQueue(tx_func);
}

void Node::onCanFrameReceived(CanardFrame const & frame, CanardMicrosecond const & rx_timestamp_us)
{
  uint32_t const extended_can_id = frame.extended_can_id;
  size_t   const payload_size    = frame.payload_size;

  std::array<uint8_t, 8> payload{};
  memcpy(payload.data(), frame.payload, std::min(payload_size, payload.size()));

  _canard_rx_queue.enqueue(std::make_tuple(extended_can_id, payload_size, payload, rx_timestamp_us));
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

  _canard_subscription_map.erase(port_id);
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
  while (!_canard_rx_queue.isEmpty())
  {
    auto [extended_can_id, payload_size, payload, rx_timestamp_us] = _canard_rx_queue.dequeue();

    CanardFrame frame;
    frame.extended_can_id = extended_can_id;
    frame.payload_size = payload_size;
    frame.payload = reinterpret_cast<const void *>(payload.data());

    CanardRxTransfer transfer;
    int8_t const result = canardRxAccept(&_canard_hdl,
                                        rx_timestamp_us,
                                        &frame,
                                        0, /* redundant_transport_index */
                                        &transfer,
                                        nullptr);

    if(result == 1)
    {
      auto const sub_citer = _canard_subscription_map.find(transfer.metadata.port_id);
      if (sub_citer == std::end(_canard_subscription_map))
        continue;

      auto const sub_ptr = sub_citer->second;
      if (sub_ptr->canard_transfer_kind() != transfer.metadata.transfer_kind)
        continue;

      sub_ptr->onTransferReceived(transfer);

      /* Free dynamically allocated memory after processing. */
      _canard_hdl.memory_free(&_canard_hdl, transfer.payload);

        /*
        if (transfer.metadata.transfer_kind == CanardTransferKindResponse) {
          if ((_tx_transfer_map.count(transfer.metadata.port_id) > 0) && (_tx_transfer_map[transfer.metadata.port_id] == transfer.metadata.transfer_id))
          {
            transfer_received_func(transfer, *this);
            unsubscribe(CanardTransferKindResponse, transfer.metadata.port_id);
          }
        }
        else
          transfer_received_func(transfer, *this);
          */
    }
  }
}

void Node::processTxQueue(CanFrameTxFunc const tx_func)
{
  for(CanardTxQueueItem * tx_queue_item = const_cast<CanardTxQueueItem *>(canardTxPeek(&_canard_tx_queue));
      tx_queue_item != nullptr;
      tx_queue_item = const_cast<CanardTxQueueItem *>(canardTxPeek(&_canard_tx_queue)))
  {
    /* Discard the frame if the transmit deadline has expired. */
    if (tx_queue_item->tx_deadline_usec > _micros_func()) {
      _canard_hdl.memory_free(&_canard_hdl, canardTxPop(&_canard_tx_queue, tx_queue_item));
      continue;
    }

    /* Attempt to transmit the frame via CAN. */
    if (tx_func(tx_queue_item->frame)) {
      _canard_hdl.memory_free(&_canard_hdl, canardTxPop(&_canard_tx_queue, tx_queue_item));
      continue;
    }

    return;
  }
}
