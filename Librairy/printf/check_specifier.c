/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** check_specifier.c
*/

#include <stdarg.h>
#include <unistd.h>

#include "printf.h"

int check_specifier_bis(printf_t *format, va_list list)
{
    switch (format->specifier) {
        case 'o':
            return (print_number(format, va_arg(list, long long int)
            , "01234567"));
        case 'x':
            return (print_number(format, va_arg(list, long long int)
            , "0123456789abcdef"));
        case 'X':
            return (print_number(format, va_arg(list, long long int)
            , "0123456789ABCDEF"));
        case 'b':
            return (print_number(format, va_arg(list, long long int)
            , "01"));
        case 'p':
            return (print_pointer(format, va_arg(list, void *)));
    }
    return (-1);
}

int check_specifier(printf_t *format, va_list list)
{
    switch (format->specifier) {
        case 'c':
            return (print_char(format, va_arg(list, int)));
        case 's':
            return (print_str(format, va_arg(list, char *)));
        case 'S':
            return (print_str(format, va_arg(list, char *)));
        case 'd':
            return (print_number(format, va_arg(list, long long int)
            , "0123456789"));
        case 'i':
            return (print_number(format, va_arg(list, long long int)
            , "0123456789"));
        case 'u':
            return (print_number(format, va_arg(list, long long int)
            , "0123456789"));
        default:
            return (check_specifier_bis(format, list));
    }
    return (-1);
}