/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

#include "../../includes/navy.h"

void send_data()
{
    my_printf("%d | %d", game.pos_number, game.pos_letter - 65);
    my_printf("yes ? %d \n", 0 <= game.pos_letter);
    for (int counter = 0; counter < game.pos_letter - 65; counter++) {
        my_printf("coounter %d", counter);
        kill(game.enemy_pid, SIGUSR1);
    }
    kill(game.enemy_pid, SIGUSR2);
    for (int number = 0;  number < game.pos_number;  number++) {
        kill(game.enemy_pid, SIGUSR1);
    }
    kill(game.enemy_pid, SIGUSR2);
}