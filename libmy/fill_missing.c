/*
** EPITECH PROJECT, 2020
** My_printf
** File description:
** utils for my_printf
*/

#include "my.h"
#include <stdlib.h>

char *fill_missing(char *nb, int len)
{
    int lenof = my_strlen(nb);
    char *vic = malloc(len * sizeof(char) + 1);
    char *temp = malloc(len * sizeof(char) + 1);
    int i = 0;
    while (i < len - lenof) {
        vic[i] = '0';
        i++;
    }
    vic[i] = ('\0');
    temp = my_strcat(vic, nb);
    return (temp);
}
