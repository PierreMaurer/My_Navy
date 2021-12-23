/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

#include "../includes/navy.h"

int error_handling_usr1(int user_pid, char *pwd_map)
{
    if (check_exist_pid(user_pid) == 84) {
        printf("Wrong PID");
        return 84;
    } else {
        return 0;
    }
}