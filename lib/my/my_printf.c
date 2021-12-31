/*
** EPITECH PROJECT, 2021
** B-CPE-101-STG-1-1-infinadd-pierre.maurer
** File description:
** infin_add.c
*/

#include "my.h"

void (*f[])(va_list arg) = {
        my_decimal,
        my_octal,
        my_hexa,
        my_hexa,
        my_decimal,
        printf_putchar,
        printf_putstr,
        my_pointer,
        my_e,
        my_decimal,
        my_float
};

int my_printf(char *string, ...)
{
    va_list list;

    va_start(list, string);
    for (int count = 0; string[count] != '\0'; count++) {
        if (string[count] == '%' && string[count+1] == '%') {
            my_putchar('%');
            count++;
        } else if (string[count] == '%') {
            my_print_flag(string, count, list);
            count++;
        } else {
            my_putchar(string[count]);
        }
    }
    va_end(list);
    return 0;
}

void my_print_flag(char *string, int count, va_list list)
{
    char my_flag[] = "ioxXucspndf";

    for (int counter = 0; counter <= 10; counter++) {
        if (string[count + 1] == my_flag[counter]) {
            (f[counter](list));
            return;
        }
    }
    return;
}
