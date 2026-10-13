add_library(
        UnixMicroControllersOperationSystemPlugin
        ${CMAKE_CURRENT_SOURCE_DIR}/src/UnixMicroControllersOperationSystemPlugin.cpp
)

target_include_directories(UnixMicroControllersOperationSystemPlugin PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

IncludeCore(UnixMicroControllersOperationSystemPlugin)

