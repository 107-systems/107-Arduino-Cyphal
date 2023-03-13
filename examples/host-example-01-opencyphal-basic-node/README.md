<a href="https://opencyphal.org/"><img align="right" src="https://raw.githubusercontent.com/107-systems/.github/main/logo/opencyphal.svg" width="25%"></a>
:floppy_disk: `example-01-opencyphal-basic-node`
================================================
* Setup a virtual CAN interface (`vcan0`)
```bash
sudo ./setup_vcan.sh
```
You can observe the frames on the virtual CAN bus using `candump`
```bash
candump vcan0
```
* Install `yakut`
```bash
python3 -m pip install yakut
```
* Compile OpenCyphal DSDL
```bash
yakut compile https://github.com/OpenCyphal/public_regulated_data_types/archive/refs/heads/master.zip
```
* Setup `yakut`
```bash
. setup_yakut.sh
```
* Start `yakut`
```bash
yakut monitor
```
* Use `yakut`

Read the register list of the node.
```bash
yakut rl 42
[cyphal.node.description, cyphal.node.id, cyphal.pub.temperature.id, cyphal.pub.temperature.type]
```

Read/write register access:
```bash
$ y r 42 cyphal.node.description
basic-cyphal-node

$ y r 42 cyphal.node.id
42

$ y r 42 cyphal.node.id 12
12
```
