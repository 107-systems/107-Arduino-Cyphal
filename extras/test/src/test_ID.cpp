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

static CanardPortID const ID_PORT_ID = 1337;

/**************************************************************************************
 * PRIVATE GLOBAL VARIABLES
 **************************************************************************************/

static util::CanFrame can_frame;
static uavcan_node_ID_1_0 id;
static CanardNodeID id_node_id = 0;

/**************************************************************************************
 * PRIVATE FUNCTION DEFINITION
 **************************************************************************************/

static bool transmitCanFrame(uint32_t const id, uint8_t const * data, uint8_t const len)
{
  util::CanFrame frame{id, std::vector<uint8_t>(data, data + len)};
  can_frame = frame;
  return true;
}

void onID_1_0_Received(CanardTransfer const & transfer, ArduinoUAVCAN & /* uavcan */)
{
  ID_1_0<ID_PORT_ID> const received_id = ID_1_0<ID_PORT_ID>::create(transfer);

  id_node_id = transfer.remote_node_id;
  id.value = received_id.data.value;
}

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE("A 'ID.1.0.uavcan' message is sent", "[id-01]")
{
  ArduinoUAVCAN uavcan(util::LOCAL_NODE_ID, util::micros, transmitCanFrame);

  ID_1_0<ID_PORT_ID> id(65);
  uavcan.publish(id);
  uavcan.transmitCanFrame();
  /*
   * pyuavcan publish 1337.uavcan.node.ID.1.0 '{value: 65}' --tr='CAN(can.media.socketcan.SocketCANMedia("vcan0",8),13)'
   */
  REQUIRE(can_frame.id   == 0x1005390D);
  REQUIRE(can_frame.data == std::vector<uint8_t>{0x41, 0x00, 0xE0});
}

TEST_CASE("A 'ID.1.0.uavcan' message is received", "[id-02]")
{
  uavcan_node_ID_1_0_init(&id);
  ArduinoUAVCAN uavcan(util::LOCAL_NODE_ID, util::micros, transmitCanFrame);

  REQUIRE(uavcan.subscribe<ID_1_0<ID_PORT_ID>>(onID_1_0_Received));
  /*
   * pyuavcan publish 1337.uavcan.node.ID.1.0 '{value: 13}' --tr='CAN(can.media.socketcan.SocketCANMedia("vcan0",8),27)'
   */
  uint8_t const data[] = {0x0D, 0x00, 0xE0};
  uavcan.onCanFrameReceived(0x1005391B, data, sizeof(data));

  REQUIRE(id_node_id == 27);
  REQUIRE(id.value == 13);
}
