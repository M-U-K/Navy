/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** send_pull
*/

#include "fct.h"

void envoi_c_h(data_t *data, int coord, struct sigaction s)
{
    recup_bin(data, coord);
    for (int i = 0; i != 8; i++) {
        s.sa_sigaction = &handler_e;
        sigaction(SIGUSR1, &s, 0);
        sigaction(SIGUSR2, &s, 0);
        usleep(5000);
        if (data->coord_bin[i] == '0')
            kill(data->pid_h, SIGUSR1);
        if (data->coord_bin[i] == '1')
            kill(data->pid_h, SIGUSR2);
        pause();
    }
}

void envoi_c_h2(data_t *data, int coord, struct sigaction s)
{
    recup_bin(data, coord);
    pid_tmp = 0;
    for (int i = 0; i != 8; i++) {
        s.sa_sigaction = &handler_e2;
        sigaction(SIGUSR1, &s, 0);
        sigaction(SIGUSR2, &s, 0);
        usleep(5000);
        if (data->coord_bin[i] == '0')
            kill(data->pid_h, SIGUSR1);
        if (data->coord_bin[i] == '1')
            kill(data->pid_h, SIGUSR2);
        usleep(80000);
    }
}

void envoi_h_c(data_t *data, int coord, struct sigaction s)
{
    recup_bin(data, coord);
    for (int i = 0; i != 8; i++) {
        if (data->pid_c == 0)
            data->pid_c = pid_tmp;
        s.sa_sigaction = &handler_e;
        sigaction(SIGUSR1, &s, 0);
        sigaction(SIGUSR2, &s, 0);
        usleep(5000);
        if (data->coord_bin[i] == '0')
            kill(data->pid_c, SIGUSR1);
        if (data->coord_bin[i] == '1')
            kill(data->pid_c, SIGUSR2);
        pause();
    }
}

void reception_co(data_t *data, struct sigaction s)
{
    int i = 0;

    for (; i != 8; i++) {
        if (data->pid_c == 0)
            data->pid_c = pid_tmp;
        s.sa_sigaction = &handler_r;
        sigaction(SIGUSR1, &s, 0);
        sigaction(SIGUSR2, &s, 0);
        pause();
    }
    usleep(8000);
}

void reception(data_t *data, struct sigaction s)
{
    int i = 0;

    free(data->coord_bin);
    data->coord_bin = malloc(sizeof(char) * 9);
    for (; i != 8; i++) {
        s.sa_sigaction = &handler_r;
        sigaction(SIGUSR1, &s, 0);
        sigaction(SIGUSR2, &s, 0);
        if (pid_tmp == 10)
            data->coord_bin[i] = '0';
        if (pid_tmp == 12)
            data->coord_bin[i] = '1';
        pause();
    }
    data->coord_bin[i] = '\0';
    recup_coord(data);
    usleep(8000);
}