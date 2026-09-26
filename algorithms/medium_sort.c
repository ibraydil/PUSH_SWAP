/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokuzmic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 18:40:44 by pokuzmic          #+#    #+#             */
/*   Updated: 2026/09/25 18:40:46 by pokuzmic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b_position_to_top(t_stack **stack, int position)
{
	while (position > 0)
	{
		rb(stack);
		position--;
	}
}

void	push_chunks(t_stacks *stacks)
{
	int	size;
	int	chunk_size;
	int	start;
	int	end;
	int	position;

	size = stack_size(stacks->a);
	chunk_size = calculate_chunk_size(size);
	start = 0;
	end = chunk_size - 1;
	while (start < size)
	{
		if (end >= size)
			end = size - 1;
		position = find_chunk_position(stacks->a, start, end);
		while (position != -1)
		{
			move_position_to_top(&stacks->a, position);
			pb(stacks);
			position = find_chunk_position(stacks->a, start, end);
		}
		start += chunk_size;
		end += chunk_size;
	}
}

void	push_back_sorted(t_stacks *stacks)
{
	int	position;

	while (stacks->b != NULL)
	{
		position = find_max_rank_position(stacks->b);
		move_b_position_to_top(&stacks->b, position);
		pa(stacks);
	}
}

void	medium_sort(t_stacks *stacks)
{
	assign_ranks(stacks->a);
	push_chunks(stacks);
	push_back_sorted(stacks);
}
