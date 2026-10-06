/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibrayev <dibrayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 16:11:37 by dibrayev          #+#    #+#             */
/*   Updated: 2026/09/29 18:59:50 by dibrayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	disorder(t_stack *a)
{
	int		i;
	int		j;
	double	pairs;
	double	error;

	if (!a || a->size <= 1)
		return (0);
	i = 0;
	pairs = 0;
	error = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			pairs++;
			if (a->data[i] > a->data[j])
				error++;
			j++;
		}
		i++;
	}
	return (error / pairs);
}
