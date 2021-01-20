/*
** EPITECH PROJECT, 2020
** Day06
** File description:
** Copies a string into another
** By Loys Caucheteux
** loys.caucheteux@epitech.eu
*/

#include <stdio.h>
#include "my.h"

char *my_strncpy (char *dest , char const *src, int n)
{
    int i = my_strlen(src);
    int j = 0;

    while (j < n)
    {
        dest[j] = src[j];
        if (j > i)
        {
            dest[j] = '\0';
            j = n * 2;
        }
        j++;
    }
    return (dest);
}
