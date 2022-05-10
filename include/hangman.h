/*
** EPITECH PROJECT, 2022
** hangman
** File description:
** stumper 7
*/

#ifndef HANGMAN_H_
    #define HANGMAN_H_

    typedef struct game_s {
	int tries;
	char *secret_word;
	char *player_word;
    } game_t;

    void clean_str_end(char *str);
    void clean_str_start(char *str);
    int find_space(char *str);
    char **my_str_to_word_array(char *str, char delim);
    int open_file(const char *path);
    char **read_file(const char *path);
    int init_struct(char **dictionary, int ac, char **av, game_t *game);
    int game_main(game_t *game);
    int my_put_nbr(int nb);

#endif /* HANGMAN_H_ */
