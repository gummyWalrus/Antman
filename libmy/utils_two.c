/*
** EPITECH PROJECT, 2020
** My_printf
** File description:
** utils for my_printf
*/

#include "my.h"
#include <stdlib.h>

int get_flag(char flag)
{
    int str_flaglist[11] = {'s',  'S', 'd', 'i', 'c', 'x', 'X', \
    'o', 'b', 'u', 0};
    int i = 0;
    while (str_flaglist[i] != 0)
    {
        if (str_flaglist[i] == flag)
            return (i);
        else
            i++;
    }
}

char *rm_zero(char *nbr)
{
    int i = 0;

    while (nbr[i] == '0')
        i++;
    return (&nbr[i]);
}
