/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

#include "../../includes/navy.h"

int connection_user(void)
{
    if (game.is_co)
        return 1;
    if (game.type != 0) {
        return 0;
    } else {
        printf("my_pid: %d\n", game.pid);
        printf("waiting for enemy connection...\n");
        pause();

    }
    return 1;
}