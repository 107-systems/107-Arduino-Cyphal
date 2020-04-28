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
#include <functional>

#include <ArduinoO1Heap.h>

#include <libcanard/canard.h>

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef std::function<unsigned long()> MicroSecondFunc;
typedef std::function<void(CanardTransfer &)> OnTransferReceivedFunc;

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class ArduinoUAVCAN
{
public:

  ArduinoUAVCAN(uint8_t const node_id,
                MicroSecondFunc micros,
                OnTransferReceivedFunc on_transfer_received);


  void onCanFrameReceive(uint32_t const id, uint8_t const * data, uint8_t const len);


private:

  ArduinoO1Heap _o1heap;
  CanardInstance _canard_ins;
  MicroSecondFunc _micros;
  OnTransferReceivedFunc _on_transfer_received;

  static void * o1heap_allocate(CanardInstance * const ins, size_t const amount);
  static void   o1heap_free    (CanardInstance * const ins, void * const pointer);

  static void convertToCanardFrame(unsigned long const rx_timestamp_us, uint32_t const id, uint8_t const * data, uint8_t const len, CanardFrame & frame);

};

#endif /* ARDUINO_UAVCAN_H_ */
