/*
** EPITECH PROJECT, 2021
** antman
** File description:
** grosse galere
*/

#include "../../include/my.h"
#include "include/antman.h"

int cmp_is_over(strlist *cmp)
{
    strelem *cur = cmp->first;
    int len = 0;

    for (int i = 0; cur->next != NULL; i++)
    {
        len += cur->value[1] - 32;
        cur = cur->next;
    }
    if (len >= 32)
        return (0);
    return (1);
}

int my_strlistlen(strlist *li)
{
    int i;
    strelem *cur = li->first;

    for (i = 1; cur->next != NULL; i++)
        cur = cur->next;
    return (i);
}

void my_putmstr(strlist *cmp)
{
    strelem *cur = cmp->first;

    while (cur->next != NULL)
    {
        my_printf("offset %d len %d value %c\n",
        (cur->value[0] - 32), (cur->value[1] - 32), (cur->value[2]));
        cur = cur->next;
    }
    my_printf("offset %d len %d value %c\n",
    (cur->value[0] - 32), (cur->value[1] - 32), (cur->value[2]));
}

int get_matchlenght(char *sch, char *lok)
{
    int i = 0;

    for (i = 0; lok[i] != '\0' && sch[i] != '\0' && sch[i] == lok[i]; i++)
    {
    }
    return (i);
}