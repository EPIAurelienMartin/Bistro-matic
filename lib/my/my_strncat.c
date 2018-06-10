/*
** EPITECH PROJECT, 2017
** my_strncat
** File description:
** strncat
*/

#include "my.h"

char	*my_strncat(char *dest, char const *src, int nb)
{
	int	i = 0;
	int	j = my_strlen(dest);

	while (i < nb && src[i] != '\0') {
		dest[i + j] = src[i];
		i++;
	}
	dest[i + j] = '\0';
	return (dest);
}
