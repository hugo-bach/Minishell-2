/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** fct who print a string
*/

#include "my_sh.h"

void my_putstr(char *str, int fd)
{
    if (str == NULL)
        return;
    write(fd, str, my_strlen(str));
}
