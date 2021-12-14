//
// Created by peter_trapp on 08/12/2021.
//

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

int main(void)
{
    process_info();
    return 0;
}