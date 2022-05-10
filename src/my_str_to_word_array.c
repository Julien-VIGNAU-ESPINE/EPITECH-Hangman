/*
** EPITECH PROJECT, 2022
** my
** File description:
** my_str_to_word_array
*/

#include "stdlib.h"

static int number_of_delimiters(char *str, char delim)
{
    int i = 0;
    int result = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] == delim)
            result++;
    }
    if (result == 0)
        return (result + 2);
    return (result + 1);
}

static char **allocate_array(char *str, char delim)
{
    char **result = NULL;
    int y = 0;
    int size = 0;

    if (!str)
        return (NULL);
    result = malloc(sizeof(char *) * (number_of_delimiters(str, delim) + 1));
    for (int i = 0; str[i]; i++, size++)
        if (str[i] == delim) {
            result[y] = malloc(sizeof(char) * size + 1);
            y++;
            size = 0;
        }
    if (size != 0)
        result[y++] = malloc(sizeof(char) * size + 1);
    result[y] = NULL;
    return (result);
}

char **my_str_to_word_array(char *str, char delim)
{
    char **result = allocate_array(str, delim);
    int x = 0;
    int y = 0;

    if (!result)
        return (NULL);
    for (int j = 0; str[j] != '\0'; j++, x++) {
        if (str[j] != delim)
            result[y][x] = str[j];
        else {
            result[y][x] = '\0';
            y++;
            x = -1;
        }
    }
    result[y][x] = '\0';
    return (result);
}
