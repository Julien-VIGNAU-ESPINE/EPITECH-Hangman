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

static char *read_letter(void)
{
    char letter[4];

    read(0, &letter, 4);
    return (letter);
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

static int letter_action(char *word, game_t *game)
{
    char letter;
    if (strlen(letter) >= 2)
        write(2, "Guess must be a single letter\n", 30);
    else if (check_letter(game, letter) == 0) {
        letter = word[0];
        printf("%c: is not in this word\n",letter);
        game->tries -= 1;
    }
    return 0;
}

int game_main(game_t *game)
{
    char word[4];

    printf("%s\nTries: %i\n\n", game->game_word, game->tries);
    while (game->tries != 0) {
        write(1, "Your letter: ", 13);
        word = read_letter();
        letter_action(word, game);
        printf("%s\nTries: %i\n\n", game->game_word, game->tries);
        if (strcmp(game->to_find, game->game_word) == 0) {
            printf("Congratulations!\n");
            return (0);
        }
    }
    printf("You lost!\n");
    return (0);
}
