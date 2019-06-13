set(source
    SDLib.cpp
)

set(headers
    SDLib.h
)

set(SDL2_DIR ${CMAKE_CURRENT_SOURCE_DIR})

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_library(SDL SHARED ${headers} ${source})

target_link_libraries(SDL snakeModels guiInterface ${SDL2_LIBRARIES})

target_include_directories(SDL INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
