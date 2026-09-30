/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_testing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 17:17:32 by pokuzmic          #+#    #+#             */
/*   Updated: 2026/09/30 12:41:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**args;
	int		amount;
	int		*numbers;
	int		i;

	args = prepare_args(argc, argv);
	if (args == NULL)
	{
		ft_putstr_fd("Parsing error\n", 2);
		return (1);
	}
	amount = count_args(args);
	numbers = parse_numbers(args, amount);
	if (numbers == NULL)
	{
		free_args(args);
		ft_putstr_fd("Parsing error\n", 2);
		return (1);
	}
	i = 0;
	while (i < amount)
	{
		ft_putnbr_fd(numbers[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	free(numbers);
	free_args(args);
	return (0);
}
