##
## EPITECH PROJECT, 2022
## Hangman
## File description:
## stumper5
##

SRC	=	src/main.c \
		src/read_file.c \
		src/my_str_to_word_array.c \
		src/clean_str.c \
		src/find_space.c \
		src/init_struct.c \
		src/game.c \
		src/my_put_nbr.c

OBJ = $(SRC:.c=.o)

CFLAGS = -I ./include

NAME = hangman

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -g3

clean:
	rm -f src/*~

fclean: clean
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all

