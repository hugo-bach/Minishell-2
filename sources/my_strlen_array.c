/*
** EPITECH PROJECT, 2018
** my_strlen_array.c
** File description:
** fct strlen of array
*/

#include "my_sh.h"

int my_strlen_array(char **str)
{
    int nb = 0;

    if (str == NULL)
        return (0);
    for (; str[nb]; nb++);
    return (nb);
}
