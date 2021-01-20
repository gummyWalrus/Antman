/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** Prints a given arg
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
# define ERROR_CODE 84

void init_form(t_form *form, char *format)
{
    form->bef = malloc(my_strlen(format) * sizeof(char));
    form->pos = 0;
    form->arg_type = '0';
}

int get_narg(char *str)
{
    int n_arg = 0;

    for (int i = 1; str[i] != '\0'; i++) {
        if ((str[i] == 's' || str[i] == 'd' || str[i] == 'i' || str[i] == 'x'
        || str[i] == 'X' || str[i] == 'o' || str[i] == 'c' || str[i] == 'b'
        || str[i] == 'S' || str[i] == 'u') && str[i-1] == '%')
            n_arg++;
    }
    return (n_arg);
}

char *get_last(char *str)
{
    char *res = malloc(my_strlen(str));
    int j = 0;
    for (int i = my_strlen(str) - 1; str[i] != '%'; i--) {
        res[j] = str[i];
        j++;
    }
    res[j-1] = '\0';
    res = my_revstr(res);
    return (res);
}

void divide_str(t_form *form, char *str)
{
    int i = form->pos;
    int j = 0;

    form->bef = malloc(my_strlen(str) * sizeof(char));
    while (str[i] != '\0' && str[i] != '%') {
        form->bef[j] = str[i];
        i++;
        j++;
    }
    if (str[i] == '%') {
        form->arg_type = str[i+1];
    }
    i = i + 2;
    form->pos = i;
}

int my_printf(char *format, ...)
{
    (my_strlen(format) == 0) ? (exit(ERROR_CODE)) : (0);
    va_list args;
    t_form form;
    void (*fun_ptr[10])() = {s_flag, sh_flag, d_flag, i_flag, c_flag, \
    xs_flag, xh_flag, o_flag, b_flag, u_flag};
    int n_arg = get_narg(format);
    int flag_n;

    init_form(&form, format);
    if (my_strlen(format) > 0) {
        va_start(args, format);
        for (int i = 1; i <= n_arg; i++) {
            divide_str(&form, format);
            my_putstr(form.bef);
            flag_n = get_flag(form.arg_type);
            (*fun_ptr[flag_n])(va_arg(args, void *));
        }
        my_putstr(get_last(format));
    }
    return (0);
}