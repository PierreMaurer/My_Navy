/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

#include "../../includes/navy.h"

void first_player_game()
{
    while (game.proc_status != 84 && game.win == 0) {
        print_total_map();
        get_data();
        get_hit();
        usleep(150);
        reset_pos();
        get_sig_data();
        game.pos_number--;
        check_hit();
        game.win = 1;
        print_total_map();

    }
    return;
}

void second_player_game()
{
    game.pos_letter--;
    while (game.proc_status != 84 && game.win == 0) {
        print_total_map();
        get_sig_data();
        check_hit();
        reset_pos();
        get_data();
        get_hit();
        usleep(150);
        reset_pos();
        game.win = 1;
        print_total_map();
    }
    return;
}

void reset_pos()
{
    game.pos_number = 0;
    game.pos_letter = 0;
    game.sig_rec = 0;
}

void game_turn()
{
    if (game.proc_status != 84 && game.win == 0) {
        (game.type == 0) ? first_player_game() : second_player_game();
    }
}