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
typedef std::function<void(CanardTransfer const &)> OnTransferReceivedFunc;
typedef std::function<bool(uint32_t const, uint8_t const *, uint8_t const)> CanFrameTransmitFunc;

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class ArduinoUAVCAN
{
public:

  static constexpr int8_t ERROR = -1;

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


  /* This is the public API by which this library is used. */
  bool   subscribe(CanardPortID const port_id, size_t const payload_size_max, OnTransferReceivedFunc func);
  template <typename T>
  int8_t publish  (T const & msg);
  template <typename T_REQ, typename T_RESP>
  int8_t request  (T_REQ const & req, CanardNodeID const remote_node_id, OnTransferReceivedFunc func);


private:

  typedef struct
  {
    CanardRxSubscription canard_rx_sub;
    OnTransferReceivedFunc transfer_complete_callback;
  } RxSubMessageData;

  typedef struct
  {
    CanardRxSubscription canard_rx_sub;
    CanardTransferID request_transfer_id;
    OnTransferReceivedFunc transfer_complete_callback;
  } RxSubResponseData;

  ArduinoO1Heap _o1heap;
  CanardInstance _canard_ins;
  MicroSecondFunc _micros;
  CanFrameTransmitFunc _transmit_func;
  std::map<CanardPortID, RxSubMessageData> _rx_sub_msg_map;
  std::map<CanardPortID, RxSubResponseData> _rx_sub_rsp_map;
  std::map<CanardPortID, uint8_t> _tx_pub_transfer_id_map;

  static void * o1heap_allocate(CanardInstance * const ins, size_t const amount);
  static void   o1heap_free    (CanardInstance * const ins, void * const pointer);

  static void convertToCanardFrame(unsigned long const rx_timestamp_us, uint32_t const id, uint8_t const * data, uint8_t const len, CanardFrame & frame);

  bool   subscribeMessage (CanardPortID const port_id, size_t const payload_size_max, OnTransferReceivedFunc func);
  bool   subscribeResponse(CanardPortID const port_id, size_t const payload_size_max, CanardTransferID const request_transfer_id, OnTransferReceivedFunc func);
  bool   subscribe        (CanardTransferKind const transfer_kind, CanardPortID const port_id, size_t const payload_size_max, CanardRxSubscription * canard_rx_sub);
  bool   unsubscribe      (CanardPortID const port_id);
  int8_t publish          (CanardNodeID const remote_node_id, CanardTransferKind const transfer_kind, CanardPortID const port_id, size_t const payload_size, void * payload);

};

/**************************************************************************************
 * TEMPLATE SOURCE FILE
 **************************************************************************************/

#include "ArduinoUAVCAN.ipp"

#endif /* ARDUINO_UAVCAN_H_ */
