/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

# include "../includes/navy.h"

void init_global_struct(char **argv, p_t type)
{
    if (type == 1) {
        printf("pwd: %s", argv[2]);
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
int navy(int argc, char **argv)
{
    game.proc_status = check_exist_map(argv[1]);
    p_t type = (argc == 3) ? second : first;
    init_global_struct(argv, type);
    connection_user();
    if (game.proc_status == 84) {
        //Faut free la structure
        return game.proc_status;
    }
    //Joueur

    return game.proc_status;
}