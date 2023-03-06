/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_putstr.c
*/

#include "printf.h"

#include <unistd.h>

int put_str(char const *str)
{
    int len = 0;

    if (str == NULL)
        return (0);
    for (int ctr = 0; str[ctr] != '\0'; ctr += 1)
        len += 1;
    write(1, str, len);
    return (0);
}