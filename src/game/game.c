/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

#include "../../includes/navy.h"

void first_player_game()
{
    print_total_map();
    return;
}

void second_player_game()
{
    print_total_map();
    return;
}
void game_turn()
{
    if (game.proc_status != 84 && game.win == 0) {
        (game.type == 0) ? first_player_game() : second_player_game();
    }
}