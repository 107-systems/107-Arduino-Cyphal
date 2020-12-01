`107-Arduino-UAVCAN`
====================
[![Unit Tests](https://github.com/107-systems/107-Arduino-UAVCAN/workflows/Unit%20Tests/badge.svg)](https://github.com/107-systems/107-Arduino-UAVCAN/actions?workflow=Unit+Tests)
[![codecov](https://codecov.io/gh/107-systems/107-Arduino-UAVCAN/branch/master/graph/badge.svg)](https://codecov.io/gh/107-systems/107-Arduino-UAVCAN)
[![Compile Examples](https://github.com/107-systems/107-Arduino-UAVCAN/workflows/Compile%20Examples/badge.svg)](https://github.com/107-systems/107-Arduino-UAVCAN/actions?workflow=Compile+Examples)
[![Extra Library Checks](https://github.com/107-systems/107-Arduino-UAVCAN/workflows/Extra%20Library%20Checks/badge.svg)](https://github.com/107-systems/107-Arduino-UAVCAN/actions?workflow=Extra+Library+Checks)
[![General Formatting Checks](https://github.com/107-systems/107-Arduino-UAVCAN/workflows/General%20Formatting%20Checks/badge.svg)](https://github.com/107-systems/107-Arduino-UAVCAN/actions?workflow=General+Formatting+Checks)
[![Spell Check](https://github.com/107-systems/107-Arduino-UAVCAN/workflows/Spell%20Check/badge.svg)](https://github.com/107-systems/107-Arduino-UAVCAN/actions?workflow=Spell+Check)

Arduino library for providing a convenient C++ interface for accessing [UAVCAN](https://uavcan.org/) ([v1.0-beta](https://uavcan.org/specification/UAVCAN_Specification_v1.0-beta.pdf)) utilizing [libcanard](https://github.com/UAVCAN/libcanard).

<p align="center">
  <a href="https://github.com/107-systems/107-Arduino-Viper"><img src="https://github.com/107-systems/.github/raw/main/logo/viper.jpg" width="40%"></a>
</p>

This library works for
* [ArduinoCore-samd](https://github.com/arduino/ArduinoCore-samd): [`Arduino Zero`](https://store.arduino.cc/arduino-zero), [`MKR 1000`](https://store.arduino.cc/arduino-mkr1000-wifi), [`MKR WiFi 1010`](https://store.arduino.cc/arduino-mkr-wifi-1010), [`Nano 33 IoT`](https://store.arduino.cc/arduino-nano-33-iot), [`MKR GSM 1400`](https://store.arduino.cc/arduino-mkr-gsm-1400-1415), [`MKR NB 1500`](https://store.arduino.cc/arduino-mkr-nb-1500-1413), [`MKR WAN 1300/1310`](https://store.arduino.cc/mkr-wan-1310) :heavy_check_mark:
* [ArduinoCore-mbed](https://github.com/arduino/ArduinoCore-mbed): [`Portenta H7`](https://store.arduino.cc/portenta-h7), [`Nano 33 BLE`](https://store.arduino.cc/arduino-nano-33-ble) :heavy_check_mark:

### Demo-Application
* [UAVCAN-GNSS-Node](https://github.com/107-systems/UAVCAN-GNSS-Node): A UAVCAN node with a GNSS sensor providing location data.

### Example
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
Please take a look at the [wiki](https://github.com/107-systems/107-Arduino-UAVCAN/wiki) for notes pertaining development of `107-Arduino-UAVCAN`.
