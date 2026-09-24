/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_testing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokuzmic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 17:17:32 by pokuzmic          #+#    #+#             */
/*   Updated: 2026/09/22 19:32:38 by pokuzmic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**args;
	int		amount;
	int		*numbers;
	t_stack	*stack_a;

	args = prepare_args(argc, argv);
	if (args == NULL)
		return (1);
	amount = count_args(args);
	numbers = parse_numbers(args, amount);
	free_args(args, argc);
	if (numbers == NULL)
		return (1);
	stack_a = create_stack(numbers, amount);
	free(numbers);
	if (stack_a == NULL)
		return (1);
	free_stack(stack_a);
	return (0);
}
