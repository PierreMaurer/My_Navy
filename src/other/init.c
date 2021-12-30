/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

# include "../../includes/navy.h"

void init_global_struct(char **argv, p_t type)
{
    if (type == 1) {
        game.map = create_map_player(argv[2]);
        game.enemy_pid = my_getnbr(argv[1]);
    } else {
        game.map = create_map_player(argv[1]);
    }
    game.pid = getpid();
    game.enemy_map = create_map_enemy();
    game.proc_status = 0;
    game.type = type;
    game.is_co = 0;
}
