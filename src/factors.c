/*
** EPITECH PROJECT, 2017
** evalexpr
** File description:
** factors
*/

#include "my.h"
#include "bistro-matic.h"

char    *mod_it(char *str1, char *str2, char *base, char *ops)
{
	char	forcat[2];
	char	*big;

	if (my_strcmp(str2, "0") == 0) {
		my_putstr(ERROR_MSG);
		exit(84);
	}
	forcat[0] = ops[OP_SUB_IDX];
	forcat[1] = '\0';
	big = my_strcat(forcat, mul_it(str2, div_it(str1, str2, \
						    base, ops), base, ops));
	return (add_it(str1, big, base, ops));
}

char     *factors(char **str, char *base, char *ops)
{
	char	*res = my_strtol(str, base, ops);

	while (**str != '\0') {
		if (**str == ops[OP_MULT_IDX]) {
			res = mul_it(res, my_strtol(str, base, ops), base, ops);
		} else if (**str == ops[OP_DIV_IDX]) {
			res = verif_div(res, \
					my_strtol(str, base, ops), base, ops);
		} else if (**str == ops[OP_MOD_IDX]) {
			res = mod_it(res, my_strtol(str, base, ops), base, ops);
		} else {
			return (res);
		}
	}
	return (res);
}
