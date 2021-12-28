/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

# include "../includes/navy.h"
extern navy_t game = {0};
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
    return_result = check_exist_map(argv[1]);
    navy(argc, argv);
    return return_result;
}

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        help_menu();
        return 0;
    } else if (argc == 3) {
        //check_exist_pid(my_getnbr(argv[1]));
        printf("Player 2");
    } else if (argc == 2 ) {
        gameloop_usr1(argc, argv);
    } else {
        help_menu();
    }
    return 0;
}