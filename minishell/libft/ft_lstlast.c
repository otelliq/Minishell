/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:41:41 by mboudrio          #+#    #+#             */
/*   Updated: 2023/09/26 08:13:29 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_liste	*ft_lstlast(t_liste *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
