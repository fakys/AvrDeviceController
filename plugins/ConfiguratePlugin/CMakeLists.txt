add_library(
        ConfiguratePlugin
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ConfigurateLoader.cpp
)

target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/ConfigEntity)

