/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** fct
*/

#ifndef FCT_H
#define FCT_H

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <ucontext.h>
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "navy.h"

pid_t pid_tmp;

//handler.c
void handler_e2(int sign, siginfo_t *siginfo, void *context);
void handler_e(int sign, siginfo_t *siginfo, void *context);
void handler_r(int sign, siginfo_t *siginfo, void *context);

//main.c
int hote(data_t *data, game_data_t *game_data);
int client(int pid_h, data_t *data, game_data_t *game_data);

//send_pull.c
void envoi_c_h(data_t *data, int coord, struct sigaction s);
void envoi_h_c(data_t *data, int coord, struct sigaction s);
void reception(data_t *data, struct sigaction s);
void reception_co(data_t *data, struct sigaction s);
void envoi_c_h2(data_t *data, int coord, struct sigaction s);

//deci_bin.c
void recup_coord(data_t *data);
void recup_bin(data_t *data, int coord);

data_t *init_data(void);

//extern pid_t pid_tmp;

#endif