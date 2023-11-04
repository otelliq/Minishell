/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:22:20 by otelliq           #+#    #+#             */
/*   Updated: 2023/09/30 21:28:27 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	unset_value(t_elem **head, char *s)
{
	t_elem	*current;
	t_elem	*before;

	current = *head;
	before = NULL;
	if (current != NULL && ft_strcmp(current->name, s) == 0)
	{
		*head = current->next;
		free(current->name);
		free(current->value);
		free(current);
		return ;
	}
	while (current != NULL && ft_strcmp(current->name, s) != 0)
	{
		before = current;
		current = current->next;
	}
	if (current == NULL)
		return ;
	free(current->name);
	free(current->value);
	free(current);
	before->next = current->next;
}

void	unset_command(t_list *list, t_sum *sum)
{
	int	i;

	i = 0;
	while (list->args[i])
	{
		unset_value(&sum->env, list->args[i]);
		unset_value(&sum->exp, list->args[i]);
		i++;
	}
}
