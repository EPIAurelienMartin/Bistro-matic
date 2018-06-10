/*
** EPITECH PROJECT, 2017
** op
** File description:
** bse
*/

#include "my.h"
#include "bistro-matic.h"

void    check_in_bops_same(char *base, char *ops)
{
	int     i = 0;
	int     j = 0;
	int     error = 0;

	while (base[i]) {
		j = 0;
		while (ops[j]) {
			(base[i] == ops[j]) ? error = 84 : error;
			j++;
		}
		i++;
	}
	if (error == 84) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit (84);
	}
}
