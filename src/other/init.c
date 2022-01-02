/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

# include "../../includes/navy.h"

void init_global_struct(char **argv, p_t type)
{
    game.proc_status = 0;
    game.sig_rec = 0;
    if (type == 1) {
        game.map = create_map_player(argv[2]);
        game.enemy_pid = my_getnbr(argv[1]);
    } else
        game.map = create_map_player(argv[1]);
    game.pid = getpid();
    game.enemy_map = create_map_enemy();
    game.type = type;
    game.is_co = 0;
    game.pos_letter = 0;
    game.pos_number = 0;
    game.hit = 0;
    game.enemy_hit = 0;
}
