set(PLUGINS "" CACHE STRING "List of items")
set(ALL_PLUGIN_OBJET "")
set(PLUGIN_INCLUDES "")


if (NOT PLUGINS)
    set(PLUGINS "FileRWPlugin" "ConfiguratePlugin")
endif ()

message(STATUS "aaa = ${PLUGINS}")

function(PluginRegister)
    string(APPEND ALL_PLUGIN_OBJET "(AbstractPlugin*) new ${ARGN},")
    string(APPEND PLUGIN_INCLUDES "#include \"${ARGN}.h\"\n")
    add_subdirectory(${CMAKE_SOURCE_DIR}/plugins/${ARGN})
    target_link_libraries(AvrDeviceController PUBLIC ${ARGN})
endfunction()


foreach(plugin ${PLUGINS})
    PluginRegister(${plugin})
endforeach()

file(WRITE ${CMAKE_BINARY_DIR}/plugins.h "${PLUGIN_INCLUDES}")

target_compile_definitions(AvrDeviceController PUBLIC
        "ALL_PLUGIN_OBJECTS=${ALL_PLUGIN_OBJET}"
)

target_include_directories(AvrDeviceController PRIVATE ${CMAKE_BINARY_DIR})