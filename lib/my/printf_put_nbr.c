/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** display a number given as param
*/

#include <stdio.h>
#include "my.h"

void my_putchar(char c);

void printf_put_nbr(va_list arg)
{
    my_put_nbr(va_arg(arg, int));
}

void printf_putstr(va_list arg)
{
    my_putstr(va_arg(arg, char *));
}

void printf_putchar(va_list arg)
{
    my_putchar(va_arg(arg, int));
}
