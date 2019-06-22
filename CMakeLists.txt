cmake_minimum_required(VERSION 3.12)

project("app")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include("AddDirectory")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory("DLLoader")
add_subdirectory("GuiInterface")
add_subdirectory("SnakeModels")
add_subdirectory("SDL")
#add_subdirectory("SFML")
add_subdirectory("OpenGL")
add_subdirectory("app")
