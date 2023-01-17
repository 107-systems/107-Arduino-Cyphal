##########################################################################
cmake_minimum_required(VERSION 3.15)
##########################################################################
set(LIBO1HEAP_TARGET o1heap)
##########################################################################
add_library(${LIBO1HEAP_TARGET} STATIC
  o1heap.c
)
target_compile_options(${LIBO1HEAP_TARGET} PRIVATE -std=c++11)
target_include_directories(${LIBO1HEAP_TARGET} PUBLIC .)
##########################################################################
