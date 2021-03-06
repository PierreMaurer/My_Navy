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
            my_printf("my_pid: %d\nsuccessfully connected\n\n", game.pid);
        } else {
            my_printf("Bad PID\n");
            game.proc_status = 84;
        }
    } else {
        my_printf("my_pid: %d\nwaiting for enemy connection...\n", game.pid);
        get_enemy_pid();
        pause();
        if (!game.is_co && game.proc_status == 84) {
            my_printf("Error connexion");
            return;
        }
        my_printf("\nenemy connected\n\n");
    }
    return;
}