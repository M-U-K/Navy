/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** take_length.c
*/

#include <stdlib.h>

#include "printf.h"

void return_length(char c, printf_t *format)
{
    if (c != format->length[0] && format->length[0] != 'a')
        format->is_ok = false;
    if (format->length[0] == 'a' || format->is_ok == false)
        format->length[0] = c;
    else
        format->length[1] = c;
}

int take_length(char const *mod, printf_t *format)
{
    int ctr = 0;

    format->length = malloc(sizeof(char) * 3);
    for (int ctr = 0; ctr < 3; ctr += 1)
        format->length[ctr] = 'a';
    while (is_a_length(mod[ctr]) == true) {
        if (format->length[1] != 'a') {
            format->is_ok = false;
            format->length[1] = 'a';
        }
        else
            return_length(mod[ctr], format);
        ctr += 1;
    }
    format->length[2] = '\0';
    return (ctr);
}