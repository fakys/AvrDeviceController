add_library(
        FileRWPlugin
        ${CMAKE_CURRENT_SOURCE_DIR}/src/FileEntity.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/AllFileReadDriver.cpp
)


target_include_directories(FileRWPlugin PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/drivers/abstracts
        ${CMAKE_CURRENT_SOURCE_DIR}/include/drivers
        ${CMAKE_CURRENT_SOURCE_DIR}/include/exceptions
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)


IncludeCore(FileRWPlugin)
