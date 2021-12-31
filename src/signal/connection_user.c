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
            my_printf("my_pid: %d\n", game.pid);
            my_printf("successfully connected\n\n");
        } else {
            my_printf("Bad PID\n");
            game.proc_status = 84;
        }
    } else {
        my_printf("my_pid: %d\n", game.pid);
        my_printf("waiting for enemy connection...\n");
        get_enemy_pid();
        pause();
        if (!game.is_co && game.proc_status == 84) {
            my_printf("Error connexion");
            return;
        }
        my_printf("\nenemy connect\n\n");
    }
    return;
}