//
// Created by peter_trapp on 08/12/2021.
//

#ifndef NAVY_H
#define NAVY_H

    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <signal.h>
    #include "my.h"

    typedef struct user {
    pid_t pid;
    int id;
}user_t;
int check_exist_pid(int pid_user);
int error_handling_usr1(int user_pid, char *pwd_map);
int gameloop_usr1();

#endif //NAVY_H
