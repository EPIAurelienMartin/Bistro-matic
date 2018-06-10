/*
** EPITECH PROJECT, 2017
** my_strcapitalize
** File description:
** strcapitalize
*/

#include "my.h"

int	is_alphanum(char c)
{
	if ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a') \
	    || (c <= '9' && c >= '0')) {
		return (0);
	} else {
		return (1);
	}
}

char	*my_strcapitalize(char *str)
{
	int	i = 1;

	if (str[0] <= 'z' && str[0] >= 'a')
		str[0] = str[0] - 32;
	while (str[i] != '\0') {
		if (is_alphanum(str[i - 1]) == 0 &&
			str[i] <= 'Z' && str[i] >= 'A') {
			str[i] = str[i] + 32;
		}
		if (is_alphanum(str[i - 1]) == 1 &&
			str[i] <= 'z' && str[i] >= 'a') {
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}
