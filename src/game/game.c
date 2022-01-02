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
        if (game.win == 1)
            break;
        reset_pos();
        get_sig_data();
        game.pos_number--;
        check_hit();
        check_win();
    }
    if (game.hit == 14)
        my_printf("I won\n");
    if (game.enemy_hit == 14)
        my_printf("Enemy won\n");
}

void second_player_game()
{
    game.pos_letter--;
    while (game.proc_status != 84 && game.win == 0) {
        print_total_map();
        get_sig_data();
        check_hit();
        reset_pos();
        check_win();
        if (game.win == 1)
            break;
        get_data();
        get_hit();
        usleep(150);
        reset_pos();
        game.pos_number--;
        check_win();
    }
    if (game.hit == 14)
        my_printf("I won\n");
    if (game.enemy_hit == 14)
        my_printf("Enemy won\n");
}

void check_win()
{
    if (game.hit == 14 || game.enemy_hit == 14)
        game.win = 1;
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