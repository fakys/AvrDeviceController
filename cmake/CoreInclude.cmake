function(IncludeCore)
#    Метод для регистрации зависимостей ядра
    target_include_directories(${ARGN} PUBLIC
            ${CMAKE_SOURCE_DIR}/include
            ${CMAKE_SOURCE_DIR}/include/Exceptions
            ${CMAKE_SOURCE_DIR}/include/Patterns
            ${CMAKE_SOURCE_DIR}/include/Arguments
            ${CMAKE_SOURCE_DIR}/include/Communication
            ${CMAKE_SOURCE_DIR}/include/Communication/drivers
    )
endfunction()