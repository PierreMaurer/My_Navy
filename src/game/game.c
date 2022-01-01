/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

#include "../../includes/navy.h"

void first_player_game()
{
    while (game.proc_status != 84 || game.win != 0) {
        print_total_map();
        get_data();
        get_sig_data();
    }
    return;
}

void second_player_game()
{
    while (game.proc_status != 84 || game.win != 0) {
        print_total_map();
        get_sig_data();
        get_data();
    }
    return;
}
void game_turn()
{
    if (game.proc_status != 84 && game.win == 0) {
        (game.type == 0) ? first_player_game() : second_player_game();
    }
}