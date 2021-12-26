/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

#include "../includes/navy.h"

int check_exist_pid(int pid_user)
{
    if (!kill(pid_user, SIGUSR1)) {
        return 0;
    } else {
        printf("Bad PID\n");
        return 84;
    }
}