/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 15:13:54 by dibrayev          #+#    #+#             */
/*   Updated: 2026/09/28 09:59:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(t_stack *stack)
{
	int tmp;
	
	if (stack->size < 2)
		return ;
	tmp = stack->data[0]; /*saved the first element in tmp*/
	stack->data[0] = stack->data[1]; /*added the second element as the firts*/
	stack->data[1] = tmp; /*added the previous first as the second*/
}

void ft_rotate(t_stack *stack)
{
	int i;
	int tmp;
	int n;

	i = 0;
	if (stack->size < 2)
		return ;
	tmp = stack->data[0];
	n = stack->size;
	while (i < n - 1)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[n - 1] = tmp;
}
/*Shifts all elements up by one; the top element becomes the bottom.*/

void ft_revrotate(t_stack *stack)
{
	int i;
	int tmp;
	int n;

	if (stack->size < 2)
		return ;
	n = stack->size;
	i = n - 1;
	tmp = stack->data[n - 1];
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = tmp;	
}
/*1 2 3 4 5 becomes 5 1 2 3 4*/

void ft_push(t_stack *src, t_stack *dst)
{
	int tmp;
	int i;

	if (src->size == 0 || dst->size >= dst->cap)
		return ;
	tmp = src->data[0];
	i = dst->size;
	while (i > 0)
	{
		dst->data[i] = dst->data[i - 1];
		i--;
	}
	dst->data[0] = tmp;
	i = 0;
	while (i < src->size - 1)
	{
		src->data[i] = src->data[i + 1];
        i++;
	}
	src->size--;
	dst->size++;
} 

/*moves one element from the top 
of one stack to the top of the other.*/
/*
before:   src: 7 2 9        dst: 4 5
after:    src: 2 9          dst: 7 4 5*/

void	ft_sa(t_ps *p)
{
	if (p->a.size < 2)
		return ;
	ft_swap(&p->a);
	p->counts[0]++;
	p->total++;
	ft_putendl_fd("sa", 1);
}

void	ft_sb(t_ps *p)
{
	if (p->b.size < 2)
		return ;
	ft_swap(&p->b);
	p->counts[1]++;
	p->total++;
	ft_putendl_fd("sb", 1);
}

void	ft_ss(t_ps *p)
{
	if (p->a.size < 2 && p->b.size < 2)
		return ;
	if (p->a.size >= 2)
		ft_swap(&p->a);
	if (p->b.size >= 2)
		ft_swap(&p->b);
	p->counts[2]++;
	p->total++;
	ft_putendl_fd("ss", 1);
}

void	ft_pa(t_ps *p)
{
	if (p->b.size == 0)
		return ;
	if (p->a.size >= p->a.cap)
		return ;
	ft_push(&p->b, &p->a);
	p->counts[3]++;
	p->total++;
	ft_putendl_fd("pa", 1);
}

void	ft_pb(t_ps *p)
{
	if (p->a.size == 0)
		return ;
	if (p->b.size >= p->b.cap)
		return ;
	ft_push(&p->a, &p->b);
	p->counts[4]++;
	p->total++;
	ft_putendl_fd("pb", 1);
}

void	ft_ra(t_ps *p)
{
	if (p->a.size < 2)
		return ;
	ft_rotate(&p->a);
	p->counts[5]++;
	p->total++;
	ft_putendl_fd("ra", 1);
}

void	ft_rb(t_ps *p)
{
	if (p->b.size < 2)
		return ;
	ft_rotate(&p->b);
	p->counts[6]++;
	p->total++;
	ft_putendl_fd("rb", 1);
}

void	ft_rr(t_ps *p)
{
	if (p->a.size < 2 && p->b.size < 2)
		return ;
	if (p->a.size >= 2)
		ft_rotate(&p->a);
	if (p->b.size >= 2)
		ft_rotate(&p->b);
	p->counts[7]++;
	p->total++;
	ft_putendl_fd("rr", 1);
}

void	ft_rra(t_ps *p)
{
	if (p->a.size < 2)
		return ;
	ft_revrotate(&p->a);
	p->counts[8]++;
	p->total++;
	ft_putendl_fd("rra", 1);
}

void	ft_rrb(t_ps *p)
{
	if (p->b.size < 2)
		return ;
	ft_revrotate(&p->b);
	p->counts[9]++;
	p->total++;
	ft_putendl_fd("rrb", 1);
}

void	ft_rrr(t_ps *p)
{
	if (p->a.size < 2 && p->b.size < 2)
		return ;
	if (p->a.size >= 2)
		ft_revrotate(&p->a);
	if (p->b.size >= 2)
		ft_revrotate(&p->b);
	p->counts[10]++;
	p->total++;
	ft_putendl_fd("rrr", 1);
}
