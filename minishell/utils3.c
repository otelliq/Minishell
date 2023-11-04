/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:56:40 by otelliq           #+#    #+#             */
/*   Updated: 2023/09/30 22:02:08 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	issymbol(char c)
{
	return (c == '<' || c == '>');
}

char	*fill_the_red(int len, int i, int j, char *input)
{
	char	c_tmp;
	char	*result;

	result = ft_malloc((2 * len + 1), NULL, ALLOC);
	while (i < len)
	{
		c_tmp = input[i];
		if (issymbol(c_tmp))
		{
			result[j++] = ' ';
			result[j++] = c_tmp;
			if (i < len - 1 && issymbol(input[i + 1]))
				result[j++] = input[i++ + 1];
			result[j++] = ' ';
		}
		else
			result[j++] = c_tmp;
		i++;
	}
	result[j] = '\0';
	return (result);
}

int	has_mismatched_quotes(const char *str)
{
	int	single_quote;
	int	double_quote;

	single_quote = process_single_quotes(str);
	double_quote = process_double_quotes(str);
	return (single_quote != 0 || double_quote != 0);
}

int	is_empty(const char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '\t')
			return (1);
		line++;
	}
	return (0);
}
