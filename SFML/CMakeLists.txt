set(source
    SFMLib.cpp
)

set(headers
    SFMLib.h
)

add_library(SFML SHARED ${headers} ${source})

target_link_libraries(SFML snakeModels guiInterface)

target_include_directories(SFML INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
