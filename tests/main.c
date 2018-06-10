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
	if (my_strlen(b) < 2) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit(EXIT_BASE);
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
	if (my_strlen(ops) != 7) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit(EXIT_OPS);
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
