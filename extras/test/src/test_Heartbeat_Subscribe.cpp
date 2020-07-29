/**
 * @brief   Test code for testing 107-Arduino-UAVCAN.
 * @license LGPL 3.0
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <vector>

#include <catch.hpp>

#include <test/util/Const.h>
#include <test/util/Types.h>
#include <test/util/micros.h>

#include <ArduinoUAVCAN.h>
#include <types/uavcan/node/Heartbeat.1.0.h>

/**************************************************************************************
 * PRIVATE GLOBAL VARIABLES
 **************************************************************************************/

static uint32_t              hb_uptime  = 0;
static Heartbeat_1_0::Health hb_health  = Heartbeat_1_0::Health::NOMINAL;
static Heartbeat_1_0::Mode   hb_mode    = Heartbeat_1_0::Mode::OPERATIONAL;
static uint32_t              hb_vssc    = 0;
static CanardNodeID          hb_node_id = 0;

/**************************************************************************************
 * PRIVATE FUNCTION DEFINITION
 **************************************************************************************/

void onHeatbeat_1_0_Received(CanardTransfer const & transfer, ArduinoUAVCAN & /* uavcan */)
{
  Heartbeat_1_0 const hb = Heartbeat_1_0::create(transfer);

  hb_node_id = transfer.remote_node_id;
  hb_uptime  = hb.uptime();
  hb_health  = hb.health();
  hb_mode    = hb.mode();
  hb_vssc    = hb.vssc();
}

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE("A '32085.Heartbeat.1.0.uavcan' message is received", "[heatbeat-subscribe-01]")
{
  ArduinoUAVCAN uavcan(util::LOCAL_NODE_ID, util::micros, nullptr);

  REQUIRE(uavcan.subscribe(Heartbeat_1_0::PORT_ID, Heartbeat_1_0::MAX_PAYLOAD_SIZE, onHeatbeat_1_0_Received));

  /* Create:
   *   pyuavcan publish 32085.uavcan.node.Heartbeat.1.0 '{uptime: 1337, health: 2, mode: 7, vendor_specific_status_code: 42}' --tr='CAN(can.media.socketcan.SocketCANMedia("vcan0",8),59)'
   *
   * Capture:
   *   sudo modprobe vcan
   *   sudo ip link add dev vcan0 type vcan
   *   sudo ip link set up vcan0
   *   candump -decaxta vcan0
   */
  uint8_t const data[] = {0x39, 0x05, 0x00, 0x00, 0x5E, 0x05, 0x00, 0xE1};
  uavcan.onCanFrameReceived(0x107D553B, data, 8);

  REQUIRE(hb_node_id == 59);
  REQUIRE(hb_uptime  == 1337);
  REQUIRE(hb_health  == Heartbeat_1_0::Health::CAUTION);
  REQUIRE(hb_mode    == Heartbeat_1_0::Mode::OFFLINE);
  REQUIRE(hb_vssc    == 42);
}
