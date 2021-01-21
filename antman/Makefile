##
## EPITECH PROJECT, 2020
## bs antmain
## File description:
## makefile for antman
##

NAME=		antman

SRC=		src/antman.c	\
			src/compress.c	\
			src/list.c		\
			src/listing.c	\
			src/compress_2.c\
			src/list_4.c	\
			src/list_3.c	\
			src/pls_work.c	\
			src/list_2.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME) clean

$(NAME):	$(OBJ)
		gcc -g -o $(NAME) $(SRC) libmy.a

clean:
		rm -f $(OBJ)

fclean:		clean

re:		fclean all

.PHONY:		all fclean clean re
