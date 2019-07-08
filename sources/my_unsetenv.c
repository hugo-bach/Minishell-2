/*
** EPITECH PROJECT, 2018
** my_unsetenv.c
** File description:
** fct unsetenv
*/

#include "my_sh.h"

static char **delete_line_env(char **env, char *variable)
{
    char *value = my_strcat(variable, "=");
    char *temp = NULL;
    int i = 0;

    for (; env[i + 1]; i++)
        if (my_strncmp(env[i], value, my_strlen(value)) == 0) {
            temp = env[i];
            env[i] = env[i + 1];
            env[i + 1] = temp;
        }
    if (my_strncmp(env[i], value, my_strlen(value)) == 0)
        env[i] = NULL;
    if (temp != NULL)
        free(temp);
    free(value);
    return (env);
}

char **my_unsetenv(char **cmd, char **env)
{
    if (my_strlen_array(cmd) == 1) {
        my_putstr("unsetenv: Too few arguments.\n", 2);
        return (env);
    }
    if (env == NULL)
        return (NULL);
    for (int i = 1; cmd[i]; i++)
        env = delete_line_env(env, cmd[i]);
    return (env);
}
