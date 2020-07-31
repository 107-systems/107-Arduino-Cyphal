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
#include <test/util/micros.h>

#include <ArduinoUAVCAN.h>
#include <types/uavcan/node/Heartbeat.1.0.h>

/**************************************************************************************
 * PRIVATE GLOBAL VARIABLES
 **************************************************************************************/

static util::CanFrame can_frame;

/**************************************************************************************
 * PRIVATE FUNCTION DEFINITION
 **************************************************************************************/

static bool transmitCanFrame(uint32_t const id, uint8_t const * data, uint8_t const len)
{
  util::CanFrame frame{id, std::vector<uint8_t>(data, data + len)};
  can_frame = frame;
  return true;
}

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE("A '32085.Heartbeat.1.0.uavcan' message is sent", "[heatbeat-publish-01]")
{
  ArduinoUAVCAN uavcan(util::LOCAL_NODE_ID, util::micros, transmitCanFrame);

  Heartbeat_1_0 hb_1(9876, Heartbeat_1_0::Health::NOMINAL, Heartbeat_1_0::Mode::SOFTWARE_UPDATE, 5);
  uavcan.publish(hb_1);
  uavcan.transmitCanFrame();
  /*
   * pyuavcan publish 32085.uavcan.node.Heartbeat.1.0 '{uptime: 9876, health: 0, mode: 3, vendor_specific_status_code: 5}' --tr='CAN(can.media.socketcan.SocketCANMedia("vcan0",8),13)'
   */
  REQUIRE(can_frame.id   == 0x107D550D);
  REQUIRE(can_frame.data == std::vector<uint8_t>{0x94, 0x26, 0x00, 0x00, 0xAC, 0x00, 0x00, 0xE0});

  Heartbeat_1_0 hb_2(9881, Heartbeat_1_0::Health::ADVISORY, Heartbeat_1_0::Mode::MAINTENANCE, 123);
  uavcan.publish(hb_2);
  uavcan.transmitCanFrame();
  /*
   * pyuavcan publish 32085.uavcan.node.Heartbeat.1.0 '{uptime: 9881, health: 1, mode: 2, vendor_specific_status_code: 123}' --tr='CAN(can.media.socketcan.SocketCANMedia("vcan0",8),13)'
   */
  REQUIRE(can_frame.id   == 0x107D550D);
  REQUIRE(can_frame.data == std::vector<uint8_t>{0x99, 0x26, 0x00, 0x00, 0x69, 0x0F, 0x00, 0xE1});
}
