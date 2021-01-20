/*
** EPITECH PROJECT, 2020
** Day06
** File description:
** Lower the case of a string
** By Loys Caucheteux
** login : loys.caucheteux@epitech.eu
*/

#include "my.h"

char *my_strlowcase(char *str) {
    int i = 0;
    int len = my_strlen(str) + 1;
    char new_str[len];
    int gratto;

    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90) {
            gratto = str[i];
            gratto = gratto + 32;
            str[i] = gratto;
            i++;
        }
        else
            i++;
    }
    str[i] = '\0';
    return (str);
}
