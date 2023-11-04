/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:53:27 by otelliq           #+#    #+#             */
/*   Updated: 2023/09/30 20:33:32 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_last(char *s)
{
	int		i;
	int		j;
	char	*val;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	while (s[i] && s[i] != '=')
		i++;
	if (s[i] == '\0')
		return (NULL);
	if (s[i + 1] == '\0')
		return (NULL);
	j = len - i;
	i++;
	val = malloc((sizeof(char) * j + 1));
	j = 0;
	while (i < len)
		val[j++] = s[i++];
	val[j] = '\0';
	return (val);
}

t_elem	*env_init(char **env)
{
	t_elem	*s;
	t_elem	*d;
	int		i;

	s = NULL;
	i = 0;
	while (env[i])
	{
		d = create_node(env[i++]);
		addback_node(&s, d);
	}
	return (s);
}

void	env_printer(t_sum *s)
{
	t_elem	*current;

	current = s->env;
	while (current)
	{
		printf("%s=%s\n", current->name, current->value);
		current = current->next;
	}
}

char	**change_list_to_array(t_elem *env)
{
	char	**inenv;
	t_elem	*current;
	int		len;
	int		i;

	current = env;
	len = 0;
	while (current)
	{
		len++;
		current = current->next;
	}
	inenv = (char **)ft_malloc((sizeof(char *) * (len + 1)), NULL, ALLOC);
	if (!inenv)
		return (NULL);
	current = env;
	i = 0;
	while (current)
	{
		inenv[i] = ft_strdup(current->content);
		current = current->next;
		i++;
	}
	inenv[i] = NULL;
	return (inenv);
}
