NAME = ../SDL.dylib

CC = clang++

CFLAGS = -Wall -Wextra -Werror

IFLAGS = -I includes -I ../includes -I ~/.brew/Cellar/sdl2/2.0.8/include/SDL2

LFLAGS = -L ~/.brew/lib -lSDL2 -lpng

CPP11 = -std=c++11

SRC_DIR = ./sources/

SRC_MODEL_DIR = ../sources/model/

OBJ_DIR = ./obj/

SRC =       SDLib.cpp \

SRC_MODEL = Block.cpp \
            GameModel.cpp \
            Map.cpp \
            Snake.cpp \
            SnakeBlock.cpp \
            FoodBlock.cpp \

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))\

OBJ_M = $(addprefix $(OBJ_DIR), $(SRC_MODEL:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_M)
	$(CC) -shared -o $@ $(OBJ) $(OBJ_M) $(LFLAGS) -fPIC

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) $(CPP11) -o $@ -c $< $(CFLAGS) $(IFLAGS)

$(OBJ_DIR)%.o: $(SRC_MODEL_DIR)%.cpp
	$(CC) $(CPP11) -o $@ -c $< $(CFLAGS) $(IFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf  $(NAME)
	rm -rf  $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
