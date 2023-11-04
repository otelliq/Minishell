/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:58:34 by mboudrio          #+#    #+#             */
/*   Updated: 2022/10/13 17:19:51 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cast_dst;
	unsigned char	*cast_src;

	i = 0;
	if (!dst && !src)
		return (NULL);
	cast_dst = (unsigned char *)dst;
	cast_src = (unsigned char *)src;
	while (i < n)
	{
		cast_dst[i] = cast_src[i];
		i++;
	}
	return (dst);
}
