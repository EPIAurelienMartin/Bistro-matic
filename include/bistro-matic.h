/*
** EPITECH PROJECT, 2017
** bistro-matic
** File description:
** au bistro
*/

#ifndef _BISTRO_H_
#define _BISTRO_H_

#include "mult.h"

#define OP_OPEN_PARENT_IDX 0
#define OP_CLOSE_PARENT_IDX 1
#define OP_PLUS_IDX 2
#define OP_SUB_IDX 3
#define OP_MULT_IDX 4
#define OP_DIV_IDX 5
#define OP_MOD_IDX 6

#define EXIT_USAGE 84
#define EXIT_BASE 84
#define EXIT_SIZE_NEG 84
#define EXIT_MALLOC 84
#define EXIT_READ 84
#define EXIT_OPS 84
#define SYNTAX_ERROR_MSG "syntax error"
#define ERROR_MSG "error"

struct s_div
{
	int	len_c;
	int	a;
	int	count;
	int	len;
};

char	*summands(char **str, char *basen, char *ops);
char	*factors(char **str, char *base, char *ops);
int	gest_string(char **str, char *ops);
int	is_op(char c, char *ops, int i, int j);
int	nb_strlen(char *str, char *base, char *ops);
int	is_in_base(char c, char *base);
char	*my_strtol(char **str, char *base, char *ops);
char	*eval_expr(char *base, char *ops, char *expr, unsigned int size);
char	*get_expr(unsigned int size);
void	check_base(char *b);
void	check_ops(char *ops);
void	check_expr(char *str, char *base, char *ope);

void	init_functions(char *(*calc[2])(char*, char*, char*));
void	swap_words(char **a, char **b);
int	which_op(char **a, char **b, char *ops, int *sign);
char	*add_it(char *s1, char *s2, char *base, char *ops);
int	is_comp(char c, char d, char *base);
char	check_add_res(int res, char *base, int *ret);
int	check_add_ret(int res, char *base);
char	*do_inf_add(char *a, char *b, char *base);
int	is_in_base(char c, char *base);
int	my_pstrcmp(char *s1, char *s2, char *ops);
int	my_nstrcmp(char *s1, char *s2, char *ops);
char	*remove_zero(char *str, int sign, char *ops, char *base);
char	check_sub_res(int res, char *base, int *ret);
int	check_sub_ret(int res);
char	*do_inf_sub(char *a, char *b, char *base);
char	*div_it(char *str1, char *str2, char *base, char *ope);
char	*mod_it(char *str1, char *str2, char *base, char *op);
char	*verif_div(char *str1, char *str2, char *base, char *ope);
void	check_in_bops_same(char *base, char *ops);
char	*my_forcat(char *ope);
char	*my_div_zero(int len, char *str2, char *base);
char	*add_zero2(char *str1, char *str2, char *base);
char	*str_zero(char *str1, char *str2, char *base);

#endif /* _BISTRO_H_ */
