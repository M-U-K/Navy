/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** take_width_and_precision.c
*/

#include "printf.h"

int take_width(char const *mod, printf_t *format)
{
    int nb = 0;
    int ctr = 0;

    while (is_number(mod[ctr]) == true) {
        nb = (nb * 10) + (mod[ctr] - 48);
        ctr += 1;
    }
    format->width = nb;
    return (ctr);
}

int take_precision(char const *mod, printf_t *format)
{
    int nb = 0;
    int ctr = 0;

    if (mod[ctr] != '.') {
        format->precision = -1;
        return (0);
    }
    ctr += 1;
    while (is_number(mod[ctr]) == true) {
        nb = (nb * 10) + (mod[ctr] - 48);
        ctr += 1;
    }
    format->precision = nb;
    return (ctr);
}