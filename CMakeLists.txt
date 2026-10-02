cmake_minimum_required(VERSION 3.28)

project(avr_proto_linux)

project(avr_proto_linux LANGUAGES CXX)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(avr_proto_linux ${SOURCES})

target_include_directories(avr_proto_linux PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(${CMAKE_SOURCE_DIR}/plugins/FileRWPlugin)

target_link_libraries(avr_proto_linux PUBLIC FileRWPlugin)

add_definitions(-D_PROJECT_NAME_=avr_proto_linux)