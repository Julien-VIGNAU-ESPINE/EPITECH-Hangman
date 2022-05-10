/*
** EPITECH PROJECT, 2022
** hangman
** File description:
** stumper5
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "hangman.h"

static char read_letter(void)
{
    char letter[2];

    read(0, &letter, 2);
    return (letter[0]);
}

static int check_letter(game_t *game, char letter)
{
    int if_in = 0;

    for (int i = 0; game->to_find[i] != '\0'; i++) {
        if (game->to_find[i] == letter) {
            game->game_word[i] = letter;
            if_in = 1;
        }
    }
    return (if_in);
}

int game_main(game_t *game)
{
    char letter;

    printf("%s\nTries: %i\n\n", game->game_word, game->tries);
    while (game->tries != 0) {
        write(1, "Your letter: ", 13);
        letter = read_letter();
        if (check_letter(game, letter) == 0) {
            printf("%c: is not in this word\n", letter);
            game->tries -= 1;
        }
        printf("%s\nTries: %i\n\n", game->game_word, game->tries);
        if (strcmp(game->to_find, game->game_word) == 0) {
            printf("Congratulations!\n");
            return (0);
        }
    }
    printf("You lost!\n");
    return (0);
}
