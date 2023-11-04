/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:58:58 by mboudrio          #+#    #+#             */
/*   Updated: 2023/09/30 17:19:37 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*create_command_list(char *line)
{
	char	**p;
	t_list	*command;
	int		i;
	t_list	*d;

	p = splitstring(line);
	command = NULL;
	i = 0;
	while (p[i])
	{
		d = create_new_element(p[i]);
		add_last_node(&command, d);
		i++;
	}
	return (command);
}

void	applying_redirections(t_list *command, t_data *data, t_sum *sum)
{
	if (finding_here_doc(command) > 0)
		applying_her_doc(data, command);
	if (finding_rederection(command) > 0)
		applying_redirections_and_fd(data, command);
	execute_builtin(command, sum);
}

void	execute_commands(t_list *command, t_data *data, t_sum *sum)
{
	int	fdo;
	int	fdin;

	fdo = dup(STDOUT_FILENO);
	fdin = dup(STDIN_FILENO);
	if (list_length(command) == 1)
	{
		if (is_builtin(command) == 1)
			execute_builtin(command, sum);
		else
			one_command(command, data, sum);
	}
	else
		ft_fork(command, sum, data);
	dup2(fdo, STDOUT_FILENO);
	dup2(fdin, STDIN_FILENO);
}

char	*fill_the_quotes(char *str, char curr_char, char curr, int res)
{
	char	*result;
	int		i;
	int		j;

	j = 0;
	i = 0;
	result = ft_calloc(res + 1, 1);
	curr = '\0';
	while (str[i] != '\0')
	{
		curr_char = str[i];
		if ((curr_char == '\'' || curr_char == '"') && curr == '\0')
			curr = curr_char;
		else if (curr_char == curr)
			curr = '\0';
		else
			result[j++] = curr_char;
		i++;
	}
	result[j] = '\0';
	return (result);
}

char	*return_without_quote(char *str)
{
	char	curr;
	int		res;
	char	curr_char;
	int		i;
	char	*result;

	i = 0;
	curr = '\0';
	res = ft_strlen(str);
	while (str[i] != '\0')
	{
		curr_char = str[i];
		if ((curr_char == '\'' || curr_char == '"') && curr == '\0')
			curr = curr_char;
		else if (curr_char == curr)
		{
			curr = '\0';
			res--;
		}
		i++;
	}
	result = fill_the_quotes(str, curr_char, curr, res);
	return (result);
}
