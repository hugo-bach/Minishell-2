/*
** EPITECH PROJECT, 2018
** my_fct input
** File description:
** fct input
*/

#include "my_sh.h"

static int check_error_pipe(char *cmd)
{
    int nb = 0;
    for (int i = 0, count = 0; cmd[i]; i++) {
        if (cmd[0] == '|')
            return (-1);
        (cmd[i] == '|') ? nb++ : 0;
        (cmd[i] == '>') ? count++ : 0;
        if (count > 0 && nb != 0) {
            my_putstr("Ambiguous output redirect.\n", 2);
            return (-2);
        }
        if (cmd[i] != ' ' && cmd[i] != '|' && cmd[i] != '\0')
            nb = 0;
        if (nb == 2)
            return (-1);
    }
    if (nb != 0)
        return (-1);
    return (0);
}

void my_input(char **env)
{
    char *temp = NULL;
    char **cmd = NULL;
    size_t len = 0;
    int nb = 0;

    single_env(env);
    while (1) {
        env = single_env(NULL);
        (isatty(0)) ? my_putstr("> ", 1) : 0;
        (getline(&temp, &len, stdin) == -1) ? exit(0) : 0;
        replace_char(temp, '\n', '\0');
        cmd = my_strtab(temp, ';');
        for (int i = 0; cmd[i]; i++) {
            if ((nb = check_error_pipe(cmd[i])) == -1)
                my_putstr("Invalid null command.\n", 2);
            else if (cmd[i][0] != '\0' && nb != -2)
                my_pipe(cmd[i], env);
        }
    }
}
