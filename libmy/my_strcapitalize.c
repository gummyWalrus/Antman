/*
** EPITECH PROJECT, 2020
** my_strupcase
** File description:
** Task 08
*/

#include "my.h"

char *my_strlowcase_for_capitalize(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
        ++i;
    }
    return (str);
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    int j;

    my_strlowcase_for_capitalize(str);
    if (str[i] >= 'a' && str[i] <= 'z')
        str[i] -= 32;
    while (str[i])
    {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z') &&
        (str[i] < '0' || str[i] > '9'))
        {
            j = i;
            if (str[j + 1] >= 'a' && str[j + 1] <= 'z')
                str[j + 1] -= 32;
        }
        i++;
    }
    return (str);
}
