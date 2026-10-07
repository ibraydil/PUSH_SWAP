/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pokuzmic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:13:00 by pokuzmic          #+#    #+#             */
/*   Updated: 2026/08/24 10:22:11 by pokuzmic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

static char	*ft_word_split(const char *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	word = malloc(sizeof(*word) * (i + 1));
	if (word == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	*ft_free(char **words, int j)
{
	int	k;

	k = 0;
	while (k < j)
	{
		free(words[k]);
		k++;
	}
	free(words);
	return (NULL);
}

static char	**ft_fill_words(char **words, const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			words[j] = ft_word_split(&s[i], c);
			if (words[j] == NULL)
				return (ft_free(words, j));
			while (s[i] != '\0' && s[i] != c)
				i++;
			j++;
		}
		else
			i++;
	}
	words[j] = NULL;
	return (words);
}

char	**ft_split(const char *s, char c)
{
	char	**words;

	if (s == NULL)
		return (NULL);
	words = malloc(sizeof(*words) * (ft_count_words(s, c) + 1));
	if (words == NULL)
		return (NULL);
	return (ft_fill_words(words, s, c));
}
