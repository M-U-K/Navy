/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** handler
*/

#include "fct.h"

void handler_e2(int sign, siginfo_t *siginfo, void *context)
{
    (void)sign;
    (void)siginfo;
    (void)context;
    pid_tmp = 1;
}

void handler_e(int sign, siginfo_t *siginfo, void *context)
{
    (void)sign;
    (void)siginfo;
    (void)context;
}

void handler_r(int sign, siginfo_t *siginfo, void *context)
{
    (void)context;
    if (pid_tmp == 0)
        pid_tmp = siginfo->si_pid;
    else
        pid_tmp = siginfo->si_signo;
    usleep(1000);
    kill(siginfo->si_pid, sign);
}