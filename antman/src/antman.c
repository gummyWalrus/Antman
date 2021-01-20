/*
** EPITECH PROJECT, 2021
** antman
** File description:
** main
*/

#include "../../include/my.h"
#include "include/antman.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    char *data = fpath_text(argv[1]);
    int o;

    if (argc == 3) {
        if (my_getnbr(argv[2]) == 1) {
            lzing(data);
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

void my_putinfo(match *mat)
{
    // my_putchar(32 + mat->offset);
    // my_putchar(32 + mat->len);
    // my_putchar(mat->value);
    my_printf("outputed offset %d len %d\n", mat->offset, mat->len);
}