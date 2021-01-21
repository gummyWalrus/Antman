/*
** EPITECH PROJECT, 2021
** antman
** File description:
** compresssoooorrrr
*/

#include "../../include/my.h"
#include "include/antman.h"

char *my_matcher(char *c, list *search)
{
    char *looker = my_strdup(get_nstr(c, 32));
    char *sch = my_liststr(search);
    strlist *match_cmp;
    strlist *ncmp = init_strlist(looker);

    match_cmp = init_strlist("*\0");
    compressor(match_cmp, ncmp, ncmp->first, sch);
    return (match_cmp->first->value);
}

matches *matches_fbuffer(char *c, list *search)
{
    list *look = fstr_genlist(c, 32);
    elem *clook = look->first;
    elem *csch = search->first;
    matches *mtcs;
    elemat *cur;

    for (int i = 0; i != 32; i++)
    {
        cur = malloc(sizeof(elemat));
        cur->mat = my_putlz(look, search);
        if (i == 0) {
            mtcs = init_matches(cur);
            clook = clook->next;
            del_first(look);
        }
        else {
            append_matches(mtcs, cur);
            clook = clook->next;
            del_first(look);
        }
    }
    my_put_matches(mtcs);
    return (mtcs);
}

elemat *elem_get_bestmatch(matches *mtcs)
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
    return (res);
}

char *get_nstr(char *str, int n)
{
    char *res = malloc((n + 1) * sizeof(char));
    int i;

    for (i = 0; i != n; i++)
        res[i] = str[i];
    res[i] = '\0';
    return (res);
}
