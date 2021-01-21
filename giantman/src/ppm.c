/*
** EPITECH PROJECT, 2021
** antman
** File description:
** compress funcs
*/

#include "../../include/my.h"
#include "include/giantman.h"

char *ppm_uncompressor(char *data, char const *filepath)
{
    struct stat file;
    stat(filepath, &file);
    int size = file.st_size;
    char *image_size = malloc(sizeof(char) * 500);
    image_size = give_size_image(data);
    my_putstr(image_size);
    my_putchar('\n');
    data = &data[my_strlen(image_size)];
    uncompress_image(data, file.st_size * 5);

    return data;
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