##########################################################################
cmake_minimum_required(VERSION 3.15)
##########################################################################
set(LIBCANARD_TARGET canard)
##########################################################################
add_library(${LIBCANARD_TARGET} STATIC
  canard.c
)
target_compile_options(${LIBCANARD_TARGET} PRIVATE -std=c++11)
target_include_directories(${LIBCANARD_TARGET} PUBLIC .)
##########################################################################
