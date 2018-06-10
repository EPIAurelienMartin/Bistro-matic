/*
** EPITECH PROJECT, 2017
** tests_add_it
** File description:
** tests_add_it
*/

#include "bistro-matic.h"
#include "my.h"
#include <criterion/criterion.h>

Test(div_it, div_it_simple_op)
{
	char	*str1;
	char	*str2;
	char	*base;
	char	*ops;

	base = "0123456789";
	ops = "()+-*/%";
	str1 = my_strdup("99");
	str2 = my_strdup("2");
	cr_assert(my_strcmp(verif_div(str1, str2, base, ops), "49") == 0);
}

Test(my_div_zero, add_zero_after_div)
{
	int	len;
	char	*str2;
	char	*base;

	base = "0123456789";
	len = 5;
	str2 = my_strdup("2");
	cr_assert(my_strcmp(my_div_zero(len, str2, base), "20000") == 0);
	len = 49;
	str2 = my_strdup("2000000000000000000000000");
	cr_assert(my_strcmp(my_div_zero(len, str2, base), "2000000000000000000000000000000000000000000000000") == 0);
	len = 1;
	str2 = my_strdup("2");
	cr_assert(my_strcmp(my_div_zero(len, str2, base), "2") == 0);
}

Test(add_zero2, add_zero_before_div)
{
	char	*str1;
	char	*str2;
	char	*base;

	base = "0123456789";
	str1 = my_strdup("2");
	str2 = my_strdup("2");
	cr_assert(my_strcmp(add_zero2(str1, str2, base), "2") == 0);
	str1 = my_strdup("23");
	str2 = my_strdup("2");
	cr_assert(my_strcmp(add_zero2(str1, str2, base), "02") == 0);
	str1 = my_strdup("23456789456");
	str2 = my_strdup("2654");
	cr_assert(my_strcmp(add_zero2(str1, str2, base), "00000002654") == 0);
}

Test(str_zero, add_zero_str)
{
	char	*str1;
	char	*str2;
	char	*base;

	base = "0123456789";
	str1 = my_strdup("2");
	str2 = my_strdup("2");
	cr_assert(my_strcmp(str_zero(str1, str2, base), "2") == 0);
}
