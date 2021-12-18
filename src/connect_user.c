/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

#include "../includes/navy.h"

int check_exist_pid(int pid_user)
{
    if (!kill(pid_user, 0)) {
        return 0;
    }
    return 84;
}