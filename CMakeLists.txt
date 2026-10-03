cmake_minimum_required(VERSION 3.28)

project(AvrDeviceController)

project(AvrDeviceController LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(AvrDeviceController ${SOURCES})

add_definitions(-D_PROJECT_NAME_="AvrDeviceController")
add_definitions(-D_PROJECT_CONFIG_PATH_="/etc/avr_device_controller/main.conf")

target_include_directories(AvrDeviceController PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(AvrDeviceController PUBLIC ${CMAKE_SOURCE_DIR}/include/ProcessManager)
target_include_directories(AvrDeviceController PUBLIC ${CMAKE_SOURCE_DIR}/include/Patterns)
target_include_directories(AvrDeviceController PUBLIC ${CMAKE_SOURCE_DIR}/include/Arguments)
target_include_directories(AvrDeviceController PUBLIC ${CMAKE_SOURCE_DIR}/include/Communication)
target_include_directories(AvrDeviceController PUBLIC ${CMAKE_SOURCE_DIR}/include/Communication/drivers)

add_subdirectory(${CMAKE_SOURCE_DIR}/plugins/FileRWPlugin)
add_subdirectory(${CMAKE_SOURCE_DIR}/plugins/ConfiguratePlugin)

target_link_libraries(AvrDeviceController PUBLIC FileRWPlugin)
target_link_libraries(AvrDeviceController PUBLIC ConfiguratePlugin)
