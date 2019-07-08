/*
** EPITECH PROJECT, 2018
** my_error.c
** File description:
** fct who write error
*/

#include "my_sh.h"

void my_error(char *cmd, int err)
{
    char *str = strerror(err);

    my_putstr(cmd, 2);
    my_putstr(": ", 2);
    my_putstr(str, 2);
    if (err == 8)
        my_putstr(". Wrong Architecture", 2);
    my_putstr(".\n", 2);
}
