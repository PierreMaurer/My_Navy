/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

#include "../../includes/navy.h"

void send_data()
{
    for (int counter = 0; counter < game.pos_letter - 65; counter++) {
        kill(game.enemy_pid, SIGUSR1);
        usleep(150);
    }
    kill(game.enemy_pid, SIGUSR2);
    for (int number = 0;  number < game.pos_number;  number++) {
        kill(game.enemy_pid, SIGUSR1);
        usleep(150);
    }
    kill(game.enemy_pid, SIGUSR2);
}

void get_data_handler(int sig, siginfo_t *signal, void *ptr)
{
    if (sig == SIGUSR1 && game.sig_rec == 0) {
        game.pos_letter += 1;
    } else if (sig == SIGUSR1 && game.sig_rec == 1) {
        game.pos_number += 1;
    } else if (sig == SIGUSR2) {
        game.sig_rec += 1;
    }
}

void get_sig_data(void)
{
    struct sigaction my_sig;
    my_sig.sa_sigaction = get_data_handler;
    my_sig.sa_flags = SA_SIGINFO;
    my_printf("waiting for enemy's attack...\n");
    while (game.sig_rec != 2) {
        sigaction(SIGUSR1, &my_sig, NULL);
        sigaction(SIGUSR2, &my_sig, NULL);
        pause();
    }
    game.sig_rec = 0;
    return;
}
