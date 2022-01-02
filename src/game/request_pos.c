/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

#include "../../includes/navy.h"
void get_data()
{
    ssize_t read = 0;
    size_t size_buff = 0;
    char *line = NULL;
    while (game.proc_status != 84) {
        my_printf("attack: ");
        read = getline(&line, &size_buff, stdin);
        if (read == -1)
            break;
        if (line[0] >= 'A' && line[0] <= 'H' && line[1] - '0' >= 1 && line[1] - '0' <= 8) {
            game.pos_letter = line[0];
            game.pos_number = line[1] - '0';
            break;
        } else
            my_printf("wrong position\n");
    }
    send_data();
    free(line);
}