/*
** EPITECH PROJECT, 2018
** my_sh.h
** File description:
** header of the project minishell 2
*/

#ifndef MY_SH
#define MY_SH

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/limits.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int my_strlen(char *);
int my_strlen_array(char **);
int my_strncmp(char *, char *, int);
char *my_getenv(char **, char *);
char **my_tabdup(char **);
char *my_strdup(char *);
char **my_calloc_array(int);
char *my_calloc_str(int);
void my_putstr(char *, int);
void write_my_error(char *);
char *my_strcat(char *, char *);
char **my_unsetenv(char **, char **);
char **my_env(char **, char **);
char **my_setenv(char **, char **);
int my_strcmp(char *, char *);
char **my_strtab(char *, char);
void replace_char(char *, char, char);
void my_input(char **);
void my_treat_cmd(char **, char **);
char *my_cmd(char *);
char *my_strcat_path(char *, char *);
int my_access(char *, char *);
void my_error(char *, int);
char **single_env(char **);
void my_pipe(char *, char **);
int is_builtin(char *);
void my_free(char **);
char **my_exit(char **, char **);
char *clean_string(char *);
char *single_old(char *);
char *get_pwd(void);
char **my_cd(char **, char **);
void check_signal(int);

#endif /*MY_SH*/
