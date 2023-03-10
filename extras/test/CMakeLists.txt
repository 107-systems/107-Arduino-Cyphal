##########################################################################
cmake_minimum_required(VERSION 3.15)
##########################################################################
set(TEST_TARGET "test_cyphal++")
##########################################################################
include_directories(external/catch2/v2.13.10/include)
include_directories(../../src)
include_directories(../../src/util/registry)
##########################################################################
add_executable(${TEST_TARGET}
  src/test_main.cpp
  src/test_registry_impl.cpp
  src/test_registry_value.cpp
)
##########################################################################
target_compile_options(${TEST_TARGET} PRIVATE -Wall -Wextra -Wpedantic -Werror)
##########################################################################
target_compile_features(${TEST_TARGET} PRIVATE cxx_std_17)
##########################################################################
