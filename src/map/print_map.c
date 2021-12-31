/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

# include "../../includes/navy.h"

void print_tab(char **map)
{
    int row = 0;
    int col = 0;

    for (; row != 8; row++) {
        my_printf("%d|", row + 1);
        for (col = 0; col != 7; col++) {
            my_printf("%c ", map[row][col]);
        }
        my_printf("%c", map[row][col]);
        my_printf("\n");
    }
}

void print_total_map()
{
    my_printf("my positions:\n");
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    print_tab(game.map);
    my_printf("\nenemy's positions:\n");
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    print_tab(game.enemy_map);
    my_printf("\n");
}