/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** put nbr
*/

#include <unistd.h>

int my_put_nbr(int nb)
{
    int i;
    char c;

    if (nb < 0) {
        write(1, "-", 1);
        nb = nb * (-1);
    }
    if (nb >= 10) {
        i = (nb % 10);
        nb = (nb - i) / 10;
        my_put_nbr(nb);
        c = 48 + i;
        write(1, &c, 1);
    } else {
        c = 48 + nb % 10;
        write(1, &c, 1);
    }
    return (0);
}
