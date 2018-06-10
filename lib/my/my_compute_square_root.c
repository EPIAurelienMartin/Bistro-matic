/*
** EPITECH PROJECT, 2017
** my_compute_square_root
** File description:
** compute_square_root
*/

#include "my.h"

int	my_compute_square_root(int nb)
{
	int i;

	i = 0;
	if (nb < 0)
		return (0);
	while ((i * i) != nb) {
		if ((i * i) > nb) {
			return (0);
		}
		i = i + 1;
	}
	return (i);
}
