/*
** EPITECH PROJECT, 2021
** B-CPE-101-STG-1-1-infinadd-pierre.maurer
** File description:
** infin_add.c
*/

#include "my.h"

void my_decimal(va_list arg)
{
    my_put_nbr(va_arg(arg, int ));
    return;
}

void my_float(va_list arg)
{
    return;
}

void my_octal(va_list arg)
{
    int dec = va_arg(arg, int );
    int octal = 0;

    for (int count = 1; dec != 0; count *= 10, dec /= 8) {
        octal += (dec % 8) * count;
    }
    my_put_nbr(octal);
    return;
}

void my_hexa(va_list arg)
{
    int dec = va_arg(arg, int );
    int hexa = 0;

    for (int count = 1; dec != 0; count *= 10, dec /= 16) {
        hexa += (dec % 16) * count;
    }
    my_put_nbr(hexa);
    return;
}
