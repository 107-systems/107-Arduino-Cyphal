<a href="https://uavcan.org/"><img align="right" src="https://raw.githubusercontent.com/107-systems/.github/main/logo/uavcan.svg" width="20%"></a>
UAVCAN-GNSS-Node
================

[![Compile Sketch status](https://github.com/107-systems/UAVCAN-GNSS-Node/workflows/Compile%20Sketch/badge.svg)](https://github.com/107-systems/UAVCAN-GNSS-Node/actions?workflow=Compile+Sketch)

Demo firmware for UAVCAN GNSS Node utilizing [107-Arduino-UAVCAN](https://github.com/107-systems/107-Arduino-UAVCAN).

**Attention**: [107-Arduino-UAVCAN](https://github.com/107-systems/107-Arduino-UAVCAN) (which provides the UAVCAN connectivity within this demo sketch) is supporting [UAVCAN](https://uavcan.org/) ([v1.0-beta](https://uavcan.org/specification/UAVCAN_Specification_v1.0-beta.pdf)). Most UAVCAN support tools do not yet support UAVCAN V1 (but legacy UAVCAN V0). Therefore the best way to interact with the UAVCAN GNSS Node is via [pyuavcan](https://github.com/UAVCAN/pyuavcan) which has already been ported to V1.

### Hardware Setup
In order to assemble the hardware required for the `UAVCAN-GNSS-Node` you need to integrate a [`MKR Zero`](https://store.arduino.cc/mkr-zero) with a [`MKR CAN Shield`](https://store.arduino.cc/arduino-mkr-can-shield) and a [`MKR GPS Shield`](https://store.arduino.cc/arduino-mkr-gps-shield) as shown below.

<p align="center">
  <img src="uavcan-gnss-node-arduino-stack.jpg" width="40%">
</p>

### Quick Start
* Install [arduino-cli](https://arduino.github.io/arduino-cli/latest/installation)
* Clone this repository and [compile](https://arduino.github.io/arduino-cli/latest/commands/arduino-cli_compile/):
```bash
git clone https://github.com/107-systems/UAVCAN-GNSS-Node && cd UAVCAN-GNSS-Node
arduino-cli compile -b arduino:samd:mkrzero
```
* Connect your MKR Zero based Arduino stack and [upload](https://arduino.github.io/arduino-cli/latest/commands/arduino-cli_upload/):
```bash
arduino-cli upload .
```
* Or compile and upload in one step:
```bash
arduino-cli compile -b arduino:samd:mkrzero -u
```
