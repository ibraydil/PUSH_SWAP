/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 14:17:54 by marvin            #+#    #+#             */
/*   Updated: 2026/08/21 14:17:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *box, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle [0] == '\0')
		return ((char *)box);
	i = 0;
	while (box[i] != '\0' && i < len)
	{
		j = 0;
		while (box[i + j] && (i + j) < len && box[i + j] == needle[j])
		{
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)&box[i]);
		i++;
	}
	return (NULL);
}
