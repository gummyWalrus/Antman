/*
** EPITECH PROJECT, 2021
** antman
** File description:
** chained handling
*/

#include "../../include/my.h"
#include "include/antman.h"

list *init_list(char value)
{
    list *li = malloc(sizeof(list));
    elem *el = malloc(sizeof(elem));

    el->next = NULL;
    el->value = value;
    el->index = 0;
    li->first = el;
    return (li);
}

void append_end(list *li, char value)
{
    elem *cur = li->first;
    elem *new = malloc(sizeof(elem));
    int index = 1;

    while (cur->next != NULL) {
        index++;
        cur = cur->next;
    }
    new->next = NULL;
    new->value = value;
    new->index = index;
    cur->next = new;
}

list *fstr_genlist(char *str, int size)
{
    list *li = init_list(str[0]);

    for (int i = 1; i != size && str[i] != '\0'; i++)
    {
        append_end(li, str[i]);
    }
    return (li);
}

void del_first(list *li)
{
    elem *tmp = li->first;
    int i;

    if (my_listlen(li) > 1) {
        li->first = li->first->next;
        free(tmp);
        tmp = li->first;
        li->first->index = 0;
        for (i = 0; tmp->next != NULL; i++)
        {
            tmp = tmp->next;
            tmp->index = i;
        }
        tmp->index = i;
    }
}

int my_listlen(list *li)
{
    int i;
    elem *cur = li->first;

    for (i = 1; cur->next != NULL; i++)
        cur = cur->next;
    return (i);
}