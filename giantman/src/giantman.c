/*
** EPITECH PROJECT, 2021
** antman
** File description:
** decompress funcs
*/

#include "../../include/my.h"
#include "include/giantman.h"

char *get_nstr(char *str, int n)
{
    char *res = malloc((n + 1) * sizeof(char));
    int i;

    for (i = 0; i != n; i++)
        res[i] = str[i];
    res[i] = '\0';
    return (res);
}

char *my_convbin_format(int nbr, int len)
{
    char *temp = malloc((len + 1) * sizeof(char));
    int i = 0;

    while (nbr >= 2) {
        temp[i] = (48 + (nbr % 2));
        nbr = (nbr / 2);
        i++;
    }
    if (nbr > 0)
        temp[i] = (48 + nbr);
    temp[i + 1] = '\0';
    my_revstr(temp);
    temp = fill_missing(temp, len);
    return (temp);
}

int my_bintoi(char *bin)
{
    char *str = my_strdup(bin);
    int res = 0;

    my_revstr(str);
    for (int i = 0; str[i] != '\0'; i++)
        res += ((str[i] - '0') * my_compute_power_rec(2, i));
    return (res);
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < nb && dest[i + j] != '\0'; i++);
    if (nb > i) {
        for (j = 0; i + j < nb; j++)
            dest[i + j] = src[j];
    }
    dest[i + j] = '\0';
    return (dest);
}

char *my_cutstr(char *str, int max)
{
    char *final_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (int i = 0; str[i] != '\0' && i < max; i++) {
        final_str[i] = str[i];
    }
    return final_str;
}
