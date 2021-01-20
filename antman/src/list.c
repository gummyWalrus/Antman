/*
** EPITECH PROJECT, 2021
** antman
** File description:
** listing funcs
*/

#include "../../include/my.h"
#include "include/antman.h"

void my_putlist(list *li)
{
    elem *cur = li->first;

    for (int i = 0; cur->next != NULL; i++) {
        my_put_nbr(cur->index);
        my_putchar(':');
        my_putchar(cur->value);
        my_putchar(' ');
        cur = cur->next;
    }
    my_put_nbr(cur->index);
    my_putchar(':');
    my_putchar(cur->value);
    my_putchar('\n');
}

void my_putlistelem(elem *li)
{
    elem *cur = li;

    for (int i = 0; cur->next != NULL; i++) {
        my_put_nbr(cur->index);
        my_putchar(':');
        my_putchar(cur->value);
        my_putchar(' ');
        cur = cur->next;
    }
    my_put_nbr(cur->index);
    my_putchar(':');
    my_putchar(cur->value);
    my_putchar('\n');
}

matches *init_matches(elemat *first)
{
    matches *li = malloc(sizeof(matches));

    li->first = first;
    return (li);
}

void append_matches(matches *mtcs, elemat *elem)
{
    int index = 1;
    elemat *cur = mtcs->first;

    while (cur->next != NULL) {
        index++;
        cur = cur->next;
    }
    elem->index = index;
    cur->next = elem;
}

elemat *get_laste(matches *mtcs)
{
    elemat *res = mtcs->first;

    for (int i = 0; res->next != NULL; i++)
    {
        res = res->next;
    }
    return (res);
}