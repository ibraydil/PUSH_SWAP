/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 15:13:54 by dibrayev          #+#    #+#             */
/*   Updated: 2026/09/28 09:59:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_revrotate(t_stack *stack)
{
	int	i;
	int	tmp;
	int	n;

	if (stack->size < 2)
		return ;
	n = stack->size;
	i = n - 1;
	tmp = stack->data[n - 1];
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = tmp;
}

void	ft_rra(t_ps *p)
{
	if (p->a.size < 2)
		return ;
	ft_revrotate(&p->a);
	p->counts[8]++;
	p->total++;
	ft_putendl_fd("rra", 1);
}

void	ft_rrb(t_ps *p)
{
	if (p->b.size < 2)
		return ;
	ft_revrotate(&p->b);
	p->counts[9]++;
	p->total++;
	ft_putendl_fd("rrb", 1);
}

void	ft_rrr(t_ps *p)
{
	if (p->a.size < 2 && p->b.size < 2)
		return ;
	if (p->a.size >= 2)
		ft_revrotate(&p->a);
	if (p->b.size >= 2)
		ft_revrotate(&p->b);
	p->counts[10]++;
	p->total++;
	ft_putendl_fd("rrr", 1);
}
