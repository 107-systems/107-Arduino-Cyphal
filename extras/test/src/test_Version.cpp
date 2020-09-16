/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch.hpp>

#include <test/util/Const.h>
#include <test/util/Types.h>
#include <test/util/micros.h>

#include <ArduinoUAVCAN.h>

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

static CanardPortID const VERSION_PORT_ID = 12345;

/**************************************************************************************
 * PRIVATE GLOBAL VARIABLES
 **************************************************************************************/

static util::CanFrame can_frame;
uavcan_node_Version_1_0 version;
static CanardNodeID version_node_id = 0;

/**************************************************************************************
 * PRIVATE FUNCTION DEFINITION
 **************************************************************************************/

static bool transmitCanFrame(uint32_t const id, uint8_t const * data, uint8_t const len)
{
  util::CanFrame frame{id, std::vector<uint8_t>(data, data + len)};
  can_frame = frame;
  return true;
}

void onVersion_1_0_Received(CanardTransfer const & transfer, ArduinoUAVCAN & /* uavcan */)
{
  Version_1_0<VERSION_PORT_ID> const received_version = Version_1_0<VERSION_PORT_ID>::create(transfer);

  version_node_id = transfer.remote_node_id;
  version.major   = received_version.data.major;
  version.minor   = received_version.data.minor;
}

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE("A 'Version.1.0.uavcan' message is sent", "[version-01]")
{
  ArduinoUAVCAN uavcan(util::LOCAL_NODE_ID, util::micros, transmitCanFrame);

  Version_1_0<VERSION_PORT_ID> version;
  version.data.major = 0xCA;
  version.data.minor = 0xFE;
  uavcan.publish(version);
  uavcan.transmitCanFrame();
  /*
   * pyuavcan publish 12345.uavcan.node.Version.1.0 '{major: 0xCA, minor: 0xFE}' --tr='CAN(can.media.socketcan.SocketCANMedia("vcan0",8),13)'
   */
  REQUIRE(can_frame.id   == 0x1030390D);
  REQUIRE(can_frame.data == std::vector<uint8_t>{0xCA, 0xFE, 0xE0});
}

TEST_CASE("A 'Version.1.0.uavcan' message is received", "[version-02]")
{
  uavcan_node_Version_1_0_init(&version);
  ArduinoUAVCAN uavcan(util::LOCAL_NODE_ID, util::micros, transmitCanFrame);

  REQUIRE(uavcan.subscribe<Version_1_0<VERSION_PORT_ID>>(onVersion_1_0_Received));
  /*
   * pyuavcan publish 12345.uavcan.node.Version.1.0 '{major: 0x13, minor: 0x37}' --tr='CAN(can.media.socketcan.SocketCANMedia("vcan0",8),27)'
   */
  uint8_t const data[] = {0x13, 0x37, 0xE0};
  uavcan.onCanFrameReceived(0x1030391B, data, sizeof(data));

  REQUIRE(version_node_id == 27);
  REQUIRE(version.major == 0x13);
  REQUIRE(version.minor == 0x37);
}
