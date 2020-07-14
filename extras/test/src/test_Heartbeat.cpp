/**
 * @brief   Test code for testing 107-Arduino-UAVCAN.
 * @license LGPL 3.0
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <vector>

#include <catch.hpp>

#include <test/util/Time.h>

#include <ArduinoUAVCAN.h>
#include <transfer/uavcan/node/Heartbeat.1.0.h>

#include <iostream>

/**************************************************************************************
 * PRIVATE GLOBAL VARIABLES
 **************************************************************************************/

static uint32_t              hb_uptime  = 0;
static Heartbeat_1_0::Health hb_health  = Heartbeat_1_0::Health::NOMINAL;
static Heartbeat_1_0::Mode   hb_mode    = Heartbeat_1_0::Mode::OPERATIONAL;
static uint32_t              hb_vssc    = 0;
static CanardNodeID          hb_node_id = 0;

static uint32_t              can_rx_id  = 0;
static std::vector<uint8_t>  can_rx_data;

/**************************************************************************************
 * PRIVATE FUNCTION DEFINITION
 **************************************************************************************/

static bool transmitCanFrame(uint32_t const id, uint8_t const * data, uint8_t const len)
{
/*
  std::cout << "[" << std::hex << id << std::dec << "] ";
  std::for_each(data,
                data+len,
                [](uint8_t const d)
                {
                  std::cout << std::hex << (int)d << std::dec << " ";
                });
  std::cout << std::endl;
*/
  can_rx_id = id;
  can_rx_data = std::vector<uint8_t>(data, data + len);

  return true;
}

void onHeatbeat_1_0_Received(CanardTransfer const & transfer)
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

TEST_CASE("A '32085.Heartbeat.1.0.uavcan' transfer is received", "[heatbeat-01]")
{
  util::Time time_util;

  ArduinoUAVCAN uavcan(13, time_util.micros(), transmitCanFrame);

  REQUIRE(uavcan.subscribe(32085, 7, onHeatbeat_1_0_Received));

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

  REQUIRE(hb_node_id == 59);
  REQUIRE(hb_uptime  == 1337);
  REQUIRE(hb_health  == Heartbeat_1_0::Health::CAUTION);
  REQUIRE(hb_mode    == Heartbeat_1_0::Mode::OFFLINE);
  REQUIRE(hb_vssc    == 0);
}

TEST_CASE("A '32085.Heartbeat.1.0.uavcan' transfer is sent", "[heatbeat-02]")
{
  util::Time time_util;

  ArduinoUAVCAN uavcan(13, time_util.micros(), transmitCanFrame);

  Heartbeat_1_0 hb(9876, Heartbeat_1_0::Health::NOMINAL, Heartbeat_1_0::Mode::SOFTWARE_UPDATE, 5);

  WHEN("A heartbeat message is published")
  {
    REQUIRE(uavcan.publish(32085, hb) == true);

    REQUIRE(uavcan.transmitCanFrame() == true);

    REQUIRE(can_rx_id   == 0x107D550D);
    REQUIRE(can_rx_data == std::vector<uint8_t>{0x94, 0x26, 0x00, 0x00, 0xAC, 0x00, 0x00, 0xE0});
  }
}
