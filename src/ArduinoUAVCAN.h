/**
 * @brief   Arduino library for controlling the Zubax Orel 20.
 * @license MIT
 */

#ifndef ARDUINO_UAVCAN_H_
#define ARDUINO_UAVCAN_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#undef max
#undef min
#include <map>
#include <memory>
#include <functional>

#include <ArduinoO1Heap.h>

#include <libcanard/canard.h>

#include <transfer/uavcan/node/Heartbeat.1.0.h>

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef std::function<unsigned long()> MicroSecondFunc;

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class ArduinoUAVCAN
{
public:

  ArduinoUAVCAN(uint8_t const node_id,
                MicroSecondFunc micros);


  void onCanFrameReceived(uint32_t const id, uint8_t const * data, uint8_t const len);


  bool subscribe_Heartbeat_1_0(OnHeartbeat_1_0_ReceivedFunc func);


private:

  ArduinoO1Heap _o1heap;
  CanardInstance _canard_ins;
  MicroSecondFunc _micros;
  std::map<CanardPortID, std::shared_ptr<CanardRxSubscription>> _rx_subscription_map;
  OnHeartbeat_1_0_ReceivedFunc _on_heartbeat_1_0_func;

  static void * o1heap_allocate(CanardInstance * const ins, size_t const amount);
  static void   o1heap_free    (CanardInstance * const ins, void * const pointer);

  static void convertToCanardFrame(unsigned long const rx_timestamp_us, uint32_t const id, uint8_t const * data, uint8_t const len, CanardFrame & frame);

  bool subscribeMessage  (CanardPortID const port_id, size_t const payload_size_max);
  bool unsubscribeMessage(CanardPortID const port_id);

};

#endif /* ARDUINO_UAVCAN_H_ */
