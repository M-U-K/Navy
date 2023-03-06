/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#include "printf.h"

void print_format(printf_t *format)
{
    write(1, "%", 1);
    for (int ctr = 0; ctr < 3; ctr += 1)
        if (format->flags[ctr] != 'a')
            write(1, &(format->flags[ctr]), 1);
    if (format->width != 0)
        put_nbr(format->width);
    if (format->precision != -1) {
        write(1, ".", 1);
        put_nbr(format->precision);
    }
    for (int ctr = 0; ctr < 3; ctr += 1)
        if (format->length[ctr] != 'a')
            write(1, &(format->length[ctr]), 1);
    if (format->specifier != '\0')
        write(1, &(format->specifier), 1);
}

int my_printf(char const *mod, ...)
{
    printf_t *format = malloc(sizeof(printf_t));
    va_list list;
    int ctr = 0;

    va_start(list, mod);
    while (mod[ctr] != '\0') {
        if (mod[ctr] == '%') {
            ctr += take_format(&(mod[ctr + 1]), format);
            if (format->is_ok == false)
                print_format(format);
            else
                format->specifier == '%' ? write(1, "%", 1) :
                check_specifier(format, list);
        } else {
            write(1, &(mod[ctr]), 1);
            ctr += 1;
        }
    }
    va_end(list);
    return (0);
}