/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** deci_bin
*/

#include "fct.h"
#include "utils.h"

void recup_bin(data_t *data, int coord)
{
    int i = 0;

    free(data->coord_bin);
    data->coord_bin = malloc(sizeof(char) * 9);
    coord = coord * 2;
    while (coord != 0) {
        if (coord % 2 == 1)
            data->coord_bin[i] = '1';
        if (coord % 2 == 0)
            data->coord_bin[i] = '0';
        coord = coord / 2;
        i++;
    }
    for (; i != 8; i++)
        data->coord_bin[i] = '0';
    data->coord_bin[i] = '\0';
    data->coord_bin = reverse_string(data->coord_bin);
}

void recup_coord(data_t *data)
{
    int nbr = 128;

    data->coord = 0;
    for (int i = 0; data->coord_bin[i] != '\0'; i++) {
        if (data->coord_bin[i] == '1')
            data->coord += nbr;
        nbr = nbr / 2;
    }
}