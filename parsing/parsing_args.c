/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 13:17:32 by pokuzmic          #+#    #+#             */
/*   Updated: 2026/09/30 12:07:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_args(char **args)
{
	int	i;

	if (args == NULL)
		return ;
	i = 0;
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	add_arg_words(char **args, char *str, int index)
{
	char	**split;
	int		i;

	split = split_args(str, " \t\n\v\f\r");
	if (split == NULL)
		return (-1);
	i = 0;
	while (split[i] != NULL)
	{
		args[index++] = split[i++];
	}
	free(split);
	return (index);
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
