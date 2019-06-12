add_library(guiInterface INTERFACE)

target_sources(guiInterface INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/IGui.h)

target_include_directories(guiInterface INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})