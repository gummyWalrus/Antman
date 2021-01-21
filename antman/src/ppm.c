/*
** EPITECH PROJECT, 2021
** antman
** File description:
** compress funcs
*/

#include "../../include/my.h"
#include "include/antman.h"

char **ppm_compressor(char *data, char const *filepath)
{
    struct stat t;
    stat(filepath, &t);
    int size = t.st_size;
    char *buffer = malloc(sizeof(char) * 500);
    buffer = take_size_image(data);
    my_putstr(buffer);
    char **tab = from_str_to_tab(&data[50 + my_strlen(buffer)]);
    int nbr;

    for (int k = 0; tab[k] != NULL; k++) {
        nbr = from_str_to_int(tab[k]);
        compress_image(nbr);
    }
    return tab;
}

char **from_str_to_tab(char *str)
{
    int len = my_strlen(str);
    int j = 0;
    int t = 0;
    char **tab = malloc(sizeof(char *) * len);
    tab[j] = malloc(sizeof(char) * len);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            j++;
            t = 0;
            tab[j] = malloc(sizeof(char) * len);
        } else {
            tab[j][t] = str[i];
            t++;
        }
    }
    return tab;
}

int from_str_to_int(char *str)
{
    int sign = 1;
    int result = 0;
    int i = 0;

    if (str[1] == '-') {
        sign = -1;
        i += 1;
    }

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            result *= 10;
            result += str[i] - '0';
        } else
            return (result);
        i++;
    }
    return result;
}