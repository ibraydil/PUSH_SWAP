# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/29 14:10:11 by codespace         #+#    #+#              #
#    Updated: 2026/09/29 14:10:12 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

INCLUDES	= -I. -I$(LIBFT_DIR)

# Entry point: replace with the real main file once it exists
MAIN		= parsing/parsing_testing.c

SRCS		= $(MAIN) \
			  operations.c \
			  options.c \
			  benchmark.c \
			  disorder.c \
			  parsing/parsing_utils.c \
			  parsing/parsing_args.c \
			  parsing/parsing_split.c \
			  parsing/stack_init.c \
			  algorithms/simple_algorithm.c \
			  algorithms/medium_utils.c \
			  algorithms/medium_sort.c \
			  algorithms/complex.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

