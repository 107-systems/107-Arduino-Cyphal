#!/bin/bash
# Make sure the script runs with super user priviliges.
[ "$UID" -eq 0 ] || exec sudo bash "$0" "$@"
# Load the kernel module.
modprobe vcan
# Create the virtual CAN interface.
ip link add dev vcan0 type vcan
# Bring the virutal CAN interface online.
ip link set up vcan0
