/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:47:41 by otelliq           #+#    #+#             */
/*   Updated: 2023/09/30 22:00:14 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_elem	*create_node(char *s)
{
	t_elem	*nd;

	nd = (t_elem *)malloc(sizeof(t_elem));
	if (!nd)
		return (NULL);
	nd->content = s;
	nd->name = env_first(nd->content);
	nd->value = env_last(nd->content);
	nd->next = NULL;
	return (nd);
}

void	addback_node(t_elem **lst, t_elem *new)
{
	t_elem	*back;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	back = last_node(*lst);
	back->next = new;
	new->next = NULL;
}

t_elem	*last_node(t_elem *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

char	*env_first(char *s)
{
	int		i;
	int		j;
	char	*val;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '=')
		i++;
	val = malloc(sizeof(char) * i + 1);
	while (j < i)
	{
		val[j] = s[j];
		j++;
	}
	val[j] = '\0';
	return (val);
}
