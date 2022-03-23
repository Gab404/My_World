##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC =   ./src/my_world.c \
		./src/coord_map.c \
		./src/window.c \
		./src/create_line.c \
		./src/transformation.c \
		./src/help.c \
		./src/deform_map.c \
		./src/event.c \
		./src/banner.c \
		./src/button.c \
		./src/fct_btn.c \
		./src/lib.c \
		./src/lib_2.c \
		./src/save.c \
		./src/size_tool.c \
		./src/str_to_word_array.c \
		./src/load_map.c \
		./src/open_file.c \
		./src/handle_background.c \
		./src/menu.c \
		./src/menu_2.c \
		./src/menu_3.c \
		./src/menu_3_2.c \
		./src/display.c \
		./src/create_line_helper1.c \
		./src/create_element.c \
		./src/music.c \


OBJ    =    $(SRC:.c=.o)

NAME   =    my_world

CFLAGS += -Wall -Wextra

CPPFLAGS	+=	-I./includes

all:    $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -l csfml-window -l csfml-graphics \
	-l csfml-system -l csfml-audio -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
	fclean
	re
