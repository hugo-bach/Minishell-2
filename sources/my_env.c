/*
** EPITECH PROJECT, 2018
** my_env.c
** File description:
** my env
*/

#include "my_sh.h"

char **my_env(char **cmd, char **env)
{
    (void) cmd;

    for (int i = 0; env[i]; i++) {
        my_putstr(env[i], 1);
        write(1, "\n", 1);
    }
    return (env);
}
