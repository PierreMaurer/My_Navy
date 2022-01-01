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

void get_data_handler(int sig, siginfo_t *signal, void *ptr)
{
    if (sig == SIGUSR1) {
        game.pos_number += 1;
    } else if (sig == SIGUSR2) {
        game.sig_rec = 1;
    }
    my_printf("number %d", game.pos_number);
}

void get_sig_data(void)
{
    struct sigaction my_sig;
    int data_letter = 0;
    int data_int = 0;

    my_sig.sa_sigaction = get_data_handler;
    my_sig.sa_flags = SA_SIGINFO;
    my_printf("waiting for enemy's attack...");
    while (!game.sig_rec) {
        my_printf("dans le while");
        sigaction(SIGUSR1, &my_sig, NULL);
        sigaction(SIGUSR2, &my_sig, NULL);
        pause();
    }
    return;
}

