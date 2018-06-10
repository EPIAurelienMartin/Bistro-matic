/*
** EPITECH PROJECT, 2017
** my_sort_in_array
** File description:
** array_or_tab
*/

#include "my.h"

void	my_sort_int_array(int *tab, int size)
{
	int	i = 1;

	while (i < size) {
		if (tab[i] < tab[i - 1]) {
			my_swap(&tab[i], &tab[i - 1]);
			my_sort_int_array(tab, size);
		} else
			i++;
	}
}
