//
// Created by peter_trapp on 08/12/2021.
//

# ifndef NAVY_H
    # define NAVY_H

    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <signal.h>
    #include "my.h"

    typedef enum player_type {
    first,
    second
} p_t;

    typedef struct game_navy {
    pid_t pid;
    pid_t enemy_pid;
    int proc_status;
    int is_co;
    int win;
    char **map;
    char **enemy_map;
    p_t type;
}navy_t;

extern navy_t game;
int check_exist_pid(int pid_user);
int error_handling_usr1(int user_pid, char *pwd_map);
int check_exist_map(char *pwd_map);
int map_size(char *pwd);
int gameloop_usr1(int argc, char **argv);
int fs_understand_return_of_read(int fd , char *buffer , int size);
char **transform_to_array_char(char **buff);
char **create_map_player(char *pwd);
char **create_map_enemy();
int navy(int argc, char **argv);
void print_tab(char **map);
char  **place_boat(char **map, char *pos);

//Connection_user
void connection_user(void);
void get_enemy_pid(void);

//Utils
void init_global_struct(char **argv, p_t type);
#endif //NAVY_H
