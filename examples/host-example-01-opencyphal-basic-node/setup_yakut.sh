export YAKUT_COMPILE_OUTPUT=.yakut
export YAKUT_PATH="$YAKUT_COMPILE_OUTPUT"
export UAVCAN__CAN__IFACE='socketcan:vcan0'
export UAVCAN__CAN__MTU=8
export UAVCAN__NODE__ID=$(yakut accommodate)  # Pick an unoccupied node-ID automatically for this shell session.
echo "Auto-selected node-ID for this session: $UAVCAN__NODE__ID"
