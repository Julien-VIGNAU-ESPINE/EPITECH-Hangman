/*
** EPITECH PROJECT, 2022
** Hangman
** File description:
** stumper7
*/

#include <stdlib.h>
#include <time.h>

static int check_number(char *str)
{
    int check = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str [i] > '9')
            check = 1;
    return (check);
}

static void free_tab(char **all_word)
{
    for (int i = 0; all_word[i] != NULL; i++)
        free(all_word[i]);
    free(all_word);
}

static int check_tab(char **all_word)
{
    for (int i = 0; all_word[i] != NULL; i++) {
        clean_str_end(all_word[i]);
        clean_str_start(all_word[i]);
        if (find_space(all_word[i]) == 1)
            return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    return (0);
}
