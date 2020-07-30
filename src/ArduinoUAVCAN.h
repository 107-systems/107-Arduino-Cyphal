/**
 * @brief   Arduino library for providing a convenient C++ interface for accessing UAVCAN.
 * @license MIT
 */

#ifndef ARDUINO_UAVCAN_H_
#define ARDUINO_UAVCAN_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <stdint.h>

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
class ArduinoUAVCAN;
typedef std::function<void(CanardTransfer const &, ArduinoUAVCAN &)> OnTransferReceivedFunc;
typedef std::function<bool(uint32_t const, uint8_t const *, uint8_t const)> CanFrameTransmitFunc;

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class ArduinoUAVCAN
{
public:

  ArduinoUAVCAN(uint8_t const node_id,
                MicroSecondFunc micros,
                CanFrameTransmitFunc transmit_func);


  /* Must be called from the application upon the
   * reception of a can frame.
   */
  void onCanFrameReceived(uint32_t const id, uint8_t const * data, uint8_t const len);
  /* Must be called regularly from within the application
   * in order to transmit all CAN pushed on the internal
   * stack via publish/request.
   */
  bool transmitCanFrame();


  template <typename T>                     bool subscribe       (OnTransferReceivedFunc func);

  /* publish/subscribe API for "message" data exchange paradigm */
  template <typename T_MSG>                 bool publish         (T_MSG const & msg);

  /* request/response API for "service" data exchange paradigm */
  template <typename T_RSP>                 bool respond         (T_RSP const & rsp, CanardNodeID const remote_node_id, CanardTransferID const transfer_id);
  template <typename T_REQ, typename T_RSP> bool request         (T_REQ const & req, CanardNodeID const remote_node_id, OnTransferReceivedFunc func);


private:

  typedef struct
  {
    CanardRxSubscription canard_rx_sub;
    OnTransferReceivedFunc transfer_complete_callback;
  } RxTransferData;

  ArduinoO1Heap _o1heap;
  CanardInstance _canard_ins;
  MicroSecondFunc _micros;
  CanFrameTransmitFunc _transmit_func;
  std::map<CanardPortID, RxTransferData> _rx_transfer_map;
  std::map<CanardPortID, CanardTransferID> _tx_transfer_map;

  static void * o1heap_allocate(CanardInstance * const ins, size_t const amount);
  static void   o1heap_free    (CanardInstance * const ins, void * const pointer);

  static void convertToCanardFrame(unsigned long const rx_timestamp_us, uint32_t const id, uint8_t const * data, uint8_t const len, CanardFrame & frame);

  bool   subscribe     (CanardTransferKind const transfer_kind, CanardPortID const port_id, size_t const payload_size_max, OnTransferReceivedFunc func);
  bool   unsubscribe   (CanardPortID const port_id);
  bool   enqeueTransfer(CanardNodeID const remote_node_id, CanardTransferKind const transfer_kind, CanardPortID const port_id, size_t const payload_size, void * payload, CanardTransferID * transfer_id);

};

/**************************************************************************************
 * TEMPLATE SOURCE FILE
 **************************************************************************************/

#include "ArduinoUAVCAN.ipp"

#endif /* ARDUINO_UAVCAN_H_ */
