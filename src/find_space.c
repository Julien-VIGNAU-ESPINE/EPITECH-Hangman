/*
** EPITECH PROJECT, 2022
** hangman
** File description:
** find space
*/

int find_space(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ' ')
            return (1);
    return (0);
}
