/*
** EPITECH PROJECT, 2020
** Day04
** File description:
** librairy file
*/

#ifndef my_h
#define my_h

#include <stdio.h>
#include <stdlib.h>

void my_putchar(char);
int my_isneg(int);
int my_put_nbr(int);
void my_swap(int *, int *);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
int *my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char * my_strcpy(char *, char const *);
char * my_strncpy(char *, char const *, int);
char * my_revstr(char *);
char * my_strstr(char *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
int my_showstr(char *);
int isnum_char(char);
int my_showmem(char const *, int);
char *my_strcat(char *, char *);
char * my_strncat(char *, char const *, int);
int my_char_isprintable(char);
char *my_convhexa(int);
int return_i(int , int);
void my_err_putchar(char);
int my_err_putstr(char const *);
char *my_strdup(char *);
char *fill_missing(char *, int);
char *my_conv_octal(int);
char *my_showstr_octal(char *);
char *my_convbin(unsigned int);
int my_printf(char *format, ...);
char *rm_zero(char *);
int get_flag(char);
void s_flag(char *);
void c_flag(int);
void di_flag(int);
void d_flag(int);
void i_flag(int);
void sh_flag(char *);
void o_flag(int);
void x_flag(int);
void xh_flag(int);
void xs_flag(int);
void b_flag(unsigned int);
void p_flag(unsigned long);
void of_flag(int);
void u_flag(unsigned int);
char *int_read(int);
int my_putunsigned(unsigned int);
char *unsigned_read(unsigned int);
typedef struct s_form
{
    char *bef;
    char *aft;
    char arg_type;
    int pos;
}t_form;
#endif
