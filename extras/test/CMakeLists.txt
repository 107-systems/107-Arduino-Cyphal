##########################################################################
cmake_minimum_required(VERSION 3.15)
##########################################################################
project("test_cyphal++")
##########################################################################
if(CMAKE_C_COMPILER_ID STREQUAL "GNU" AND CMAKE_C_COMPILER_VERSION VERSION_LESS 11)
    message(WARNING "GNU C compiler version ${CMAKE_C_COMPILER_VERSION} is too old and is unsupported. Version 11+ is required.")
endif()
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 11)
    message(WARNING "GNU C++ compiler version ${CMAKE_CXX_COMPILER_VERSION} is too old and is unsupported. Version 11+ is required.")
endif()
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
