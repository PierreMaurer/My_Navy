/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

# include "../../includes/navy.h"

int check_exist_map(char *pwd_map)
{
    int file = open(pwd_map, O_RDONLY);

    if (file == -1) {
        return 84;
    }
    return file;
}