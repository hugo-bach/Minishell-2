/*
** EPITECH PROJECT, 2018
** is_builtin.c
** File description:
** is a builtin
*/

#include "my_sh.h"

int is_builtin(char *cmd)
{
    char *built_in[6] = {"setenv", "unsetenv", "env", "cd", "exit", NULL};

    for (int i = 0; built_in[i]; i++)
        if (my_strcmp(built_in[i], cmd) == 0)
            return (1);
    return (0);
}
