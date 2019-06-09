NAME = ../SFML.dylib

CC = clang++

DIR_SFML =  ~/.brew/Cellar/sfml/2.4.2_1

CFLAGS = -Wall -Wextra -Werror

IFLAGS = -I includes -I includes -I $(DIR_SFML)/include

GL =	-framework opengl \
		$(DIR_SFML)/lib/libsfml-graphics.2.4.2.dylib \
		$(DIR_SFML)/lib/libsfml-_window.2.4.2.dylib \
		$(DIR_SFML)/lib/libsfml-system.2.4.2.dylib \
		-L $(DIR_SFML)/lib -Wl,-rpath,$(DIR_SFML)/lib \

LFLAGS = -L $(DIR_SFML)/lib -lsfml-graphics -lsfml-_window -lsfml-system

SRC_DIR = ./sources/

OBJ_DIR = ./obj/

SRC = SFMLib.cpp

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -shared -o $@ $(OBJ) $(GL) -fPIC

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf  $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
