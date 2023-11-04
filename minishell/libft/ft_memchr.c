/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:34:26 by mboudrio          #+#    #+#             */
/*   Updated: 2022/10/29 17:22:40 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*c_s;

	i = 0;
	c_s = (unsigned char *)s;
	while (i < n)
	{
		if (c_s[i] == (unsigned char)c)
			return (&c_s[i]);
		i++;
	}
	return (0);
}
