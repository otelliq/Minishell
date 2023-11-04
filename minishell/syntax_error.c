/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:05:01 by mboudrio          #+#    #+#             */
/*   Updated: 2023/09/30 13:00:21 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirection_syntax_error(char *line)
{
	int	i;

	i = 0;
	if (ft_strcmp(line, ">>") == 0 || ft_strcmp(line, "<<") == 0
		|| ft_strcmp(line, "<") == 0 || ft_strcmp(line, ">") == 0)
		return (1);
	while (line[i] != '\0')
	{
		if ((line[i] == '>' && line[i + 1] == '<') || (line[i] == '>' && line[i \
			+ 1] == '>' && line[i + 2] == '>'))
			return (1);
		if ((line[i] == '<' && line[i + 1] == '>') || (line[i] == '<' && line[i \
			+ 1] == '<' && line[i + 2] == '<'))
			return (1);
		i++;
	}
	if (line[0] == '>' || line[0] == '<' || line[ft_strlen(line) - 1] == '>'
		|| line[ft_strlen(line) - 1] == '<')
		return (1);
	return (0);
}

int	pipes_errors(char *line)
{
	int	i;
	int	n;
	int	j;

	n = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '|')
		{
			n = 1;
			j = i;
			while (line[++j])
			{
				if (line[j] != ' ' && line[j] != '\t' && \
					line[j] != '\0' && line[j] != '|')
				{
					n = 0;
					break ;
				}
			}
		}
		i++;
	}
	return (n);
}

int	process_single_quotes(const char *str)
{
	int	single_quote;
	int	i;

	single_quote = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			if (single_quote == 0)
				single_quote = 1;
			else
				single_quote = 0;
		}
		i++;
	}
	return (single_quote);
}

int	process_double_quotes(const char *str)
{
	int	double_quote;
	int	i;

	double_quote = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
		{
			if (double_quote == 0)
				double_quote = 1;
			else
				double_quote = 0;
		}
		i++;
	}
	return (double_quote);
}

int	checking_errors(char *str)
{
	if (redirection_syntax_error(str))
	{
		printf("there is a syntax error ! try again\n");
		return (0);
	}
	if (pipes_errors(str))
	{
		printf("there is a syntax error ! try again\n");
		return (0);
	}
	if (matched(str))
	{
		printf("there is a syntax error ! try again\n");
		return (0);
	}
	return (1);
}
