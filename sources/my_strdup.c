/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** fct who copy a string
*/

#include "my_sh.h"

char *my_strdup(char *str)
{
    char *result = my_calloc_str(my_strlen(str));

    if (str == NULL)
        return (NULL);
    for (int i = 0; str[i]; i++)
        result[i] = str[i];
    return (result);
}
