add_library(
        UartProtoPlugin
        ${CMAKE_CURRENT_SOURCE_DIR}/src/UartProtoPlugin.cpp
)

target_include_directories(UartProtoPlugin PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

IncludeCore(UartProtoPlugin)

