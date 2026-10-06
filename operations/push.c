/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 15:13:54 by dibrayev          #+#    #+#             */
/*   Updated: 2026/09/28 09:59:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *src, t_stack *dst)
{
	int	tmp;
	int	i;

	if (src->size == 0 || dst->size >= dst->cap)
		return ;
	tmp = src->data[0];
	i = dst->size;
	while (i > 0)
	{
		dst->data[i] = dst->data[i - 1];
		i--;
	}
	dst->data[0] = tmp;
	i = 0;
	while (i < src->size - 1)
	{
		src->data[i] = src->data[i + 1];
		i++;
	}
	src->size--;
	dst->size++;
}

void	ft_pa(t_ps *p)
{
	if (p->b.size == 0 || p->a.size >= p->a.cap)
		return ;
	ft_push(&p->b, &p->a);
	p->counts[3]++;
	p->total++;
	ft_putendl_fd("pa", 1);
}

void	ft_pb(t_ps *p)
{
	if (p->a.size == 0 || p->b.size >= p->b.cap)
		return ;
	ft_push(&p->a, &p->b);
	p->counts[4]++;
	p->total++;
	ft_putendl_fd("pb", 1);
}
