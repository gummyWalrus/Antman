/*
** EPITECH PROJECT, 2020
** Day08
** File description:
** alocates memory for a string
** By Loys Caucheteux
** login : loys.caucheteux@epitech.eu
*/

#include "my.h"

char *my_strdup(char *src)
{
    int len = (my_strlen(src)+1);
    char *str_alloc = malloc(sizeof(char) * len);

    my_strcpy(str_alloc, src);
    str_alloc[len] = ('\0');
    return (str_alloc);
}
