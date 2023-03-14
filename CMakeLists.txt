##########################################################################
cmake_minimum_required(VERSION 3.15)
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
option(BUILD_TEST "Build test code provided with this library" OFF)
##########################################################################
add_subdirectory(src/libcanard)
add_subdirectory(src/libo1heap)
##########################################################################
add_library(${PROJECT_NAME} STATIC
  src/util/nodeinfo/NodeInfo.cpp
  src/Node.cpp
)
##########################################################################
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
##########################################################################
target_include_directories(${PROJECT_NAME} PUBLIC src extras/cyphal++/include)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_link_libraries(${PROJECT_NAME} canard o1heap)
##########################################################################
if(BUILD_EXAMPLES)
  add_subdirectory(examples/host-example-01-opencyphal-basic-node)
endif()
##########################################################################
if(BUILD_TEST)
  add_subdirectory(extras/test)
endif()
##########################################################################
