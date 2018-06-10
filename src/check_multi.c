/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "my.h"
#include "mult.h"

char	*mul_it(char *str1, char *str2, char *base, char *ope)
{
	struct s_mult m;
	char	*res;
	int	signe = 0;

	if (str1[0] == '-') {
		str1++;
		signe++;
	}
	if (str2[0] == '-') {
		str2++;
		signe++;
	}
	m.base = my_strdup(base);
	m.nb1 = my_strdup(str1);
	m.nb2 = my_strdup(str2);
	m.res = 0;
	res = multiplication(&m, ope);
	if (signe == 1)
		res = my_strcat(("-"), res);
	return (res);
}
