/**
 * @brief   Test code for testing 107-Arduino-UAVCAN.
 * @license LGPL 3.0
 */

#ifndef TEST_UTIL_ON_TRANSFER_RECEIVED_H_
#define TEST_UTIL_ON_TRANSFER_RECEIVED_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <ArduinoUAVCAN.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace util
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class Transfer
{

public:

  Transfer();

  OnTransferReceivedFunc onTransferReceived();

  bool received() const;
  CanardTransfer & operator()();


private:

  bool _transfer_received;
  CanardTransfer _transfer;

  void internalOnTransferReceived(CanardTransfer & transfer);

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* util */

#endif /* TEST_UTIL_ON_TRANSFER_RECEIVED_H_ */
