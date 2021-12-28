/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

#include "../../includes/navy.h"


void handle_signal(int signal)
{

}
void sig_connexion(void)
{
    struct sigaction sa;
    struct sigset_t sigset_game;

    sigemptyset(&sigset_game);
    sa.sa_handler = &handle_signal;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_mask = &sigset_game;
    sigfillset(&sa.sa_mask);

    printf("my pid: %d\nwaiting for enemy connection...\n", getpid());
    pause();
    printf("successfully connected\n");
}

