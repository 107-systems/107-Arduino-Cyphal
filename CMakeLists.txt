##########################################################################
cmake_minimum_required(VERSION 3.15)
##########################################################################
project("cyphal++")
##########################################################################
set(CMAKE_VERBOSE_MAKEFILE OFF)
##########################################################################
option(BUILD_EXAMPLES "Build all examples provided with this library" OFF)
##########################################################################
add_subdirectory(src/libcanard)
add_subdirectory(src/libo1heap)
##########################################################################
add_library(${PROJECT_NAME} STATIC
  src/util/nodeinfo/NodeInfo.cpp
  src/util/vla/vla.cpp
  src/Node.cpp
)
##########################################################################
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
##########################################################################
target_include_directories(${PROJECT_NAME} PUBLIC src extras/cyphal++/include)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)
target_link_libraries(${PROJECT_NAME} canard o1heap)
##########################################################################
if(BUILD_EXAMPLES)
  add_subdirectory(examples/host-example-01-opencyphal-basic-node)
endif()
##########################################################################
