set(source
    SDLib.cpp
)

set(headers
    SDLib.h
)

if (WIN32)
    set(SDL2_DIR ${CMAKE_CURRENT_SOURCE_DIR})
endif()

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_library(SDLib SHARED ${headers} ${source})

target_link_libraries(SDLib snakeModels guiInterface ${SDL2_LIBRARIES})

target_include_directories(SDLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
