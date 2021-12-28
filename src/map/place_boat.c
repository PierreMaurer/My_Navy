/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

# include "../../includes/navy.h"

char  **place_boat(char **map, char *pos)
{
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    for (int position = 0; position < 31; position += 8) {
        x1 = (pos[position + 2] - 65);
        y1 = pos[position + 3] - 48;
        x2 = pos[position + 5] - 65;
        y2 = pos[position + 6] - 48;
        map[y1 - 1][x1] = pos[position + 0];
        map[y2 - 1][x2] = pos[position + 0];
        if (pos[position + 0] - '0' > 2) {
            for (int counter = 0; counter < pos[position + 0] - 2; counter++) {
                map[y1 - 1][x1] = pos[position + 0];
                y1 += (y1 == y2) ? 0 : 1;
                x1 += (x1 == x2) ? 0 : 1;
            }
        }
    }
    return map;
}