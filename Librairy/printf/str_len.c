/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** str_len.c
*/

#include "printf.h"

int str_len(char const *str)
{
    int size = 0;

    while (str[size] != '\0')
        size += 1;
    return (size);
}