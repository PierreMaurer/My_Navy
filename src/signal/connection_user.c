/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

#include "../../includes/navy.h"

void connection_user(void)
{
    if (game.is_co)
        return;
    if (game.type == 1) {
        if (!kill(game.enemy_pid, SIGUSR1)) {
            printf("my_pid: %d\n", game.pid);
            printf("successfully connected");
        } else {
            printf("Bad PID\n");
            game.proc_status = 84;
        }
    } else {
        printf("my_pid: %d\n", game.pid);
        printf("waiting for enemy connection...\n");
        get_enemy_pid();
        pause();
        if (!game.is_co && game.proc_status == 84) {
            printf("Error connexion");
            return;
        }
        printf("\nenemy connect\n\n");
    }
    return;
}