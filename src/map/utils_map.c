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
        printf("File not find\n");
        return 84;
    }
    return file;
}

int map_size(char *pwd)
{
    struct stat my_stat;

    if (stat(pwd, &my_stat) == -1) {
        printf("Bad file\n");
        game.proc_status = 84;
        return 84;
    }
    return my_stat.st_size;
}

int fs_understand_return_of_read(int fd , char *buffer , int size)
{
    int	file;

    file = read(fd, buffer, size);
    if (file == size) {
        return 0;
    } else if (file == -1) {
        return 84;
    }
    if (file == 0) {
        return 84;
    } else if (file < size) {
        return 84;
    }
    return 0;
}