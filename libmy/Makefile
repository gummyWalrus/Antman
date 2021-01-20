##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## my first Makefile
##

NAME	=	libmy.a

SRC	=	*.c


OBJ     =	$(SRC:.c=.o)


all     :	$(NAME)
		rm -f $(OBJ)


$(NAME) :
		gcc -c $(SRC)
		ar rc $(NAME) $(OBJ)
		cp libmy.a ../antman/
		cp libmy.a ../giantman/

clean	:
		rm -f $(OBJ)

fclean  :	clean
		rm -f $(NAME)
		rm -f ../$(NAME)

re      :	fclean all clean

.PHONE: all clean fclean re
