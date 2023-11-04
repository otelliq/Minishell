/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:41:34 by mboudrio          #+#    #+#             */
/*   Updated: 2023/09/26 08:06:49 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_liste **lst, void (*del)(void *))
{
	t_liste	*tmp;
	t_liste	*n;

	tmp = *lst;
	while (tmp)
	{
		n = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = n;
	}
	*lst = NULL;
}
