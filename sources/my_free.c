/*
** EPITECH PROJECT, 2018
** my_free.c
** File description:
** fct who free
*/

#include "my_sh.h"

void my_free(char **str)
{
    if (str == NULL)
        return;
    for (int i = 0; str[i]; i++)
        free(str[i]);
    free(str);
}
