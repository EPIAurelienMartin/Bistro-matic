/*
** EPITECH PROJECT, 2017
** infin_add
** File description:
** beginning
*/

#include "bistro-matic.h"
#include "my.h"

void	init_functions(char *(*calc[2])(char*, char*, char*))
{
	calc[0] = &do_inf_add;
	calc[1] = &do_inf_sub;
}

void	swap_words(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	which_op(char **a, char **b, char *ops, int *sign)
{
	if (*a[0] == ops[OP_SUB_IDX] && *b[0] == ops[OP_SUB_IDX]) {
		*sign = 1;
		*a[0] = '0';
		*b[0] = '0';
		return (0);
	}
	if (*a[0] == ops[OP_SUB_IDX] && *b[0] != ops[OP_SUB_IDX]) {
		if (my_nstrcmp(*a, *b, ops) > 0)
			*sign = 1;
		*a[0] = '0';
		return (1);
	} else if (*a[0] != ops[OP_SUB_IDX] && *b[0] == ops[OP_SUB_IDX]) {
		if (my_nstrcmp(*a, *b, ops) < 0)
			*sign = 1;
		*b[0] = '0';
		return (1);
	}
	return (0);
}

char	*add_it(char *s1, char *s2, char *base, char *ops)
{
	char	*(*calc[2]) (char* , char* , char*);
	char	*res;
	int	sign = 0;

	init_functions(calc);
	if (my_nstrcmp(s1, s2, ops) < 0)
		swap_words(&s1, &s2);
	res = calc[which_op(&s1, &s2, ops, &sign)](s1, s2, base);
	return (my_revstr(remove_zero(res, sign, ops, base)));
}
