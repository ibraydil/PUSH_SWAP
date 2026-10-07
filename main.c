/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 12:00:00 by codespace         #+#    #+#             */
/*   Updated: 2026/10/07 12:00:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->data[i] > stack->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static int	load_stacks(t_ps *p, int argc, char **argv)
{
	char	**args;
	int		amount;
	int		*numbers;

	args = prepare_args(argc, argv);
	if (args == NULL)
		return (0);
	amount = count_args(args);
	numbers = NULL;
	if (amount > 0)
		numbers = parse_numbers(args, amount);
	free_args(args);
	if (numbers == NULL)
		return (0);
	if (!init_ps(p, amount) || !init_stack(&p->a, numbers, amount))
	{
		free(numbers);
		free_ps(p);
		return (0);
	}
	free(numbers);
	return (1);
}

static void	run_sort(t_ps *p, t_strategy strategy, double dis)
{
	if (strategy == ADAPTIVE)
		adaptive_sort(p, dis);
	else if (strategy == SIMPLE)
		selection_sort(p);
	else if (strategy == MEDIUM)
		medium_sort(p);
	else
		radix_sort(p);
}

int	main(int argc, char **argv)
{
	t_ps		p;
	t_strategy	strategy;
	double		dis;

	if (argc < 2)
		return (0);
	if (!load_stacks(&p, argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	strategy = get_strategy(argc, argv);
	p.bench = is_bench(argc, argv);
	dis = disorder(&p.a);
	if (!is_sorted(&p.a))
		run_sort(&p, strategy, dis);
	print_benchmark(&p, strategy, dis);
	free_ps(&p);
	return (0);
}
