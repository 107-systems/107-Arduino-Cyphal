/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "NodeBase.hpp"

#include <cstring>

#include "util/nodeinfo/NodeInfo.hpp"
#include "util/registry/Registry.hpp"
#include "util/port/PortListPublisher.hpp"

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

NodeBase::NodeBase(MicrosFunc const micros_func,
           CanFrameTxFunc const tx_func,
           CanardNodeID const node_id,
           size_t const tx_queue_capacity,
           size_t const mtu_bytes)
: _canard_hdl{canardInit(NodeBase::heap_allocate, NodeBase::heap_free)}
, _micros_func{micros_func}
, _tx_func{tx_func}
, _canard_tx_queue{canardTxInit(tx_queue_capacity, mtu_bytes)}
, _mtu_bytes{mtu_bytes}
, _opt_port_list_pub{std::nullopt}
{
  _canard_hdl.node_id = node_id;
  _canard_hdl.user_reference = static_cast<void *>(this);

  _opt_port_list_pub = std::make_shared<impl::PortListPublisher>(*this, _micros_func);
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

#if !defined(__GNUC__) || (__GNUC__ >= 11)
Registry NodeBase::create_registry()
{
  return std::make_shared<impl::Registry>(*this, _micros_func);
}
#endif

NodeInfo NodeBase::create_node_info(uint8_t const protocol_major, uint8_t const protocol_minor,
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

void NodeBase::processPortList()
{
  if (_opt_port_list_pub.has_value())
    _opt_port_list_pub.value()->update();
}


void NodeBase::onCanFrameReceived(CanardFrame const & frame, CanardMicrosecond const rx_timestamp_usec)
{
  CanardRxTransfer rx_transfer;
  CanardRxSubscription * rx_subscription;
  int8_t const result = canardRxAccept(&_canard_hdl,
                                       rx_timestamp_usec,
                                       &frame,
                                       0, /* redundant_transport_index */
                                       &rx_transfer,
                                       &rx_subscription);

  if(result == 1)
  {
    /* Obtain the pointer to the subscribed object and in invoke its reception callback. */
    impl::SubscriptionBase * sub_ptr = static_cast<impl::SubscriptionBase *>(rx_subscription->user_reference);
    sub_ptr->onTransferReceived(rx_transfer);

    /* Free dynamically allocated memory after processing. */
    _canard_hdl.memory_free(&_canard_hdl, rx_transfer.payload);
  }
}

bool NodeBase::enqueue_transfer(CanardMicrosecond const tx_timeout_usec,
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

void NodeBase::unsubscribe(CanardPortID const port_id, CanardTransferKind const transfer_kind)
{
  canardRxUnsubscribe(&_canard_hdl,
                      transfer_kind,
                      port_id);
}

/**************************************************************************************
 * PROTECTED MEMBER FUNCTIONS
 **************************************************************************************/

void NodeBase::processTxQueue()
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