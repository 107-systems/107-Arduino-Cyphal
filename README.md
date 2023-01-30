<a href="https://opencyphal.org/"><img align="right" src="https://raw.githubusercontent.com/107-systems/.github/main/logo/opencyphal.svg" width="25%"></a>
`107-Arduino-Cyphal`
====================
[![Arduino Library Badge](https://www.ardu-badge.com/badge/107-Arduino-Cyphal.svg?)](https://www.ardu-badge.com/107-Arduino-Cyphal)
[![Compile Examples](https://github.com/107-systems/107-Arduino-Cyphal/workflows/Compile%20Examples/badge.svg)](https://github.com/107-systems/107-Arduino-Cyphal/actions?workflow=Compile+Examples)
[![Smoke test status](https://github.com/107-systems/107-Arduino-Cyphal/actions/workflows/smoke-test.yml/badge.svg)](https://github.com/107-systems/107-Arduino-Cyphal/actions/workflows/smoke-test.yml)
[![Arduino Lint](https://github.com/107-systems/107-Arduino-Cyphal/workflows/Arduino%20Lint/badge.svg)](https://github.com/107-systems/107-Arduino-Cyphal/actions?workflow=Arduino+Lint)
[![keywords.txt Checks](https://github.com/107-systems/107-Arduino-Cyphal/workflows/Extra%20Library%20Checks/badge.svg)](https://github.com/107-systems/107-Arduino-Cyphal/actions?workflow=Extra+Library+Checks)
[![General Formatting Checks](https://github.com/107-systems/107-Arduino-Cyphal/workflows/General%20Formatting%20Checks/badge.svg)](https://github.com/107-systems/107-Arduino-Cyphal/actions?workflow=General+Formatting+Checks)
[![Spell Check](https://github.com/107-systems/107-Arduino-Cyphal/workflows/Spell%20Check/badge.svg)](https://github.com/107-systems/107-Arduino-Cyphal/actions?workflow=Spell+Check)

This Arduino library implements the [OpenCyphal](https://opencyphal.org/) ([v1.0-beta](https://opencyphal.org/specification/Cyphal_Specification.pdf)) utilizing [libcanard](https://github.com/OpenCyphal/libcanard).

<p align="center">
  <a href="https://github.com/107-systems/viper"><img src="https://github.com/107-systems/.github/raw/main/logo/viper.jpg" width="40%"></a>
</p>

This library works for
* [ArduinoCore-mbed](https://github.com/arduino/ArduinoCore-mbed): [`Portenta H7`](https://store.arduino.cc/portenta-h7), [`Nano 33 BLE`](https://store.arduino.cc/arduino-nano-33-ble), [`Nano RP2040 Connect`](https://store.arduino.cc/nano-rp2040-connect), [`Edge Control`](https://store.arduino.cc/edge-control) :heavy_check_mark:
* [arduino-pico](https://github.com/earlephilhower/arduino-pico): [`Raspberry Pi Pico`](https://www.raspberrypi.org/products/raspberry-pi-pico), `Adafruit Feather RP2040`, ... :heavy_check_mark:
* **Host** (x86/x64/...): Using the CMake build system this library can be cross-compiled to a static C++ library and linked against any C++ executable. This is possible because the code itself is pure C/C++ without and dependencies to the Arduino framework.
```bash
* git clone https://github.com/107-systems/107-Arduino-Cyphal && cd 107-Arduino-Cyphal
  mkdir build && cd build
  cmake .. && make
```
or
```bash
cmake -DBUILD_EXAMPLES=ON .. && make
```

### Reference-Implementations
* [OpenCyphal-GNSS-Node](examples/OpenCyphal-GNSS-Node): A Cyphal node with a GNSS sensor providing location data.
* [OpenCyphal-ToF-Distance-Sensor-Node](examples/OpenCyphal-ToF-Distance-Sensor-Node): A Cyphal node providing distance data measured with a TMF8801 ToF distance sensor.
* [OpenCyphalPicoBase-firmware](https://github.com/107-systems/OpenCyphalPicoBase-firmware): Firmware for the [OpenCyphalPicoBase](https://github.com/generationmake/OpenCyphalPicoBase) board.
* [l3xz-aux-ctrl-firmware](https://github.com/107-systems/l3xz-aux-ctrl-firmware): Firmware for the [L3X-Z](https://github.com/107-systems/l3xz) auxiliary controller ([OpenCyphalPicoBase](https://github.com/generationmake/OpenCyphalPicoBase)).
* [l3xz-leg-ctrl-firmware](https://github.com/107-systems/l3xz-leg-ctrl-firmware): Firmware for the [L3X-Z](https://github.com/107-systems/l3xz) leg controller ([l3xz-leg-ctrl-hardware](https://github.com/107-systems/l3xz-leg-ctrl-hardware)).
* [l3xz-radiation-sensor-firmware](https://github.com/107-systems/l3xz-radiation-sensor-firmware): Firmware for the [L3X-Z](https://github.com/107-systems/l3xz) radiation sensor ([OpenCyphalPicoBase](https://github.com/generationmake/OpenCyphalPicoBase)).

### Example
```C++
#include <107-Arduino-Cyphal.h>
/* ... */
Node node_hdl([](CanardFrame const & frame) { /* ... */ });
Heartbeat_1_0 hb;
/* ... */
void loop() {
  /* Process all pending OpenCyphal actions. */
  node_hdl.spinSome();

  /* Update the heartbeat object */
  hb.uptime(millis() / 1000);
  hb.mode = Heartbeat_1_0::Mode::OPERATIONAL;

  /* Publish the heartbeat once/second */
  static unsigned long prev = 0;
  unsigned long const now = millis();
  if(now - prev > 1000) {
    node_hdl.publish(hb);
    prev = now;
  }
}
```
