/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:37:22 by mboudrio          #+#    #+#             */
/*   Updated: 2023/09/30 15:48:44 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_counter(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0' && *s == c)
		s++;
	while (*s != '\0')
	{
		count++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (count);
}

static int	word_length(char const *str, char c)
{
	int	l;

	l = 0;
	while (str[l] && str[l] != c)
		l++;
	return (l);
}

static char	**spliter(char **res, char const *s, char c, int words_count)
{
	int		i;
	int		j;
	int		word_len;

	i = 0;
	while (*s && *s == c)
		s++;
	while (i < words_count)
	{
		while (*s && *s == c)
			s++;
		word_len = word_length(s, c);
		res[i] = (char *)ft_malloc(sizeof(char) * word_len + 1, \
		NULL, ALLOC);
		j = 0;
		while (j < word_len)
			res[i][j++] = *s++;
		res[i][j] = '\0';
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words_count;

	if (!s)
		return (NULL);
	words_count = word_counter(s, c);
	res = (char **)ft_malloc(sizeof(char *) * (words_count + 1), \
	NULL, ALLOC);
	if (!res)
		return (NULL);
	res = spliter(res, s, c, words_count);
	return (res);
}
