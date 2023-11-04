/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:36:17 by mboudrio          #+#    #+#             */
/*   Updated: 2022/10/29 19:18:15 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle[0])
		return ((char *)&haystack[i]);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (i + j >= len)
				return (0);
			if (needle[j] == haystack[i + j] && needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
