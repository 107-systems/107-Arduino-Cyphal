/**
 * @brief   Test code for testing 107-Arduino-UAVCAN.
 * @license LGPL 3.0
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch.hpp>

#include <test/util/Time.h>
#include <test/util/Transfer.h>

#include <ArduinoUAVCAN.h>

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE("")
{
  util::Time time_util;
  util::Transfer transfer_util;
  
  ArduinoUAVCAN uavcan(13, time_util.micros(), transfer_util.onTransferReceived());

  uavcan.subscribeMessage(32085, 8);

  uint8_t const data[] = {0x39, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE1};
  uavcan.onCanFrameReceived(0x107D553B, data, 8);
  
  REQUIRE(transfer_util.received());
  REQUIRE(transfer_util().port_id == 32085);
  REQUIRE(transfer_util().remote_node_id == 59);
}
