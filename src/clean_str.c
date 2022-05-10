/*
** EPITECH PROJECT, 2021
** my_compute_power_rec
** File description:
** clean str
*/

static void str_decale(char *str, int i)
{
    for (; str[i]; i++)
        str[i] = str[i + 1];
}

void clean_str_end(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        if ((str[i] == ' ' || str[i] == '\t') && (str[i + 1] == '\0' ||
        str[i + 1] == ' ' || str[i + 1] == '\t')) {
            str_decale(str, i);
            i--;
        }
}

void clean_str_start(char *str)
{
    int i = 0;

    for (; (str[i] == ' ' || str[i] == '\t'); i++) {
        str_decale(str, i);
        i--;
    }
}
