/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** print_pointer.c
*/

#include <stdio.h>

#include "printf.h"

int print_pointer(printf_t *format, void *pointer)
{
    format->flags[0] = '#';
    print_number(format, (long long int)pointer, "0123456789abcdef");
    return (0);
}