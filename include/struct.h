/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** struct
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct data_s
{
    char *coord_bin;
    int coord;
    pid_t pid_h;
    pid_t pid_c;
    int hit_x;
    int hit_y;
} data_t;

#endif
