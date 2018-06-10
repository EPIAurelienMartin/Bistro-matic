/*
** EPITECH PROJECT, 2017
** ui
** File description:
** ui
*/

#include "bistro-matic.h"
#include "my.h"

int	main(int ac, char **av)
{
	char	*res = 0;

	res = do_inf_sub(av[1], av[2], av[3]);
	my_putstr(res);
	return (0);
}
