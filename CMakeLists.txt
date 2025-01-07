##########################################################################
cmake_minimum_required(VERSION 3.8)
##########################################################################
project("cyphal++")
##########################################################################
if(CMAKE_C_COMPILER_ID STREQUAL "GNU" AND CMAKE_C_COMPILER_VERSION VERSION_LESS 11)
  message(WARNING "GNU C compiler version ${CMAKE_C_COMPILER_VERSION} is too old and is unsupported. Version 11+ is required.")
endif()
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 11)
  message(WARNING "GNU C++ compiler version ${CMAKE_CXX_COMPILER_VERSION} is too old and is unsupported. Version 11+ is required.")
endif()
##########################################################################
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
##########################################################################
option(BUILD_EXAMPLES "Build all examples provided with this library" OFF)
##########################################################################
add_library(${PROJECT_NAME} STATIC
  src/Node.cpp
  src/libcanard/canard.c
  src/libo1heap/o1heap.c
)
##########################################################################
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
##########################################################################
target_include_directories(${PROJECT_NAME} PUBLIC src extras/cyphal++/include src/libcanard src/libo1heap)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
##########################################################################
if(BUILD_EXAMPLES)
  add_subdirectory(examples/CAN/host-example-01-opencyphal-basic-node)
endif()
##########################################################################
