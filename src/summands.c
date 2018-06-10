/*
** EPITECH PROJECT, 2017
** bootstrap evalexpr
** File description:
** summands
*/

#include "bistro-matic.h"
#include "my.h"

char	*summands(char **str, char *base, char *ops)
{
	char	*res = NULL;

	while (**str != '\0') {
		if (res == NULL)
			res = factors(str, base, ops);
		else
			res = add_it(res, factors(str, base, ops), base, ops);
		if (**str == ops[OP_CLOSE_PARENT_IDX]) {
			*str += 1;
			return (res);
		}
	}
	return (res);
}

char	*eval_expr(char *base, char *ops, char *expr, unsigned int size)
{
	char	*res;

	(void)size;
	res = summands(&expr, base, ops);
	return (res);
}
