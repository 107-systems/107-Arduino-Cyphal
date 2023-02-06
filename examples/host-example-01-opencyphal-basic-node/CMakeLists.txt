##########################################################################
cmake_minimum_required(VERSION 3.15)
##########################################################################
set(EXAMPLE_01_TARGET host-example-01-basic-cyphal-node)
##########################################################################
add_executable(${EXAMPLE_01_TARGET}
        host-example-01-opencyphal-basic-node.cpp
        socketcan.c
        )
target_link_libraries(${EXAMPLE_01_TARGET} cyphal++ pthread)
##########################################################################
