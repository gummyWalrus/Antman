/*
** EPITECH PROJECT, 2021
** antman
** File description:
** list funcs
*/

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

void my_put_matches(matches *mtc)
{
    elemat *cur = mtc->first;

    for (int i = 0; cur->next != NULL; i++)
    {
        my_printf("pattern %d offset %d len %d\n", i, cur->mat->offset, cur->mat->len);
        cur = cur->next;
    }
}