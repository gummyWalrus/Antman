/*
** EPITECH PROJECT, 2020
** Day04
** File description:
** Swap the value of two param
** By Loys Caucheteux
** login : loys.caucheteux@epitech.eu
*/

#include "my.h"
#include <stdlib.h>

char *my_convbin(unsigned int nbr)
{
    char *temp = malloc(64 * sizeof(char));
    int i = 0;

    while (nbr >= 2) {
        temp[i] = (48 + (nbr % 2));
        nbr = (nbr / 2);
        i++;
    }
    if (nbr > 0)
        temp[i] = (48 + nbr);
    temp[i+1] = '\0';
    my_revstr(temp);
    return (temp);
}
