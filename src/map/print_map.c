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
        printf("%d|", row + 1);
        for (col = 0; col != 7; col++) {
            printf("%c ", map[row][col]);
        }
        printf("%c", map[row][col]);
        printf("\n");
    }
}

void print_total_map()
{
    printf("my positions:\n");
    printf(" |A B C D E F G H\n");
    printf("-+---------------\n");
    print_tab(game.map);
    printf("\nenemy's positions:\n");
    printf(" |A B C D E F G H\n");
    printf("-+---------------\n");
    print_tab(game.enemy_map);
    printf("\n");
}