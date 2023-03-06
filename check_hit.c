/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** check_hiting.c
*/

#include "navy.h"
#include "utils.h"
#include "printf.h"

int check_hit(int coord, game_data_t *game_data)
{
    int x = coord / 10;
    int y = coord % 10;
    int col = (x + 1) * 2;
    int line = y + 2;

    my_printf("%c%c: ", x + 65, y + 49);
    if (game_data->board[line][col] != '.'
    && game_data->board[line][col] != 'x'
    && game_data->board[line][col] != 'o') {
        game_data->board[line][col] = 'x';
        game_data->total_boat -= 1;
        my_printf("hit\n\n");
        return (1);
    }
    if (game_data->board[line][col] != 'x')
        game_data->board[line][col] = 'o';
    my_printf("missed\n\n");
    return (0);
}

bool have_hit(int coord, int hit, game_data_t *game_data)
{
    int x = coord / 10;
    int y = coord % 10;
    int col = (x + 1) * 2;
    int line = y + 2;

    my_printf("%c%c: ", x + 65, y + 49);
    if ((hit % 10) == 1) {
        game_data->radar[line][col] = 'x';
        my_printf("hit\n\n");
    } else {
        if (game_data->radar[line][col] != 'x')
            game_data->radar[line][col] = 'o';
        my_printf("missed\n\n");
    }
    if ((hit / 10) == 1) {
        print_board(game_data);
        my_printf("I won\n\n");
        return (true);
    }
    return (false);
}