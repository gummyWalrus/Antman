/*
** EPITECH PROJECT, 2021
** antman
** File description:
** compress funcs
*/

#include "../../include/my.h"
#include "include/antman.h"

void lzing(char *str)
{
    list *search = init_list(str[0]);

    for (int i = 0; i <= my_strlen(str); i)
    {
        (i != 0) ? append_end(search, str[i]) : (0);
        (my_listlen(search) >= 90) ? (del_first(search)) : (0);
        i += my_putlz(&str[i], search);
    }
}

int my_putlz(char *c, list *sch)
{
    list *look = fstr_genlist(c, 32);
    matches *mtc = get_matchs(sch, look);
    match *mat;
    int flag = 0;

    (mtc->first->index != 84) ? (flag = 1) : (0);
    if (flag == 1) {
        mat = get_bestmatch(mtc);
        mat->value = c[mat->len];
    }
    else {
        mat = malloc(sizeof(match));
        mat->value = c[0];
        mat->offset = 0;
        mat->len = 0;
    }
    ///my_putinfo(mat);
    return (mat->len + 1);
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
    my_putinfo(mc);
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