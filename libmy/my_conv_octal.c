/*
** EPITECH PROJECT, 2020
** my_conv_octal
** File description:
** returns an int into an octal charray
*/
#include "my.h"
#include <stdlib.h>

char *my_conv_octal(int nbr)
{
    int len = my_strlen(int_read(nbr));
    char *temp = malloc(len * 2 * sizeof(char));
    int i = 0;

    while (nbr > 8) {
        temp[i] = (48 + (nbr % 8));
        nbr = (nbr / 8);
        i++;
    }
    if (nbr > 0)
        temp[i] = (48 + nbr);
    temp[i+1] = '\0';
    my_revstr(temp);
    temp = fill_missing(temp, 3);
    return (temp);
}
