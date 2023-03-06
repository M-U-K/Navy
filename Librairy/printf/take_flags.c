/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** check_flag.c
*/

#include <stdlib.h>

#include "printf.h"

char *return_flag(char c, char *flags)
{
    switch (c) {
        case '#':
            flags[0] = '#';
        break;
        case '+':
            flags[1] = '+';
        break;
        case '-':
            flags[2] = '-';
        break;
        case ' ':
            if (flags[1] == 'a')
                flags[1] = ' ';
        break;
        case '0':
            if (flags[2] == 'a')
                flags[2] = '0';
        break;
    }
    return (flags);
}

int take_flag(char const *mod, printf_t *format)
{
    int ctr = 0;

    format->flags = malloc(sizeof(char) * 4);
    for (int flag_ctr = 0; flag_ctr < 3; flag_ctr += 1)
        format->flags[flag_ctr] = 'a';
    while (is_a_flag(mod[ctr]) == true) {
        format->flags = return_flag(mod[ctr], format->flags);
        ctr += 1;
    }
    format->flags[3] = '\0';
    return (ctr);
}