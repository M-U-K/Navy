/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** print_number.c
*/

#include <unistd.h>

#include "printf.h"

void print_zero_or_space(printf_t *format, int nb_len)
{
    if (is_in_flags(format->flags, '0'))
        for (int ctr = 0; ctr < format->width - nb_len; ctr += 1)
            write(1, "0", 1);
    else
        for (int ctr = 0; ctr < format->width - nb_len; ctr += 1)
            write(1, " ", 1);
}

void print_hashtag_flags(printf_t *format)
{
    if (is_in_flags(format->flags, '#')) {
        switch (format->specifier) {
            case 'o':
                write(1, "0", 1);
                return;
            case 'x':
                write(1, "0x", 2);
                return;
            case 'X':
                write(1, "0X", 2);
                return;
            case 'p':
                write(1, "0x", 2);
        }
    }
}

void print_width(printf_t *format, long long int nb, int nb_len
, char const *base)
{
    if (is_in_flags(format->flags, '-')) {
        print_hashtag_flags(format);
        put_nbr_base(nb, base);
        print_zero_or_space(format, nb_len);
    }
    else {
        print_zero_or_space(format, nb_len);
        print_hashtag_flags(format);
        put_nbr_base(nb, base);
    }
}

int check_hashtag_flags(printf_t *format)
{
    if (is_in_flags(format->flags, '#')) {
        switch (format->specifier) {
            case 'o':
                return (1);
            case 'x':
                return (2);
            case 'X':
                return (2);
            case 'p':
                return (2);
        }
    }
    return (0);
}

int print_number(printf_t *format, long long int nb, char const *base)
{
    int nb_len = 0;
    int base_len = str_len(base);

    for (int tmp = nb; tmp > 0; tmp /= base_len)
        nb_len += 1;
    if (is_in_flags(format->flags, ' ')) {
        write(1, " ", 1);
        nb_len += 1;
    } else if (is_in_flags(format->flags, '+')
    && (format->specifier == 'd' || format->specifier == 'i')) {
        write(1, "+", 1);
        nb_len += 1;
    }
    nb_len += check_hashtag_flags(format);
    if (format->width > 0)
        print_width(format, nb, nb_len, base);
    else {
        print_hashtag_flags(format);
        put_nbr_base(nb, base);
    }
    return (0);
}