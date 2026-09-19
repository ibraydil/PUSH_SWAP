/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibrayev <dibrayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 15:13:54 by dibrayev          #+#    #+#             */
/*   Updated: 2026/09/19 17:14:30 by dibrayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(t_stack *stack)
{
	int tmp;
	
	if (stack -> size < 2)
		return ;
	tmp = stack -> data[0]; /*saved the first element in tmp*/
	stack -> data[0] = stack -> data[1]; /*added the second element as the firts*/
	stack -> data[1] = tmp; /*added the previous first as the second*/
}

void ft_rotate(t_stack *stack)
{
	int i;
	int tmp;
	int n;

	i = 0;
	if (stack -> size < 2)
		return ;
	tmp = stack -> data[0];
	n = stack -> size;
	while (i < n - 1)
	{
		stack -> data[i] = stack -> data[i + 1];
		i++;
	}
	stack -> data[n - 1] = tmp;
}
/*Shifts all elements up by one; the top element becomes the bottom.*/

void ft_mirotate(t_stack *stack)
{
	int i;
	int tmp;
	int n;

	if (stack -> size < 2)
		return ;
	n = stack -> size;
	i = n - 1;
	tmp = stack -> data[n - 1];
	while (i > 0)
	{
		stack -> data[i] = stack -> data[i - 1];
		i--;
	}
	stack -> data[0] = tmp;	
}
/*1 2 3 4 5 becomes 5 1 2 3 4*/

void ft_push(t_stack *src, t_stack *dst)
{
	int tmp;
	int i;

	if (src -> size == 0)
		return ;
	tmp = src -> data[0];
	i = dst -> size;
	while (i > 0)
	{
		dst -> data[i] = dst -> data[i - 1];
		i--;
	}
	src -> size--;
	dst -> size++;
} 


/*moves one element from the top 
of one stack to the top of the other.*/
/*
before:   src: 7 2 9        dst: 4 5
after:    src: 2 9          dst: 7 4 5*/
