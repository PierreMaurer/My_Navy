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

void get_hit_handler(int sig, siginfo_t *signal, void *ptr)
{
    if (sig == SIGUSR1) {
        my_printf("%c%d: hit\n\n",game.pos_letter, game.pos_number);
        print_tab(game.enemy_map);
        game.enemy_map[game.pos_number - 1][game.pos_letter - 65] = 'x';
    } else if (sig == SIGUSR2) {
        my_printf("%c%d: missed\n\n",game.pos_letter, game.pos_number);
        game.enemy_map[game.pos_number - 1][game.pos_letter - 65] = 'x';
    }
}

void get_hit(void)
{
    struct sigaction my_sig;
    my_sig.sa_sigaction = get_hit_handler;
    my_sig.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &my_sig, NULL);
    sigaction(SIGUSR2, &my_sig, NULL);
    return;
}

