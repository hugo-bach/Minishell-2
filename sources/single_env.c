/*
** EPITECH PROJECT, 2018
** single_env.c
** File description:
** single env c
*/

#include "my_sh.h"

char **single_env(char **env)
{
    static char **str;

    if (env == NULL)
        return (str);
    str = env;
    return (str);
}
