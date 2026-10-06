/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 15:13:54 by dibrayev          #+#    #+#             */
/*   Updated: 2026/09/28 09:59:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *stack)
{
	int	i;
	int	tmp;
	int	n;

	i = 0;
	if (stack->size < 2)
		return ;
	tmp = stack->data[0];
	n = stack->size;
	while (i < n - 1)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[n - 1] = tmp;
}

void	ft_ra(t_ps *p)
{
	if (p->a.size < 2)
		return ;
	ft_rotate(&p->a);
	p->counts[5]++;
	p->total++;
	ft_putendl_fd("ra", 1);
}

void	ft_rb(t_ps *p)
{
	if (p->b.size < 2)
		return ;
	ft_rotate(&p->b);
	p->counts[6]++;
	p->total++;
	ft_putendl_fd("rb", 1);
}

void	ft_rr(t_ps *p)
{
	if (p->a.size < 2 && p->b.size < 2)
		return ;
	if (p->a.size >= 2)
		ft_rotate(&p->a);
	if (p->b.size >= 2)
		ft_rotate(&p->b);
	p->counts[7]++;
	p->total++;
	ft_putendl_fd("rr", 1);
}
