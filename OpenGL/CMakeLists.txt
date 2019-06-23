set(source
    OpenGLib.cpp
)

set(headers
    OpenGLib.h
)

find_package(glfw3 3.3 REQUIRED)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

add_library(OpenGLib SHARED ${headers} ${source})

target_link_libraries(OpenGLib snakeModels guiInterface ${OPENGL_gl_LIBRARY} glfw)

target_include_directories(OpenGLib PUBLIC ${OPENGL_INCLUDE_DIR})
target_include_directories(OpenGLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
