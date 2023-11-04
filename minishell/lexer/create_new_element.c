/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_element.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:58:06 by mboudrio          #+#    #+#             */
/*   Updated: 2023/09/30 21:54:25 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_splito(char *str)
{
	t_slp_p	*val;
	char	*word;
	char	**words;

	word = NULL;
	val = init_slp_p();
	words = (char **)ft_malloc((val->i_c * sizeof(char *)), NULL, ALLOC);
	while (str[val->i] != '\0')
	{
		if (str[val->i] == '"' || str[val->i] == '\'')
			val->inside_quotes = !val->inside_quotes;
		else if (ft_isspace(str[val->i]) && !val->inside_quotes)
			fill_them(val, word, str, words);
		val->i++;
	}
	if (val->i > val->w_s)
	{
		word = (char *)ft_malloc((val->i - val->w_s + 1), NULL, ALLOC);
		ft_strncpy(word, str + val->w_s, val->i - val->w_s);
		word[val->i - val->w_s] = '\0';
		words[val->word_count++] = word;
	}
	words[val->word_count] = NULL;
	return (words);
}

t_list	*create_new_element(char *line)
{
	t_list	*element;
	char	**p;
	int		i;

	i = 0;
	p = ft_splito(line);
	while (p[i])
	{
		p[i] = return_without_quote(p[i]);
		i++;
	}
	element = ft_malloc(sizeof(t_list), NULL, ALLOC);
	if (!element)
		return (NULL);
	element->linee = ft_strdup(line);
	element->command = ft_strdup(p[0]);
	element->args = fill_args(p);
	element->all = fill_args1(p);
	element->cmdarg = fill_args2(p);
	element->next = NULL;
	return (element);
}

char	**fill_args2(char **p)
{
	int		i;
	int		j;
	char	**d;
	int		n;

	i = 0;
	d = NULL;
	while (p[i] && (ft_strcmp(p[i], ">") != 0 || ft_strcmp(p[i], "<") != 0))
		i++;
	j = 0;
	n = 0;
	d = ft_malloc(sizeof(char *) * (i + 1), NULL, ALLOC);
	while (n < i)
	{
		if ((ft_strcmp(p[j], ">") == 0 || ft_strcmp(p[j], "<") == 0
				|| ft_strcmp(p[j], ">>") == 0 || ft_strcmp(p[j], "<<") == 0))
			break ;
		d[n++] = ft_strdup(p[j++]);
	}
	d[n] = NULL;
	return (d);
}

char	**fill_args(char **p)
{
	int		i;
	int		j;
	char	**d;
	int		n;

	i = 0;
	d = NULL;
	while (p[i])
		i++;
	i = i - 1;
	j = 1;
	n = 0;
	d = ft_malloc(sizeof(char *) * (i + 1), NULL, ALLOC);
	while (n < i)
		d[n++] = ft_strdup(p[j++]);
	d[n] = NULL;
	return (d);
}

char	**fill_args1(char **p)
{
	int		i;
	int		j;
	char	**d;

	i = 0;
	j = 0;
	d = NULL;
	while (p[i])
		i++;
	d = ft_malloc(sizeof(char *) * (i + 1), NULL, ALLOC);
	while (j < i)
	{
		d[j] = ft_strdup(p[j]);
		j++;
	}
	d[j] = NULL;
	return (d);
}
