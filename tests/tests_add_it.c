/*
** EPITECH PROJECT, 2017
** tests_add_it
** File description:
** tests_add_it
*/

#include "bistro-matic.h"
#include "my.h"
#include <criterion/criterion.h>

Test(add_it, add_it_simple_op)
{
	char	*str1;
	char	*str2;
	char	*base;
	char	*ops;

	base = "0123456789";
	ops = "()+-*/%";
	str1 = my_strdup("1");
	str2 = my_strdup("99");
	cr_assert(my_strcmp(add_it(str1, str2, base, ops), "100") == 0);
	str1 = my_strdup("987");
	str2 = my_strdup("789");
	cr_assert(my_strcmp(add_it(str1, str2, base, ops), "1776") == 0);
}

Test(add_it, add_it_big_op)
{
	char	*str1;
	char	*str2;
	char	*base;
	char	*ops;

	base = "0123456789";
	ops = "()+-*/%";
	str1 = my_strdup("1000000000000000");
	str2 = my_strdup("1");
	cr_assert(my_strcmp(add_it(str1, str2, base, ops), "1000000000000001") == 0);
	str1 = my_strdup("3456789876543456789876545678908765456789087654567898765456");
	str2 = my_strdup("9876543567898765435678987654345789865456787654567876545676");
	cr_assert(my_strcmp(add_it(str1, str2, base, ops), "13333333444442222225555533333254555322245875309135775311132") == 0);
}
