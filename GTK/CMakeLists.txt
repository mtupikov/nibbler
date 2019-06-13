set(source
    GTKLib.cpp
)

set(headers
    GTKLib.h
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK2 REQUIRED gtk+-2.0)

include_directories(${GTK2_INCLUDE_DIRS})
link_directories(${GTK2_LIBRARY_DIRS})
add_definitions(${GTK2_CFLAGS_OTHER})

add_library(GTK SHARED ${headers} ${source})

target_link_libraries(GTK snakeModels guiInterface ${GTK2_LIBRARIES})

target_include_directories(GTK INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
