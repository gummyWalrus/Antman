/*
** EPITECH PROJECT, 2020
** Day06
** File description:
** checks if a string is alphabetic
** By Loys Caucheteux
** login : loys.caucheteux@epitech.eu
*/

#include "my.h"

int my_str_isalpha(char const *str) {
    int i = 0;
    int n_alpha = 0;
    int flag = 0;

    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90
            || str[i] >= 97 && str[i] <= 122) {
            n_alpha++;
            i++;
        }
        else
            i++;
    }
    if ((n_alpha == (i)) || (my_strlen(str)-1) == 0)
        return (1);
    else
        return (0);
}
