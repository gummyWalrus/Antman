/*
** EPITECH PROJECT, 2021
** antman
** File description:
** main giantman
*/

#include "../include/my.h"
#include "include/giantman.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    char *data = fpath_text(argv[1]);

    if (argc == 3) {
        if (my_getnbr(argv[2]) == 1) {
            lz_uncompressor(data);
        }
    }
    return 0;
}

char *fpath_text(char const *path)
{
    struct stat st;
    char *data;
    int fd = open(path, 0);

    stat(path, &st);
    data = malloc((st.st_size) * sizeof(char));
    read(fd, data, st.st_size);
    close(fd);
    return (data);
}

match *get_match(char offset, char len, char c)
{
    offset -= 48;
    len -= 48;
    char *binoff = my_convbin_format(offset, 8);
    char *binlen = my_convbin_format(len, 8);
    match *mtc = malloc(sizeof(match));
    mtc->offset = my_bintoi(binoff);
    mtc->len = my_bintoi(binlen);
    mtc->value = c;
    return mtc;
}

void lz_uncompressor(char *data)
{
    int count = 0;
    char final_string[4096];
    match *mtc;

    for (int i = 0; data[i] != NULL; i += 3) {
        mtc = get_match(data[i], data[i + 1], data[i + 2]);
        my_strcat(final_string, steps_back(mtc, count, final_string));
        count = my_strlen(final_string);
    }
    my_putstr(final_string);
    my_putchar('\n');
}

char *steps_back(match *mtc, int count, char *final_string)
{
    char *buffer = malloc(sizeof(char) * (my_strlen(final_string) + 1));
    int count_saver = count;
    if (mtc->offset != 0)
        for ( ; count > count_saver - mtc->offset; count--);
    if (mtc->len != 0) {
        buffer = &final_string[count];
        buffer = my_cutstr(buffer, mtc->len);
    }
    buffer[my_strlen(buffer)] = mtc->value;
    return buffer;
}
