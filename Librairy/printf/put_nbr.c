/*
** EPITECH PROJECT, 2019
** Day03
** File description:
** my_put_nbr.c
*/

#include <unistd.h>

int put_nbr(int nb)
{
    int pow = 1;

    if (nb < 0) {
        nb *= -1;
        write(1, "-", 1);
    }
    for (int temp_nb = nb; (temp_nb / 10) != 0; pow *= 10)
        temp_nb /= 10;
    for (int temp = 0; pow > 0; pow /= 10) {
        temp = nb / pow + 48;
        nb %= pow;
        write(1, &temp, 1);
    }
    return (0);
}