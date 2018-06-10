/*
** EPITECH PROJECT, 2017
** div
** File description
** div
*/

#include "my.h"
#include "bistro-matic.h"

char	*my_div_zero(int len, char *str2, char *base)
{
	char	*res = malloc(sizeof(char) * len + 1);
	int	a = 0;
	int	diff = len - my_strlen(str2);

	while (str2[a]) {
		res[a] = str2[a];
		a++;
	}
	while (diff > 0) {
		res[a] = base[0];
		a++;
		diff--;
	}
	res[a] = '\0';
	return (res);
}

char	*add_zero2(char *str1, char *str2, char *base)
{
	char	*res = malloc(sizeof(char) * my_strlen(str1) + 1);
	int	len1 = my_strlen(str1);
	int	len2 = my_strlen(str2);
	int	a = 0;
	int	b = 0;

	if (len1 <= len2)
		return (str2);
	else
		len2 = len1 - len2;
	for (a = a ; (len2 != 0) ; a++) {
		res[a] = base[0];
		len2--;
	}
	for (a = a; (len1 != 0); a++) {
		res[a] = str2[b];
		b++;
		len1--;
	}
	res[a] = '\0';
	return (res);
}

char	*str_zero(char *str1, char *str2, char *base)
{
	char	*res = malloc(sizeof(char) * my_strlen(str2) + 1);
	int	a = 0;
	int	b = 0;
	int	diff = my_strlen(str2) - my_strlen(str1);

	while (diff != 0) {
		res[a] = base[0];
		a++;
		diff--;
	}
	while (str1[b]) {
		res[a] = str1[b];
		a++;
		b++;
	}
	res[a] = '\0';
	return (res);
}

char	*div_it(char *str1, char *str2, char *b, char *ope)
{
	char	*res = malloc(sizeof(char) * my_strlen(str1) + 1);
	char	*div_zero = my_div_zero(my_strlen(str1), str2, b);
	char	*div_minus = my_strcat("-", div_zero);
	int	len_c = my_strlen(str1);
	int	len = my_strlen(str1) - my_strlen(str2);
	int	count = 0;
	int	a = 0;
	char	*forcat = my_forcat(ope);

	for (count = 0; (len >= 0); len-- , a++) {
		for (count = 0; (my_strcmp(str_zero(str1, div_zero, b), \
					  div_zero) >= 0); count++) {
			(my_strlen(str1) < my_strlen(div_zero)) ? div_zero = \
				my_div_zero(my_strlen(str1), str2, b) : 0;
			div_minus = my_strcat(forcat, div_zero);
			str1 = add_it(str1, div_minus, b, ope);
		}
		len_c--;
		div_zero = add_zero2(str1, my_div_zero(len_c, str2, b), b);
		res[a] = b[count];
	}
	return (res_clean(res, b, ope));
}

char	*verif_div(char *str1, char *str2, char *base, char *ope)
{
	char	forcat[2];
	char	*res = "0";
	int	sign = 0;

	if (my_strcmp(str2, "0") == 0) {
		my_putstr(ERROR_MSG);
		exit(84);
	}
	forcat[0] = ope[OP_SUB_IDX];
	forcat[1] = '\0';
	if (str1[0] == ope[OP_SUB_IDX]) {
		sign++;
		str1++;
	}
	if (str2[0] == ope[OP_SUB_IDX]) {
		sign++;
		str2++;
	}
	if (sign == 1)
		res = my_strcat(forcat, div_it(str1, str2, base, ope));
	else
		res = div_it(str1, str2, base, ope);
	return (res);
}
