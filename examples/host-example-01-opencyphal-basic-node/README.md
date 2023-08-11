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

$ y r 42 cyphal.pub.counter.id
65535                            

$ y r 42 cyphal.pub.counter.id 1001
1001
```

Store changed configuration and restart node:
```bash
$ y cmd 42 store
$ y cmd 42 restart
```
**Note**: `restart` is implemented in this example as `exit(0)`, hence you need to restart the application yourself.

Subscribe to counter subject:
```bash
y sub 1001:uavcan.primitive.scalar.Integer8.1.0 --with-metadata
---
1001:
  _meta_: {ts_system: 1691741133.026175, ts_monotonic: 25484.463219, source_node_id: 12, transfer_id: 1, priority: nominal, dtype: uavcan.primitive.scalar.Integer8.1.0}
  value: 1
---
1001:
  _meta_: {ts_system: 1691741138.027977, ts_monotonic: 25489.465034, source_node_id: 12, transfer_id: 2, priority: nominal, dtype: uavcan.primitive.scalar.Integer8.1.0}
  value: 2
...
```
