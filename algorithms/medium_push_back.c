/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 18:40:44 by pokuzmic          #+#    #+#             */
/*   Updated: 2026/09/28 09:22:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_second_max_position(t_stack *b, int max_pos)
{
	int	i;
	int	pos;

	pos = -1;
	i = 0;
	while (i < b->size)
	{
		if (i != max_pos && (pos == -1 || b->data[i] > b->data[pos]))
			pos = i;
		i++;
	}
	return (pos);
}

static int	moves_to_top(t_stack *b, int position)
{
	if (position <= b->size / 2)
		return (position);
	return (b->size - position);
}

static void	rotate_b_to_top(t_ps *p, int position)
{
	int	moves;

	if (position <= p->b.size / 2)
	{
		moves = position;
		while (moves-- > 0)
			ft_rb(p);
	}
	else
	{
		moves = p->b.size - position;
		while (moves-- > 0)
			ft_rrb(p);
	}
}

void	push_back_sorted(t_ps *p)
{
	int	max_pos;
	int	second_pos;

	while (p->b.size > 0)
	{
		max_pos = find_max_position(&p->b);
		second_pos = find_second_max_position(&p->b, max_pos);
		if (second_pos != -1
			&& moves_to_top(&p->b, second_pos) < moves_to_top(&p->b, max_pos))
		{
			rotate_b_to_top(p, second_pos);
			ft_pa(p);
			rotate_b_to_top(p, find_max_position(&p->b));
			ft_pa(p);
			ft_sa(p);
		}
		else
		{
			rotate_b_to_top(p, max_pos);
			ft_pa(p);
		}
	}
}
