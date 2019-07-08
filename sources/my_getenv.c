/*
** EPITECH PROJECT, 2018
** my_getenv.c
** File description:
** fct who return the pointer of the env
*/

#include "my_sh.h"

char *my_getenv(char **env, char *variable)
{
    char *temp = NULL;

    if (env == NULL || variable == NULL)
        return (NULL);
    temp = my_strcat(variable, "=");
    for (int i = 0; env[i]; i++)
        if (my_strncmp(env[i], temp, my_strlen(temp)) == 0) {
            free(temp);
            return (env[i]);
        }
    free(temp);
    return (NULL);
}
