/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:45:19 by otelliq           #+#    #+#             */
/*   Updated: 2023/09/30 15:41:55 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	access_handling(char *s, char **ss, char **envv)
{
	execve(s, ss, envv);
	perror("execve");
	exit(126);
}

int	ft_access(char *path, int res)
{
	if (access(path, res) == 0)
		return (0);
	else
		return (-1);
}

int	path_finder(t_elem *element)
{
	while (element)
	{
		if (ft_strcmp(element->name, "PATH") == 0)
			return (1);
		element = element->next;
	}
	return (0);
}

char	*ft_strjoin_env(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return ((char *)s2);
	if (s2 == NULL)
		return ((char *)s1);
	str = ft_malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2), NULL,
			ALLOC);
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = '/';
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
