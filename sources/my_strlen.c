/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** fct who count nb char in the string
*/

#include "my_sh.h"

int my_strlen(char *str)
{
    int nb = 0;

    if (str == NULL)
        return (0);
    for (; str[nb]; nb++);
    return (nb);
}
