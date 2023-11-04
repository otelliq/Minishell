/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_last_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:58:00 by mboudrio          #+#    #+#             */
/*   Updated: 2023/09/24 10:07:40 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_last_node(t_list **lst, t_list *new)
{
	t_list	*tail;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tail = last_node1(*lst);
	tail->next = new;
	new->next = NULL;
}

t_list	*last_node1(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}
