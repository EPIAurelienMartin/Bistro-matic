/*
** EPITECH PROJECT, 2017
** bootstrap_evalexpr
** File description:
** test
*/

#include "bistro-matic.h"
#include "my.h"

void	check_base(char *b)
{
	int	i = 0;
	int	j = 0;
	int	error = 0;

	if (my_strlen(b) < 2) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit(EXIT_BASE);
	}
	while (b[i]) {
		j = 0;
		while (b[j]) {
			(j == i) ? j++ : j;
			(b[i] == b[j] && i != j) ? error = 84 : error;
			j++;
		}
		i++;
	}
	if (error == 84) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit (84);
	}
}

char	*get_expr(unsigned int size)
{
	char	*expr;

	if (size <= 0) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit(EXIT_SIZE_NEG);
	}
	expr = malloc(size + 1);
	if (expr == NULL) {
		my_putstr(ERROR_MSG);
		exit(EXIT_MALLOC);
	}
	if (read(0, expr, size) != size) {
		my_putstr(ERROR_MSG);
		exit(EXIT_READ);
	}
	expr[size] = '\0';
	return (expr);
}

void	check_ops(char *ops)
{
	int	i = 0;
	int	j = 0;
	int	error = 0;

	if (my_strlen(ops) != 7) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit(EXIT_OPS);
	}
	while (ops[i]) {
		j = 0;
		while (ops[j]) {
			(j == i) ? j++ : j;
			(ops[i] == ops[j] && i != j) ? error = 84 : error;
			j++;
		}
		i++;
	}
	if (error == 84) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit (84);
	}
}

void	my_panel(void)
{
	my_putstr("USAGE\n\t   ./calc base operators ");
	my_putstr("size_read\n\nDESCRIPTION\n\t");
	my_putstr("   \e[1mbase\e[0m\t      all the symbols of the base\n");
	my_putstr("\t   \e[1moperators\e[0m  the symbols for the parentheses ");
	my_putstr("and the 5 operators\n\t");
	my_putstr("   \e[1msize_read\e[0m  number of characters to be read\n");
}

int	main(int ac, char **av)
{
	int		a = -1;
	char		*expr;
	unsigned int	size;

	if (ac != 4 && my_strcmp(av[1], "-h") != 0 ) {
		my_putstr("Usage: ");
		my_putstr(av[0]);
		my_putstr(" base ops\"()+-*/%\" exp_len\n");
		exit(EXIT_USAGE);
	}
	else if (my_strcmp(av[1], "-h") == 0)
		my_panel();
	else {
		check_base(av[1]);
		check_ops(av[2]);
		check_in_bops_same(av[1], av[2]);
		size = my_getnbr(av[3]);
		expr = get_expr(size);
		check_expr(expr, av[1], av[2]);
		while (expr[++a]) {
			if (expr[a] == '(' && (is_in_base(expr[a - 1], av[1]) != -1)) {
				my_putstr(SYNTAX_ERROR_MSG);
				exit(84);
			}
		}
		my_putstr(eval_expr(av[1], av[2], expr, size));
		return (EXIT_SUCCESS);
	}
}
