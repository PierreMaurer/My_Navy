/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** display a character
*/

#include "my.h"
#include <stdlib.h>

int digit_length(int nb)
{
    if (nb == 0)
        return 1;
    int counter = 0;
    while (nb != 0) {
        nb /= 10;
        counter++;
    }
    return counter;
}

char *convert_i_c(int N)
{
    int length = digit_length(N);
    char *int_to_c;
    int_to_c = malloc(sizeof(char *) * length + 1);
    if (int_to_c == NULL) {
        my_putstr("Impossible to malloc");
        return 0;
    }
    int_to_c[length] = '\0';
    if (N < 0) {
        int_to_c[0] = '-';
    }
    length--;
    for (; length >= 0; length--) {
        int_to_c[length] = N % 10 + '0';
        N /= 10;
    }
    return int_to_c;
}