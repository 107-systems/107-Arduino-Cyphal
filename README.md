<a href="https://107-systems.org/"><img align="right" src="https://raw.githubusercontent.com/107-systems/.github/main/logo/107-systems.png" width="15%"></a>
:floppy_disk: `107-Arduino-Cyphal`
==================================
<a href="https://opencyphal.org/"><img align="right" src="https://raw.githubusercontent.com/107-systems/.github/main/logo/opencyphal.svg" width="25%"></a>
[![Arduino Library Badge](https://www.ardu-badge.com/badge/107-Arduino-Cyphal.svg?)](https://www.ardu-badge.com/107-Arduino-Cyphal)
[![Compile Examples](https://github.com/107-systems/107-Arduino-Cyphal/workflows/Compile%20Examples/badge.svg)](https://github.com/107-systems/107-Arduino-Cyphal/actions?workflow=Compile+Examples)
[![Smoke test status](https://github.com/107-systems/107-Arduino-Cyphal/actions/workflows/smoke-test.yml/badge.svg)](https://github.com/107-systems/107-Arduino-Cyphal/actions/workflows/smoke-test.yml)
[![Unit Tests](https://github.com/107-systems/107-Arduino-Cyphal/workflows/Unit%20Tests/badge.svg)](https://github.com/107-systems/107-Arduino-Cyphal/actions?workflow=Unit+Tests)
[![Code Coverage](https://codecov.io/gh/107-systems/107-Arduino-Cyphal/branch/main/graph/badge.svg)](https://codecov.io/gh/107-systems/107-Arduino-Cyphal)
[![Arduino Lint](https://github.com/107-systems/107-Arduino-Cyphal/workflows/Arduino%20Lint/badge.svg)](https://github.com/107-systems/107-Arduino-Cyphal/actions?workflow=Arduino+Lint)
[![keywords.txt Checks](https://github.com/107-systems/107-Arduino-Cyphal/workflows/Extra%20Library%20Checks/badge.svg)](https://github.com/107-systems/107-Arduino-Cyphal/actions?workflow=Extra+Library+Checks)
[![General Formatting Checks](https://github.com/107-systems/107-Arduino-Cyphal/workflows/General%20Formatting%20Checks/badge.svg)](https://github.com/107-systems/107-Arduino-Cyphal/actions?workflow=General+Formatting+Checks)
[![Spell Check](https://github.com/107-systems/107-Arduino-Cyphal/workflows/Spell%20Check/badge.svg)](https://github.com/107-systems/107-Arduino-Cyphal/actions?workflow=Spell+Check)

This Arduino library implements the [OpenCyphal](https://opencyphal.org/) ([v1.0-beta](https://opencyphal.org/specification/Cyphal_Specification.pdf)) utilizing [libcanard](https://github.com/OpenCyphal/libcanard).

<p align="center">
  <a href="https://github.com/107-systems/l3xz"><img src="https://raw.githubusercontent.com/107-systems/.github/main/logo/l3xz-logo-memento-mori-github.png" width="30%"></a>
  <a href="https://github.com/107-systems/viper"><img src="https://github.com/107-systems/.github/raw/main/logo/viper.jpg" width="30%"></a>
</p>

This library works for
* [arduino-pico](https://github.com/earlephilhower/arduino-pico): [`Raspberry Pi Pico`](https://www.raspberrypi.org/products/raspberry-pi-pico), `Adafruit Feather RP2040`, ... :heavy_check_mark:
* **Host** (x86/x64/...): Using the CMake build system this library can be cross-compiled to a static C++ library and linked against any C++ executable. This is possible because the code itself is pure C/C++ without and dependencies to the Arduino framework.
```bash
* git clone https://github.com/107-systems/107-Arduino-Cyphal && cd 107-Arduino-Cyphal
  mkdir build && cd build
  cmake .. && make
```
or
```bash
cmake -DBUILD_EXAMPLES=ON -DBUILD_TEST=ON .. && make
```

### Reference-Implementations
* [OpenCyphal-GNSS-Node](examples/OpenCyphal-GNSS-Node): A Cyphal node with a GNSS sensor providing location data.
* [OpenCyphal-ToF-Distance-Sensor-Node](examples/OpenCyphal-ToF-Distance-Sensor-Node): A Cyphal node providing distance data measured with a TMF8801 ToF distance sensor.
* [OpenCyphalPicoBase-firmware](https://github.com/107-systems/OpenCyphalPicoBase-firmware): Firmware for the [OpenCyphalPicoBase](https://github.com/generationmake/OpenCyphalPicoBase) board.
* [l3xz-aux-ctrl-firmware](https://github.com/107-systems/l3xz-aux-ctrl-firmware): Firmware for the [L3X-Z](https://github.com/107-systems/l3xz) auxiliary controller ([OpenCyphalPicoBase](https://github.com/generationmake/OpenCyphalPicoBase)).
* [l3xz-leg-ctrl-firmware](https://github.com/107-systems/l3xz-leg-ctrl-firmware): Firmware for the [L3X-Z](https://github.com/107-systems/l3xz) leg controller ([l3xz-leg-ctrl-hardware](https://github.com/107-systems/l3xz-leg-ctrl-hardware)).
* [l3xz-radiation-sensor-firmware](https://github.com/107-systems/l3xz-radiation-sensor-firmware): Firmware for the [L3X-Z](https://github.com/107-systems/l3xz) radiation sensor ([OpenCyphalPicoBase](https://github.com/generationmake/OpenCyphalPicoBase)).

### Examples
#### Publisher
```C++
#include <107-Arduino-Cyphal.h>
/* ... */
Node::Heap<Node::DEFAULT_O1HEAP_SIZE> node_heap;
Node node_hdl(node_heap.data(), node_heap.size(), micros, [] (CanardFrame const & frame) { /* ... */ });

Publisher<Heartbeat_1_0> heartbeat_pub = node_hdl.create_publisher<Heartbeat_1_0>
  (Heartbeat_1_0::FixedPortId, 1*1000*1000UL /* = 1 sec in usecs. */);
/* ... */
void loop() {
  /* Process all pending OpenCyphal actions. */
  node_hdl.spinSome();
  /* ... */
  uavcan::node::Heartbeat_1_0 msg;

  msg.uptime = now / 1000;
  msg.health.value = uavcan::node::Health_1_0::NOMINAL;
  msg.mode.value = uavcan::node::Mode_1_0::OPERATIONAL;
  msg.vendor_specific_status_code = 0;

  heartbeat_pub->publish(msg);
  /* ... */
}
```

#### Subscriber
```C++
#include <107-Arduino-Cyphal.h>
/* ... */
Node::Heap<Node::DEFAULT_O1HEAP_SIZE> node_heap;
Node node_hdl(node_heap.data(), node_heap.size(), micros, [] (CanardFrame const & frame) { /* ... */ });

Subscription heartbeat_subscription = node_hdl.create_subscription<Heartbeat_1_0>
  (Heartbeat_1_0::FixedPortId, CANARD_DEFAULT_TRANSFER_ID_TIMEOUT_USEC, onHeartbeat_1_0_Received);
/* ... */
void loop() {
  /* Process all pending OpenCyphal actions. */
  node_hdl.spinSome();
}
/* ... */
void onHeartbeat_1_0_Received(Heartbeat_1_0 const & msg)
{
  char msg_buf[64];
  snprintf(msg_buf, sizeof(msg_buf),
           "Uptime = %d, Health = %d, Mode = %d, VSSC = %d",
           msg.uptime, msg.health.value, msg.mode.value, msg.vendor_specific_status_code);
  Serial.println(msg_buf);
}
```

#### Service Server
```C++
#include <107-Arduino-Cyphal.h>
/* ... */
Node::Heap<Node::DEFAULT_O1HEAP_SIZE> node_heap;
Node node_hdl(node_heap.data(), node_heap.size(), micros, [] (CanardFrame const & frame) { /* ... */ });

ServiceServer execute_command_srv = node_hdl.create_service_server<ExecuteCommand::Request_1_1, ExecuteCommand::Response_1_1>(
  ExecuteCommand::Request_1_1::FixedPortId,
  2*1000*1000UL,
  onExecuteCommand_1_1_Request_Received);
/* ... */
void loop() {
  /* Process all pending OpenCyphal actions. */
  node_hdl.spinSome();
}
/* ... */
ExecuteCommand::Response_1_1 onExecuteCommand_1_1_Request_Received(ExecuteCommand::Request_1_1 const & req)
{
  ExecuteCommand::Response_1_1 rsp;
  rsp.status = ExecuteCommand::Response_1_1::STATUS_SUCCESS;
  return rsp;
}
```

#### Service Client
```C++
#include <107-Arduino-Cyphal.h>
/* ... */
Node::Heap<Node::DEFAULT_O1HEAP_SIZE> node_heap;
Node node_hdl(node_heap.data(), node_heap.size(), micros, [] (CanardFrame const & frame) { /* ... */ });

ServiceClient<ExecuteCommand::Request_1_1> srv_client = node_hdl.create_service_client<ExecuteCommand::Request_1_1, ExecuteCommand::Response_1_1>(
  ExecuteCommand::Request_1_1::FixedPortId,
  2*1000*1000UL,
  onExecuteCommand_1_1_Response_Received);
/* ... */
void setup() {
  ExecuteCommand::Request_1_1 req;
  req.command = 0xCAFE;

  if (!srv_client->request(27 /* remote node id */, req))
    Serial.println("Service request failed.");
}
void loop() {
  /* Process all pending OpenCyphal actions. */
  node_hdl.spinSome();
}
/* ... */
void onExecuteCommand_1_1_Response_Received(ExecuteCommand::Response_1_1 const & rsp)
{
  if (rsp.status == ExecuteCommand::Response_1_1::STATUS_SUCCESS)
    Serial.println("Response: Success");
  else
    Serial.println("Response: Error");
}
```
