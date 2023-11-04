/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 02:15:51 by mboudrio          #+#    #+#             */
/*   Updated: 2023/09/26 08:07:33 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_liste **lst, t_liste *new)
{
	t_liste	*back;

	back = ft_lstlast(*lst);
	if (back)
	{
		back->next = new;
		return ;
	}
	*lst = new;
}
