/*
** EPITECH PROJECT, 2017
** forcat
** File description:
** forcat
*/

#include "bistro-matic.h"
#include "my.h"

char	*my_forcat(char *ope)
{
	char	*forcat;

	forcat = malloc(sizeof(*forcat) * 2);
	forcat[0] = ope[OP_SUB_IDX];
	forcat[1] = '\0';
	return (forcat);
}
