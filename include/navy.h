/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** navy.h
*/

#ifndef NAVY_H
#define NAVY_H

#include <stdio.h>
#include <stdbool.h>

#define ABS(value) ((value) < 0 ? -(value) : (value))

typedef struct {
    char **board;
    char **radar;
    int total_boat;
} game_data_t;

game_data_t *init_game_data(char const *filename);

int take_coord(void);
int check_hit(int coord, game_data_t *game_data);
bool have_hit(int coord, int hit, game_data_t *game_data);

void print_board(game_data_t *game_data);

#endif