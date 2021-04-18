/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <vector>

#include <catch.hpp>

#include <test/util/Const.h>
#include <test/util/Types.h>

#include <ArduinoUAVCAN.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

using namespace uavcan::node;

/**************************************************************************************
 * PRIVATE GLOBAL VARIABLES
 **************************************************************************************/

static util::CanFrame can_frame;
static uavcan_node_Heartbeat_1_0 hb_data;
static CanardNodeID hb_node_id = 0;

/**************************************************************************************
 * PRIVATE FUNCTION DEFINITION
 **************************************************************************************/

static bool transmitCanFrame(CanardFrame const & f)
{
  util::CanFrame const frame{f.extended_can_id,
                             std::vector<uint8_t>(reinterpret_cast<uint8_t const *>(f.payload), reinterpret_cast<uint8_t const *>(f.payload) + f.payload_size)};
  can_frame = frame;
  return true;
}

static void onHeatbeat_1_0_Received(CanardTransfer const & transfer, ArduinoUAVCAN & /* uavcan */)
{
  Heartbeat_1_0 const received_hb = Heartbeat_1_0::deserialize(transfer);

  hb_node_id                          = transfer.remote_node_id;
  hb_data.uptime                      = received_hb.data.uptime;
  hb_data.health.value                = received_hb.data.health.value;
  hb_data.mode.value                  = received_hb.data.mode.value;
  hb_data.vendor_specific_status_code = received_hb.data.vendor_specific_status_code;
}

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE("A '32085.Heartbeat.1.0.uavcan' message is sent", "[heartbeat-01]")
{
  ArduinoUAVCAN uavcan(util::LOCAL_NODE_ID, transmitCanFrame);

  Heartbeat_1_0 hb(uavcan_node_Heartbeat_1_0_FIXED_PORT_ID_);
  hb.data.uptime = 9876;
  hb.data.health.value = uavcan_node_Health_1_0_NOMINAL;
  hb.data.mode.value = uavcan_node_Mode_1_0_SOFTWARE_UPDATE;
  hb.data.vendor_specific_status_code = 5;
  uavcan.publish(hb);
  while(uavcan.transmitCanFrame()) { }
  /*
   * pyuavcan publish 7509.uavcan.node.Heartbeat.1.0 '{uptime: 9876, health.value: {value: 0}, mode.value: {value: 3}, vendor_specific_status_code: 5}' --tr='CAN(can.media.socketcan.SocketCANMedia("vcan0",8),13)'
   */
  REQUIRE(can_frame.id   == 0x107D550D);
  REQUIRE(can_frame.data == std::vector<uint8_t>{0x94, 0x26, 0x00, 0x00, 0x00, 0x03, 0x05, 0xE0});

  hb.data.uptime = 9881;
  hb.data.health.value = uavcan_node_Health_1_0_ADVISORY;
  hb.data.mode.value = uavcan_node_Mode_1_0_MAINTENANCE;
  hb.data.vendor_specific_status_code = 123;
  uavcan.publish(hb);
  while(uavcan.transmitCanFrame()) { }
  /*
   * pyuavcan publish 7509.uavcan.node.Heartbeat.1.0 '{uptime: 9881, health.value: {value: 1}, mode.value: {value: 2}, vendor_specific_status_code: 123}' --tr='CAN(can.media.socketcan.SocketCANMedia("vcan0",8),13)'
   */
  REQUIRE(can_frame.id   == 0x107D550D);
  REQUIRE(can_frame.data == std::vector<uint8_t>{0x99, 0x26, 0x00, 0x00, 0x01, 0x02, 0x7B, 0xE1});
}

TEST_CASE("A '32085.Heartbeat.1.0.uavcan' message is received", "[heartbeat-02]")
{
  uavcan_node_Heartbeat_1_0_initialize_(&hb_data);
  ArduinoUAVCAN uavcan(util::LOCAL_NODE_ID, nullptr);

  REQUIRE(uavcan.subscribe<Heartbeat_1_0>(uavcan_node_Heartbeat_1_0_FIXED_PORT_ID_, onHeatbeat_1_0_Received));

  /* Create:
   *   pyuavcan publish 7509.uavcan.node.Heartbeat.1.0 '{uptime: 1337, health.value: {value: 2}, mode.value: {value: 2}, vendor_specific_status_code: 42}' --tr='CAN(can.media.socketcan.SocketCANMedia("vcan0",8),59)'
   *
   * Capture:
   *   sudo modprobe vcan
   *   sudo ip link add dev vcan0 type vcan
   *   sudo ip link set up vcan0
   *   candump -decaxta vcan0
   */
  std::vector<uint8_t> const data{0x39, 0x05, 0x00, 0x00, 0x02, 0x02, 0x2A, 0xE1};
  uavcan.onCanFrameReceived(util::toCanardFrame(0x107D553B, data));

  REQUIRE(hb_node_id                          == 59);
  REQUIRE(hb_data.uptime                      == 1337);
  REQUIRE(hb_data.health.value                == uavcan_node_Health_1_0_CAUTION);
  REQUIRE(hb_data.mode.value                  == uavcan_node_Mode_1_0_MAINTENANCE);
  REQUIRE(hb_data.vendor_specific_status_code == 42);
}
