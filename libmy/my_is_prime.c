/*
** EPITECH PROJECT, 2020
** Day05
** File description:
** Checks if a number is a prime number or not
*/

#include "my.h"

int my_is_prime(int nb)
{
    int i = 2;
    while (nb % i != 0)
    {
        i++;
    }
    if (i == nb)
    {
        return (1);
    }
    else{
        return (0);}
}
