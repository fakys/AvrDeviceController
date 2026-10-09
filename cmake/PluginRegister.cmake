set(PLUGINS "" CACHE STRING "List of items")
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