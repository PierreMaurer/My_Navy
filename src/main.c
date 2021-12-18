/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

#include "../includes/navy.h"

void process_info() {
    pid_t process_id;
    pid_t p_process_id;
    pid_t pg_process_id;
    process_id = getpid();
    p_process_id = getppid();
    pg_process_id = getpgid(p_process_id);
    printf("PID: %d\n", process_id);
    printf("PPID: %d\n", p_process_id);
    printf("PGID %d\n", pg_process_id);
    sleep(50);
}

int main(int argc, char **argv)
{
    if (argc == 2) {
        check_exist_pid(my_getnbr(argv[1]));
    } else {
        process_info();
    }
    return 0;
}