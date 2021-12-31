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
    init_global_struct(argv, (argc == 3) ? second : first);
    if (game.proc_status != 84) {
        //Faut free la structure
        connection_user();
        game_turn();
        return game.proc_status;
    }
    return game.proc_status;
}