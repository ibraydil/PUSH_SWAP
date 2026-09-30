/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 16:17:32 by pokuzmic          #+#    #+#             */
/*   Updated: 2026/09/30 12:34:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_stack *stack, int *numbers, int amount)
{
	stack->data = malloc(sizeof(int) * amount);
	if (stack->data == NULL)
		return (0);
	stack->size = amount;
	stack->cap = amount;
	while (amount > 0)
	{
		amount--;
		stack->data[amount] = numbers[amount];
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	free(stack->data);
	stack->data = NULL;
	stack->size = 0;
	stack->cap = 0;
}

void	init_ps(t_ps *p)
{
	int	i;
	
	p->a.data = NULL;
	p->a.size = 0;
	p->a.cap = 0;
	p->b.data = NULL;
	p->b.size = 0;
	p->b.cap = 0;
	p->total = 0;
	p->bench = 0;
	i = 0;
	while (i < 11)
	{
		p->counts[i] = 0;
		i++;
	}
}

void	free_ps(t_ps *p)
{
	free_stack(&p->a);
	free_stack(&p->b);
}
