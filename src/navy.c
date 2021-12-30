/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

# include "../includes/navy.h"

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
    game_turn();
    return game.proc_status;
}