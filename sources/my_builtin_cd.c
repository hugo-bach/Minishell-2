/*
** EPITECH PROJECT, 2018
** my_chdir.c
** File description:
** fct cd
*/

#include "my_sh.h"

static char **my_change_dir(char **cmd, char **env)
{
    char *pwd_old = single_old(NULL);
    char *pwd_now = get_pwd();
    char *pwd[4] = {"setenv", "PWD", pwd_old, NULL};

    if (my_strlen(cmd[1]) == 1 && cmd[1][0] == '-') {
        if (chdir(pwd_old) == -1)
            my_error("", errno);
        else {
            env = my_setenv(pwd, env);
            single_old(pwd_now);
        }
    } else {
        if (chdir(cmd[1]) == -1)
            my_error(cmd[1], errno);
        else {
            (1) ? pwd[2] = get_pwd(), env = my_setenv(pwd, env) : 0;
            single_old(pwd_now);
        }
    }
    return (env);
}

char **my_cd(char **cmd, char **env)
{
    char *home = my_strdup(my_getenv(env, "HOME"));
    char *pwd_now = get_pwd();
    char *pwd[4] = {"setenv", "PWD", home + 5, NULL};

    if (my_strlen_array(cmd) > 2) {
        my_putstr("cd: Too many arguments.\n", 2);
        return (env);
    } else if (my_strlen_array(cmd) == 1) {
        if (chdir(home + 5) == - 1) {
            (home == NULL) ? my_putstr("cd: No home directory.\n", 2) :
            my_putstr("cd: Can't change to home directory.\n", 2);
        } else {
            env = my_setenv(pwd, env);
            single_old(pwd_now);
        }
    } else
        env = my_change_dir(cmd, env);
    return (env);
}
