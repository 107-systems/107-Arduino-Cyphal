##########################################################################
cmake_minimum_required(VERSION 3.15)
##########################################################################
set(LIBSOCKETCAN_TARGET socketcan)
##########################################################################
add_library(${LIBSOCKETCAN_TARGET} STATIC
  socketcan.c
  SocketCAN.cpp
)
##########################################################################
target_include_directories(${LIBSOCKETCAN_TARGET} PUBLIC .)
target_include_directories(${LIBSOCKETCAN_TARGET} PRIVATE ../../../src/libcanard)
##########################################################################
