/*
** EPITECH PROJECT, 2021
** antman
** File description:
** compress funcs
*/

#include "../../include/my.h"
#include "include/antman.h"

char compress_image(int nbr)
{
    char *str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPKRSTUVWXYZ";
    char *units = "0123456789";
    char c;
    char d;

    if (nbr >= 0 && nbr < 10) {
        d = units[nbr];
        my_putchar('a');
        my_putchar(d);
    } else {
        c = str[nbr / 10];
        d = units[nbr % 10];
        my_putchar(c);
        my_putchar(d);
    }
    return c;
}

char *take_size_image(char *data)
{
    int count = 0;
    char *buffer = malloc(sizeof(char) * 500);
    int i;
    int j;

    for (i = 0; count < 2; i++) {
        if (data[i] == '\n')
            count++;
        else
            continue;
    }
    j = i;
    for ( ; data[i] != '\n'; i++);
    buffer = my_cutstr(&data[j], i - j);
    return buffer;
}

char *my_cutstr(char *str, int max)
{
    char *final_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (int i = 0; str[i] != '\0' && i < max; i++) {
        final_str[i] = str[i];
    }
    return final_str;
}