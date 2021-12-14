/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** reverse a string given in params
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int c = 0;
    int i = 0;
    int len_str = my_strlen(str) - 1;

    for (i = i; i < len_str; i++) {
        c = str[i];
        str[i] = str[len_str];
        str[len_str] = c;
        len_str--;
    }
    return (str);
}
