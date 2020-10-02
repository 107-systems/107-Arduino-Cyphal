`107-Arduino-UAVCAN`
====================
[![Unit Tests](https://github.com/107-systems/107-Arduino-UAVCAN/workflows/Unit%20Tests/badge.svg)](https://github.com/107-systems/107-Arduino-UAVCAN/actions?workflow=Unit+Tests)
[![codecov](https://codecov.io/gh/107-systems/107-Arduino-UAVCAN/branch/master/graph/badge.svg)](https://codecov.io/gh/107-systems/107-Arduino-UAVCAN)
[![Compile Examples](https://github.com/107-systems/107-Arduino-UAVCAN/workflows/Compile%20Examples/badge.svg)](https://github.com/107-systems/107-Arduino-UAVCAN/actions?workflow=Compile+Examples)
[![Extra Library Checks](https://github.com/107-systems/107-Arduino-UAVCAN/workflows/Extra%20Library%20Checks/badge.svg)](https://github.com/107-systems/107-Arduino-UAVCAN/actions?workflow=Extra+Library+Checks)
[![General Formatting Checks](https://github.com/107-systems/107-Arduino-UAVCAN/workflows/General%20Formatting%20Checks/badge.svg)](https://github.com/107-systems/107-Arduino-UAVCAN/actions?workflow=General+Formatting+Checks)
[![Spell Check](https://github.com/107-systems/107-Arduino-UAVCAN/workflows/Spell%20Check/badge.svg)](https://github.com/107-systems/107-Arduino-UAVCAN/actions?workflow=Spell+Check)

Arduino library for providing a convenient C++ interface for accessing [UAVCAN](https://uavcan.org/) ([v1.0-alpha](https://uavcan.org/specification/UAVCAN_Specification_v1.0-alpha.pdf)) utilizing [libcanard](https://github.com/UAVCAN/libcanard).

<p align="center">
  <a href="https://github.com/107-systems/107-Arduino-Viper"><img src="extras/logo/viper-logo.jpg" width="40%"></a>
</p>

This library works for
* [ArduinoCore-samd](https://github.com/arduino/ArduinoCore-samd): [`Arduino Zero`](https://store.arduino.cc/arduino-zero), [`MKR 1000`](https://store.arduino.cc/arduino-mkr1000-wifi), [`MKR WiFi 1010`](https://store.arduino.cc/arduino-mkr-wifi-1010), [`Nano 33 IoT`](https://store.arduino.cc/arduino-nano-33-iot), [`MKR GSM 1400`](https://store.arduino.cc/arduino-mkr-gsm-1400-1415), [`MKR NB 1500`](https://store.arduino.cc/arduino-mkr-nb-1500-1413), [`MKR WAN 1300/1310`](https://store.arduino.cc/mkr-wan-1310) :heavy_check_mark:
* [ArduinoCore-mbed](https://github.com/arduino/ArduinoCore-mbed): [`Portenta H7`](https://store.arduino.cc/portenta-h7), [`Nano 33 BLE`](https://store.arduino.cc/arduino-nano-33-ble) :heavy_check_mark:

## Example
### Subscribe
```C++
#include <ArduinoUAVCAN.h>
/* ... */
ArduinoUAVCAN uavcan(13, nullptr);
/* ... */
void setup() {
  /* ... */
  uavcan.subscribe<Heartbeat_1_0>(onHeatbeat_1_0_Received);
}
/* ... */
void onHeatbeat_1_0_Received(CanardTransfer const & transfer, ArduinoUAVCAN & /* uavcan */)
{
  Heartbeat_1_0 const hb = Heartbeat_1_0::create(transfer);

  char msg[64];
  snprintf(msg, 64, "ID %02X, Uptime = %d, Health = %d, Mode = %d, VSSC = %d", transfer.remote_node_id, hb.data.uptime, hb.data.health, hb.data.mode, hb.data.vendor_specific_status_code);

  Serial.println(msg);
}
```

### Publish
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
bool transmitCanFrame(uint32_t const id, uint8_t const * data, uint8_t const len) {
  /* ... */
}
```

### Service Client
```C++
#include <ArduinoUAVCAN.h>
/* ... */
ArduinoUAVCAN uavcan(13, transmitCanFrame);
/* ... */
void setup() {
  /* ... */
  /* Request some coffee. */
  char const cmd_param[] = "I want a double espresso with cream";
  ExecuteCommand_1_0::Request req:
  req.data.command = 0xCAFE;
  req.data.parameter_length = std::min(cmd_param.length(), uavcan_node_ExecuteCommand_1_0_Request_parameter_array_capacity());
  std::copy(cmd_param.c_str(), cmd_param.c_str() + req.data.parameter_length, req.data.parameter);

  uavcan.request<ExecuteCommand_1_0::Request, ExecuteCommand_1_0::Response>(req, 27 /* remote node id */, onExecuteCommand_1_0_Response_Received);
}

void loop() {
  /* Transmit all enqeued CAN frames */
  while(uavcan.transmitCanFrame()) { }
}
/* ... */
void onExecuteCommand_1_0_Response_Received(CanardTransfer const & transfer, ArduinoUAVCAN & /* uavcan */) {
  ExecuteCommand_1_0::Response const rsp = ExecuteCommand_1_0::Response::create(transfer);

  if (rsp.data.status == ExecuteCommand_1_0::Response::Status::SUCCESS)
    Serial.println("Coffee successful retrieved");
  else
    Serial.println("Error when retrieving coffee");
}
/* ... */
bool transmitCanFrame(CanardFrame const & frame) {
  /* ... */
}
```


### Service Server
```C++
#include <ArduinoUAVCAN.h>
/* ... */
ArduinoUAVCAN uavcan(13, transmitCanFrame);
/* ... */
void setup() {
  /* ... */
  /* Subscribe to incoming service requests */
  uavcan.subscribe<ExecuteCommand_1_0::Request>(onExecuteCommand_1_0_Request_Received);
}

void loop() {
  /* Transmit all enqeued CAN frames */
  while(uavcan.transmitCanFrame()) { }
}
/* ... */
void onExecuteCommand_1_0_Request_Received(CanardTransfer const & transfer, ArduinoUAVCAN & uavcan) {
  ExecuteCommand_1_0::Request req = ExecuteCommand_1_0::Request::create(transfer);
  ExecuteCommand_1_0::Response rsp;

  if (req.command() == 0xCAFE) {
    rsp = ExecuteCommand_1_0::Response::Status::SUCCESS;
    uavcan.respond(rsp, transfer.remote_node_id, transfer.transfer_id);
  } else {
    rsp = ExecuteCommand_1_0::Response::Status::NOT_AUTHORIZED;
    uavcan.respond(rsp, transfer.remote_node_id, transfer.transfer_id);
  }
}
/* ... */
bool transmitCanFrame(CanardFrame const & frame) {
  /* ... */
}
```

### How to generate C header files from DSDL via nunavut/nnvg
```bash
cd ~
https://github.com/UAVCAN/nunavut && cd nunavut
python3.8 -m pip install .

cd ~
git clone https://github.com/UAVCAN/public_regulated_data_types && cd public_regulated_data_types
nnvg --outdir include --templates c_jinja --pp-trim-trailing-whitespace -e .h uavcan
```
