/*
** EPITECH PROJECT, 2017
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "my.h"

int	word_len(char const *str)
{
	int	i = 0;

	while ((is_alphanum(str[i]) == 0) && str[i] != '\0')
		i++;
	return (i);
}

int	how_many_words(char const *str)
{
	int	i = 0;
	int	count = 0;

	while (str[i]) {
		while (is_alphanum(str[i]) == 1 && str[i] != '\0') {
			i++;
		}
		while (is_alphanum(str[i]) == 0 && str[i] != '\0') {
			i++;
		}
		count++;
	}
	if (is_alphanum(str[i - 1]) == 1)
		count--;
	return (count);
}

int	str_to_array_loop(char const *str, int m, int i, char **tab)
{
	int	j = 0;

	while ((is_alphanum(str[m]) == 1) && str[m] != '\0')
		m++;
	tab[i] = malloc(sizeof(**tab) * (word_len(&str[m]) + 1));
	if (tab[i] == NULL) {
		return (-1);
	}
	for (j = 0; (is_alphanum(str[m]) == 0) && str[m] != '\0'; j++) {
		tab[i][j] = str[m];
		m++;
	}
	tab[i][j] = '\0';
	return (m);
}

char	**my_str_to_word_array(char const *str)
{
	int	i = 0;
	int	m = 0;
	char	**tab;

	tab = malloc(sizeof(*tab) * (how_many_words(str) + 1));
	if (tab == NULL) {
		return (NULL);
	}
	for (i = 0; i < how_many_words(str); i++) {
		m = str_to_array_loop(str, m, i, tab);
		if (m == -1) {
			return (NULL);
		}
	}
	tab[i] = NULL;
	return (tab);
}
