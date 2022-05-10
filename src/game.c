/*
** EPITECH PROJECT, 2022
** hangman
** File description:
** stumper 7
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "hangman.h"
#include <stdlib.h>

static char *read_letter(void)
{
    char *letter = malloc(sizeof(char) * 5);
    int nb_read = 0;

    nb_read = read(0, letter, 4);
    letter[nb_read] = '\0';
    return (letter);
}

static int check_letter(game_t *game, char letter)
{
    int if_in = 0;

    for (int i = 0; game->secret_word[i] != '\0'; i++) {
        if (game->secret_word[i] == letter) {
            game->player_word[i] = letter;
            if_in = 1;
        }
    }
    return (if_in);
}

static int letter_action(char *word, game_t *game)
{
    if (strlen(word) > 2)
        write(2, "Guess must be a single letter\n", 30);

    else if (check_letter(game, word[0]) == 0) {
        write(1, &word[0], 1);
        write(1, ": is not in this word\n", 22);
        game->tries -= 1;
    }
    return (0);
}

static int print_things(char *player_word, int tries)
{
    write(1, player_word, strlen(player_word));
    write(1, "\nTries: ", 8);
    my_put_nbr(tries);
    write(1, "\n\n", 2);
    return (0);
}

int game_main(game_t *game)
{
    char *word = NULL;

    print_things(game->player_word, game->tries);
    while (game->tries != 0) {
        write(1, "Your letter: ", 13);
        word = read_letter();
        letter_action(word, game);
        print_things(game->player_word, game->tries);
        free(word);
        if (strcmp(game->secret_word, game->player_word) == 0) {
            write(1, "Congratulations!\n", 17);
            return (0);
        }
    }
    write(1, "You lost!\n", 10);
    return (0);
}
