/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokuzmic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:50:09 by pokuzmic          #+#    #+#             */
/*   Updated: 2026/09/25 17:50:14 by pokuzmic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack != NULL)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	find_position(t_stack *stack, int value)
{
	int	position;

	position = 0;
	while (stack != NULL)
	{
		if (stack->value == value)
			return (position);
		stack = stack->next;
		position++;
	}
	return (-1);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack != NULL)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	move_min_to_top(t_stack **stack)
{
	int	min;
	int	position;
	int	size;

	min = find_min(*stack);
	position = find_position(*stack, min);
	size = stack_size(*stack);
	if (position <= size / 2)
	{
		while (position > 0)
		{
			ra(stack);
			position--;
		}
	}
	else
	{
		while (position < size)
		{
			rra(stack);
			position++;
		}
	}
}

void	selection_sort(t_stacks *stacks)
{
	while (stacks->a != NULL)
	{
		move_min_to_top(&stacks->a);
		pb(stacks);
	}
	while (stacks->b != NULL)
		pa(stacks);
}


