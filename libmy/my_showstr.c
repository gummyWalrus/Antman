/*
** EPITECH PROJECT, 2020
** Day06
** File description:
** prints a string that contains non printable chars
** but they are written in Hexa Base
** By Loys Caucheteux
** login : loys.caucheteux@epitech.eu
*/

#include <stdio.h>
#include "my.h"

int my_showstr(char *str)
{
    int charac;

    for (int i = 0; str[i] != '\0'; i++) {
        charac = str[i];
        if (my_char_isprintable(str[i]) != 1) {
            my_putchar('/');
            my_putstr(my_convhexa(charac));
        }
        else {
            my_putchar(str[i]);
        }
    }
    return (0);
}
