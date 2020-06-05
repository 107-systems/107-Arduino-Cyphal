/**
 * @brief   Arduino library for controlling the Zubax Orel 20.
 * @license MIT
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "ArduinoUAVCAN.h"

#include <assert.h>

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

ArduinoUAVCAN::ArduinoUAVCAN(uint8_t const node_id,
                             MicroSecondFunc micros)
: _canard_ins{canardInit(ArduinoUAVCAN::o1heap_allocate, ArduinoUAVCAN::o1heap_free)}
, _micros{micros}
, _on_heartbeat_1_0_func{nullptr}
{
  assert(_micros != nullptr);

  _canard_ins.node_id = node_id;
  _canard_ins.mtu_bytes = CANARD_MTU_CAN_CLASSIC;
  _canard_ins.user_reference = reinterpret_cast<void *>(&_o1heap);
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

void ArduinoUAVCAN::onCanFrameReceived(uint32_t const id, uint8_t const * data, uint8_t const len)
{
  CanardFrame frame;
  convertToCanardFrame(_micros(), id, data, len, frame);

  CanardTransfer transfer;
  int8_t const result = canardRxAccept(&_canard_ins,
                                       &frame,
                                       0,
                                       &transfer);

  if(result == 1)
  {
    if(transfer.port_id == 32085 && _on_heartbeat_1_0_func)
    {
      _on_heartbeat_1_0_func(transfer.remote_node_id, (transfer));
    }
    _o1heap.free(const_cast<void *>(transfer.payload));
  }
}

bool ArduinoUAVCAN::subscribe_Heartbeat_1_0(OnHeartbeat_1_0_ReceivedFunc func)
{
  _on_heartbeat_1_0_func = func;
  return subscribeMessage(32085, 8);
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

bool ArduinoUAVCAN::subscribeMessage(CanardPortID const port_id, size_t const payload_size_max)
{
  /* Create new rx subscription instance and keep it in internal list
   * in order to prevent it from being deleted once 'rx_subscription'
   * goes out of scope.
   */
  std::shared_ptr<CanardRxSubscription> rx_subscription = std::make_shared<CanardRxSubscription>();
  _rx_subscription_map[port_id] = rx_subscription;

  int8_t const result = canardRxSubscribe(&_canard_ins,
                                          CanardTransferKindMessage,
                                          port_id,
                                          payload_size_max,
                                          CANARD_DEFAULT_TRANSFER_ID_TIMEOUT_USEC,
                                          rx_subscription.get());
  bool const success = (result >= 0);
  return success;
}

bool ArduinoUAVCAN::unsubscribeMessage(CanardPortID const port_id)
{
  int8_t const result = canardRxUnsubscribe(&_canard_ins,
                                            CanardTransferKindMessage,
                                            port_id);

  /* Remove CanardRxSubscription instance from internal list since the
   * structure is no longed needed.
   */
  _rx_subscription_map.erase(port_id);

  bool const success = (result >= 0);
  return success;
}
