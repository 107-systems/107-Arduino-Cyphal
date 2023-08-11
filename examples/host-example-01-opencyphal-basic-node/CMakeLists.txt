##########################################################################
cmake_minimum_required(VERSION 3.15)
##########################################################################
set(EXAMPLE_01_TARGET host-example-01-basic-cyphal-node)
##########################################################################
add_executable(${EXAMPLE_01_TARGET}
        host-example-01-opencyphal-basic-node.cpp
        socketcan.c
        kv_host.cpp
        )
##########################################################################
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_link_libraries(${EXAMPLE_01_TARGET} cyphal++ pthread)
##########################################################################
execute_process(
        COMMAND git rev-parse --short=16 HEAD
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
        OUTPUT_VARIABLE GIT_HASH
        OUTPUT_STRIP_TRAILING_WHITESPACE
)
target_compile_definitions(${PROJECT_NAME} PUBLIC CYPHAL_NODE_INFO_GIT_VERSION=0x${GIT_HASH})
##########################################################################
