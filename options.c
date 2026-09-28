/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 09:19:14 by codespace         #+#    #+#             */
/*   Updated: 2026/09/28 09:27:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_strategy	get_strategy(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--simple") == 0)
			return (SIMPLE);
		if (ft_strcmp(argv[i], "--medium") == 0)
			return (MEDIUM);
		if (ft_strcmp(argv[i], "--complex") == 0)
			return (COMPLEX);
		if (ft_strcmp(argv[i], "--adaptive") == 0)
			return (ADAPTIVE);
		i++;
	}
	return (ADAPTIVE);
}

int	is_bench(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			return (1);
		i++;
	}
	return (0);
}

int	is_option(char *arg)
{
	if (ft_strcmp(arg, "--simple") == 0)
		return (1);
	if (ft_strcmp(arg, "--medium") == 0)
		return (1);
	if (ft_strcmp(arg, "--complex") == 0)
		return (1);
	if (ft_strcmp(arg, "--adaptive") == 0)
		return (1);
	if (ft_strcmp(arg, "--bench") == 0)
		return (1);
	return (0);
}

int	count_numbers(char **argv)
{
	int		i;
	int		count;
	char	**split;
	int		j;

	i = 1;
	count = 0;
	while (argv[i] != NULL)
	{
		if (!is_option(argv[i]))
		{
			split = split_args(argv[i], " \t\n\v\f\r");
			if (split == NULL)
				return (-1);
			j = 0;
			while (split[j] != NULL)
			{
				count++;
				j++;
			}
			free_words(split, j);
		}
		i++;
	}
	return (count);
}
