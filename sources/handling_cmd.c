/*
** EPITECH PROJECT, 2018
** handling_cmd.c
** File description:
** fct who treat cmd
*/

#include "my_sh.h"

void check_signal(int signal)
{
    if (WIFSIGNALED(signal) > 0) {
        if (WTERMSIG(signal) == 11)
            my_putstr("Segmentation fault", 1);
        if (WTERMSIG(signal) == 8)
            my_putstr("Floating exception", 1);
        if (WCOREDUMP(signal))
            my_putstr(" (core dumped)", 1);
        my_putstr("\n", 1);
    }
}

void exec_cmd(char *path, char **cmd, char **env)
{
    int status = 0;

    status = execve(path, cmd, env);
    if (status == -1) {
        my_error(path, errno);
        exit(0);
    }
}

void my_treat_cmd(char **cmd, char **env)
{
    char *built_in[6] = {"setenv", "unsetenv", "env", "exit", "cd", NULL};
    char **(*built[5])(char **, char **) = {my_setenv, my_unsetenv, my_env,
                                            my_exit, my_cd};
    int status = 0;

    env = single_env(NULL);
    (cmd[0][0] == '\0') ? exit(0) : 0;
    for (int i = 0; built_in[i]; i++)
        if (my_strcmp(built_in[i], cmd[0]) == 0) {
            (1) ? single_env((*built[i])(cmd, env)), status++ : 0;
            return;
        }
    if (status == 0 && my_access(cmd[0], my_getenv(env, "PATH")) != -1)
        exec_cmd(my_cmd(NULL), cmd, env);
    else if (status == 0 && access(cmd[0], F_OK) != -1) {
        exec_cmd(cmd[0], cmd, env);
    } else {
        my_putstr(cmd[0], 2);
        (1) ? my_putstr(": Command not found.\n", 2), exit(1) : 0;
    }
}
