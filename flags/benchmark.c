/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 09:19:08 by codespace         #+#    #+#             */
/*   Updated: 2026/09/28 09:55:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_strategy(t_strategy strategy)
{
	ft_putstr_fd("strategy: ", 2);
	if (strategy == SIMPLE)
		ft_putstr_fd("simple\n", 2);
	else if (strategy == MEDIUM)
		ft_putstr_fd("medium\n", 2);
	else if (strategy == COMPLEX)
		ft_putstr_fd("complex\n", 2);
	else
		ft_putstr_fd("adaptive\n", 2);
}

static void	print_complexity(t_strategy strategy)
{
	ft_putstr_fd("complexity: ", 2);
	if (strategy == SIMPLE)
		ft_putstr_fd("O(n^2)\n", 2);
	else if (strategy == MEDIUM)
		ft_putstr_fd("O(n*sqrt(n))\n", 2);
	else if (strategy == COMPLEX)
		ft_putstr_fd("O(n log n)\n", 2);
	else
		ft_putstr_fd("adaptive\n", 2);
}

static void	print_operations(t_ps *p)
{
	static char	*names[11] = {
		"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"
	};
	int			i;

	i = 0;
	while (i < 11)
	{
		ft_putstr_fd(names[i], 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(p->counts[i], 2);
		ft_putstr_fd("\n", 2);
		i++;
	}
}

void	print_benchmark(t_ps *p, t_strategy strategy, double disorder)
{
	int	percent;

	if (!p->bench)
		return ;
	percent = (int)(disorder * 10000.0 + 0.5);
	ft_putstr_fd("disorder: ", 2);
	ft_putnbr_fd(percent / 100, 2);
	ft_putstr_fd(".", 2);
	if (percent % 100 < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(percent % 100, 2);
	ft_putstr_fd("%\n", 2);
	print_strategy(strategy);
	print_complexity(strategy);
	ft_putstr_fd("total operations: ", 2);
	ft_putnbr_fd(p->total, 2);
	ft_putstr_fd("\n", 2);
	print_operations(p);
}
