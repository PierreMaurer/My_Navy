/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

# include "../../includes/navy.h"

char **transform_to_array_char(char **buff)
{
    for (int row = 0; row != 8; row++)
    {
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
    struct stat my_stat;
    char buff[map_size(pwd)];
    int map_open = check_exist_map(pwd);
    char **map = malloc(sizeof(char *) * map_size(pwd));
    stat(pwd, &my_stat);

    if (my_stat.st_size == 0 ||
            fs_understand_return_of_read(map_open, buff, map_size(pwd)) != 0) {
        return;
    }
    close(map_open);
    map = transform_to_array_char(map);
    map = place_boat(map, buff);
    return map;
}

char **create_map_enemy()
{
    struct stat my_stat;
    char **map = malloc(sizeof(char *) * 31);

    map = transform_to_array_char(map);
    return map;
}