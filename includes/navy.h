/*
** EPITECH PROJECT, 2021
** navy
** File description:
** make a navy game
*/

# ifndef NAVY_H
    # define NAVY_H

    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <fcntl.h>
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
    int sig_rec;
    char **map;
    char **enemy_map;
    int pos_letter;
    int pos_number;
    p_t type;
}navy_t;

extern navy_t game;
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
void check_map(char *map);
void check_boat(char *map);
void connection_user(void);
void get_enemy_pid(void);
void init_global_struct(char **argv, p_t type);
void print_total_map();
void game_turn();
void get_data();
void check_hit();
void reset_pos();
void send_data();
void get_sig_data(void);
void get_data_handler(int sig, siginfo_t *signal, void *ptr);
void get_hit_handler(int sig, siginfo_t *signal, void *ptr);
void get_hit(void);
void help_menu();
#endif //NAVY_H
