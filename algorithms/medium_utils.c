/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokuzmic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 18:40:53 by pokuzmic          #+#    #+#             */
/*   Updated: 2026/09/25 18:40:55 by pokuzmic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_ranks(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		rank;

	current = stack;
	while (current != NULL)
	{
		rank = 0;
		compare = stack;
		while (compare != NULL)
		{
			if (compare->value < current->value)
				rank++;
			compare = compare->next;
		}
		current->rank = rank;
		current = current->next;
	}
}

int	calculate_chunk_size(int size)
{
	int	chunk;

	chunk = 1;
	while (chunk * chunk < size)
		chunk++;
	return (chunk);
}

int	find_chunk_position(t_stack *stack, int start, int end)
{
	int	position;

	position = 0;
	while (stack != NULL)
	{
		if (stack->rank >= start && stack->rank <= end)
			return (position);
		stack = stack->next;
		position++;
	}
	return (-1);
}

void	move_position_to_top(t_stack **stack, int position)
{
	while (position > 0)
	{
		ra(stack);
		position--;
	}
}

int	find_max_rank_position(t_stack *stack)
{
	int	max_rank;
	int	position;
	int	max_position;

	max_rank = stack->rank;
	position = 0;
	max_position = 0;
	while (stack != NULL)
	{
		if (stack->rank > max_rank)
		{
			max_rank = stack->rank;
			max_position = position;
		}
		stack = stack->next;
		position++;
	}
	return (max_position);
}
