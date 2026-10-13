add_library(
        AvrDevicesPlugin
        ${CMAKE_CURRENT_SOURCE_DIR}/src/AvrDevicesPlugin.cpp
)

target_include_directories(AvrDevicesPlugin PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Exceptions
)


IncludeCore(AvrDevicesPlugin)
target_link_libraries(AvrDeviceController PUBLIC UartProtoPlugin)
target_link_libraries(AvrDeviceController PUBLIC UnixMicroControllersOperationSystemPlugin)

