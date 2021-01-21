/*
** EPITECH PROJECT, 2021
** antman
** File description:
** list funcs
*/

#include <sys/stat.h>
#include <sys/dir.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my.h"
#include "include/antman.h"

elem *felem_index(list *mtcs, int index)
{
    elem *res = mtcs->first;

    while (res->index != index && res->next != NULL)
    {
        res = res->next;
    }
    return (res);
}

match *get_bestmatch(matches *mtcs)
{
    elemat *cur = mtcs->first;
    elemat *res = mtcs->first;

    for (int i = 0; cur->next != NULL; i++)
    {
        if (res->mat->len < cur->mat->len) {
            res = cur;
            cur = cur->next;
        }
        else
            cur = cur->next;
    }
    if (res->mat->len < cur->mat->len) {
            res = cur;
            cur = cur->next;
    }
    return (res->mat);
}

matches *init_error(void)
{
    matches *error = malloc(sizeof(matches));

    error->first = malloc(sizeof(elemat));
    error->first->index = 84;
    return (error);
}

//my_printf("pattern %d offset %d len %d\n", i, cur->mat->offset, cur->mat->le);

void my_put_matches(matches *mtc)
{
    elemat *cur = mtc->first;

    my_putstr("\nnew buffers\n");
    for (int i = 0; cur->next != NULL; i++)
    {
        my_printf("index %d offset : %d len : %d letter %c\n", cur->index, cur->mat->offset, cur->mat->len, cur->mat->value);
        cur = cur->next;
    }
}

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