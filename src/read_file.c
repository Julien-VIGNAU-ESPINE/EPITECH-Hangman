/*
** EPITECH PROJECT, 2022
** hangman
** File description:
** hangman.h
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "hangman.h"

static int check_size_file(const char *path)
{
    struct stat sb;

    stat(path, &sb);
    return (sb.st_size);
}

int open_file(const char *path)
{
    int file = 0;

    file = open(path, O_RDONLY);
    if (file < 0) {
        close(file);
        return (1);
    }
    close(file);
    return (0);
}

char **read_file(const char *path)
{
    char *buf = malloc(sizeof(char) * (check_size_file(path) + 1));
    char **tab = NULL;

    read(open(path, O_RDONLY), buf, check_size_file(path));
    buf[check_size_file(path)] = '\0';
    if (check_size_file(path) <= 0)
        return (tab);
    tab = my_str_to_word_array(buf, '\n');
    free(buf);
    return (tab);
}
