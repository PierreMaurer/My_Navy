/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

#include "../../includes/navy.h"
void game_turn()
{
    if (game.proc_status != 84 && game.win == 0) {
        print_total_map();
    }
}