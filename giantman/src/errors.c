/*
** EPITECH PROJECT, 2021
** giantman
** File description:
** errors
*/

#include "../../include/my.h"
#include "include/giantman.h"
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int errors(int ac, char const **argv)
{
    int fd;
    DIR* directory;
    if (ac != 3)
        return 84;

    directory = opendir(argv[1]);
    if (errno != ENOTDIR) {
        my_putstr("This is a directory\n");
        return 84;
    }

    fd = open(argv[1], 0);
    if (fd == -1) {
        my_putstr("No such file or directory\n");
        return 84;
    }
    return 0;
}