/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:22:57 by mboudrio          #+#    #+#             */
/*   Updated: 2023/09/30 15:42:36 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_liste	*ft_lstnew(void *content)
{
	t_liste	*p;

	p = (t_liste *)ft_malloc(sizeof(*p), NULL, ALLOC);
	if (!p)
		return (NULL);
	p->content = content;
	p->next = NULL;
	return (p);
}
