cmake_minimum_required(VERSION 3.14)
include(pico_sdk_import.cmake)
project(picoCPP VERSION 1.0.0)
add_executable(picoCPP
               main.cpp)

pico_sdk_init()

pico_enable_stdio_usb(picoCPP 1)
pico_enable_stdio_uart(picoCPP 1)
pico_add_extra_outputs(picoCPP)

target_link_libraries(picoCPP
                      pico_stdlib
                      hardware_gpio
                      hardware_i2c
                      hardware_spi
                      hardware_adc
                      hardware_uart)
