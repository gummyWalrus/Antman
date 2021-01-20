/*
** EPITECH PROJECT, 2020
** Day04
** File description:
** counts the number of char in a string
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}
