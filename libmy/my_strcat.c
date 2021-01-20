/*
** EPITECH PROJECT, 2020
** Day07
** File description:
** concatenates 2 strings
** By Loys Caucheteux
** login : loys.caucheteux@epitech.eu
*/

#include "my.h"

char *my_strcat(char *dest, char *src)
{
    int dest_len = my_strlen(dest);
    char *res = malloc((my_strlen(dest) + 1) * sizeof(char));
    int i = 0;
    res = dest;
    while (src[i] != '\0') {
        res[i + dest_len] = src[i];
        i++;
    }
    res[i + dest_len] = '\0';
    return (res);
}
