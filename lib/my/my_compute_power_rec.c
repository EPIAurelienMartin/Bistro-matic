/*
** EPITECH PROJECT, 2017
** my_compute_power_rec
** File description:
** compute_power
*/

#include "my.h"

int	my_compute_power_rec(int nb, int power)
{
	if (power > 0) {
		if (power > 1)
			nb *= my_compute_power_rec(nb, power - 1);
		else
			return (nb);
	} else if (power == 0) {
		return (1);
	} else {
		return (0);
	}
	return (nb);
}
