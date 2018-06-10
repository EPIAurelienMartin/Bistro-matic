/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** revstr
*/

#include "my.h"

char	*my_revstr(char *str)
{
	int	i = 0;
	int	j = my_strlen(str) - 1;
	char	c;

	while  (i <= (j / 2)) {
		c = str[i];
		str[i] = str[j - i];
		str[j - i] = c;
		i++;
	}
	return (str);
}
