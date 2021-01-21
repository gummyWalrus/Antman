/*
** EPITECH PROJECT, 2021
** antman
** File description:
** it's a bloody nightmare !
*/

#include "../../include/my.h"
#include "include/antman.h"

char *str_fmatch(elemat *mat)
{
    char *res = malloc(4);

    if (mat->mat->len == 0 && mat->mat->offset == 0)
    {
        res[0] = 32;
        res[1] = 32;
        res[2] = mat->mat->value;
        res[3] = '\0';
    }
    else
    {
        res[0] = mat->mat->offset;
        res[1] = mat->mat->len;
        res[2] = mat->mat->value;
        res[3] = '\0';
    }
    return (res);
}

//returns the bestmatch in a (search) for a given index in b (lookahead)

elemat *my_matching(char *a, char *b, int index)
{
    elemat *mat = malloc(sizeof(elemat));
    matches *mtcs;
    int j;
    int o = 0;

    mat->mat = malloc(sizeof(match));
    for (int i = 0; a[i] != '\0'; i) {
        for (j = i; a[j] != '\0' && a[j] != b[index]; j++)
            mat->mat->start = j;
        if (a[j] != '\0') {
            mat->mat->start = j;
            mat->mat->len = get_matchlenght(&a[j], &b[index]);
            mat->mat->offset = (my_strlen(a) - mat->mat->start);
            mat->mat->value = a[mat->mat->start + mat->mat->len];
            i += mat->mat->len;
            mat->next = NULL;
        }
        else {
            mat->mat->start = 0;
            mat->mat->len = 0;
            mat->mat->offset = 0;
            mat->mat->value = a[mat->mat->start];
            i++;
        }
        if (o == 0) {
            mtcs = init_matches(mat);
            o++;
        }
        else {
            append_matches(mtcs, mat);
            o++;
        }
    }
    return (elem_get_bestmatch(mtcs));
}

elemat *ultimate_match(char *a, char *b)
{
    matches *mtcs;
    elemat *mat = my_matching(a, b, 0);
    int i = 0;

    for (i = 0; b[i] != '\0'; i++)
    {
        mat = my_matching(a, b, i);
        if (i == 0)
            mtcs = init_matches(mat);
        else
            append_matches(mtcs, mat);
    }
    if (i == 0)
        mtcs = init_matches(mat);

    return (elem_get_bestmatch(mtcs));
}

void compressor(strlist *cmp, strlist *dcmp, strelem *look, char *sch)
{
    elemat *mat = ultimate_match(sch, look->value);
    int flag = 0;

    append_startstr(cmp, str_fmatch(mat));
    if (mat->mat->len != 0 && cmp_is_over(cmp)) {
        append_startstr(dcmp, &look->value[mat->mat->start + mat->mat->len]);
        append_startstr(dcmp, get_nstr(look->value, mat->mat->start));
        compressor(cmp, dcmp, dcmp->first, sch);
    }
    else if (look->value[mat->mat->start + 1] != '\0' && cmp_is_over(cmp)) {
        append_startstr(dcmp, &look->value[mat->mat->start + 1]);
        del_bindex(dcmp, look->index + 1);
        compressor(cmp, dcmp, dcmp->first, sch);
    }
}

char *my_liststr(list *li)
{
    elem *cur = li->first;
    char *res = malloc((my_listlen(li) + 1) * sizeof(char));
    int i = 0;

    for (i = 0; cur->next != NULL; i++)
    {
        res[i] = cur->value;
        cur = cur->next;
    }
    res[i] = cur->value;
    res[i + 1] = '\0';
    return (res);
}