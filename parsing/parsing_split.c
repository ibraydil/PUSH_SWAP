/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing _split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokuzmic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 15:17:32 by pokuzmic          #+#    #+#             */
/*   Updated: 2026/09/22 16:32:38 by pokuzmic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	define_separator(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (!define_separator(str[i], sep))
		{
			words++;
			while (str[i] && !define_separator(str[i], sep))
				i++;
		}
		else
			i++;
	}
	return (words);
}

char	*word_split(char *str, char *sep)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] != '\0' && !define_separator(str[i], sep))
		i++;
	word = malloc(sizeof(*word) * (i + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && !define_separator(str[i], sep))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**split_args(char *str, char *charset)
{
	char	**words;

	if (str == NULL || charset == NULL)
		return (NULL);
	words = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (words == NULL)
		return (NULL);
	if (!fill_words(words, str, charset))
		return (NULL);
	return (words);
}

char	**prepare_args(int argc, char **argv)
{
	char	**args;
	int		i;
	int		j;

	if (argc < 2)
		return (NULL);
	args = malloc(sizeof(char *) * (count_numbers(argv) + 1));
	if (args == NULL)
		return (NULL);
	i = 1;
	j = 0;
	while (i < argc)
	{
		if (!is_option(argv[i]))
		{
			j = add_arg_words(args, argv[i], j);
			if (j == -1)
				return (free_args(args), NULL);
		}
		i++;
	}
	args[j] = NULL;
	return (args);
}
