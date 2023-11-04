/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:32:03 by otelliq           #+#    #+#             */
/*   Updated: 2023/09/30 15:41:15 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*add_spaces(char *input)
{
	int		len;
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	len = ft_strlen(input);
	result = fill_the_red(len, i, j, input);
	return (result);
}

char	*ft_strncpy(char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while (s2[i] != '\0' && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	while (i < n)
	{
		s1[i] = '\0';
		i++;
	}
	return (s1);
}

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

void	fill_it(t_slp_p *val, char *word, char *input, char **words)
{
	char	**new_words;

	if (val->i > val->w_s)
	{
		word = (char *)ft_malloc(val->i - val->w_s + 1, NULL, ALLOC);
		ft_strncpy(word, input + val->w_s, val->i - val->w_s);
		word[val->i - val->w_s] = '\0';
		words[val->word_count++] = word;
		if (val->word_count == val->i_c)
		{
			val->i_c *= 2;
			new_words = (char **)ft_malloc(val->i_c * sizeof(char *),
					NULL, ALLOC);
			ft_memcpy(new_words, words, val->word_count * sizeof(char *));
			words = new_words;
		}
	}
	val->w_s = val->i + 1;
}

int	matched(const char *str)
{
	if (has_mismatched_quotes(str))
		return (1);
	else
		return (0);
}
