/*
** EPITECH PROJECT, 2020
** Myputnbr
** File description:
** write the number in argue
*/

#include <stdio.h>
#include "my.h"

int my_getnbr(char const *str)
{
    int sign = 1;
    int i = 0;
    int nb = 0;
    int nb_char = 0;

    while (str[i] != '\0' && (str[i] <= '0' || str[i] > '9')) {
        if (str[i] == '-')
            sign = sign * -1;
        i++;
    }
    if (str[i] == '\0')
        return (0);
    while (str[i] != '\0' && (str[i] <= '9' && str[i] >= '0')) {
        if ((nb == 214748364&&str[i]- 48 > 7) || nb > 214748364 || nb_char >10)
            return (0);
        nb = nb * 10 + (str[i] - '0');
        i++;
        nb_char++;
    }
    return (nb * sign);
}
