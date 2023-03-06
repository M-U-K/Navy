/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** main
*/

#include "fct.h"
#include "navy.h"
#include "utils.h"
#include "printf.h"


int case_h(void)
{
    my_printf("USAGE\n");
    my_printf("\t./navy [first_player_pid] navy_positions\n");
    my_printf("DESCRIPTION\n");
    my_printf("\tfirst_player_pid: only for the 2nd"
    " player. pid of the first player.\n");
    my_printf("\tnavy_positions: file representing "
    "the positions of the ships.\n");
    return (0);
}

int main(int ac, char **av)
{
    data_t *data = init_data();
    game_data_t *game_data = NULL;
    int check = 0;

    if (ac == 2 && cmp_string(av[1], "-h") == 0)
        return (case_h());
    if (ac == 2) {
        game_data = init_game_data(string_dup(av[1]));
        if (game_data == NULL)
            return (84);
        check = hote(data, game_data);
    }
    else if (ac == 3) {
        game_data = init_game_data(string_dup(av[2]));
        if (game_data == NULL)
            return (84);
        check = client(get_number(av[1]), data, game_data);
    }
    else
        return (84);
    return (check);
}