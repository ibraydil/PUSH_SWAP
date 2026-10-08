/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibrayev <dibrayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 15:12:20 by dibrayev          #+#    #+#             */
/*   Updated: 2026/10/07 12:57:07 by dibrayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static int	values_to_ranks(t_stack *a)
{
	int	*sorted;
	int	i;
	int	j;

	sorted = sorted_copy(a);
	if (sorted == NULL)
		return (0);
	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (sorted[j] != a->data[i])
			j++;
		a->data[i] = j;
		i++;
	}
	free(sorted);
	return (1);
}

void	radix_sort(t_ps *ps)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	if (!values_to_ranks(&ps->a))
	{
		selection_sort(ps);
		return ;
	}
	size = ps->a.size;
	max_bits = get_max_bits(size);
	i = -1;
	while (++i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((ps->a.data[0] >> i) & 1) == 1)
				ft_ra(ps);
			else
				ft_pb(ps);
		}
		while (ps->b.size > 0)
			ft_pa(ps);
	}
}

/*1 % 2 is 1*/

/* b will be: 1, then 21, then 321 and at the end 654321
then back from b to a like this: a wiil be 6, then 56, and in the end 123456 */

/*When you divide an integer by 2, 
you are shifting all the binary digits one spot to the right, 
and dropping any remainder.

Example with number 5:

    In binary, 5 is 101 (one 4, zero 2s, one 1).

    If you right shift by 1 (5 >> 1), the bits shift right 
    to become 10 (binary for 2).

    If you divide by 2 (5 / 2), integer division truncates the decimal, 
    giving you 2.*/

/*A left shift (<<) moves all the binary digits to the left and 
fills the empty space on the right with a 0.Mathematically, 
shifting left by 1 is equivalent to multiplying by 2 (* 2).
Shifting left by 2 (<< 2) is equivalent to multiplying by 4 (* 4).
Shifting left by $n$ is equivalent to multiplying by $2^n$.

In binary, 3 is 11 (one 2, one 1).

If you left shift by 1 (3 << 1), 
a 0 is added to the right, making it 110 (binary for 6).*/
