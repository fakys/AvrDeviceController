function(IncludeCore)
#    Метод для регистрации зависимостей ядра
    target_include_directories(${ARGN} PUBLIC
            ${CMAKE_SOURCE_DIR}/include
            ${CMAKE_SOURCE_DIR}/include/Exceptions
            ${CMAKE_SOURCE_DIR}/include/Patterns
            ${CMAKE_SOURCE_DIR}/include/Arguments
            ${CMAKE_SOURCE_DIR}/include/Communication
            ${CMAKE_SOURCE_DIR}/include/Communication/drivers
            ${CMAKE_SOURCE_DIR}/include/FileRW/include/drivers/abstracts
            ${CMAKE_SOURCE_DIR}/include/FileRW/include/drivers
            ${CMAKE_SOURCE_DIR}/include/FileRW/include/exceptions
            ${CMAKE_SOURCE_DIR}/include/FileRW/include
            ${CMAKE_SOURCE_DIR}/include/Configurate
            ${CMAKE_SOURCE_DIR}/include/Configurate/Exceptions
            ${CMAKE_SOURCE_DIR}/include/Configurate/ConfigEntity
            ${CMAKE_SOURCE_DIR}/include/Configurate/ConfigEntity/ConfigTypes
    )
endfunction()