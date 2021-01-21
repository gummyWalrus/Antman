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
typedef struct strelem strelem;
typedef struct strlist strlist;
typedef struct strmatch strmatch;
typedef struct strmatchs strmatchs;

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
    int start;
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
typedef struct strlist
{
    strelem *first;
}strlist;
typedef struct strelem
{
    char *value;
    int index;
    strelem *next;
    strelem *prev;
}strelem;
typedef struct strmatch
{
    int start;
    int offset;
    int len;
    char value;
}strmatch;
typedef struct strmatchs
{
    strmatch *first;
}strmatchs;

void append_end(list *li, char value);
strlist *init_strlist(char *value);
list *fstr_genlist(char *str, int size);
void del_first(list *li);
int my_listlen(list *li);
matches *get_matchs(list *search, list *look);
int get_matchlen(elem *look, elem *sch);
void lzing(char *str);
char *fpath_text(char const *path);
elemat *get_laste(matches *mtcs);
list *init_list(char value);
match *my_putlz(list *look, list *sch);
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
int errors(int ac, char const **argv);
char *my_matcher(char *c, list *search);
matches *matches_fbuffer(char *c, list *search);
elemat *elem_get_bestmatch(matches *mtcs);
char *my_liststr(list *li);
void append_endstr(strlist *li, char *value);
void append_startstr(strlist *li, char *value);
void del_bindex(strlist *li, int index);
char *str_fmatch(elemat *mat);
char *get_nstr(char *str, int n);
strlist *init_strlist(char *value);
int cmp_is_over(strlist *cmp);
void compressor(strlist *cmp, strlist *dcmp, strelem *look, char *sch);
void my_putmstr(strlist *cmp);
int get_matchlenght(char *sch, char *lok);
int my_strlistlen(strlist *li);
#endif