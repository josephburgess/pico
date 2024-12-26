cmake_minimum_required(VERSION 3.13)

if(NOT DEFINED ENV{PICO_SDK_PATH})
    message(FATAL_ERROR "PICO_SDK_PATH is not set. Please set it to the path of the Raspberry Pi Pico SDK.")
else()
    set(PICO_SDK_PATH $ENV{PICO_SDK_PATH})
    message(STATUS "Using PICO_SDK_PATH: ${PICO_SDK_PATH}")
endif()

include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

pico_sdk_init()

add_subdirectory(projects/blink)
add_subdirectory(projects/breathing-light)
add_subdirectory(projects/button-blink)
add_subdirectory(projects/external-blink)
add_subdirectory(projects/on-off-switch)
add_subdirectory(projects/waterfall)
