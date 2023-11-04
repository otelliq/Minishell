/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:02:34 by otelliq           #+#    #+#             */
/*   Updated: 2023/09/30 21:54:01 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pre_tokenization(char *line, t_data *data, t_sum *sum, t_elem *env)
{
	t_list	*command;

	line = expansion(line, data, sum, env);
	if (is_empty(line))
	{
		command = create_command_list(line);
		execute_commands(command, data, sum);
	}
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

void	fill_them(t_slp_p *val, char *word, char *input, char **words)
{
	char	**new_words;

	if (val->i > val->w_s)
	{
		word = (char *)ft_malloc((val->i - val->w_s + 1), NULL, ALLOC);
		ft_strncpy(word, input + val->w_s, val->i - val->w_s);
		word[val->i - val->w_s] = '\0';
		words[val->word_count++] = word;
		if (val->word_count == val->i_c)
		{
			val->i_c *= 2;
			new_words = (char **)ft_malloc((val->i_c * sizeof(char *)), \
			NULL, ALLOC);
			ft_memcpy(new_words, words, val->word_count * sizeof(char *));
			words = new_words;
		}
	}
	val->w_s = val->i + 1;
}
