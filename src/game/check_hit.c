/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

#include "../../includes/navy.h"

void check_hit()
{
    if (game.map[game.pos_number][game.pos_letter] != '.') {
        my_printf("%c%d: hit\n\n",game.pos_letter + 65, game.pos_number + 1);
        game.map[game.pos_number][game.pos_letter] = 'x';
        kill(game.enemy_pid, SIGUSR1);
    } else {
        my_printf("%c%d: missed\n\n",game.pos_letter + 65, game.pos_number + 1);
        game.map[game.pos_number][game.pos_letter] = 'o';
        kill(game.enemy_pid, SIGUSR2);
    }

}