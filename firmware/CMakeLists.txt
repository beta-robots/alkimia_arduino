cmake_minimum_required(VERSION 2.8.3)

include_directories(include
	${ROS_LIB_DIR}
)

file(GLOB_RECURSE FIRMWARE_SRC_FILES RELATIVE ${PROJECT_SOURCE_DIR} src/*.cpp)

# Remove this if using an Arduino without native USB (eg, other than Leonardo)
# We are using micro or nano
add_definitions(-DUSB_CON)

generate_arduino_firmware(single_fin
	SRCS src/single_fin.cpp ${FIRMWARE_SRC_FILES} ${ROS_LIB_DIR}/time.cpp 
	BOARD mega
	PORT /dev/ttyACM0
)