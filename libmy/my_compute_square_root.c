/*
** EPITECH PROJECT, 2020
** Day05
** File description:
** returns the square root of the given int if it's a whole number
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    for (int i = 1; i * i <= nb; i++)
    {
        if ((nb % i == 0) && (nb / i == i))
            return (i);
    }
            return (0);
}
