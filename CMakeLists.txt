##########################################################################
cmake_minimum_required(VERSION 3.15)
##########################################################################
project("libcyphalcan++")
##########################################################################
add_definitions(-DLIB_CYPHAL_CMAKE_BUILD)
##########################################################################
add_subdirectory(src/libcanard)
add_subdirectory(src/libo1heap)
add_subdirectory(src/libsocketcan)
##########################################################################
add_library(${PROJECT_NAME} STATIC
  src/host/SocketCAN.cpp
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
target_include_directories(${PROJECT_NAME} PUBLIC src)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_link_libraries(${PROJECT_NAME} canard o1head socketcan)
##########################################################################
