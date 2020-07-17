/**
 * @brief   Arduino library for providing a convenient C++ interface for accessing UAVCAN.
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

#include "ArduinoO1Heap.h"
#include "libcanard/canard.h"

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef std::function<unsigned long()> MicroSecondFunc;
typedef std::function<bool(uint32_t const, uint8_t const *, uint8_t const)> CanFrameTransmitFunc;

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class ArduinoUAVCAN
{
public:

  static int constexpr ERROR = -1;

  ArduinoUAVCAN(uint8_t const node_id,
                MicroSecondFunc micros,
                CanFrameTransmitFunc transmit_func);


  void onCanFrameReceived(uint32_t const id, uint8_t const * data, uint8_t const len);
  bool transmitCanFrame();


  bool subscribe(CanardPortID const port_id, size_t const payload_size_max, std::function<void(CanardTransfer const &)> func);

  template <typename T>
  int publish(T const & msg);


private:

  typedef struct
  {
    CanardRxSubscription canard_rx_sub;
    std::function<void(CanardTransfer const &)> transfer_complete_callback;
  } RxSubscriptionData;

  ArduinoO1Heap _o1heap;
  CanardInstance _canard_ins;
  MicroSecondFunc _micros;
  CanFrameTransmitFunc _transmit_func;
  std::map<CanardPortID, RxSubscriptionData> _rx_sub_map;
  std::map<CanardPortID, uint8_t> _tx_pub_transfer_id_map;

  static void * o1heap_allocate(CanardInstance * const ins, size_t const amount);
  static void   o1heap_free    (CanardInstance * const ins, void * const pointer);

  static void convertToCanardFrame(unsigned long const rx_timestamp_us, uint32_t const id, uint8_t const * data, uint8_t const len, CanardFrame & frame);

  bool subscribe  (CanardPortID const port_id, size_t const payload_size_max, CanardRxSubscription * canard_rx_sub);
  bool unsubscribeMessage(CanardPortID const port_id);
  int  publish           (CanardTransferKind const transfer_kind, CanardPortID const port_id, size_t const payload_size, void * payload);

};

/**************************************************************************************
 * TEMPLATE SOURCE FILE
 **************************************************************************************/

#include "ArduinoUAVCAN.ipp"

#endif /* ARDUINO_UAVCAN_H_ */
