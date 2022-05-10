/*
** EPITECH PROJECT, 2022
** hangman
** File description:
** init struct
*/

#include <string.h>
#include <stdlib.h>
#include "hangman.h"

static int len_tab(char **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return (i);
}

static char *create_player_word(int len)
{
    char *str = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len; i++)
        str[i] = '*';
    str[len] = '\0';
    return (str);
}

int init_struct(char **dictionary, int ac, char **av, game_t *game)
{
    int index = rand() % (len_tab(dictionary) - 1);

    game->tries = 10;
    if (ac == 3)
        game->tries = atoi(av[2]);
    game->secret_word = strdup(dictionary[index]);
    game->player_word = create_player_word(strlen(game->secret_word));
    return (0);
}
