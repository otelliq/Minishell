/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:38:41 by otelliq           #+#    #+#             */
/*   Updated: 2023/09/30 21:57:18 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	value_checker(t_elem *elements, char *s)
{
	char	*value;
	char	*name;

	value = env_last(s);
	name = env_first(s);
	while (elements)
	{
		if (ft_strcmp(elements->name, name) == 0)
		{
			if (elements->value != NULL && value == NULL)
			{
				freeing(value, name);
				return (0);
			}
			if (value != NULL)
				elements->value = ft_strdup(value);
			free(value);
			free(name);
			return (0);
		}
		elements = elements->next;
	}
	free(value);
	free(name);
	return (1);
}

void	node_compare(t_elem *env, t_elem *exp)
{
	t_elem	*s;

	s = ft_malloc(sizeof(t_elem), NULL, ALLOC);
	while (env)
	{
		s = exp;
		while (s)
		{
			if (ft_strcmp(env->name, s->name) == 0 && ft_strcmp(env->value,
					s->value) != 0)
			{
				env->value = ft_strdup(s->value);
			}
			s = s->next;
		}
		env = env->next;
	}
}
