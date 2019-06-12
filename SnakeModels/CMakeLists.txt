set(source
    Block.cpp
    FoodBlock.cpp
    GameModel.cpp
    Map.cpp
    Snake.cpp
    SnakeBlock.cpp
)

set(headers
    Block.h
    FoodBlock.h
    GameModel.h
    Map.h
    Ptrs.h
    Snake.h
    SnakeBlock.h
)

add_library(snakeModels STATIC ${headers} ${source})

target_include_directories(snakeModels INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
