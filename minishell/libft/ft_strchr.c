/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:51:11 by mboudrio          #+#    #+#             */
/*   Updated: 2022/10/11 20:31:51 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (*p != (unsigned char)c)
	{
		if (*p == '\0')
		{
			return (NULL);
		}
		p++;
	}
	return ((char *)p);
}
