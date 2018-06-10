/*
** EPITECH PROJECT, 2017
** tests_strtol
** File description:
** tests_strtol
*/

#include "bistro-matic.h"
#include "my.h"
#include <criterion/criterion.h>

Test(my_strtol, nb_return)
{
	char	*str;
	char	*base = "0123456789";
	char	*ops = "()+-*/%";

	str = my_strdup("3+44");
	cr_expect(my_strcmp(my_strtol(&str, base, ops), "3") == 0);
	str = my_strdup("99");
	cr_expect(my_strcmp(my_strtol(&str, base, ops), "99") == 0);
	str = my_strdup("0");
	cr_expect(my_strcmp(my_strtol(&str, base, ops), "0") == 0);
	str = my_strdup("-10");
	cr_expect(my_strcmp(my_strtol(&str, base, ops), "-10") == 0);
	str = my_strdup("-77--99");
	cr_expect(my_strcmp(my_strtol(&str, base, ops), "-77") == 0);
}

Test(my_strtol, rest_return_is_ok)
{
	char	*str;
	char	*base = "0123456789";
	char	*ops = "()+-*/%";

	str = my_strdup("77+099");
	my_strtol(&str, base, ops);
	cr_expect(str[0] == '+');
	str = my_strdup("99");
	my_strtol(&str, base, ops);
	cr_expect(str[0] == '\0');
	str = my_strdup("0");
	my_strtol(&str, base, ops);
	cr_expect(str[0] == '\0');
	str = my_strdup("-10.,");
	my_strtol(&str, base, ops);
	cr_expect(str[0] == '.');
	str = my_strdup("-77-099");
	my_strtol(&str, base, ops);
	cr_expect(str[0] == '-');
}
