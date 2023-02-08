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
#include <unistd.h> /* close */

#include <mutex>
#include <chrono>
#include <thread>
#include <atomic>
#include <iostream>

#include <cyphal++/cyphal++.h>

#include "socketcan.h"

/**************************************************************************************
 * CONSTANT
 **************************************************************************************/

static CanardPortID const DEFAULT_COUNTER_PORT_ID = 1001U;
static uint16_t const DEFAULT_TEMPERATURE_UPDATE_PERIOD_ms = 5*1000UL;

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef uavcan::primitive::scalar::Integer8_1_0 CounterMsg;

/**************************************************************************************
 * FUNCTION DECLARATION
 **************************************************************************************/

extern "C" CanardMicrosecond micros();
extern "C" unsigned long millis();

/**************************************************************************************
 * MAIN
 **************************************************************************************/

int main(int argc, char ** argv)
{
  int const socket_can_fd = socketcanOpen("vcan0", false);
  if (socket_can_fd < 0) {
    std::cerr << "Error opening CAN interface 'vcan0'" << std::endl;
    return EXIT_FAILURE;
  }

  Node::Heap<Node::DEFAULT_O1HEAP_SIZE> node_heap;
  Node node_hdl(node_heap.data(), node_heap.size(), micros, [socket_can_fd] (CanardFrame const & frame) { return (socketcanPush(socket_can_fd, &frame, 1000*1000UL) > 0); });
  std::mutex node_mtx;

  Publisher<uavcan::node::Heartbeat_1_0> heartbeat_pub = node_hdl.create_publisher<uavcan::node::Heartbeat_1_0>
    (uavcan::node::Heartbeat_1_0::FixedPortId, 1*1000*1000UL /* = 1 sec in usecs. */);

  Publisher<CounterMsg> counter_pub = node_hdl.create_publisher<CounterMsg>
    (DEFAULT_COUNTER_PORT_ID, 1*1000*1000UL /* = 1 sec in usecs. */);

  /* REGISTER ***************************************************************************/

  RegisterList reg_list(node_hdl, micros);
  auto reg_rw_node_id = reg_list.create_ro<uavcan::primitive::array::Natural8_1_0>
    ("cyphal.node.id",
     [&node_hdl]()
     {
        return uavcan::primitive::array::Natural8_1_0{{node_hdl.getNodeId()}};
     });
  auto reg_ro_node_description = reg_list.create_ro<uavcan::primitive::String_1_0>
    ("cyphal.node.description",
     []()
     {
        return vla::to_String_1_0("basic-cyphal-node");
     });
  auto reg_rw_pub_temperature_id = reg_list.create_ro<uavcan::primitive::array::Natural16_1_0>
    ("cyphal.pub.temperature.id",
     []()
     {
        return uavcan::primitive::array::Natural16_1_0{{DEFAULT_COUNTER_PORT_ID}};
     });
  auto reg_ro_pub_temperature_type = reg_list.create_ro<uavcan::primitive::String_1_0>
    ("cyphal.pub.temperature.type",
     []()
     {
        return vla::to_String_1_0("uavcan.primitive.scalar.Integer8.1.0");
     });
  auto reg_rw_pub_temperature_update_period_ms = reg_list.create_ro<uavcan::primitive::array::Natural16_1_0>
    ("cyphal.pub.temperature.update_period_ms",
     []()
     {
       return uavcan::primitive::array::Natural16_1_0{{DEFAULT_TEMPERATURE_UPDATE_PERIOD_ms}};
     });

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

  std::atomic<bool> rx_thread_active{false};
  std::thread rx_thread(
    [&rx_thread_active, &node_hdl, &node_mtx, socket_can_fd]()
    {
      rx_thread_active = true;
      while (rx_thread_active)
      {
        CanardFrame rx_frame;
        uint8_t payload_buffer[CANARD_MTU_CAN_CLASSIC] = {0};

        int16_t const rc = socketcanPop(socket_can_fd, &rx_frame, sizeof(payload_buffer), payload_buffer, CANARD_DEFAULT_TRANSFER_ID_TIMEOUT_USEC, nullptr);
        if (rc < 0)
          std::cerr << "socketcanPop failed with error " << strerror(abs(rc)) << std::endl;
        else if (rc > 0) {
          std::lock_guard<std::mutex> lock(node_mtx);
          node_hdl.onCanFrameReceived(rx_frame);
        }

      }
    });

  /* MAIN LOOP **************************************************************************/

  auto prev_heartbeat = millis();
  auto prev_counter = millis();

  CounterMsg counter_msg;
  counter_msg.value = 0;

  for (;;)
  {
    {
      std::lock_guard<std::mutex> lock(node_mtx);
      node_hdl.spinSome();
    }

    auto const now = millis();

    if ((now - prev_heartbeat) > 1000UL)
    {
      prev_heartbeat = now;

      uavcan::node::Heartbeat_1_0 msg;

      msg.uptime = now / 1000;
      msg.health.value = uavcan::node::Health_1_0::NOMINAL;
      msg.mode.value = uavcan::node::Mode_1_0::OPERATIONAL;
      msg.vendor_specific_status_code = 0;

      heartbeat_pub->publish(msg);
    }

    if ((now - prev_counter) > reg_rw_pub_temperature_update_period_ms->value()[0])
    {
      prev_counter = now;
      counter_pub->publish(counter_msg);
      counter_msg.value++;
    }
  }

  rx_thread_active = false;
  rx_thread.join();

  close(socket_can_fd);

  return EXIT_SUCCESS;
}

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

CanardMicrosecond micros()
{
  ::timespec ts{};
  if (0 != clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts))
  {
    std::cerr << "CLOCK_PROCESS_CPUTIME_ID" << std::endl;
    std::abort();
  }
  auto const nsec = (ts.tv_sec * 1000*1000*1000UL) + ts.tv_nsec;
  return static_cast<CanardMicrosecond>(nsec / 1000UL);
}

unsigned long millis()
{
  return micros() / 1000;
}
