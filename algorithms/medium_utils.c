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

int	calculate_chunk_size(int size)
{
	int	chunk;

	chunk = 1;
	while (chunk * chunk < size)
		chunk++;
	return (chunk);
}

int	find_chunk_position(t_stack *stack, int *sorted, int start, int end)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->data[i] >= sorted[start]
			&& stack->data[i] <= sorted[end])
			return (i);
		i++;
	}
	return (-1);
}

int	find_max_position(t_stack *stack)
{
	int	i;
	int	max_position;

	if (stack->size == 0)
		return (-1);
	i = 1;
	max_position = 0;
	while (i < stack->size)
	{
		if (stack->data[i] > stack->data[max_position])
			max_position = i;
		i++;
	}
	return (max_position);
}

void	sort_array(int *array, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int	*sorted_copy(t_stack *stack)
{
	int	*sorted;
	int	i;

	sorted = malloc(sizeof(int) * stack->size);
	if (sorted == NULL)
		return (NULL);
	i = 0;
	while (i < stack->size)
	{
		sorted[i] = stack->data[i];
		i++;
	}
	sort_array(sorted, stack->size);
	return (sorted);
}
