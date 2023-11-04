/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:55:07 by otelliq           #+#    #+#             */
/*   Updated: 2023/09/30 15:41:32 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\r' || \
	c == '\f')
		return (0);
	return (1);
}

int	special_char(char c)
{
	if (c == '\'' || c == '\"' || c == '<' || c == '>' || c == '|')
		return (0);
	return (1);
}

int	is_equal(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '=' && s[i + 1] != '\0')
			return (1);
		if (s[i] == '=' && s[i + 1] == '\0')
			return (0);
		i++;
	}
	return (0);
}

int	special_char1(char c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}

char	*ft_strndup(char *s1, int n)
{
	char	*copy;
	int		s1_len;
	int		i;

	i = 0;
	s1_len = ft_strlen(s1);
	copy = ft_malloc(sizeof(char) * (s1_len + 1), NULL, ALLOC);
	if (!copy)
		return (NULL);
	while (s1[i] && i < n)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
