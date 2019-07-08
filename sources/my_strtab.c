/*
** EPITECH PROJECT, 2018
** my_strtab.c
** File description:
** str tab
*/

#include "my_sh.h"

static int count_sep(char *str, char c)
{
    int nb = 1;
    int i = 0;

    for (; str[i] && (str[i] == c || str[i] == ' '); i++);
    for (; str[i]; i++) {
        if (str[i] == c)
            nb++;
        for (; str[i] && str[i] == c; i++);
    }
    return (nb);
}

static int count_size_word(char *str, int i, char sep)
{
    int nb = 1;

    for (;str[i] && str[i] == sep; i++);
    for (; str[i] && str[i] != sep; i++, nb++);
    return (nb);
}

char **my_strtab(char *str, char sep)
{
    char **result = my_calloc_array(count_sep(str, sep));
    int i = 0;

    replace_char(str, '\t', ' ');
    for (; str[i] && (str[i] == ' ' || str[i] == sep); i++);
    result[0] = my_calloc_str(count_size_word(str, i, sep));
    for (int j = 0, k = 0; str[i]; i++) {
        if (str[i] == sep && str[i + 1] != sep && str[i + 1]) {
            result[++j] = my_calloc_str(count_size_word(str, i, sep));
            k = 0;
        } else if (str[i] != sep)
            result[j][k++] = str[i];
    }
    return (result);
}
