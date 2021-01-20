/*
** EPITECH PROJECT, 2020
** Int read
** File description:
** returns an int into a string
*/
#include "my.h"
#include <stdlib.h>

char *my_showstr_octal(char *str)
{
    int charac;
    char *res = malloc(my_strlen(str) * 2 * sizeof(char));
    char *temp;
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        temp = malloc(my_strlen(str) * sizeof(char));
        charac = str[i];
        if (my_char_isprintable(str[i]) != 1) {
            temp[0] = '\\';
            temp = my_strcat(temp, my_conv_octal(charac));
            res = my_strcat(res, my_strdup(temp));
            j = j + my_strlen(temp) - 1;
        }
        else {
            res[j] = str[i];
        }
        j++;
    }
    res[j] = '\0';
    return (res);
}
