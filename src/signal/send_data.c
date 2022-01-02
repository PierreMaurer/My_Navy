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