##
## EPITECH PROJECT, 2020
## bs antmain
## File description:
## makefile for antman
##

NAME=		giantman

SRC=		src/giantman.c	\
			src/errors.c	\
			src/decompress.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME) clean

$(NAME):	$(OBJ)
		gcc -g -o $(NAME) $(SRC) libmy.a

clean:
		rm -f $(OBJ)

fclean:		clean

re:		fclean all

.PHONY:		all fclean clean re
