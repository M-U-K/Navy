/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** is_a_flag.c
*/

#include "printf.h"
#include <stdbool.h>

bool is_a_flag(char c)
{
    if (c == '-' || c == '+' || c == '#' || c == '0' || c == ' ')
        return (true);
    return (false);
}

bool is_a_length(char c)
{
    if (c == 'h' || c == 'l' || c == 'L')
        return (true);
    return (false);
}

bool is_a_specifier(char c)
{
    char const specifier[] = {"cdiouxXp%bsS"};

    for (int ctr = 0; specifier[ctr] != '\0'; ctr += 1)
        if (specifier[ctr] == c)
            return (true);
    return (false);
}

bool is_number(char c)
{
    if ('0' <= c && c <= '9')
        return (true);
    return (false);
}

bool is_in_flags(char *flags, char flag)
{
    for (int ctr = 0; flags[ctr] != '\0'; ctr += 1)
        if (flags[ctr] == flag)
            return (true);
    return (false);
}