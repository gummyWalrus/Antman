/*
** EPITECH PROJECT, 2020
** my_convhexa
** File description:
** returns an int into an octal charray
*/
#include "my.h"
#include <stdlib.h>

char *my_convhexa(int nbr)
{
    int len = my_strlen(int_read(nbr));
    char *temp = malloc(len * 2 * sizeof(char));
    int i = 0;

    while (nbr > 16) {
        if ((nbr % 16) > 9){
            temp[i] = (87 + (nbr % 16));
            nbr = (nbr / 16);
            i++;
        }
        else {
            temp[i] = (48 + (nbr % 16));
            nbr = (nbr / 16);
            i++;
        }
    }
    (nbr <= 9) ? (temp[i] = (48 + nbr)) : (temp[i] = (87 + nbr));
    temp[i+1] = '\0';
    my_revstr(temp);
    return (temp);
}

