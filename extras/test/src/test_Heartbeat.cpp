/**
 * @brief   Test code for testing 107-Arduino-UAVCAN.
 * @license LGPL 3.0
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch.hpp>

#include <test/util/Time.h>

#include <ArduinoUAVCAN.h>

/**************************************************************************************
 * PRIVATE GLOBAL VARIABLES
 **************************************************************************************/

static Heartbeat_1_0::Data hb_data    = { 0, Heartbeat_1_0::Health::NOMINAL, Heartbeat_1_0::Mode::OPERATIONAL, 0};
static CanardNodeID        hb_node_id = 0;

/**************************************************************************************
 * PRIVATE FUNCTION DEFINITION
 **************************************************************************************/

void onHeatbeat_1_0_Received(CanardTransfer const & transfer)
{
  Heartbeat_1_0 hb(transfer);

  hb_node_id     = transfer.remote_node_id;
  hb_data.uptime = hb.uptime();
  hb_data.health = hb.health();
  hb_data.mode   = hb.mode();
  hb_data.vssc   = hb.vssc();
}

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE("A '32085.Heartbeat.1.0.uavcan' transfer was received", "[heatbeat-01]")
{
  util::Time time_util;

  ArduinoUAVCAN uavcan(13, time_util.micros());

  REQUIRE(uavcan.subscribe(32085, 8, onHeatbeat_1_0_Received));

  /* Create:
   *   pyuavcan publish 32085.uavcan.node.Heartbeat.1.0 '{uptime: 1337, health: 2, mode: 7}' --tr='CAN(can.media.socketcan.SocketCANMedia("vcan0",8),59)'
   *
   * Capture:
   *   sudo modprobe vcan
   *   sudo ip link add dev vcan0 type vcan
   *   sudo ip link set up vcan0
   *   candump -decaxta vcan0
   */
  uint8_t const data[] = {0x39, 0x05, 0x00, 0x00, 0x1E, 0x00, 0x00, 0xE1};
  uavcan.onCanFrameReceived(0x107D553B, data, 8);

  REQUIRE(hb_node_id     == 59);
  REQUIRE(hb_data.uptime == 1337);
  REQUIRE(hb_data.health == Heartbeat_1_0::Health::CAUTION);
  REQUIRE(hb_data.mode   == Heartbeat_1_0::Mode::OFFLINE);
  REQUIRE(hb_data.vssc   == 0);
}
