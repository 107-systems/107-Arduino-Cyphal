##########################################################################
cmake_minimum_required(VERSION 3.15)
##########################################################################
project("test_cyphal++")
##########################################################################
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
##########################################################################
include_directories(external/catch2/v2.13.10/include)
include_directories(../../src)
include_directories(../../src/util/registry)
##########################################################################
add_executable(${PROJECT_NAME}
  src/test_main.cpp
  src/test_registry_impl.cpp
  src/test_registry_value.cpp
)
##########################################################################
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
##########################################################################
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
##########################################################################
