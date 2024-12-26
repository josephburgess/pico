cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(PICO_BOARD pico CACHE STRING "Board type")

if(NOT DEFINED ENV{PICO_SDK_PATH})
    message(FATAL_ERROR "PICO_SDK_PATH is not set. Please set it to the path of the Raspberry Pi Pico SDK.")
endif()
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
project(button-blink C CXX ASM)
pico_sdk_init()
add_executable(button-blink button-blink.c)
target_link_libraries(button-blink pico_stdlib)
pico_add_extra_outputs(button-blink)
