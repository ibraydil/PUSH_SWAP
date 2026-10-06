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

static int	is_same(char *arg, char *opt)
{
	return (ft_strncmp(arg, opt, ft_strlen(opt) + 1) == 0);
}

t_strategy	get_strategy(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_same(argv[i], "--simple"))
			return (SIMPLE);
		if (is_same(argv[i], "--medium"))
			return (MEDIUM);
		if (is_same(argv[i], "--complex"))
			return (COMPLEX);
		if (is_same(argv[i], "--adaptive"))
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
		if (is_same(argv[i], "--bench"))
			return (1);
		i++;
	}
	return (0);
}

int	is_option(char *arg)
{
	if (is_same(arg, "--simple"))
		return (1);
	if (is_same(arg, "--medium"))
		return (1);
	if (is_same(arg, "--complex"))
		return (1);
	if (is_same(arg, "--adaptive"))
		return (1);
	if (is_same(arg, "--bench"))
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
