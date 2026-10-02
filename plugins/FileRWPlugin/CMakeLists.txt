add_library(FileRWPlugin INTERFACE)

target_include_directories(FileRWPlugin SYSTEM INTERFACE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(FileRWPlugin SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/drivers/abstracts)
target_include_directories(FileRWPlugin SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/exceptions)
target_include_directories(FileRWPlugin SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)