/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

#include "../includes/navy.h"
#include <fcntl.h>
#include <sys/stat.h>
int check_exist_map(char *pwd_map)
{
    int file = open(pwd_map, O_RDONLY);
    if (file == -1) {
        printf("File not find\n");
        return 84;
    }
    printf("File founded\n");
    return file;
}

int map_size(char *pwd)
{
    struct stat my_stat;
    if (stat(pwd, &my_stat) == -1) {
        printf("Bad file\n");
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

void print_tab(char **map)
{
    int row = 0;
    int col = 0;
    printf(" |A B C D E F G H\n");
    printf("-+---------------\n");
    for (row = 0; row != 8; row++) {
        printf("%d|", row + 1);
        for (col = 0; col != 7; col++)
            printf("%c ", map[row][col]);
        printf("%c", map[row][col]);
        printf("\n");
    }
}

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

int **create_map(char *pwd)
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
    for (int col = 0; buff[col] != '\0'; col++) {
        printf("%c", buff[col]);
    }
    printf("\n");
    map = transform_to_array_char(map);
    map = place_boat(map, buff);
    print_tab(map);

}