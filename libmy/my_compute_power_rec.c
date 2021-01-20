/*
** EPITECH PROJECT, 2020
** Day05
** File description:
** same as my_compute_power_it but recursive
** By Loys Caucheteux
** login : loys.caucheteux@epitech.eu
*/

#include <stdio.h>
#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    int result;
    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    result = (nb*(my_compute_power_rec(nb, p-1)));
    return (result);
}
