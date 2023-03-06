/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** take_coord.c
*/

#include "navy.h"
#include "utils.h"
#include "printf.h"

int check_coord(char *buf)
{
    int result = 0;
    int len = string_len(buf, '\0');

    if (len != 3)
        return (-1);
    if (is_in_string(buf[0], "ABCDEFGH") == false
    || is_in_string(buf[1], "12345678") == false)
        return (-1);
    result = ((buf[0] - 65) * 10) + (buf[1] - 49);
    return (result);
}

int take_coord(void)
{
    char *buf = NULL;
    size_t size = 0;
    int coord = 0;

    my_printf("attack: ");
    getline(&buf, &size, stdin);
    coord = check_coord(buf);
    if (coord == -1)
        return (my_printf("wrong position\n"), -1);
    return (coord);
}