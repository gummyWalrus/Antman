/*
** EPITECH PROJECT, 2021
** antman
** File description:
** header file for antman
*/

#ifndef ANTMAN_H
#define ANTMAN_H
typedef struct list list;
typedef struct elem elem;
typedef struct elemat elemat;
typedef struct matches matches;

typedef struct list
{
    elem *first;
}list;
typedef struct elem
{
    char value;
    elem *next;
    int index;
}elem;
typedef struct match
{
    int offset;
    int len;
    char value;
}match;
typedef struct matches
{
    elemat *first;
}matches;
typedef struct elemat
{
    match *mat;
    int index;
    elemat *next;
}elemat;
void append_end(list *li, char value);
list *fstr_genlist(char *str, int size);
void del_first(list *li);
int my_listlen(list *li);
matches *get_matchs(list *search, list *look);
int get_matchlen(elem *look, elem *sch);
void lzing(char *str);
char *fpath_text(char const *path);
elemat *get_laste(matches *mtcs);
list *init_list(char value);
int my_putlz(char *c, list *sch);
void my_putlist(list *li);
void my_putlistelem(elem *li);
elem *felem_index(list *mtcs, int index);
void append_matches(matches *mtcs, elemat *elem);
elemat *get_match(list *sch, elem *cur_look, elem *cur_sch);
matches *init_matches(elemat *first);
match *get_bestmatch(matches *mtcs);
void my_putinfo(match *);
matches *init_error(void);
void my_putlistelem(elem *li);
void my_put_matches(matches *mtc);
#endif