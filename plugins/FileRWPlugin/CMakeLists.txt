add_library(
        FileRWPlugin
        ${CMAKE_CURRENT_SOURCE_DIR}/src/FileEntity.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/AllFileReadDriver.cpp
)

target_include_directories(FileRWPlugin PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(FileRWPlugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/drivers/abstracts)
target_include_directories(FileRWPlugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/drivers)
target_include_directories(FileRWPlugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/exceptions)
target_include_directories(FileRWPlugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)