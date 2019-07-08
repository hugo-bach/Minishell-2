/*
** EPITECH PROJECT, 2018
** my_pipe.c
** File description:
** pipe fct
*/

#include "my_sh.h"

static int my_dup_cmd(char **cmd, char **env, int fd)
{
    int tb[2] = {-1, -1};
    int pid = 0;

    pipe(tb);
    pid = fork();
    if (pid == 0) {
        (1) ? close(tb[0]), close(0), dup(fd) : 0;
        (1) ? close(1), dup(tb[1]), close(tb[1]) : 0;
        my_treat_cmd(cmd, env);
        if (is_builtin(cmd[0]) == 1)
            exit(0);
    }
    close(fd);
    close(tb[1]);
    for (int i = 0; cmd[i]; i++)
        free(cmd[i]);
    free(cmd);
    return (tb[0]);
}

static int double_redir(char *cmd)
{
    static int status = 0;

    if (cmd == NULL)
        return (status);
    for (int i = 0, nb = 0; cmd[i]; i++) {
        if (cmd[i] == '>')
            nb++;
        if (nb == 2)
            status = 1;
    }
    return (status);
}

static void last_exec_cmd(char **cmd, char **temp, int fd, char **env)
{
    int fl = 0;

    dup2(fd, 0);
    if (temp[1] != NULL) {
        if (double_redir(NULL) == 0)
            fl = open(clean_string(temp[1]), O_RDWR | O_CREAT | O_TRUNC, 0666);
        else
            fl = open(clean_string(temp[1]), O_RDWR | O_CREAT | O_APPEND, 0666);
        dup2(fl, 1);
        close(fl);
    }
    if (is_builtin(cmd[0]) != 1)
        my_treat_cmd(cmd, env);
    else
        exit(0);
}

void my_pipe(char *str, char **env)
{
    int fd = dup(0);
    char **cmd = my_strtab(str, '|');
    char **temp = NULL;
    int status = 0;
    int pid = 0;

    for (int i = 0; cmd[i + 1]; i++)
        fd = my_dup_cmd(my_strtab(cmd[i], ' '), env, fd);
    double_redir(cmd[my_strlen_array(cmd) - 1]);
    temp = my_strtab(cmd[my_strlen_array(cmd) - 1], '>');
    cmd = my_strtab(temp[0], ' ');
    pid = fork();
    if (pid == 0) {
        last_exec_cmd(cmd, temp, fd, env);
    } else {
        waitpid(pid, &status, F_OK);
        check_signal(status);
        if (is_builtin(cmd[0]) == 1)
            my_treat_cmd(cmd, env);
    }
}
