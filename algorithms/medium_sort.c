/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 18:40:44 by pokuzmic          #+#    #+#             */
/*   Updated: 2026/09/28 09:22:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_position(t_ps *p, int position)
{
	int	moves;

	if (position <= p->a.size / 2)
	{
		moves = position;
		while (moves-- > 0)
			ft_ra(p);
	}
	else
	{
		moves = p->a.size - position;
		while (moves-- > 0)
			ft_rra(p);
	}
}

void	push_chunks(t_ps *p, int *sorted, int chunk_size)
{
	int	start;
	int	end;
	int	position;
	int	total;

	total = p->a.size;
	start = 0;
	while (start < total)
	{
		end = start + chunk_size - 1;
		if (end >= total)
			end = total - 1;
		position = find_chunk_position(&p->a, sorted, start, end);
		while (position != -1)
		{
			rotate_to_position(p, position);
			ft_pb(p);
			if (p->b.data[0] <= sorted[start + (end - start) / 2])
				ft_rb(p);
			position = find_chunk_position(&p->a, sorted, start, end);
		}
		start += chunk_size;
	}
}

void	medium_sort(t_ps *p)
{
	int	*sorted;
	int	chunk_size;

	sorted = sorted_copy(&p->a);
	if (sorted == NULL)
		return ;
	chunk_size = calculate_chunk_size(p->a.size);
	push_chunks(p, sorted, chunk_size);
	push_back_sorted(p);
	free(sorted);
}
