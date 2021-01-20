/*
** EPITECH PROJECT, 2020
** myprintf
** File description:
** flag file
*/

#include "my.h"

void b_flag(unsigned int nbr)
{
    my_putstr(my_convbin(nbr));
}

void u_flag(unsigned int nbr)
{
    my_putunsigned(nbr);
}