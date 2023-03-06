/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_putnbr_base.c
*/

#include <unistd.h>

#include "printf.h"

int put_nbr_base(long long int nb, char const *base)
{
    int nbase = 0;
    long long int tmp = 0;
    static bool is_zero = true;

    if (base == NULL)
        return (0);
    if (nb < 0) {
        write(1, "-", 1);
        nb *= -1;
    }
    if (nb == 0 && is_zero == true)
        write(1, "0", 1);
    is_zero = false;
    for (; base[nbase] != '\0'; nbase += 1);
    tmp = nb % (long long int)nbase;
    if (nb > 0) {
        put_nbr_base(nb /= (long long int)nbase, base);
        write(1, &(base[tmp]), 1);
    }
    is_zero = true;
    return (0);
}