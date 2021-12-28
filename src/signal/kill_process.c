/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

#include "../../includes/navy.h"
char *convert_i_c(int N);

int kill_proc(int pid)
{
    kill(pid, SIGQUIT);
    return 0;
}
