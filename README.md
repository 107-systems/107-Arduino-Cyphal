<a href="https://uavcan.org/"><img align="right" src="https://raw.githubusercontent.com/107-systems/.github/main/logo/uavcan.svg" width="20%"></a>
`107-Arduino-UAVCAN`
====================
[![Arduino Library Badge](https://www.ardu-badge.com/badge/107-Arduino-UAVCAN.svg?)](https://www.ardu-badge.com/107-Arduino-UAVCAN)
[![Unit Tests](https://github.com/107-systems/107-Arduino-UAVCAN/workflows/Unit%20Tests/badge.svg)](https://github.com/107-systems/107-Arduino-UAVCAN/actions?workflow=Unit+Tests)
[![codecov](https://codecov.io/gh/107-systems/107-Arduino-UAVCAN/branch/master/graph/badge.svg)](https://codecov.io/gh/107-systems/107-Arduino-UAVCAN)
[![Compile Examples](https://github.com/107-systems/107-Arduino-UAVCAN/workflows/Compile%20Examples/badge.svg)](https://github.com/107-systems/107-Arduino-UAVCAN/actions?workflow=Compile+Examples)
[![Arduino Lint](https://github.com/107-systems/107-Arduino-UAVCAN/workflows/Arduino%20Lint/badge.svg)](https://github.com/107-systems/107-Arduino-UAVCAN/actions?workflow=Arduino+Lint)
[![keywords.txt Checks](https://github.com/107-systems/107-Arduino-UAVCAN/workflows/Extra%20Library%20Checks/badge.svg)](https://github.com/107-systems/107-Arduino-UAVCAN/actions?workflow=Extra+Library+Checks)
[![General Formatting Checks](https://github.com/107-systems/107-Arduino-UAVCAN/workflows/General%20Formatting%20Checks/badge.svg)](https://github.com/107-systems/107-Arduino-UAVCAN/actions?workflow=General+Formatting+Checks)
[![Spell Check](https://github.com/107-systems/107-Arduino-UAVCAN/workflows/Spell%20Check/badge.svg)](https://github.com/107-systems/107-Arduino-UAVCAN/actions?workflow=Spell+Check)

Arduino library for providing a convenient C++ interface for accessing [UAVCAN](https://uavcan.org/) ([v1.0-beta](https://uavcan.org/specification/UAVCAN_Specification_v1.0-beta.pdf)) utilizing [libcanard](https://github.com/UAVCAN/libcanard).

<p align="center">
  <a href="https://github.com/107-systems/107-Arduino-DroneCore"><img src="https://github.com/107-systems/.github/raw/main/logo/viper.jpg" width="40%"></a>
</p>

This library works for
* [ArduinoCore-samd](https://github.com/arduino/ArduinoCore-samd): [`Arduino Zero`](https://store.arduino.cc/arduino-zero), [`MKR 1000`](https://store.arduino.cc/arduino-mkr1000-wifi), [`MKR WiFi 1010`](https://store.arduino.cc/arduino-mkr-wifi-1010), [`Nano 33 IoT`](https://store.arduino.cc/arduino-nano-33-iot), [`MKR GSM 1400`](https://store.arduino.cc/arduino-mkr-gsm-1400-1415), [`MKR NB 1500`](https://store.arduino.cc/arduino-mkr-nb-1500-1413), [`MKR WAN 1300/1310`](https://store.arduino.cc/mkr-wan-1310) :heavy_check_mark:
* [ArduinoCore-mbed](https://github.com/arduino/ArduinoCore-mbed): [`Portenta H7`](https://store.arduino.cc/portenta-h7), [`Nano 33 BLE`](https://store.arduino.cc/arduino-nano-33-ble), [`Nano RP2040 Connect`](https://store.arduino.cc/nano-rp2040-connect), [`Edge Control`](https://store.arduino.cc/edge-control) :heavy_check_mark:
* [arduino-esp32](https://github.com/espressif/arduino-esp32): `ESP32 Dev Module`, `ESP32 Wrover Module`, ... :heavy_check_mark:
* [arduino-pico](https://github.com/earlephilhower/arduino-pico): [`Raspberry Pi Pico`](https://www.raspberrypi.org/products/raspberry-pi-pico), `Adafruit Feather RP2040`, ... :heavy_check_mark:

### Reference-Implementation UAVCAN on Arduino
* [UAVCAN-GNSS-Node](examples/UAVCAN-GNSS-Node): A UAVCAN node with a GNSS sensor providing location data.
* [UAVCAN-ToF-Distance-Sensor-Node](examples/UAVCAN-ToF-Distance-Sensor-Node): Demo firmware for UAVCAN ToF Distance Sensor Node utilizing 107-Arduino-UAVCAN.

### Example
**Note**: Please be advised that the [examples](examples) shipped with this library are to be considered minimal examples to get you started working with [UAVCAN](https://uavcan.org/).
They are known to violate section **2.1.2.2 Regulation** of the UAVCAN Specification due to their reliance on hard-coded port identifiers.
A compliant implementation would instead provide configurable port-IDs and support the Register Interface (section **5.3 Application-layer functions**).
Fully compliant examples that implement reconfigurable port-IDs are shipped separately; e.g., [UAVCAN-GNSS-Node](examples/UAVCAN-GNSS-Node).
```C++
#include <ArduinoUAVCAN.h>
/* ... */
ArduinoUAVCAN uavcan(13, transmitCanFrame);
Heartbeat_1_0 hb;
/* ... */
void loop() {
  /* Update the heartbeat object */
  hb.uptime(millis() / 1000);
  hb.mode = Heartbeat_1_0::Mode::OPERATIONAL;

  /* Publish the heartbeat once/second */
  static unsigned long prev = 0;
  unsigned long const now = millis();
  if(now - prev > 1000) {
    uavcan.publish(hb);
    prev = now;
  }

  /* Transmit all enqeued CAN frames */
  while(uavcan.transmitCanFrame()) { }
}
/* ... */
bool transmitCanFrame(CanardFrame const & frame) {
  /* ... */
}
```

### Contribution
#### How to add missing wrappers
##### Step 1) Generate C header files from DSDL
**Option A) Use [nunavut/nnvg](https://github.com/UAVCAN/nunavut)**
* Install **nunavut**: `pip install nunavut` (you will need a functional [Python installation](https://docs.python.org/3/using/index.html))
* Get some DSDL
```bash
git clone https://github.com/UAVCAN/public_regulated_data_types
```
* Generate C header files from DSDL
```bash
nnvg --target-language c \
     --pp-max-emptylines=1  \
     --pp-trim-trailing-whitespace \
     --target-endianness=any \
     --enable-serialization-asserts \
     --outdir public_regulated_data_types/uavcan-header \
     public_regulated_data_types/uavcan

nnvg --target-language c \
     --pp-max-emptylines=1  \
     --pp-trim-trailing-whitespace \
     --target-endianness=any \
     --enable-serialization-asserts \
     --lookup public_regulated_data_types/uavcan \
     --outdir public_regulated_data_types/reg-header \
     public_regulated_data_types/reg
```
**Option B) Use [nunaweb](http://nunaweb.uavcan.org/)**
##### Step 2) Copy generated C header files to [`src/types`](https://github.com/107-systems/107-Arduino-UAVCAN/tree/master/src/types)
```bash
types/reg/drone/physics/electricity/
├── Power_0_1.h
├── PowerTs_0_1.h
├── Source_0_1.h
└── SourceTs_0_1.h
```
##### Step 3) Fix include path in generated C header files by prefixing it with `<types/`
```diff
-#include <uavcan/file/Path_1_0.h>
+#include <types/uavcan/file/Path_1_0.h>
...
-#include <reg/drone/physics/electricity/Power_0_1.h>
+#include <types/reg/drone/physics/electricity/Power_0_1.h>
```
##### Step 4) Manually implement wrapper classes in [`src/wrappers`](https://github.com/107-systems/107-Arduino-UAVCAN/tree/master/src/wrappers)
```bash
wrappers/reg/drone/physics/electricity/
├── Power_0_1.hpp
├── PowerTs_0_1.hpp
├── Source_0_1.hpp
└── SourceTs_0_1.hpp
```
##### Step 5) Add the wrapper clases to [`src/ArduinoUAVCANTypes.h`](https://github.com/107-systems/107-Arduino-UAVCAN/blob/master/src/ArduinoUAVCANTypes.h)
```diff
+#include "wrappers/reg/drone/physics/electricity/Power_0_1.hpp"
+#include "wrappers/reg/drone/physics/electricity/PowerTs_0_1.hpp"
+#include "wrappers/reg/drone/physics/electricity/Source_0_1.hpp"
+#include "wrappers/reg/drone/physics/electricity/SourceTs_0_1.hpp"
```
##### Step 6) [Create PR](https://github.com/107-systems/107-Arduino-UAVCAN/pulls) to mainline your changes
Note: Only UAVCAN types listed in [public_regulated_data_types:master](https://github.com/UAVCAN/public_regulated_data_types) will be accepted into this repository.
