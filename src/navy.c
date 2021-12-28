/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

# include "../includes/navy.h"

void init_global_struct(char *pwd, p_t type)
{
    game.map = create_map_player(pwd);
    game.pid = getpid();
    game.enemy_map = create_map_enemy();
    game.proc_status = 0;
    game.type = type;
    game.is_co = 0;
}
int navy(int argc, char **argv)
{
    p_t type = (argc == 3) ? second : first;
    init_global_struct(argv[1], type);
    connection_user();
    if (game.proc_status == 84) {
        //Faut free la structure
        return game.proc_status;
    }
    //Joueur

    return game.proc_status;
}