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

#include "kv_host.h"
#include "socketcan.h"

/**************************************************************************************
 * CONSTANT
 **************************************************************************************/

static uint16_t const COUNTER_UPDATE_PERIOD_ms = 5*1000UL;
static uint16_t const HEARTBEAT_UPDATE_PERIOD_ms = 1000UL;

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

  cyphal::Node::Heap<cyphal::Node::DEFAULT_O1HEAP_SIZE> node_heap;
  cyphal::Node node_hdl(node_heap.data(), node_heap.size(), micros, [socket_can_fd] (CanardFrame const & frame) { return (socketcanPush(socket_can_fd, &frame, 1000*1000UL) > 0); });
  std::mutex node_mtx;

  cyphal::Publisher<uavcan::node::Heartbeat_1_0> heartbeat_pub = node_hdl.create_publisher<uavcan::node::Heartbeat_1_0>(1*1000*1000UL /* = 1 sec in usecs. */);

  cyphal::Publisher<CounterMsg> counter_pub;

  /* REGISTER ***************************************************************************/

  CanardNodeID node_id = node_hdl.getNodeId();
  CanardPortID counter_port_id = std::numeric_limits<CanardPortID>::max();

  const auto node_registry = node_hdl.create_registry();

  const auto reg_ro_node_description             = node_registry->route ("cyphal.node.description", {true}, []() { return "basic-cyphal-node"; });
  const auto reg_ro_pub_counter_type             = node_registry->route ("cyphal.pub.counter.type", {true}, []() { return "uavcan.primitive.scalar.Integer8.1.0"; });
  const auto reg_rw_node_id                      = node_registry->expose("cyphal.node.id", {}, node_id);
  const auto reg_rw_pub_counter_id               = node_registry->expose("cyphal.pub.counter.id", {}, counter_port_id);

  /* Configure service server for storing persistent
   * states upon command request.
   */
#if __GNUC__ >= 11
  cyphal::support::platform::storage::host::KeyValueStorage kv_storage;
  auto const rc_load = cyphal::support::load(kv_storage, *node_registry);
  if (rc_load.has_value()) {
    std::cerr << "cyphal::support::load failed with " << static_cast<int>(rc_load.value()) << std::endl;
    return EXIT_FAILURE;
  }
#endif /* __GNUC__ >= 11 */

  auto weak_node_registry = std::weak_ptr<cyphal::registry::Registry>(node_registry);
  cyphal::ServiceServer execute_command_srv = node_hdl.create_service_server<
    uavcan::node::ExecuteCommand::Request_1_1,
    uavcan::node::ExecuteCommand::Response_1_1>(
    2*1000*1000UL,
    [&kv_storage, weak_node_registry](uavcan::node::ExecuteCommand::Request_1_1 const & req)
    {
      uavcan::node::ExecuteCommand::Response_1_1 rsp;

      if (req.command == uavcan::node::ExecuteCommand::Request_1_1::COMMAND_RESTART)
      {
        rsp.status = uavcan::node::ExecuteCommand::Response_1_1::STATUS_SUCCESS;
        exit(0);
      }
      else if (req.command == uavcan::node::ExecuteCommand::Request_1_1::COMMAND_STORE_PERSISTENT_STATES)
      {
#if __GNUC__ >= 11
        auto node_registry = weak_node_registry.lock();
        if (!node_registry)
        {
          std::cerr << "invalid reference to node registry" << std::endl;
          rsp.status = uavcan::node::ExecuteCommand::Response_1_1::STATUS_FAILURE;
          return rsp;
        }
        auto const rc_save = cyphal::support::save(kv_storage, *node_registry, []() { /* watchdog function */ });
        if (rc_save.has_value())
        {
          std::cerr << "cyphal::support::save failed with " << static_cast<int>(rc_save.value()) << std::endl;
          rsp.status = uavcan::node::ExecuteCommand::Response_1_1::STATUS_FAILURE;
          return rsp;
        }
#endif /* __GNUC__ >= 11 */
        rsp.status = uavcan::node::ExecuteCommand::Response_1_1::STATUS_SUCCESS;
      }
      else {
        rsp.status = uavcan::node::ExecuteCommand::Response_1_1::STATUS_BAD_COMMAND;
      }

      return rsp;
    });

  /* Update node configuration from register value.
   */
  node_hdl.setNodeId(node_id);
  if (counter_port_id != std::numeric_limits<CanardPortID>::max())
    counter_pub = node_hdl.create_publisher<CounterMsg>(counter_port_id, 1*1000*1000UL /* = 1 sec in usecs. */);

  std::cout << "Node #" << static_cast<int>(node_id) << std::endl
            << "\tCounter Port ID: " << counter_port_id << std::endl;

  /* NODE INFO **************************************************************************/
  const auto node_info = node_hdl.create_node_info
  (
    /* uavcan.node.Version.1.0 protocol_version */
    1, 0,
    /* uavcan.node.Version.1.0 hardware_version */
    1, 0,
    /* uavcan.node.Version.1.0 software_version */
    0, 1,
    /* saturated uint64 software_vcs_revision_id */
#ifdef CYPHAL_NODE_INFO_GIT_VERSION
    CYPHAL_NODE_INFO_GIT_VERSION,
#else
    0,
#endif
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

        std::this_thread::yield();
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

    if ((now - prev_heartbeat) > HEARTBEAT_UPDATE_PERIOD_ms)
    {
      prev_heartbeat = now;

      uavcan::node::Heartbeat_1_0 msg;

      msg.uptime = now / 1000;
      msg.health.value = uavcan::node::Health_1_0::NOMINAL;
      msg.mode.value = uavcan::node::Mode_1_0::OPERATIONAL;
      msg.vendor_specific_status_code = 0;

      heartbeat_pub->publish(msg);
    }

    if ((now - prev_counter) > COUNTER_UPDATE_PERIOD_ms)
    {
      prev_counter = now;

      if (counter_pub)
        counter_pub->publish(counter_msg);

      counter_msg.value++;
    }

    std::this_thread::yield();
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
