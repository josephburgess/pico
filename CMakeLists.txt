cmake_minimum_required(VERSION 3.13)

if(NOT DEFINED ENV{PICO_SDK_PATH})
    message(FATAL_ERROR "PICO_SDK_PATH is not set. Please set it to the path of the Raspberry Pi Pico SDK.")
else()
    set(PICO_SDK_PATH $ENV{PICO_SDK_PATH})
    message(STATUS "Using PICO_SDK_PATH: ${PICO_SDK_PATH}")
endif()

include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

pico_sdk_init()

add_subdirectory(projects/01_blink)
add_subdirectory(projects/02_external_blink)
add_subdirectory(projects/03_breathing_light)
add_subdirectory(projects/04_button_blink)
add_subdirectory(projects/05_on_off_switch)
add_subdirectory(projects/06_waterfall)
add_subdirectory(projects/07_pwm_waterfall)
