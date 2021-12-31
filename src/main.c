/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

# include "../includes/navy.h"
extern navy_t game = {0};

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        help_menu();
        return 0;
    } else if (argc == 3) {
        navy(argc, argv);
    } else if (argc == 2 ) {
        navy(argc, argv);
    } else {
        help_menu();
    }
    return game.proc_status;
}