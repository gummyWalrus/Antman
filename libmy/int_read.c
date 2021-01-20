/*
** EPITECH PROJECT, 2020
** int_read
** File description:
** returns a char * of an int
*/

#include "my.h"
#include <stdlib.h>

char *int_read(int nb)
{
    char *str = malloc(64);
    int i = 0;
    int temp = nb;
    (nb < 0) ? (nb *= -1) : (0);
    if (nb == 0)
        return ("0\0");
    while (nb != 0) {
        str[i] = nb % 10 + 48;
        nb = nb / 10;
        i++;
    }
    if (temp < 0) {
        str[i] = '-';
        str[i + 1] = '\0';
    }
    else
        str[i] = '\0';
    str = my_revstr(str);
    return (str);
}
