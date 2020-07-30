/**
 * @brief   Arduino library for providing a convenient C++ interface for accessing UAVCAN.
 * @license MIT
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "ArduinoUAVCAN.h"

#include <assert.h>

/**************************************************************************************
 * STATIC CONSTEXPR DEFINITION
 **************************************************************************************/

constexpr int8_t ArduinoUAVCAN::ERROR;

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

ArduinoUAVCAN::ArduinoUAVCAN(uint8_t const node_id,
                             MicroSecondFunc micros,
                             CanFrameTransmitFunc transmit_func)
: _canard_ins{canardInit(ArduinoUAVCAN::o1heap_allocate, ArduinoUAVCAN::o1heap_free)}
, _micros{micros}
, _transmit_func{transmit_func}
{
  assert(_micros != nullptr);

  _canard_ins.node_id = node_id;
  _canard_ins.mtu_bytes = CANARD_MTU_CAN_CLASSIC;
  _canard_ins.user_reference = reinterpret_cast<void *>(&_o1heap);
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/
#include <iostream>
void ArduinoUAVCAN::onCanFrameReceived(uint32_t const id, uint8_t const * data, uint8_t const len)
{
  CanardFrame frame;
  convertToCanardFrame(_micros(), id, data, len, frame);

  CanardTransfer transfer;
  int8_t const result = canardRxAccept(&_canard_ins,
                                       &frame,
                                       0,
                                       &transfer);

  std::cout << __FUNCTION__ << std::endl;
  std::cout << "result = " << (int)result << std::endl;

  if(result == 1)
  {
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "PORT ID = " << (int)transfer.port_id << std::endl;
    std::cout << "TRANSFER ID = " << (int)transfer.transfer_id << std::endl;

    if (_rx_msg_map.count(transfer.port_id) > 0)
    {
      _rx_msg_map[transfer.port_id].transfer_complete_callback(transfer, *this);
    }
    _o1heap.free(const_cast<void *>(transfer.payload));
  }
}

bool ArduinoUAVCAN::transmitCanFrame()
{
  if (!_transmit_func)
    return false;

  CanardFrame const * txf = canardTxPeek(&_canard_ins);

  if (txf == nullptr)
    return false;

  if (!_transmit_func(txf->extended_can_id, reinterpret_cast<uint8_t const *>(txf->payload), static_cast<uint8_t const>(txf->payload_size)))
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
  ArduinoO1Heap * o1heap = reinterpret_cast<ArduinoO1Heap *>(ins->user_reference);
  return o1heap->allocate(amount);
}

void ArduinoUAVCAN::o1heap_free(CanardInstance * const ins, void * const pointer)
{
  ArduinoO1Heap * o1heap = reinterpret_cast<ArduinoO1Heap *>(ins->user_reference);
  o1heap->free(pointer);
}

void ArduinoUAVCAN::convertToCanardFrame(unsigned long const rx_timestamp_us, uint32_t const id, uint8_t const * data, uint8_t const len, CanardFrame & frame)
{
  /* Get the reception timestamp */
  frame.timestamp_usec = rx_timestamp_us;
  /* Blank the 3 MSBits */
  frame.extended_can_id = id & 0x1FFFFFFF;
  /* Set the length */
  frame.payload_size = static_cast<size_t>(len);
  /* Set pointer to data */
  frame.payload = reinterpret_cast<const void *>(data);
}

bool ArduinoUAVCAN::subscribe(CanardTransferKind const transfer_kind, CanardPortID const port_id, size_t const payload_size_max, OnTransferReceivedFunc func)
{
  std::cout << __FUNCTION__ << std::endl;
  std::cout << "transfer_kind = " << (int)transfer_kind << std::endl;
  std::cout << "port_id = " << (int)port_id << std::endl;
  _rx_msg_map[port_id].transfer_complete_callback = func;
  int8_t const result = canardRxSubscribe(&_canard_ins,
                                          transfer_kind,
                                          port_id,
                                          payload_size_max,
                                          CANARD_DEFAULT_TRANSFER_ID_TIMEOUT_USEC,
                                          &(_rx_msg_map[port_id].canard_rx_sub));
  bool const success = (result >= 0);
  return success;
}

bool ArduinoUAVCAN::unsubscribe(CanardPortID const port_id)
{
  int8_t const result = canardRxUnsubscribe(&_canard_ins,
                                            CanardTransferKindMessage,
                                            port_id);

  /* Remove CanardRxSubscription instance from internal list since the
   * structure is no longed needed.
   */
  _rx_msg_map.erase(port_id);

  bool const success = (result >= 0);
  return success;
}

bool ArduinoUAVCAN::enqeueTransfer(CanardNodeID const remote_node_id, CanardTransferKind const transfer_kind, CanardPortID const port_id, size_t const payload_size, void * payload, CanardTransferID * transfer_id)
{
  CanardTransferID message_transfer_id;

  if ((transfer_kind == CanardTransferKindRequest) || (transfer_kind == CanardTransferKindMessage))
    message_transfer_id = (_tx_pub_transfer_id_map.count(port_id) > 0) ? _tx_pub_transfer_id_map[port_id] : 0;
  else /* CanardTransferKindResponse */
    message_transfer_id = *transfer_id;

  CanardTransfer const transfer =
  {
    /* .timestamp_usec = */ 0, /* No deadline on transmission */
    /* .priority       = */ CanardPriorityNominal,
    /* .transfer_kind  = */ transfer_kind,
    /* .port_id        = */ port_id,
    /* .remote_node_id = */ remote_node_id,
    /* .transfer_id    = */ message_transfer_id,
    /* .payload_size   = */ payload_size,
    /* .payload        = */ payload,
  };

  /* Store the used transfer id in case of requests. */
  if (transfer_kind == CanardTransferKindRequest)
    *transfer_id = _tx_pub_transfer_id_map[port_id];

  /* Increment message transfer id for the next message */
  if ((transfer_kind == CanardTransferKindRequest) || (transfer_kind == CanardTransferKindMessage))
    _tx_pub_transfer_id_map[port_id] = (message_transfer_id + 1) % CANARD_TRANSFER_ID_MAX;

  /* Serialize transfer into a series of CAN frames */
  int32_t result = canardTxPush(&_canard_ins, &transfer);
  bool const success = (result >= 0);
  return success;
}
