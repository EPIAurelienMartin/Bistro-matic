/*
** EPITECH PROJECT, 2017
** my_find_prime_sup
** File description:
** find_prime_sup
*/

#include "my.h"

int	my_find_prime_sup(int nb)
{
	int	i = 2;

	while (nb <= 2147483648) {
		if (my_is_prime(nb) == 1)
			return (nb);
		nb++;
	}
	return (0);
}
