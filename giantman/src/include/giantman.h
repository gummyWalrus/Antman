/*
** EPITECH PROJECT, 2021
** antman
** File description:
** header file for antman
*/
#ifndef GIANTMAN_H
#define GIANTMAN_H
typedef struct match match;
typedef struct match {
    int offset;
    int len;
    char value;
}match;
char *fpath_text(char const *path);
char *giantman_txt(char *data);
char *get_nstr(char *str, int n);
int errors(int ac, char const **argv);
char ootoii(char c);
int iitoo(char c);
char *my_convbin_format(int nbr, int len);
int my_bintoi(char *bin);
void my_putbinstr(char *str);
char *my_bintext(int *str);
int *my_nbrnew(char *str);
match *get_match(char offest, char len, char c);
void lz_uncompressor(char *data);
char *steps_back(match *mtc, int count, char *final_string);
char *my_charcat(char *str, char c);
char *my_strncat(char *dest, char const *src, int nb);
char *my_cutstr(char *str, int max);
int errors(int ac, char const **argv);
#endif