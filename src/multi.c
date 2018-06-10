/*
** EPITECH PROJECT, 2017
** mainmain
** File description:
** main
*/

#include "my.h"
#include "mult.h"

int	get_nbase(char *base, char carac)
{
	int  i = 0;

	for (i = 0 ; carac != base[i] ; i++);
	return (i);
}

char	*add_numbers_inf(struct s_mult *m, int len, int res)
{
	int	base = 0;

	for (base = 0; (res); len--) {
		base = get_nbase(m->base, m->res[len]);
		res += base;
		m->res[len] = m->base[res % my_strlen(m->base)];
		res /= 10;
	}
	return (m->res);
}

char	*mult_number(struct s_mult *m, int len2, int len)
{
	int	len1;
	int	res;

	for (len1 = my_strlen(m->nb1) -1; (len1 >= 0); len1--) {
		res = (get_nbase(m->base, m->nb1[len1]) * \
		       get_nbase(m->base, m->nb2[len2]));
		add_numbers_inf(m, len, res);
		len -= 1;
	}
	return (m->res);
}

char	*res_clean(char *clean, char *base, char *ope)
{
	char	*res;

	if (*clean == ope[OP_SUB_IDX])
		clean++;
	for (res = clean; (*res && *res == base[0]) ; res++);
	if (*res)
		res = my_strdup(res);
	else {
		res[0] = base[0];
		res[1] = '\0';
	}
	return (res);
}

char	*multiplication(struct s_mult *m, char *ope)
{
	int	len2;
	int	len;
	int	i = 0;

	if ((m->res = malloc(sizeof(char) * my_strlen(m->nb1) +\
			     my_strlen(m->nb2) + 1)) == NULL) {
		return (0);
	}
	for (i = 0 ; (i < my_strlen(m->nb1) + my_strlen(m->nb2)) ; i++)
		m->res[i] = m->base[0];
	m->res[i] = '\0';
	if (m->res == 0)
		return (0);
	len = my_strlen(m->res) - 1;
	for (len2 = my_strlen(m->nb2) - 1; (len2 >= 0) ; len2--) {
		mult_number(m, len2, len);
		len -= 1;
	}
	m->res = res_clean(m->res, m->base, ope);
	return (m->res);
}
