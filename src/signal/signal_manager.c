/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

#include "../../includes/navy.h"

void enemy_pid_handler(int sig, siginfo_t *signal, void *ptr)
{
    game.enemy_pid = signal->si_pid;
    game.is_co = 1;
}

void get_enemy_pid(void)
{
    struct sigaction sig;

    sig.sa_sigaction = enemy_pid_handler;
    sig.sa_flags = SA_SIGINFO;
    sigemptyset(&sig.sa_mask);
    if (sigaction(SIGUSR1, &sig, NULL)) {
        game.proc_status = 84;
        game.is_co = 0;
    }
}
