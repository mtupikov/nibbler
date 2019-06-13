set(source
    GTKLib.cpp
)

set(headers
    GTKLib.h
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
#add_definitions(${GTK3_CFLAGS_OTHER})

add_library(GTK SHARED ${headers} ${source})

target_link_libraries(GTK snakeModels guiInterface ${GTK3_LIBRARIES})

target_include_directories(GTK INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
