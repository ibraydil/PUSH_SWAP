/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing _utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokuzmic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 13:17:32 by pokuzmic          #+#    #+#             */
/*   Updated: 2026/09/22 13:32:38 by pokuzmic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_words(char **words, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		i++;
	return (i);
}

void	free_args(char **args, int argc)
{
	int	i;

	if (args == NULL)
		return ;
	if (argc == 2)
	{
		i = 0;
		while (args[i] != NULL)
		{
			free(args[i]);
			i++;
		}
	}
	free(args);
}
