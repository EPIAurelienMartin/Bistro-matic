/*
** EPITECH PROJECT, 2017
** my_str_isalpha
** File description:
** str_isalpha
*/

#include "my.h"

int	my_str_isalpha(char const *str)
{
	int	i = 0;

	if (str[i] == '\0')
		return (1);
	while ((str[i] <= 'Z' && str[i] >= 'A') ||
		(str[i] <= 'z' && str[i] >= 'a')) {
		i++;
		if (str[i] == '\0')
			return (1);
	}
	return (0);
}
