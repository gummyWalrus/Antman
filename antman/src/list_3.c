/*
** EPITECH PROJECT, 2021
** antman
** File description:
** listing
*/

#include "../../include/my.h"
#include "include/antman.h"

strlist *init_strlist(char *value)
{
    strlist *li = malloc(sizeof(strlist));
    strelem *elem = malloc(sizeof(strelem));

    elem->value = value;
    elem->next = NULL;
    elem->prev = NULL;
    elem->index = 0;
    li->first = elem;
    return (li);
}

void append_endstr(strlist *li, char *value)
{
    strelem *elem = malloc(sizeof(strelem));
    strelem *cur = li->first;
    int index = 0;

    elem->value = value;
    elem->next = NULL;

    while (cur->next != NULL) {
        index++;
        cur = cur->next;
    }
    elem->index = index;
    cur->next = elem;
    elem->prev = cur;
}

void append_startstr(strlist *li, char *value)
{
    strelem *elem = malloc(sizeof(strelem));
    strelem *tmp = li->first;
    int i;

    elem->value = value;
    elem->next = tmp;
    elem->prev = NULL;
    elem->index = 0;
    for (i = 1; tmp->next != NULL; i++)
    {
        tmp->index = i;
        tmp = tmp->next;
    }
    tmp->index = i;
    tmp->prev = elem;
    li->first = elem;
}

void del_bindex(strlist *li, int index)
{
    strelem *cur = li->first;
    int i = 0;

    if (index == 0 && (my_strlistlen(li) > 1)) {
        li->first = li->first->next;
        free(cur);
        cur = li->first;
        li->first->index = 0;
        for (i = 0; cur->next != NULL; i++) {
            cur = cur->next;
            cur->index = i;
        }
        cur->index = i;
    }
    else if (index == my_strlistlen(li)) {
        while (cur->next != NULL)
            cur = cur->next;
        cur->prev->next = NULL;
        free(cur);
    }
    else {
        for (int i = 0; i != index; i++)
            cur = cur->next;
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        free(cur);
    }
}