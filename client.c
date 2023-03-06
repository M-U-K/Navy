/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** client.c
*/

#include "fct.h"
#include "utils.h"
#include "printf.h"

int client_game(data_t *data, struct sigaction s, game_data_t *game_data)
{
    int coord = 0;

    while (1) {
        print_board(game_data);
        my_printf("waiting for enemy's attack...\n");
        reception(data, s);
        if (check_hit(data->coord, game_data) == true) {
            if (game_data->total_boat <= 0) {
                print_board(game_data);
                envoi_c_h(data, 11, s);
                return (my_printf("Enemy won\n\n"), 1);
            }
            envoi_c_h(data, 1, s);
        } else
            envoi_c_h(data, 0, s);
        while ((coord = take_coord()) == -1);
        envoi_c_h(data, coord, s);
        reception(data, s);
        if (have_hit(coord, data->coord, game_data) == true)
            return (0);
    }
}

int client(int pid_h, data_t *data, game_data_t *game_data)
{
    struct sigaction s;

    pid_tmp = -1;
    data->pid_h = pid_h;
    data->pid_c = getpid();
    s.sa_flags = SA_SIGINFO;
    my_printf("my_pid: %i\n", data->pid_c);
    envoi_c_h2(data, 8, s);
    if (pid_tmp == 0)
        return (84);
    reception_co(data, s);
    envoi_c_h(data, 8, s);
    my_printf("successfully connected\n\n");
    return (client_game(data, s, game_data));
}