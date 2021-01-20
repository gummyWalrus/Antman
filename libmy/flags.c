/*
** EPITECH PROJECT, 2020
** myprintf
** File description:
** flag function
*/

#include "my.h"

void s_flag(char *str)
{
    my_putstr(str);
}

void sh_flag(char *str)
{
    my_putstr(my_showstr_octal(str));
}

void o_flag(int nbr)
{
    my_putstr(rm_zero(my_conv_octal(nbr)));
}

void x_flag(int nbr)
{
    my_putstr(my_convhexa(nbr));
}

void di_flag(int nbr)
{
    my_putstr(int_read(nbr));
}