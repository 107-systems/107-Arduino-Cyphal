##########################################################################

cmake_minimum_required(VERSION 2.8)

##########################################################################

project(test-107-Arduino-UAVCAN)

##########################################################################

include_directories(external/catch/v2.12.1/include)
include_directories(../../src)

##########################################################################

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

##########################################################################

set(TEST_SRCS
  src/test_main.cpp
  ../../src/libcanard/canard_dsdl.c
  ../../src/libcanard/canard.c
  ../../src/o1heap/o1heap.c
  ../../src/ArduinoO1Heap.cpp
  ../../src/ArduinoUAVCAN.cpp
)

##########################################################################

add_compile_options(-Wall -Wextra -Wpedantic -Werror)
add_compile_definitions(HOST)

##########################################################################

add_executable(
  ${CMAKE_PROJECT_NAME}
  ${TEST_SRCS}
)

##########################################################################
