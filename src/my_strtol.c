/*
** EPITECH PROJECT, 2017
** lib
** File description:
** strtol
*/

#include "bistro-matic.h"
#include "my.h"

int	is_op(char c, char *ops, int i, int j)
{
	while (ops[i] != '\0' && i <= j) {
		if (c == ops[i])
			return (0);
		i++;
	}
	return (1);
}

int	nb_strlen(char *str, char *base, char *ops)
{
	int	i = 0;
	int	size = 0;

	if (is_op(str[i], ops, 2, 3) == 0) {
		size++;
		while (is_op(str[i], ops, 2, 3) == 0)
			i++;
	} else if (is_op(str[i], ops, 2, 6) == 0)
		i++;
	if (str[i] == ops[OP_OPEN_PARENT_IDX])
		return (0);
	while (is_in_base(str[i], base) != -1) {
		size++;
		i++;
	}
	return (size);
}

int	gest_string(char **str, char *ops)
{
	int	mul = 0;

	while (is_op(**str, ops, 2, 3) == 0) {
		if (**str == ops[OP_SUB_IDX])
			mul += 1;
		*str += 1;
	}
	if (is_op(**str, ops, 4, 6) == 0) {
		*str += 1;
		if (**str == ops[OP_SUB_IDX]) {
			mul += 1;
			*str += 1;
		}
	}
	return (mul);
}

char	*set_unit(char *base, char *ops)
{
	char	*res;

	res = malloc(sizeof(*res) * 3);
	res[0] = ops[OP_SUB_IDX];
	res[1] = base[1];
	res[2] = '\0';
	return (res);
}

char	*my_strtol(char **str, char *base, char *ops)
{
	char		*res;
	char		*unit = set_unit(base, ops);
	int		mul = gest_string(str, ops);
	unsigned int	i = 0;

	res = malloc(sizeof(*res) * (nb_strlen(*str, base, ops) + 1));
	if (**str == ops[OP_OPEN_PARENT_IDX]) {
		*str += 1;
		if (mul % 2 == 1)
			res = mul_it(unit, summands(str, base, ops), base, ops);
		else
			res = summands(str, base, ops);
	} else {
		res[i] = ops[OP_SUB_IDX];
		mul % 2 == 1 ? i++ : i;
		for (i = i ; (is_in_base(**str, base) != -1) ; i++) {
			res[i] = **str;
			*str += 1;
		}
	}
	return (res);
}
