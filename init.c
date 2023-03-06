/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** init
*/

#include "fct.h"

data_t *init_data(void)
{
    data_t *data = malloc(sizeof(data_t));

    pid_tmp = 0;
    data->coord_bin = malloc(sizeof(char) * 9);
    data->hit_x = 0;
    data->hit_y = 0;
    data->coord = 0;
    return (data);
}