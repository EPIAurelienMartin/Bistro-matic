/*
** EPITECH PROJECT, 2017
** tests_add_it
** File description:
** tests_add_it
*/

#include "bistro-matic.h"
#include "my.h"
#include <criterion/criterion.h>

Test(mod_it, mod_it_simple_op)
{
	char	*str1;
	char	*str2;
	char	*base;
	char	*ops;

	base = "0123456789";
	ops = "()+-*/%";
	str1 = my_strdup("1234");
	str2 = my_strdup("123");
	cr_assert(my_strcmp(mod_it(str1, str2, base, ops), "4") == 0);
}
