/*
** EPITECH PROJECT, 2020
** Day06
** File description:
** Copies a string into another
** By Loys Caucheteux
** login : loys.caucheteux@epitech.eu
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
        int i = 0;

        while (src[i] != ('\0'))
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
        return (dest);
}
