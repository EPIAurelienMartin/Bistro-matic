/*
** EPITECH PROJECT, 2017
** tests_add_it
** File description:
** tests_add_it
*/

#include "bistro-matic.h"
#include "my.h"
#include <criterion/criterion.h>

Test(mul_it, mult_it_simple_op)
{
	char	*str1;
	char	*str2;
	char	*base;
	char	*ops;

	base = "0123456789";
	ops = "()+-*/%";
	str1 = my_strdup("2");
	str2 = my_strdup("99");
	cr_assert(my_strcmp(mul_it(str1, str2, base, ops), "198") == 0);
	str1 = my_strdup("9");
	str2 = my_strdup("6");
	cr_assert(my_strcmp(mul_it(str1, str2, base, ops), "54") == 0);
	str1 = my_strdup("7");
	str2 = my_strdup("8");
	cr_assert(my_strcmp(mul_it(str1, str2, base, ops), "56") == 0);
}

Test(mul_it, mult_it_big_op)
{
	char	*str1;
	char	*str2;
	char	*base;
	char	*ops;

	base = "0123456789";
	ops = "()+-*/%";
	str1 = my_strdup("22345678765434567");
	str2 = my_strdup("3456765435678");
	cr_assert(my_strcmp(mul_it(str1, str2, base, ops), "77243769993118054162756281426") == 0);
	str1 = my_strdup("345678765456787654");
	str2 = my_strdup("56765434567897654");
	cr_assert(my_strcmp(mul_it(str1, str2, base, ops), "19622605342048919365677783082763716") == 0);
	str1 = my_strdup("000007");
	str2 = my_strdup("000008");
	cr_assert(my_strcmp(mul_it(str1, str2, base, ops), "56") == 0);
}
