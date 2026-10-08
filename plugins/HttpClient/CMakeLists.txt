add_library(
        HttpClient
)


target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_SOURCE_DIR}/include/Exceptions)
target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_SOURCE_DIR}/include/ProcessManager)
target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_SOURCE_DIR}/include/Patterns)
target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_SOURCE_DIR}/include/Arguments)
target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_SOURCE_DIR}/include/Communication)
target_include_directories(ConfiguratePlugin PUBLIC ${CMAKE_SOURCE_DIR}/include/Communication/drivers)


#Загружаем библиотеку для веб сервера
CPMAddPackage(
        NAME crow
        GITHUB_REPOSITORY CrowCpp/Crow
        GIT_TAG v1.0+5
)

target_link_libraries(AvrDeviceController PUBLIC Crow)
