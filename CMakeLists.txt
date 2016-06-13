set(CMAKE_TOOLCHAIN_FILE arduino-cmake/cmake/ArduinoToolchain.cmake)
cmake_minimum_required(VERSION 2.8)
project(alkimia_sw C CXX)

print_board_list()
print_programmer_list()

#====================================================================#
# Default values when not specified
#====================================================================#

set(ARDUINO_DEFAULT_BOARD mega2560)
set(ARDUINO_DEFAULT_PORT /dev/ttyACM0)

#====================================================================#
# Libraries
#====================================================================#
generate_arduino_library(motor_controller_lib
    SRCS alkimia_sw/motor_controller.cpp
    HDRS alkimia_sw/motor_controller.h
    )

generate_arduino_library(accelerometer_adxl335_lib
    SRCS alkimia_sw/accelerometer_adxl335.cpp
    HDRS alkimia_sw/accelerometer_adxl335.h
    )

generate_arduino_library(potentiometer_v_divider_lib
    SRCS alkimia_sw/potentiometer_v_divider.cpp
    HDRS alkimia_sw/potentiometer_v_divider.h
    )

#====================================================================#
# alkimia firmware
#====================================================================#
generate_arduino_firmware(alkimia_sw
    SKETCH alkimia_sw/alkimia_sw.ino
    HDRS alkimia_sw/constants.h
    LIBS motor_controller_lib accelerometer_adxl335_lib potentiometer_v_divider_lib
    PROGRAMMER avrispmkii
    )
