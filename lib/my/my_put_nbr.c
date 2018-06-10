/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** put_nbr
*/

#include "my.h"

int	my_put_nbr_neg(int nb)
{
	if (nb == -2147483648) {
		my_putchar('-');
		my_putchar('2');
		my_putchar('1');
		nb = 47483648;
	} else {
		nb = nb * (-1);
		my_putchar('-');
	}
	my_put_nbr(nb);
	return (0);
}

int	my_put_nbr(int nb)
{
	if (nb < 0) {
		my_put_nbr_neg(nb);
	} else if (nb > 9) {
		my_put_nbr(nb / 10);
		my_putchar(nb % 10 + 48);
	} else
		my_putchar(nb + 48);
	return (0);
}
