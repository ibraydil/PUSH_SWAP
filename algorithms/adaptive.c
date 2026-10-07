/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibrayev <dibrayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 14:47:41 by dibrayev          #+#    #+#             */
/*   Updated: 2026/10/07 14:35:51 by dibrayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->data[i] > a->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	sort_three(t_ps *p)
{
	int	max_pos;

	if (p->a.size == 3)
	{
		max_pos = find_max_position(&p->a);
		if (max_pos == 0)
			ft_ra(p);
		else if (max_pos == 1)
			ft_rra(p);
	}
	if (p->a.data[0] > p->a.data[1])
		ft_sa(p);
}

t_strategy	adaptive_regime(double disorder)
{
	if (disorder < 0.2)
		return (SInorMPLE);
	if (disorder < 0.5)
		return (MEDIUM);
	return (COMPLEX);
}

void	adaptive_sort(t_ps *p, double disorder)
{
	t_strategy	regime;

	if (p->a.size < 2 || is_sorted(&p->a))
		return ;
	if (p->a.size <= 3)
	{
		sort_three(p);
		return ;
	}
	regime = adaptive_regime(disorder);
	if (regime == SIMPLE)
		selection_sort(p);
	else if (regime == MEDIUM)
		medium_sort(p);
	else
		radix_sort(p);
}
