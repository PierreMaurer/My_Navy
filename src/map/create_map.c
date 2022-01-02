/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

# include "../../includes/navy.h"

char **transform_to_array_char(char **buff)
{
    for (int row = 0; row != 8; row++) {
        buff[row] = malloc(sizeof(char) * 8);
        if (buff[row] == NULL) {
            my_putstr("Malloc failed");
            return;
        }
        for (int col = 0; col != 8; col++) {
            buff[row][col] = '.';
        }
    }
    return buff;
}

char **create_map_player(char *pwd)
{
    char buff[31];
    int map_open = check_exist_map(pwd);
    char **map = malloc(sizeof(char *) * 31);
    if (fs_understand_return_of_read(map_open, buff, 31) != 0) {
        game.proc_status = 84;
        return NULL;
    }
    close(map_open);
    check_map(buff);
    if (game.proc_status != 84) {
        map = transform_to_array_char(map);
        map = place_boat(map, buff);
        return map;
    }
    my_printf("Error with position boat file\n");
    return NULL;
}

char **create_map_enemy()
{
    char **map = malloc(sizeof(char *) * 31);

    map = transform_to_array_char(map);
    return map;
}