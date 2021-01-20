/*
** EPITECH PROJECT, 2020
** Day06
** File description:
** reproduce the behaviour of the str cmp c function
** By Loys Caucheteux
** login : loys.caucheteux@epitech.eu
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2) {
    int s1_wei = 0;
    int s2_wei = 0;
    int i = 0;

    while (s1[i] != '\0') {
        s1_wei = (s1_wei + s1[i]);
        i++;
    }
    i = 0;
    while (s2[i] != '\0') {
        s2_wei = (s2_wei + s2[i]);
        i++;
    }
    if (s2_wei > s1_wei)
        return (-1);
    else if (s1_wei > s2_wei)
        return (1);
    else if (s1_wei == s2_wei)
        return (0);
}
