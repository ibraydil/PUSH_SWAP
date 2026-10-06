/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 15:13:54 by dibrayev          #+#    #+#             */
/*   Updated: 2026/09/28 09:59:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->data[0];
	stack->data[0] = stack->data[1];
	stack->data[1] = tmp;
}

void	ft_sa(t_ps *p)
{
	if (p->a.size < 2)
		return ;
	ft_swap(&p->a);
	p->counts[0]++;
	p->total++;
	ft_putendl_fd("sa", 1);
}

void	ft_sb(t_ps *p)
{
	if (p->b.size < 2)
		return ;
	ft_swap(&p->b);
	p->counts[1]++;
	p->total++;
	ft_putendl_fd("sb", 1);
}

void	ft_ss(t_ps *p)
{
	if (p->a.size < 2 && p->b.size < 2)
		return ;
	if (p->a.size >= 2)
		ft_swap(&p->a);
	if (p->b.size >= 2)
		ft_swap(&p->b);
	p->counts[2]++;
	p->total++;
	ft_putendl_fd("ss", 1);
}
