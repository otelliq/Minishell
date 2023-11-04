/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:11:50 by mboudrio          #+#    #+#             */
/*   Updated: 2023/09/30 15:42:26 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_malloc(size * count, NULL, ALLOC);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}
