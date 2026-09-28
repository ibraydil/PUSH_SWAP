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
# include <limits.h>
# include "libft.h"

typedef struct s_stack
{
	int	*data;
	int	size;
	int	cap;
}	t_stack;

typedef struct s_ps
{
	t_stack	a;
	t_stack	b;
	int		counts[11];
	int		total;
	int		bench;
}	t_ps;

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

/* parsing_utils.c */
int			is_valid_number(const char *str);
long		ft_atol(const char *str);
int			duplicate_check(int *numbers, int amount);
int			parse_number(char *str, int *number);
int			*parse_numbers(char **argv, int amount);

/* parsing_utils2.c */
int			fill_words(char **words, char *str, char *charset);
void		free_words(char **words, int count);
int			count_args(char **args);
void		free_args(char **args);
int			add_arg_words(char **args, char *str, int index);

/* parsing_split.c */
int			define_separator(char c, char *sep);
int			count_words(char *str, char *sep);
char		*word_split(char *str, char *sep);
char		**split_args(char *str, char *charset);
char		**prepare_args(int argc, char **argv);

/* stack_init.c */
int			init_stack(t_stack *stack, int *numbers, int amount);
void		free_stack(t_stack *stack);
void		init_ps(t_ps *p);
void		free_ps(t_ps *p);

/* simple_utils.c */
int			find_min(t_stack *stack);
int			find_position(t_stack *stack, int value);
int			stack_size(t_stack *stack);
void		move_min_to_top(t_ps *p);
void		selection_sort(t_ps *p);

/* operations.c */
void		ft_swap(t_stack *stack);
void		ft_rotate(t_stack *stack);
void		ft_revrotate(t_stack *stack);
void		ft_push(t_stack *src, t_stack *dst);
void		ft_sa(t_ps *p);
void		ft_sb(t_ps *p);
void		ft_ss(t_ps *p);
void		ft_pa(t_ps *p);
void		ft_pb(t_ps *p);
void		ft_ra(t_ps *p);
void		ft_rb(t_ps *p);
void		ft_rr(t_ps *p);
void		ft_rra(t_ps *p);
void		ft_rrb(t_ps *p);
void		ft_rrr(t_ps *p);

/* medium_utils.c */
int			calculate_chunk_size(int size);
int			find_chunk_position(t_stack *stack, int *sorted, int start,
				int end);
int			find_max_position(t_stack *stack);
void		sort_array(int *array, int size);
int			*sorted_copy(t_stack *stack);

/* medium_sort.c */
void		push_chunks(t_ps *p, int *sorted, int chunk_size);
void		push_back_sorted(t_ps *p);
void		medium_sort(t_ps *p);

/* options.c */
t_strategy	get_strategy(int argc, char **argv);
int			is_bench(int argc, char **argv);
int			is_option(char *arg);
int			count_numbers(char **argv);

/* benchmark.c */
void		print_benchmark(t_ps *p, t_strategy strategy, double disorder);

#endif
