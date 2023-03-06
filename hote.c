/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** hote.c
*/

#include "fct.h"
#include "utils.h"
#include "printf.h"

int hote_game(data_t *data, struct sigaction s, game_data_t *game_data)
{
    int coord = 0;

    while (1) {
        print_board(game_data);
        while ((coord = take_coord()) == -1);
        envoi_h_c(data, coord, s);
        reception(data, s);
        if (have_hit(coord, data->coord, game_data) == true)
            return (0);
        my_printf("waiting for enemy's attack...\n");
        reception(data, s);
        if (check_hit(data->coord, game_data) == true) {
            if (game_data->total_boat <= 0) {
                print_board(game_data);
                envoi_h_c(data, 11, s);
                return (my_printf("Enemy won\n\n"), 1);
            }
            envoi_h_c(data, 1, s);
        } else
            envoi_h_c(data, 0, s);
    }
}

int hote(data_t *data, game_data_t *game_data)
{
    struct sigaction s;

    data->pid_h = getpid();
    s.sa_flags = SA_SIGINFO;
    my_printf("my_pid: %i\n", data->pid_h);
    my_printf("waiting for enemy connection...\n\n");
    reception_co(data, s);
    envoi_h_c(data, 8, s);
    reception_co(data, s);
    my_printf("enemy connected\n\n");
    return (hote_game(data, s, game_data));
}