/*
** EPITECH PROJECT, 2020
** Day05
** File description:
** returns the closest prime number that is superior to given int
** By Loys Caucheteux
** login : loys.caucheteux@epitech.eu
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int flag = 0;
    int tested = nb;
    int out;

    while (flag == 0) {
    out = my_is_prime(tested);
    if (out == 1)
        flag = 1;
    if (flag == 0)
        tested++;
    }
    return (tested);
}
