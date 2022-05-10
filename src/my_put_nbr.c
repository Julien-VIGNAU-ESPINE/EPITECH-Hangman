/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** put nbr
*/

#include <unistd.h>

int my_put_nbr(int nb)
{
    char c;

    if (nb < 0) {
        write(1, "-", 1);
        nb *= -1;
    }
    if (nb == 0) {
        return 0;
    }
    my_put_nbr(nb / 10);
    c = (nb % 10 + '0');
    write(1, &c, 1);
    return 0;
}
