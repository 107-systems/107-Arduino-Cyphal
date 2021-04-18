##########################################################################

cmake_minimum_required(VERSION 2.8)

##########################################################################

project(test-107-Arduino-UAVCAN)

##########################################################################

include_directories(include)
include_directories(../../src)
include_directories(external/catch/v2.12.1/include)

##########################################################################

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

##########################################################################

set(TEST_SRCS
  src/util/Types.cpp

  src/test_main.cpp
#  src/test_ExecuteCommand_ServiceClient.cpp
#  src/test_ExecuteCommand_ServiceServer.cpp
  src/test_Heartbeat.cpp
#  src/test_ID.cpp
#  src/test_Version.cpp

  ../../src/libcanard/canard_dsdl.c
  ../../src/libcanard/canard.c
  ../../src/o1heap/o1heap.c
  ../../src/utility/CritSec-host.cpp
  ../../src/ArduinoUAVCAN.cpp
)

##########################################################################

add_compile_options(-Wall -Wextra -Wpedantic -Werror -Wno-ignored-qualifiers)
add_compile_definitions(HOST)

set(CMAKE_C_FLAGS   ${CMAKE_C_FLAGS}   "--coverage")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "--coverage")

##########################################################################

add_executable(
  ${CMAKE_PROJECT_NAME}
  ${TEST_SRCS}
)

##########################################################################
