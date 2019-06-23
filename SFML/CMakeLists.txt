set(source
    SFMLib.cpp
)

set(headers
    SFMLib.h
)

find_package(SFML 2.5 REQUIRED system window graphics)

add_library(SFMLib SHARED ${headers} ${source})

target_link_libraries(SFMLib snakeModels guiInterface sfml-graphics sfml-window sfml-system)

target_include_directories(SFMLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
