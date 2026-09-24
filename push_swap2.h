/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokuzmic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 15:17:32 by pokuzmic          #+#    #+#             */
/*   Updated: 2026/09/22 16:32:38 by pokuzmic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

/* parsing_utils.c */
int		is_valid_number(const char *str);
long	ft_atol(const char *str);
int		duplicate_check(int *numbers, int amount);
int		parse_number(char *str, int *number);
int		*parse_numbers(char **argv, int amount);

/* parsing_split.c */
int		define_separator(char c, char *sep);
int		count_words(char *str, char *sep);
char	*word_split(char *str, char *sep);
char	**split_args(char *str, char *sep);
char	**prepare_args(int argc, char **argv);

/* parsing_utils2.c */
int		count_args(char **args);
void	free_args(char **args, int argc);
int		fill_words(char **words, char *str, char *charset);
void	free_words(char **words, int count);

/* stack_init.c */
t_stack	*new_node(int value);
void	add_back(t_stack **stack, t_stack *new);
t_stack	*create_stack(int *numbers, int amount);
void	free_stack(t_stack *stack);

#endif
