/*
** EPITECH PROJECT, 2017
** bistro-matic
** File description:
** check_base
*/

#include "my.h"
#include "bistro-matic.h"

int	is_in_base(char c, char *base)
{
	int	i = 0;

	while (base[i] != '\0') {
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}
