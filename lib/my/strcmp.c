/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** display a character
*/

#include <unistd.h>

int my_strcmp(char *first_string, char *secondstring)
{
    int index = 0;
    int count = 0;

    for (index = 0; first_string[index] != '\0'
    || secondstring[index] != '\0';  index++) {
        if (first_string[index] != secondstring[index]) {
            count = first_string[index] - secondstring[index];
            return count;
        }
    }

}
