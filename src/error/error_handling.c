/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

#include "../../includes/navy.h"

int fs_understand_return_of_read(int fd , char *buffer , int size)
{
    int	file;

    file = read(fd, buffer, size);
    if (file == size) {
        return 0;
    } else if (file == -1) {
        my_printf("Error File...\n");
        game.proc_status = 84;
        return 84;
    }
    if (file == 0) {
        my_printf("File position empty...\n");
        game.proc_status = 84;
        return 84;
    } else if (file < size) {
        my_printf("Error with file position file...\n");
        game.proc_status = 84;
        return 84;
    }
    return 0;
}

void check_map(char *map)
{
    int counter = 0;

    for (int count = 0; count < 4; count++) {
        counter += (map[0 + 8 * count] >= '2' &&
                map[0 + 8 * count] <= '5') ? 1 : 0;
        counter += (map[1 + 8 * count] >= ':' &&
                map[1 + 8 * count] <= ':') ? 1 : 0;
        counter += (map[2 + 8 * count] >= 'A' &&
                map[2 + 8 * count] <= 'H') ? 1 : 0;
        counter += (map[3 + 8 * count] >= '1' &&
                map[3 + 8 * count] <= '8') ? 1 : 0;
        counter += (map[4 + 8 * count] >= ':' &&
                map[4 + 8 * count] <= ':') ? 1 : 0;
        counter += (map[5 + 8 * count] >= 'A' &&
                map[5 + 8 * count] <= 'H') ? 1 : 0;
        counter += (map[6 + 8 * count] >= '1' &&
                map[6 + 8 * count] <= '8') ? 1 : 0;
    }
    game.proc_status = (counter != 28) ? 84 : 0;
    if (game.proc_status == 0)
        check_boat(map);
    return;
}

void check_boat(char *map)
{
    int boat_length = 0;
    for (int counter = 0; counter < 4; counter++) {
        boat_length = map[0 + 8 * counter] - '0';
        if (map[2 + 8 * counter] == map[5 + 8 * counter]
        && (map[6 + 8 * counter] - map[3 + 8 * counter]) != boat_length) {
        }
    }
    return;
}
