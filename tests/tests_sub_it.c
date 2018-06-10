/*
** EPITECH PROJECT, 2017
** tests_add_it
** File description:
** tests_add_it
*/

#include "bistro-matic.h"
#include "my.h"
#include <criterion/criterion.h>

Test(sub_it, sub_it_simple_op)
{
	char	*str1;
	char	*str2;
	char	*base;
	char	*ops;

	base = "0123456789";
	ops = "()+-*/%";
	str1 = my_strdup("-1");
	str2 = my_strdup("99");
	cr_assert(my_strcmp(add_it(str1, str2, base, ops), "98") == 0);
	str1 = my_strdup("1");
	str2 = my_strdup("-99");
	cr_assert(my_strcmp(add_it(str1, str2, base, ops), "-98") == 0);
	str1 = my_strdup("-10");
	str2 = my_strdup("-12");
	cr_assert(my_strcmp(add_it(str1, str2, base, ops), "-22") == 0);
}

Test(sub_it, sub_it_big_op)
{
	char	*str1;
	char	*str2;
	char	*base;
	char	*ops;

	base = "0123456789";
	ops = "()+-*/%";
	str1 = my_strdup("-187654567898754356789854345678765435678");
	str2 = my_strdup("9976546789876545678976545678654567876545");
	cr_assert(my_strcmp(add_it(str1, str2, base, ops), "9788892221977791322186691332975802440867") == 0);
	str1 = my_strdup("187654567898754356789854345678765435678");
	str2 = my_strdup("-9976546789876545678976545678654567876545");
	cr_assert(my_strcmp(add_it(str1, str2, base, ops), "-9788892221977791322186691332975802440867") == 0);
	str1 = my_strdup("-123456789098765432345678987654323456787654");
	str2 = my_strdup("-345678909876543456789876543456787654567654");
	cr_assert(my_strcmp(add_it(str1, str2, base, ops), "-469135698975308889135555531111111111355308") == 0);
}
