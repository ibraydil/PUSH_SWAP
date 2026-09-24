/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokuzmic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 16:17:32 by pokuzmic          #+#    #+#             */
/*   Updated: 2026/09/22 19:32:38 by pokuzmic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (stack == NULL || new == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

t_stack	*create_stack(int *numbers, int amount)
{
	t_stack	*stack;
	t_stack	*node;
	int		i;

	stack = NULL;
	i = 0;
	while (i < amount)
	{
		node = new_node(numbers[i]);
		if (node == NULL)
		{
			while (stack != NULL)
			{
				node = stack->next;
				free(stack);
				stack = node;
			}
			return (NULL);
		}
		add_back(&stack, node);
		i++;
	}
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_stack	*next;

	while (stack != NULL)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}
