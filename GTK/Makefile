NAME = ../GTK.dylib

CC = g++

PKGCONFIG = $(shell which pkg-config)

CFLAGS = -Wall -Wextra -Werror  $(shell $(PKGCONFIG) --cflags gtk+-2.0)

IFLAGS = -I includes -I ../includes

LFLAGS = $(shell $(PKGCONFIG) --libs gtk+-2.0)

SRC_DIR = ./sources/

OBJ_DIR = ./obj/

SRC = GTKLib.cpp

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -shared -o $@ $(OBJ) $(LFLAGS) -fPIC

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
