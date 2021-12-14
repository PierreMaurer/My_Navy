/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** display a character
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void *alloc(int size)
{
    void *alloc = malloc(size);

    if (alloc != NULL) {
        return;
    }
    my_putstr("Impossible to allocated the memory");
}
