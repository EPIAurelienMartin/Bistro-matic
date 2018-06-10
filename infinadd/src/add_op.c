/*
** EPITECH PROJECT, 2017
** ops
** File description:
** ops
*/

#include "bistro-matic.h"
#include "my.h"

int	is_comp(char c, char d, char *base)
{
	if (is_in_base(c, base) != -1 || is_in_base(d, base) != -1)
		return (0);
	else
		return (1);
}

char	check_add_res(int res, char *base, int *ret)
{
	*ret = check_add_ret(res, base);
	if (res > my_strlen(base) - 1)
		return (base[res - my_strlen(base)]);
	else
		return (base[res]);
}

int	check_add_ret(int res, char *base)
{
	if (res > my_strlen(base) - 1) {
		return (1);
	} else {
		return (0);
	}
}

char	*do_inf_add(char *a, char *b, char *base)
{
	char	*res;
	int	ret = 0;
	int	pos = 1;
	int	nb;

	res = malloc(sizeof(*res) * (my_strlen(a) + 2));
	while (is_comp(a[my_strlen(a) - pos], \
		       b[my_strlen(b) - pos], base) == 0) {
		if (my_strlen(b) - pos < 0 ||
			is_in_base(b[my_strlen(b) - pos], base) == -1) {
			nb = is_in_base(a[my_strlen(a) - pos], base) + ret;
		} else {
			nb = is_in_base(a[my_strlen(a) - pos], base) + \
				is_in_base(b[my_strlen(b) - pos], base) + ret;
		}
		res[pos - 1] = check_add_res(nb, base, &ret);
		pos++;
	}
	if (ret == 1)
		res[pos - 1] = base[1];
	return (res);
}
