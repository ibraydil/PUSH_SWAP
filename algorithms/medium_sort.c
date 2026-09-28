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

void	push_chunks(t_ps *p, int *sorted, int chunk_size)
{
	int	start;
	int	end;
	int	position;
	int	moves;

	start = 0;
	while (start < p->a.size)
	{
		end = start + chunk_size - 1;
		if (end >= p->a.size)
			end = p->a.size - 1;
		position = find_chunk_position(&p->a, sorted, start, end);
		while (position != -1)
		{
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
			ft_pb(p);
			position = find_chunk_position(&p->a, sorted, start, end);
		}
		start += chunk_size;
	}
}

void	push_back_sorted(t_ps *p)
{
	int	position;
	int	moves;

	while (p->b.size > 0)
	{
		position = find_max_position(&p->b);
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
		ft_pa(p);
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
