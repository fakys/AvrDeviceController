cmake_minimum_required(VERSION 3.28)

project(AvrDeviceController)
project(AvrDeviceController LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Регистрируем src файлы
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(AvrDeviceController ${SOURCES})

#todo Этот хардкод убрать!
add_definitions(-D_PROJECT_NAME_="AvrDeviceController")
add_definitions(-D_PROJECT_CONFIG_PATH_="/etc/avr_device_controller/main.conf")

#Регистрируем до библиотеки
include(cmake/CPM.cmake) #Инструмет для загруски сторонних репозиториев
include(cmake/CoreInclude.cmake) #Инструмент для загрузки зависимостей ядра
include(cmake/PluginRegister.cmake) #Загрузчик плагинов

IncludeCore(AvrDeviceController)