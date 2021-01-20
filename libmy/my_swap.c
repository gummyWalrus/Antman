/*
** EPITECH PROJECT, 2020
** Day04
** File description:
** Swap the value of two param
** By Loys Caucheteux
** login : loys.caucheteux@epitech.eu
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int c;
    int d;

    c = *a;
    d = *b;
    *b = c;
    *a = d;
}
