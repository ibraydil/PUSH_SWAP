/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokuzmic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 13:17:32 by pokuzmic          #+#    #+#             */
/*   Updated: 2026/09/21 13:32:38 by pokuzmic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL || str[0] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (str[i] == '\0')
			return (0);
	}
	while (str[i] != '\0')
	{
		if (!ft_isdigit((unsigned char)str[i]))
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	int		i;
	long	res;
	int		neg;

	i = 0;
	res = 0;
	neg = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res > (long)INT_MAX + 1)
			return (res * neg);
		i++;
	}
	return (res * neg);
}

int	duplicate_check(int *numbers, int amount)
{
	int	i;
	int	j;

	i = 0;
	while (i < amount - 1)
	{
		j = i + 1;
		while (j < amount)
		{
			if (numbers[i] == numbers[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	parse_number(char *str, int *number)
{
	long	n;

	if (!is_valid_number(str))
		return (0);
	n = ft_atol(str);
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	*number = (int)n;
	return (1);
}

int	*parse_numbers(char **argv, int amount)
{
	int	*numbers;
	int	i;

	numbers = malloc(sizeof(int) * amount);
	if (!numbers)
		return (NULL);
	i = 0;
	while (i < amount)
	{
		if (!parse_number(argv[i], &numbers[i]))
		{
			free(numbers);
			return (NULL);
		}
		i++;
	}
	if (!duplicate_check(numbers, amount))
	{
		free(numbers);
		return (NULL);
	}
	return (numbers);
}
