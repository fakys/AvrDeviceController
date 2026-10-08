add_library(
        ConfiguratePlugin
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ConfigurateLoader.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/config_parser_helper.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ConfigEntity/Configurate.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ConfigEntity/ConfigAllDevices.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ConfigEntity/ConfigDevice.cpp
)

target_include_directories(ConfiguratePlugin PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/ConfigEntity
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Exceptions
        ${CMAKE_CURRENT_SOURCE_DIR}/include/ConfigEntity/ConfigTypes

        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include/Exceptions
        ${CMAKE_SOURCE_DIR}/include/ProcessManager
        ${CMAKE_SOURCE_DIR}/include/Patterns
        ${CMAKE_SOURCE_DIR}/include/Arguments
        ${CMAKE_SOURCE_DIR}/include/Communication
        ${CMAKE_SOURCE_DIR}/include/Communication/drivers
)



target_link_libraries(ConfiguratePlugin PUBLIC FileRWPlugin)
