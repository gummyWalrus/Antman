/*
** EPITECH PROJECT, 2020
** my_putunsigned
** File description:
** myputunsigned
*/

#include "my.h"

int	my_putunsigned(unsigned int result)
{
    unsigned int num;

    num = result % 10;
    result = result / 10;
    if (result > 0)
        my_putunsigned(result);
    my_putchar(num + '0');
    return (0);
}
