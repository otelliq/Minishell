/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:53:22 by mboudrio          #+#    #+#             */
/*   Updated: 2023/09/26 08:05:32 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_liste	*ft_lstmap(t_liste *lst, void *(*f)(void *), void (*del)(void *))
{
	t_liste	*new_list;
	t_liste	*new_node;

	new_list = NULL;
	new_node = NULL;
	if (!del || !f)
		return (NULL);
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_node, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
