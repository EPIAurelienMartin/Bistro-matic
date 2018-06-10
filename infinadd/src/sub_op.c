/*
** EPITECH PROJECT, 2017
** infadd
** File description:
** sub_ops
*/

#include "bistro-matic.h"
#include "my.h"

char	check_sub_res(int res, char *base, int *ret)
{
	*ret = check_sub_ret(res);
	if (res < 0)
		return (base[res + my_strlen(base)]);
	else
		return (base[res]);
}

int	check_sub_ret(int res)
{
	if (res < 0)
		return (1);
	else
		return (0);
}

char	*do_inf_sub(char *a, char *b, char *base)
{
	char	*res;
	int	ret = 0;
	int	pos = 1;
	int	nb;

	res = malloc(sizeof(*res) * (my_strlen(a) + 2));
	while (is_in_base(a[my_strlen(a) - pos], base) != -1) {
		if (my_strlen(b) - pos < 0 ||
			is_in_base(b[my_strlen(b) - pos], base) == -1) {
			nb = is_in_base(a[my_strlen(a) - pos], base) - ret;
		} else {
			nb = is_in_base(a[my_strlen(a) - pos], base) - \
				(is_in_base(b[my_strlen(b) - pos], base) + ret);
		}
		res[pos - 1] = check_sub_res(nb, base, &ret);
		pos++;
	}
	return (res);
}
