##
## EPITECH PROJECT, 2020
## bs antmain
## File description:
## makefile for antman
##

all:
	$(MAKE) -C libmy/.
	$(MAKE) -C antman/.
	$(MAKE) -C giantman/.

fclean:		clean

re:		fclean all

.PHONY:		all fclean re
