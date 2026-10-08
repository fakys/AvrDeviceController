add_library(
        HttpClientPlugin
        ${CMAKE_CURRENT_SOURCE_DIR}/src/HttpClientPlugin.cpp
)

target_include_directories(HttpClientPlugin PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)


#Загружаем библиотеку для веб сервера
CPMAddPackage(
        NAME crow
        GITHUB_REPOSITORY CrowCpp/Crow
        GIT_TAG v1.3
)

target_link_libraries(AvrDeviceController PUBLIC Crow)
IncludeCore(AvrDeviceController)

