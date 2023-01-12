##########################################################################
cmake_minimum_required(VERSION 3.15)
##########################################################################
project("opencyphalcan")
##########################################################################
set(CMAKE_VERBOSE_MAKEFILE OFF)
##########################################################################
option(BUILD_EXAMPLES "Build all examples provided with this library" OFF)
##########################################################################
add_subdirectory(src/libcanard)
add_subdirectory(src/libo1heap)
add_subdirectory(extras/host/libsocketcan)
##########################################################################
add_library(${PROJECT_NAME} STATIC
  extras/host/src/SocketCAN.cpp
  src/nodeinfo/NodeInfo.cpp
  src/register/util/ListResponse.cpp
  src/register/RegisterBase.cpp
  src/register/RegisterList.cpp
  src/Node.cpp
)
##########################################################################
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
##########################################################################
target_compile_definitions(${PROJECT_NAME} PUBLIC CMAKE_HOST_BUILD)
target_include_directories(${PROJECT_NAME} PUBLIC src extras/host/include)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_link_libraries(${PROJECT_NAME} canard o1heap socketcan)
##########################################################################
if(BUILD_EXAMPLES)
  add_subdirectory(extras/host/examples/example-01-opencyphal-basic-node)
endif()
##########################################################################
