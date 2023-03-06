/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** specifier_c_s_up_s.c
*/

#include <unistd.h>

#include "printf.h"

void print_space(int padding)
{
    for (int ctr = 0; ctr < padding; ctr += 1)
        write(1, " ", 1);
}

void put_char(char c)
{
    if (c >= 32 && c < 127)
        write(1, &c, 1);
    else {
        write(1, "\\0", 2);
        put_nbr_base(c, "01234567");
    }
}

int print_char(printf_t *format, int c)
{
    int padding = 1;

    if (format->width > 0) {
        if (is_in_flags(format->flags, '-')) {
            put_char(c);
            print_space(format->width - padding);
        }
        else {
            print_space(format->width - padding);
            put_char(c);
        }
    }
    else
        put_char(c);
    return (0);
}

int print_str(printf_t *format, char *str)
{
    int slen = 0;

    while (str[slen] != '\0')
        slen += 1;
    if (format->width > 0) {
        if (is_in_flags(format->flags, '-')) {
            put_str(str);
            print_space(format->width - slen);
        }
        else {
            print_space(format->width - slen);
            put_str(str);
        }
    }
    else
        put_str(str);
    return (0);
}