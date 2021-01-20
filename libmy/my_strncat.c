/*
** EPITECH PROJECT, 2020
** Day07
** File description:
** concatenates 2 strings
** By Loys Caucheteux
** login : loys.caucheteux@epitech.eu
*/

#include "my.h"

char * my_strncat(char *dest, char const *src, int n)
{
    int dest_len = my_strlen(dest);
    int i = 0;
    int flag;

    while (src[i] != '\0' && i < n) {
        dest[i + dest_len] = src[i];
        i++;
        if (i > n)
            flag = 1;
    }
    dest[dest_len + i] = ('\0');
    return (dest);
}

