//
// Created by peter_trapp on 09/12/2021.
//
#include "signal.h"
#include "stdlib.h"
#include "../includes/my.h"
char *convert_i_c(int N);

int kill_proc(int pid)
{
    kill(pid, SIGQUIT);
    return 0;
}

int main(int argc, char **argv)
{
   kill_proc(my_getnbr(argv[1]));
    return 1;
}