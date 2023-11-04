/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:41:20 by otelliq           #+#    #+#             */
/*   Updated: 2023/09/30 18:04:17 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_t_elem(t_elem *elem)
{
	t_elem	*temp;

	while (elem != NULL)
	{
		temp = elem;
		elem = elem->next;
		free(temp->content);
		free(temp->name);
		free(temp->value);
		free(temp);
	}
}

void	free_sum(t_sum *sum)
{
	free_t_elem(sum->env);
	free_t_elem(sum->exp);
	free(sum);
}
