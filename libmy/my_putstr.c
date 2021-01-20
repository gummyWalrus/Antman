/*
** EPITECH PROJECT, 2020
** Day04
** File description:
** displays the string given as parameter
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        my_putchar(str[i]);
        i++;
    }
}
