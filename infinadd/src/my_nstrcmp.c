/*
** EPITECH PROJECT, 2017
** infinadd
** File description:
** nstrcmp
*/

#include "bistro-matic.h"
#include "my.h"

int	my_pstrcmp(char *s1, char *s2, char *ops)
{
	int	i = 0;

	if (s1[0] == ops[OP_SUB_IDX] && s2[0] == ops[OP_SUB_IDX]) {
		if (my_strlen(s1) - my_strlen(s2) != 0)
			return ((my_strlen(s1) - 1) - my_strlen(s2));
		while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
			i++;
		return (s1[i] - s2[i]);
	} else if (s1[0] != ops[OP_SUB_IDX] && s2[0] != ops[OP_SUB_IDX]) {
		if (my_strlen(s1) - my_strlen(s2) != 0)
			return (my_strlen(s1) - my_strlen(s2));
		while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
			i++;
		return (s1[i] - s2[i]);
	}
	return (0);
}

int	my_nstrcmp(char *s1, char *s2, char *ops)
{
	int	i = 0;

	if (s1[0] == ops[OP_SUB_IDX] && s2[0] != ops[OP_SUB_IDX]) {
		if ((my_strlen(s1) - 1) - my_strlen(s2) != 0)
			return ((my_strlen(s1) - 1) - my_strlen(s2));
		while (s1[i + 1] == s2[i] && s1[i + 1] != '\0' && s2[i] != '\0')
			i++;
		return (s1[i + 1] - s2[i]);
	} else if (s1[0] != ops[OP_SUB_IDX] && s2[0] == ops[OP_SUB_IDX]) {
		if (my_strlen(s1) - (my_strlen(s2) - 1) != 0)
			return (my_strlen(s1) - (my_strlen(s2) - 1));
		while (s1[i] == s2[i + 1] && s1[i] != '\0' && s2[i + 1] != '\0')
			i++;
		return (s1[i] - s2[i + 1]);
	}
	else
		return (my_pstrcmp(s1, s2, ops));
}
