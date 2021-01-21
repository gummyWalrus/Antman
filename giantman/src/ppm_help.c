/*
** EPITECH PROJECT, 2021
** antman
** File description:
** compress funcs
*/

#include "../../include/my.h"
#include "include/giantman.h"

char *uncompress_image(char *data, int size)
{
    int value;

    for (int i = 0; data[i] != '\0'; i += 2) {
        value = uncompress_value(data[i], 1);
        value += uncompress_value(data[i + 1], 2);
        from_int_to_str(value);
        value = 0;
    }
}

char *from_int_to_str(int nbr)
{
    int size = 0;

    if (nbr >= 100 && nbr < 256)
        size = 3;
    else if (nbr < 100 && nbr >= 10)
        size = 2;
    else if (nbr >= 0 && nbr < 10)
        size = 1;

    if (size == 1) {
        my_putchar(nbr + '0');
    } else if (size == 2) {
        my_putchar(((nbr - (nbr % 10)) / 10) + '0');
        my_putchar((nbr % 10) + '0');
    } else if (size == 3) {
        my_putchar((nbr / 100) + '0');
        my_putchar(((nbr % 100) / 10) + '0');
        my_putchar((nbr % 10) + '0');
    }
    my_putchar('\n');
}

int uncompress_value(char c, int l)
{
    char *str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPKRSTUVWXYZ";
    char *units = "0123456789";
    int i;

    if (l == 1) {
        for (i = 0; str[i] != c; i++);
        i *= 10;
    } else if (l == 2) {
        for (i = 0; units[i] != c; i++);
    }
    return i;
}

char *give_size_image(char *data)
{
    int count = 0;
    char *buffer = malloc(sizeof(char) * 500);
    int i;

    my_putstr("P3\n# Created by GIMP version 2.10.20 PNM plug-in\n");
    for (i = 0; count < 2; i++) {
        if ((data[i] < '0' || data[i] > '9') && count == 1) {
            count++;
        } if (data[i] == ' ' && count == 0) {
            count++;
        }
    }
    buffer = my_cutstr(data, i-1);
    return buffer;
}