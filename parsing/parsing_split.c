/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 15:17:32 by pokuzmic          #+#    #+#             */
/*   Updated: 2026/09/30 12:07:27 by codespace        ###   ########.fr       */
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

int	fill_words(char **words, char *str, char *charset)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!define_separator(str[i], charset))
		{
			words[j] = word_split(&str[i], charset);
			if (words[j] == NULL)
			{
				free_words(words, j);
				return (0);
			}
			j++;
			while (str[i] && !define_separator(str[i], charset))
				i++;
		}
		else
			i++;
	}
	words[j] = NULL;
	return (1);
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
