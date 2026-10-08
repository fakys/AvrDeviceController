cmake_minimum_required(VERSION 3.28)

project(AvrDeviceController)
project(AvrDeviceController LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



set(PLUGINS "" CACHE STRING "List of items")


include(cmake/CPM.cmake)

set(PLUGINS "FileRWPlugin" "ConfiguratePlugin")

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(AvrDeviceController ${SOURCES})

add_definitions(-D_PROJECT_NAME_="AvrDeviceController")
add_definitions(-D_PROJECT_CONFIG_PATH_="/etc/avr_device_controller/main.conf")

target_include_directories(AvrDeviceController PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(AvrDeviceController PUBLIC ${CMAKE_SOURCE_DIR}/include/Exceptions)
target_include_directories(AvrDeviceController PUBLIC ${CMAKE_SOURCE_DIR}/include/Patterns)
target_include_directories(AvrDeviceController PUBLIC ${CMAKE_SOURCE_DIR}/include/Arguments)
target_include_directories(AvrDeviceController PUBLIC ${CMAKE_SOURCE_DIR}/include/Communication)
target_include_directories(AvrDeviceController PUBLIC ${CMAKE_SOURCE_DIR}/include/Communication/drivers)

set(ALL_PLUGIN_OBJET "")
set(PLUGIN_INCLUDES "")

foreach(plugin ${PLUGINS})
    string(APPEND ALL_PLUGIN_OBJET "(AbstractPlugin*) new ${plugin},")
    string(APPEND PLUGIN_INCLUDES "#include \"${plugin}.h\"\n")
    add_subdirectory(${CMAKE_SOURCE_DIR}/plugins/${plugin})
    target_link_libraries(AvrDeviceController PUBLIC ${plugin})
endforeach()


file(WRITE ${CMAKE_BINARY_DIR}/plugins.h "${PLUGIN_INCLUDES}")
target_compile_definitions(AvrDeviceController PUBLIC
        "ALL_PLUGIN_OBJECTS=${ALL_PLUGIN_OBJET}"
)

target_include_directories(AvrDeviceController PRIVATE ${CMAKE_BINARY_DIR})