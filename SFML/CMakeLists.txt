set(source
    SFMLib.cpp
)

set(headers
    SFMLib.h
)

find_package(SFML REQUIRED system window graphics)
include_directories(${SFML_INCLUDE_DIR})

add_library(SFMLib SHARED ${headers} ${source})

include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(SFMLib snakeModels guiInterface ${SFML_LIBRARIES})

target_include_directories(SFMLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
