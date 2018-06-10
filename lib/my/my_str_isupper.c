/*
** EPITECH PROJECT, 2017
** my_str_isupper
** File description:
** str_isupper
*/

#include "my.h"

int	my_str_isupper(char const *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (str[i] > 'Z' || str[i] < 'A')
			return (0);
		i++;
	}
	return (1);
}
