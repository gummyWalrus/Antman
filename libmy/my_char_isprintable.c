/*
** EPITECH PROJECT, 2020
** Day
** File description:
** check print able char
*/

#include "my.h"

int my_char_isprintable(char str) {
    int flag = 0;

    if (str >= 32 && str < 127)
        return (1);
    else
        return (0);
}
