/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <cstdlib>

#include <chrono>

#include <SocketCAN.h>
#include <107-Arduino-Cyphal.h>

/**************************************************************************************
 * CONSTANT
 **************************************************************************************/

static CanardPortID const COUNTER_PORT_ID = 1001U;

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef uavcan::primitive::scalar::Integer8_1_0<COUNTER_PORT_ID> CounterMsg;

/**************************************************************************************
 * FUNCTION DECLARATION
 **************************************************************************************/

extern "C" CanardMicrosecond micros();

/**************************************************************************************
 * MAIN
 **************************************************************************************/

int main(int argc, char ** argv)
{
  Node::Heap<Node::DEFAULT_O1HEAP_SIZE> node_heap;
  Node node_hdl(node_heap.data(), node_heap.size(), micros);

  Publisher<uavcan::node::Heartbeat_1_0<>> heartbeat_pub = node_hdl.create_publisher<uavcan::node::Heartbeat_1_0<>>
    (uavcan::node::Heartbeat_1_0<>::PORT_ID, 1*1000*1000UL /* = 1 sec in usecs. */);

  Publisher<CounterMsg> counter_pub = node_hdl.create_publisher<CounterMsg>
    (COUNTER_PORT_ID, 1*1000*1000UL /* = 1 sec in usecs. */);

  /* REGISTER ***************************************************************************/

  uint16_t temperature_update_period_ms = 5*1000;

  RegisterNatural8  reg_rw_node_id                         ("cyphal.node.id",                          Register::Access::ReadWrite, Register::Persistent::No, node_hdl.getNodeId(), [&node_hdl](uint8_t const & val) { node_hdl.setNodeId(val); });
  RegisterString    reg_ro_node_description                ("cyphal.node.description",                 Register::Access::ReadWrite, Register::Persistent::No, "basic-cyphal-node");
  RegisterNatural16 reg_ro_pub_temperature_id              ("cyphal.pub.temperature.id",               Register::Access::ReadOnly,  Register::Persistent::No, COUNTER_PORT_ID);
  RegisterString    reg_ro_pub_temperature_type            ("cyphal.pub.temperature.type",             Register::Access::ReadOnly,  Register::Persistent::No, "uavcan.primitive.scalar.Integer8.1.0");
  RegisterNatural16 reg_rw_pub_temperature_update_period_ms("cyphal.pub.temperature.update_period_ms", Register::Access::ReadWrite, Register::Persistent::No, temperature_update_period_ms, nullptr, nullptr , [](uint16_t const & val) { return std::min(val, static_cast<uint16_t>(10*1000UL)); });

  RegisterList      reg_list(node_hdl);

  reg_list.add(reg_rw_node_id);
  reg_list.add(reg_ro_node_description);
  reg_list.add(reg_ro_pub_temperature_id);
  reg_list.add(reg_ro_pub_temperature_type);

  /* NODE INFO **************************************************************************/

  NodeInfo node_info
  (
    node_hdl,
    /* uavcan.node.Version.1.0 protocol_version */
    1, 0,
    /* uavcan.node.Version.1.0 hardware_version */
    1, 0,
    /* uavcan.node.Version.1.0 software_version */
    0, 1,
    /* saturated uint64 software_vcs_revision_id */
    0,
    /* saturated uint8[16] unique_id */
    std::array<uint8_t, 16>{0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F},
    /* saturated uint8[<=50] name */
    "107-systems.basic-cyphal-node"
  );

  SocketCAN socket_can("can0", SocketCAN::Protocol::Classic);

  /* MAIN LOOP **************************************************************************/

  auto prev_heartbeat = micros();
  auto prev_counter = micros();

  CounterMsg counter_msg;
  counter_msg.data.value = 0;

  for (;;)
  {
    node_hdl.spinSome([&socket_can] (CanardFrame const & frame) { return (socket_can.push(&frame, 1000*1000UL) > 0); });

    auto const now = micros();

    if ((now - prev_heartbeat) > (1000*1000UL))
    {
      prev_heartbeat = now;

      uavcan::node::Heartbeat_1_0<> msg;

      msg.data.uptime = now / 1000;
      msg.data.health.value = uavcan_node_Health_1_0_NOMINAL;
      msg.data.mode.value = uavcan_node_Mode_1_0_OPERATIONAL;
      msg.data.vendor_specific_status_code = 0;

      heartbeat_pub->publish(msg);
    }

    if ((now - prev_counter) > (temperature_update_period_ms * 1000UL))
    {
      prev_counter = now;
      counter_pub->publish(counter_msg);
      counter_msg.data.value++;
    }
  }

  return EXIT_SUCCESS;
}

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

CanardMicrosecond micros()
{
  static auto const start = std::chrono::high_resolution_clock::now();
  auto const now = std::chrono::high_resolution_clock::now();
  auto const duration_since_app_start_us = std::chrono::duration_cast<std::chrono::microseconds>(now - start);
  return duration_since_app_start_us.count();
}
