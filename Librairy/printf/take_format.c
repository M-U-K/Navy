/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** take_format.c
*/

#include <stdlib.h>
#include <unistd.h>

#include "printf.h"

int take_format(char const *mod, printf_t *format)
{
    int ctr = 0;

    format->is_ok = true;
    ctr += take_flag(&(mod[ctr]), format);
    ctr += take_width(&(mod[ctr]), format);
    ctr += take_precision(&(mod[ctr]), format);
    ctr += take_length(&(mod[ctr]), format);
    format->specifier = '\0';
    if (is_a_specifier(mod[ctr]) == true) {
        format->specifier = mod[ctr];
        ctr += 1;
    }
    else
        format->is_ok = false;
    return (ctr + 1);
}