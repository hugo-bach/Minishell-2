/*
** EPITECH PROJECT, 2018
** my_exit_cmd.c
** File description:
** exit cmd
*/

#include "my_sh.h"

char **my_exit(char **cmd, char **env)
{
    my_free(cmd);
    my_free(env);
    exit(0);
    return (env);
}
