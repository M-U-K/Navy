/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my.h
*/
#include <stdio.h>

#ifndef PRINTF_H
#define PRINTF_H

#include <stdbool.h>
#include <stdarg.h>

typedef struct printf_s {
    char *flags;
    int width;
    int precision;
    char *length;
    char specifier;
    bool is_ok;
} printf_t;

int my_printf(char const *mod, ...);

int take_format(char const *mod, printf_t *format);

int take_flag(char const *mod, printf_t *format);
int take_width(char const *mod, printf_t *format);
int take_precision(char const *mod, printf_t *format);
int take_length(char const *mod, printf_t *format);

int check_specifier(printf_t *format, va_list list);

int print_char(printf_t *format, int c);
int print_str(printf_t *format, char *str);
int print_number(printf_t *format, long long int nb, char const *base);
int print_pointer(printf_t *format, void *pointer);

// utils
int put_nbr(int nb);
int put_str(char const *str);
int put_nbr_base(long long int nb, char const *base);
int str_len(char const *str);

// check_character.c
bool is_a_flag(char c);
bool is_a_length(char c);
bool is_a_specifier(char c);
bool is_number(char c);
bool is_in_flags(char *flags, char flag);

#endif