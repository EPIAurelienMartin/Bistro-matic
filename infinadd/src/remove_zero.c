/*
** EPITECH PROJECT, 2017
** infinadd
** File description:
** remove_zero
*/

#include "my.h"
#include "bistro-matic.h"

char	*remove_zero(char *str, int sign, char *ops, char *base)
{
	int	i = my_strlen(str) - 1;

	while (str[i] == base[0] && i != 0) {
		str[i] = '\0';
		i--;
	}
	if (sign == 1) {
		str[my_strlen(str)] = ops[OP_SUB_IDX];
		str[my_strlen(str)] = '\0';
	}
	return (str);
}
