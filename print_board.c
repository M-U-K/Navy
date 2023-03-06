/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** print_board.c
*/

#include "navy.h"
#include "printf.h"

#include <unistd.h>

void print_board(game_data_t *game_data)
{
    my_printf("my positions:\n");
    for (int ctr = 0; game_data->board[ctr] != NULL; ctr += 1)
        my_printf("%s\n", game_data->board[ctr]);
    my_printf("\nenemy's positions:\n");
    for (int ctr = 0; game_data->radar[ctr] != NULL; ctr += 1)
        my_printf("%s\n", game_data->radar[ctr]);
    write(1, "\n", 1);
}