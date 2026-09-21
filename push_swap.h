/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibrayev <dibrayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 14:53:13 by dibrayev          #+#    #+#             */
/*   Updated: 2026/09/19 15:52:01 by dibrayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include "libft.h"

typedef struct	s_stack
{
    int	*data;  /*holding the integers*/
	int	size; /*how many numbers are right now*/
	int	cap; /*how many it can hold to check the overflow*/
}   t_stack;

typedef struct s_ps
{
	t_stack	a;
	t_stack	b;
	int		counts[11]; /*how often operation was used*/
	int		total; /*total amount of operations*/
	int		bench;
}	t_ps;

#endif
