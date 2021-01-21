/*
** EPITECH PROJECT, 2021
** antman
** File description:
** compress funcs
*/

#include "../../include/my.h"
#include "include/antman.h"

char *lzing(char *str)
{
    list *search = init_list(str[0]);
    char *res = malloc(my_strlen(str) * 2);

    res[0] = '0';
    for (int i = 0; i <= my_strlen(str); i += 32)
    {
        (i != 0) ? append_end(search, str[i]) : (0);
        (my_listlen(search) >= 90) ? (del_first(search)) : (0);
        my_strcat(res, my_matcher(&str[i], search));
    }
    return (&res[1]);
}

match *my_putlz(list *look, list *sch)
{
    matches *mtc = get_matchs(sch, look);
    match *mat;
    int flag = 0;

    (mtc->first->index != 84) ? (flag = 1) : (0);
    if (flag == 1) {
        mat = get_bestmatch(mtc);
    }
    else {
        mat = malloc(sizeof(match));
        mat->offset = 0;
        mat->len = 0;
    }
    return (mat);
}

matches *get_matchs(list *sch, list *look)
{
    elem *csch = sch->first;
    elem *cur_look = look->first;
    matches *mtc;
    matches *error = init_error();
    int i = 0;

    for (int j = 0; csch->next != NULL; j++)
    {
        if (csch->value == cur_look->value) {
            if (i == 0) {
                mtc = init_matches(get_match(sch, cur_look, csch));
                i++;
                csch = csch->next;
            }
            else {
                append_matches(mtc, get_match(sch, cur_look, csch));
                i++;
                csch = csch->next;
            }
        }
        else
            csch = csch->next;
    }
    if (i == 0)
        return (error);
    return (mtc);
}

elemat *get_match(list *sch, elem *cur_look, elem *cur_sch)
{
    elemat *mtc = malloc(sizeof(elemat));
    match *mc = malloc(sizeof(match));

    mc->offset = (my_listlen(sch) - cur_sch->index);
    mc->len = get_matchlen(cur_look, cur_sch);
    mtc->mat = mc;
    mtc->next = NULL;
    return (mtc);
}

int get_matchlen(elem *look, elem *sch)
{
    elem *clook = look;
    elem *csch = sch;
    int i;

    for (i = 0; clook->value == csch->value \
    && clook->next != NULL && csch->next != NULL; i++)
    {
        clook = clook->next;
        csch = csch->next;
    }
    return (i);
}