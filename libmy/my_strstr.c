/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** Task 05
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int	i = 0;
    int	n;

    while (str[i])
    {
        n = 0;
        while (str[i + n] && str[i + n] == to_find[n])
            ++n;
        if (!to_find[n])
            return (str + i);
        ++i;
    }
    return (0);
}
