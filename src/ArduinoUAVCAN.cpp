/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "ArduinoUAVCAN.h"

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

ArduinoUAVCAN::ArduinoUAVCAN(uint8_t const node_id,
                             CanFrameTransmitFunc transmit_func)
: _canard_ins{canardInit(ArduinoUAVCAN::o1heap_allocate, ArduinoUAVCAN::o1heap_free)}
, _transmit_func{transmit_func}
{
  _canard_ins.node_id = node_id;
  _canard_ins.mtu_bytes = CANARD_MTU_CAN_CLASSIC;
  _canard_ins.user_reference = reinterpret_cast<void *>(&_o1heap);
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

void ArduinoUAVCAN::onCanFrameReceived(CanardFrame const & frame)
{
  LockGuard lock;

  CanardTransfer transfer;
  int8_t const result = canardRxAccept(&_canard_ins,
                                       &frame,
                                       0,
                                       &transfer);

  if(result == 1)
  {
    if (_rx_transfer_map.count(transfer.port_id) > 0)
    {
      OnTransferReceivedFunc transfer_received_func = _rx_transfer_map[transfer.port_id].transfer_complete_callback;

      if (transfer.transfer_kind == CanardTransferKindResponse) {
        if ((_tx_transfer_map.count(transfer.port_id) > 0) && (_tx_transfer_map[transfer.port_id] == transfer.transfer_id))
        {
          transfer_received_func(transfer, *this);
          unsubscribe(CanardTransferKindResponse, transfer.port_id);
        }
      }
      else
        transfer_received_func(transfer, *this);
    }
    _o1heap.free(const_cast<void *>(transfer.payload));
  }
}

bool ArduinoUAVCAN::transmitCanFrame()
{
  LockGuard lock;

  if (!_transmit_func)
    return false;

  CanardFrame const * txf = canardTxPeek(&_canard_ins);

  if (txf == nullptr)
    return false;

  if (!_transmit_func(*txf))
    return false;

  canardTxPop(&_canard_ins);
  _o1heap.free((void *)(txf));
  return true;
}

/**************************************************************************************
 * PRIVATE MEMBER FUNCTIONS
 **************************************************************************************/

void * ArduinoUAVCAN::o1heap_allocate(CanardInstance * const ins, size_t const amount)
{
  O1HeapLibcanard * o1heap = reinterpret_cast<O1HeapLibcanard*>(ins->user_reference);
  return o1heap->allocate(amount);
}

void ArduinoUAVCAN::o1heap_free(CanardInstance * const ins, void * const pointer)
{
  O1HeapLibcanard * o1heap = reinterpret_cast<O1HeapLibcanard*>(ins->user_reference);
  o1heap->free(pointer);
}

CanardTransferID ArduinoUAVCAN::getNextTransferId(CanardPortID const port_id)
{
  CanardTransferID const next_transfer_id = (_tx_transfer_map.count(port_id) > 0) ? ((_tx_transfer_map[port_id] + 1) % CANARD_TRANSFER_ID_MAX) : 0;
  _tx_transfer_map[port_id] = next_transfer_id;
  return next_transfer_id;
}

bool ArduinoUAVCAN::subscribe(CanardTransferKind const transfer_kind, CanardPortID const port_id, size_t const payload_size_max, OnTransferReceivedFunc func)
{
  _rx_transfer_map[port_id].transfer_complete_callback = func;
  int8_t const result = canardRxSubscribe(&_canard_ins,
                                          transfer_kind,
                                          port_id,
                                          payload_size_max,
                                          CANARD_DEFAULT_TRANSFER_ID_TIMEOUT_USEC,
                                          &(_rx_transfer_map[port_id].canard_rx_sub));
  bool const success = (result >= 0);
  return success;
}

bool ArduinoUAVCAN::unsubscribe(CanardTransferKind const transfer_kind, CanardPortID const port_id)
{
  int8_t const result = canardRxUnsubscribe(&_canard_ins,
                                            transfer_kind,
                                            port_id);

  /* Remove CanardRxSubscription instance from internal list since the
   * structure is no longed needed.
   */
  _rx_transfer_map.erase(port_id);

  bool const success = (result >= 0);
  return success;
}

bool ArduinoUAVCAN::enqeueTransfer(CanardNodeID const remote_node_id, CanardTransferKind const transfer_kind, CanardPortID const port_id, size_t const payload_size, void * payload, CanardTransferID const transfer_id)
{
  CanardTransfer const transfer =
  {
    /* .timestamp_usec = */ 0, /* No deadline on transmission */
    /* .priority       = */ CanardPriorityNominal,
    /* .transfer_kind  = */ transfer_kind,
    /* .port_id        = */ port_id,
    /* .remote_node_id = */ remote_node_id,
    /* .transfer_id    = */ transfer_id,
    /* .payload_size   = */ payload_size,
    /* .payload        = */ payload,
  };

  /* Serialize transfer into a series of CAN frames */
  int32_t result = canardTxPush(&_canard_ins, &transfer);
  bool const success = (result >= 0);
  return success;
}
