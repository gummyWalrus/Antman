/*
** EPITECH PROJECT, 2020
** Day03
** File description:
** my_putchar function but in error output
** By Loys Caucheteux
** login : loys.caucheteux@epitech.eu
*/

#include <unistd.h>
#include "my.h"

void my_err_putchar(char c)
{
    write(2, &c, 1);
}
