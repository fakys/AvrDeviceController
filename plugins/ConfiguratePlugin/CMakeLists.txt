add_library(
        ConfiguratePlugin
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ConfigurateLoader.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/config_parser_helper.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ConfigEntity/Configurate.cpp
)

target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/ConfigEntity)
target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/Exceptions)
target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/ConfigEntity/ConfigTypes)


target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_SOURCE_DIR}/include/Exceptions)
target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_SOURCE_DIR}/include/ProcessManager)
target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_SOURCE_DIR}/include/Patterns)
target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_SOURCE_DIR}/include/Arguments)
target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_SOURCE_DIR}/include/Communication)
target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_SOURCE_DIR}/include/Communication/drivers)


target_link_libraries(ConfiguratePlugin PUBLIC FileRWPlugin)
