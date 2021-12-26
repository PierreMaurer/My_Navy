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
int check_exist_map(char *pwd_map);
int map_size(char *pwd);
int gameloop_usr1(int argc, char **argv);
int fs_understand_return_of_read(int fd , char *buffer , int size);
char **transform_to_array_char(char **buff);
int **create_map(char *pwd);
void print_tab(char **map);
char  **place_boat(char **map, char *pos);
#endif //NAVY_H
