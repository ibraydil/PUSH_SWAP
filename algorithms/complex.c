/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibrayev <dibrayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 15:12:20 by dibrayev          #+#    #+#             */
/*   Updated: 2026/09/29 14:44:23 by dibrayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *a)
{
	int	num;
	int	max_bits;
	int	i;

	if (a->size == 0)
		return (0);
	num = a->data[0];
	i = 1;
	while (i < a->size)
	{
		if (a->data[i] > num)
			num = a->data[i];
		i++;
	}
	max_bits = 0;
	while (num > 0)
	{
		num /= 2;
		max_bits++;
	}
	return (max_bits);
}

void	radix_sort(t_ps *ps)
{
	int	i;
	int	j;
	int	max_bits;
	int	num;
	int	k;

	i = -1;
	max_bits = get_max_bits(&ps->a);
	while (++i < max_bits)
	{
		j = 0;
		while (j++ < ps->a.size)
		{
			num = ps->a.data[0];
			k = -1;
			while (++k < i)
				num /= 2;
			if ((num % 2) == 1)
				ft_ra(ps);
			else
				ft_pb(ps);
		}
		while (ps->b.size > 0)
			pa(ps);
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
