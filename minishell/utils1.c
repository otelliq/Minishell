/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:32:03 by otelliq           #+#    #+#             */
/*   Updated: 2023/09/30 15:41:27 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_list *list)
{
	if (ft_strcmp(list->command, "echo") == 0 || \
		ft_strcmp(list->command, "ECHO") == 0 || \
		ft_strcmp(list->command, "cd") == 0 || \
		ft_strcmp(list->command, "CD") == 0 || \
		ft_strcmp(list->command, "pwd") == 0 || \
		ft_strcmp(list->command, "PWD") == 0 || \
		ft_strcmp(list->command, "env") == 0 || \
		ft_strcmp(list->command, "ENV") == 0 || \
		ft_strcmp(list->command, "export") == 0 || \
		ft_strcmp(list->command, "EXPORT") == 0 || \
		ft_strcmp(list->command, "unset") == 0 || \
		ft_strcmp(list->command, "UNSET") == 0 || \
		!ft_strcmp(list->command, "exit") || !ft_strcmp(list->command, "EXIT"))
	{
		return (1);
	}
	else
		return (0);
}

void	execute_builtin(t_list *list, t_sum *s)
{
	if (ft_strcmp(list->command, "echo") == 0)
		echo_command(list);
	else if (ft_strcmp(list->command, "pwd") == 0)
		pwd_command();
	else if (ft_strcmp(list->command, "cd") == 0)
		cd_command(list, s);
	else if (ft_strcmp(list->command, "env") == 0)
		env_printer(s);
	else if (ft_strcmp(list->command, "export") == 0)
		export_command(list, s);
	else if (ft_strcmp(list->command, "unset") == 0)
		unset_command(list, s);
	else if (ft_strcmp(list->command, "exit") == 0)
		exit_command(list, s);
}

t_elem	*search_node(t_elem *head, char *word)
{
	t_elem	*current;

	current = head;
	while (current)
	{
		if (ft_strcmp(current->name, word) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}

t_slp_p	*init_slp_p(void)
{
	t_slp_p	*val;

	val = (t_slp_p *)ft_malloc(sizeof(t_slp_p), NULL, ALLOC);
	val->i_c = 10;
	val->word_count = 0;
	val->inside_quotes = 0;
	val->w_s = 0;
	val->i = 0;
	return (val);
}

char	**splitstring(char *input)
{
	t_slp_p	*val;
	char	*word;
	char	**words;

	word = NULL;
	val = init_slp_p();
	words = (char **)ft_malloc(val->i_c * sizeof(char *), NULL, ALLOC);
	while (input[val->i] != '\0')
	{
		if (input[val->i] == '"' || input[val->i] == '\'')
			val->inside_quotes = !val->inside_quotes;
		else if (input[val->i] == '|' && !val->inside_quotes)
			fill_it(val, word, input, words);
		val->i++;
	}
	if (val->i > val->w_s)
	{
		word = (char *)ft_malloc(val->i - val->w_s + 1, NULL, ALLOC);
		ft_strncpy(word, input + val->w_s, val->i - val->w_s);
		word[val->i - val->w_s] = '\0';
		words[val->word_count++] = word;
	}
	words[val->word_count] = NULL;
	return (words);
}
