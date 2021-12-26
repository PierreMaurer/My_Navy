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
    pause();
}

void signal_handler(int num)
{
    return;
}

int gameloop_usr1(int argc, char **argv)
{
    int return_result = 0;
    signal(SIGUSR1, signal_handler);
    return_result = check_exist_map(argv[1]);
    printf("size: %d", map_size(argv[1]));
    create_map(argv[1]);
    return return_result;
}

void help_menu()
{
    printf("USAGE\n     ./navy [first_player_pid] navy_positions\n");
    printf("DESCRIPTION\n     first_player_pid: only for the 2nd player. pid of the first player.\n");
    printf("     navy_positions: file representing the positions of the ships.\n");
}
int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        help_menu();
        return 0;
    } else if (argc == 3) {
        check_exist_pid(my_getnbr(argv[1]));
    } else if (argc == 2 ) {
        gameloop_usr1(argc, argv);
    } else {
        help_menu();
    }
    return 0;
}