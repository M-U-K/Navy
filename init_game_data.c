/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** init_game_board_data.c
*/

#include "navy.h"
#include "utils.h"
#include "printf.h"
#include "fct.h"

#include <stdlib.h>

char **init_board(void)
{
    char **board = malloc(sizeof(char *) * (10 + 1));

    if (board == NULL)
        return (print_error("ERROR\n"), NULL);
    board[0] = string_dup(" |A B C D E F G H");
    board[1] = string_dup("-+---------------");
    board[2] = string_dup("1|. . . . . . . .");
    board[3] = string_dup("2|. . . . . . . .");
    board[4] = string_dup("3|. . . . . . . .");
    board[5] = string_dup("4|. . . . . . . .");
    board[6] = string_dup("5|. . . . . . . .");
    board[7] = string_dup("6|. . . . . . . .");
    board[8] = string_dup("7|. . . . . . . .");
    board[9] = string_dup("8|. . . . . . . .");
    board[10] = NULL;
    return (board);
}

bool check_boat(char **content, int nb_boat)
{
    int tmp = 0;
    int dif1 = 0;
    int dif2 = 0;

    for (int ctr = 0; ctr < nb_boat; ctr += 1) {
        tmp = get_number(content[ctr]);
        dif1 = ABS(content[ctr][2] - content[ctr][5]);
        dif2 = ABS(content[ctr][3] - content[ctr][6]);
        if ((dif1 == tmp - 1 && dif2 == 0)
        || (dif1 == 0 && dif2 == tmp - 1))
            continue;
        return (false);
    }
    return (true);
}

char **place_boat(char **board, char *boat_ref)
{
    int line = boat_ref[3] - 48 + 1;
    int col = (boat_ref[2] - 65 + 1) * 2;
    int ref = 0;
    int symbol = boat_ref[0];

    if (ABS(boat_ref[2] - boat_ref[5]) == 0) {
        ref = boat_ref[6] - 48 + 1;
        while (line += 1, line - 1 <= ref)
            board[line - 1][col] = symbol;
    }
    else {
        ref = (boat_ref[5] - 65 + 1) * 2;
        while (col += 2, col - 2 <= ref)
            board[line][col - 2] = symbol;
    }
    return (board);
}

char **place_boats
(char **board, char **content, int nb_boat, int *total_boat)
{
    if (board == NULL || check_boat(content, nb_boat) == false)
        return (print_error("ERROR\n"), NULL);

    for (int ctr = 0; ctr < nb_boat; ctr += 1) {
        board = place_boat(board, content[ctr]);
        *total_boat += content[ctr][0] - 48;
    }
    return (board);
}

game_data_t *init_game_data(char const *filename)
{
    game_data_t *game_data = malloc(sizeof(game_data_t));
    char *tmp = read_read_file(filename);
    char **content = str_to_tab(tmp, "\n");
    int nb_boat = table_len(content);

    if (tmp == NULL || nb_boat != 4)
        return (free(game_data), NULL);
    game_data->board = init_board();
    game_data->radar = init_board();
    game_data->board = place_boats(game_data->board, content,
    nb_boat, &(game_data->total_boat));
    if (game_data->board == NULL || game_data->total_boat != 14)
        return (free(game_data), free(tmp), free_tab(content), NULL);
    return (free(tmp), free_tab(content), game_data);
}