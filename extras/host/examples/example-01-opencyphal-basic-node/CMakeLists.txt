##########################################################################
cmake_minimum_required(VERSION 3.15)
##########################################################################
set(EXAMPLE_01_TARGET example-01-basic-cyphal-node)
##########################################################################
add_executable(${EXAMPLE_01_TARGET} example-01-opencyphal-basic-node.cpp)
target_link_libraries(${EXAMPLE_01_TARGET} opencyphalcan pthread)
##########################################################################
