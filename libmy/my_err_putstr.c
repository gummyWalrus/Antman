/*
** EPITECH PROJECT, 2020
** Day04
** File description:
** displays the string given as parameter
*/

#include "my.h"

int my_err_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        my_err_putchar(str[i]);
        i++;
    }
}
