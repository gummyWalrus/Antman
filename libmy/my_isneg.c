/*
** EPITECH PROJECT, 2020
** Day03
** File description:
** functions that say if a number is negative or positive
** By Loys Caucheteux
** login : loys.caucheteux@epitech.eu
*/

#include "my.h"

int my_isneg(int n)
{
    if (n > 0)
    {
        my_putchar('P');
        my_putchar('\n');
    }
    else if (n < 0)
    {
        my_putchar('N');
        my_putchar('\n');
    }
    else
    {
        my_putchar('P');
        my_putchar('\n');
    }
    return (0);
}
