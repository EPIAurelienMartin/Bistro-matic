/*
** EPITECH PROJECT, 2017
** inf
** File description:
** inf
*/

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

struct s_mult
{
	char	*base;
	char	*nb1;
	char	*nb2;
	char	*res;
};

char	*multiplication(struct s_mult *m, char *ope);
char	*res_clean(char *clean, char *base, char *ope);
char	*mult_number(struct s_mult *m, int len2, int len);
char	*add_numbers_inf(struct s_mult *m, int len, int res);
int	get_nbase(char *base, char carac);
char	*mul_it(char *str1, char *str2, char *base, char *ope);
