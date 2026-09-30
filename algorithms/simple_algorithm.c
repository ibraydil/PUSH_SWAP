/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:50:09 by pokuzmic          #+#    #+#             */
/*   Updated: 2026/09/30 12:54:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int	min;
	int	i;

	min = stack->data[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->data[i] < min)
			min = stack->data[i];
		i++;
	}
	return (min);
}

int	find_position(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->data[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	stack_size(t_stack *stack)
{
	return (stack->size);
}

void	move_min_to_top(t_ps *p)
{
	int	min;
	int	position;
	int	size;

	min = find_min(&p->a);
	position = find_position(&p->a, min);
	size = stack_size(&p->a);
	if (position <= size / 2)
	{
		while (position > 0)
		{
			ft_ra(p);
			position--;
		}
	}
	else
	{
		while (position < size)
		{
			ft_rra(p);
			position++;
		}
	}
}

void	selection_sort(t_ps *p)
{
	while (p->a.size > 0)
	{
		move_min_to_top(p);
		ft_pb(p);
	}
	while (p->b.size > 0)
		ft_pa(p);
}
