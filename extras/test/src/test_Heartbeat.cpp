/**
 * @brief   Test code for testing 107-Arduino-UAVCAN.
 * @license LGPL 3.0
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <vector>

#include <catch.hpp>

#include <test/util/micros.h>

#include <ArduinoUAVCAN.h>
#include <uavcan/node/Heartbeat.1.0.h>

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

TEST_CASE("A '32085.Heartbeat.1.0.uavcan' message is received", "[heatbeat-01]")
{
  ArduinoUAVCAN uavcan(13, util::micros, transmitCanFrame);

  REQUIRE(uavcan.subscribe(Heartbeat_1_0::PORT_ID, Heartbeat_1_0::PAYLOAD_SIZE, onHeatbeat_1_0_Received));

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

TEST_CASE("A '32085.Heartbeat.1.0.uavcan' message is sent", "[heatbeat-02]")
{
  ArduinoUAVCAN uavcan(13, util::micros, transmitCanFrame);

  Heartbeat_1_0 hb_1(9876, Heartbeat_1_0::Health::NOMINAL, Heartbeat_1_0::Mode::SOFTWARE_UPDATE, 5);
  hb_1.publish(uavcan);
  uavcan.transmitCanFrame();
  /*
   * pyuavcan publish 32085.uavcan.node.Heartbeat.1.0 '{uptime: 9876, health: 0, mode: 3, vendor_specific_status_code: 5}' --tr='CAN(can.media.socketcan.SocketCANMedia("vcan0",8),13)'
   */
  REQUIRE(can_rx_id   == 0x107D550D);
  REQUIRE(can_rx_data == std::vector<uint8_t>{0x94, 0x26, 0x00, 0x00, 0xAC, 0x00, 0x00, 0xE0});

  Heartbeat_1_0 hb_2(9881, Heartbeat_1_0::Health::ADVISORY, Heartbeat_1_0::Mode::MAINTENANCE, 123);
  hb_2.publish(uavcan);
  uavcan.transmitCanFrame();
  /*
   * pyuavcan publish 32085.uavcan.node.Heartbeat.1.0 '{uptime: 9881, health: 1, mode: 2, vendor_specific_status_code: 123}' --tr='CAN(can.media.socketcan.SocketCANMedia("vcan0",8),13)'
   */
  REQUIRE(can_rx_id   == 0x107D550D);
  REQUIRE(can_rx_data == std::vector<uint8_t>{0x99, 0x26, 0x00, 0x00, 0x69, 0x0F, 0x00, 0xE1});
}
