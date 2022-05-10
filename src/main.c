/*
** EPITECH PROJECT, 2022
** Hangman
** File description:
** stumper7
*/

#include <stdlib.h>
#include <time.h>
#include "hangman.h"

static int check_number(char *str)
{
    int check = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str [i] > '9')
            check = 1;
    return (check);
}

static void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

static void free_all(game_t *game, char **dictionary)
{
    free(game->secret_word);
    free(game->player_word);
    free_tab(dictionary);
}

static int check_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        clean_str_end(tab[i]);
        clean_str_start(tab[i]);
        if (find_space(tab[i]) == 1)
            return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    game_t game;
    char **dictionary = NULL;

    srand(time(NULL));
    if (ac < 2 || ac > 3 || (ac == 3 && check_number(av[2]) == 1))
        return (84);
    if (open_file(av[1]) == 1)
        return (84);
    dictionary = read_file(av[1]);
    if (check_tab(dictionary) == 1) {
        free_tab(dictionary);
        return (84);
    }
    init_struct(dictionary, ac, av, &game);
    game_main(&game);
    free_all(&game, dictionary);
    return (0);
}
