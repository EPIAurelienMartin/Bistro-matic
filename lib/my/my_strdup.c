/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** strdup
*/

#include "my.h"

char	*my_strdup(char const *str)
{
	char	*s;

	s = malloc(sizeof(*s) * (my_strlen(str) + 1));
	if (s == NULL)
		return (NULL);
	my_strcpy(s, str);
	return (s);
}
