/*
** EPITECH PROJECT, 2021
** lib my
** File description:
** lib h
*/

#ifndef MY_H
    #define MY_H
#include <stdarg.h>
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strcmp(char *first_string, char *secondstring);
void *alloc(int size);
char *my_revstr(char *str);
char *convert_i_c(int number);
int my_getnbr(char const *str);
int my_strlen(char const *str);
void printf_put_nbr(va_list arg);
int my_printf(char *string, ...);
void my_octal(va_list arg);
void my_hexa(va_list arg);
void my_decimal(va_list arg);
void my_float(va_list arg);
void my_e(va_list arg);
void my_g(va_list arg);
void my_pointer(va_list arg);
void printf_putchar(va_list arg);
void printf_putstr(va_list arg);
void my_print_flag(char *string, int count, va_list list);
#endif /* !MY_H */