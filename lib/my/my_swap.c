/*
** EPITECH PROJECT, 2017
** my_swap
** File description:
** swap_it
*/

#include "my.h"

int	my_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
	return (0);
}
