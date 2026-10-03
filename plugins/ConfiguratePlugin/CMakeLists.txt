add_library(
        ConfiguratePlugin
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ConfigurateLoader.cpp
)

target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/ConfigEntity)


target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_SOURCE_DIR}/include/ProcessManager)
target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_SOURCE_DIR}/include/Patterns)
target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_SOURCE_DIR}/include/Arguments)
target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_SOURCE_DIR}/include/Communication)
target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_SOURCE_DIR}/include/Communication/drivers)
