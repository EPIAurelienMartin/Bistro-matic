/*
** EPITECH PROJECT, 2017
** check
** File description:
** stratr
*/

#include "my.h"
#include "bistro-matic.h"

int     check_is_an_ope(char c, char *ope)
{
	int     i = 0;

	while (ope[i]) {
		if (ope[i] == c)
			return (0);
		i++;
	}
	return (84);
}

int     check_is_in_base(char c, char *base, char *ope)
{
	int     i = 0;

	while (base[i]) {
		if ((base[i] == c) || (check_is_an_ope(c, ope) == 0))
			return (0);
		i++;
	}
	return (84);
}

void    check_expr(char *str, char *base, char *ope)
{
	int     i = 0;
	int     one = 0;
	int     two = 0;

	while (str[i] && check_is_in_base(str[i], base, ope) == 0) {
		if (str[i] == '(')
			one++;
		if (str[i] == ')')
			two++;
		i++;
	}
	if (one != two || i < my_strlen(str)) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit(84);
	}
}
