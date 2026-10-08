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
)



target_link_libraries(ConfiguratePlugin PUBLIC FileRWPlugin)
IncludeCore(ConfiguratePlugin)
