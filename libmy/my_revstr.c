/*
** EPITECH PROJECT, 2020
** Day06
** File description:
** Reverses a String
** By Loys Caucheteux
** login : loys.caucheteux@epitech.eu
*/

#include "my.h"

char *my_revstr(char *str)
{
    int len = (my_strlen(str)-1);
    char mem;

    if (len % 2 == 1) {
        for (int i = 0; i < ((len / 2) + 1); i++) {
            mem = str[i];
            str[i] = str[(len) - i];
            str[len - i] = mem;
        }
    }
    if (len % 2 == 0) {
        for (int i = 0; i < (len / 2); i++) {
            mem = str[i];
            str[i] = str[(len) - i];
            str[len - i] = mem;
        }
    }
    return (str);
}
