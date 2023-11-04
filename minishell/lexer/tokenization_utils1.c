/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:59:56 by otelliq           #+#    #+#             */
/*   Updated: 2023/09/30 15:24:25 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*expd(char *exp, t_data *data, t_elem *env, t_sum *sum)
{
	data->i = 0;
	while (exp[data->i])
	{
		if (exp[data->i] == '\'' && !(data->dq))
			data->sq = !(data->sq);
		if (exp[data->i] == '"' && !(data->dq))
			data->dq = !(data->dq);
		if (exp[data->i] == '$' && exp[data->i + 1] != '\0' && !(data->sq))
		{
			exp = apply_expansion(data, exp, env, sum);
			data->i = 0;
		}
		data->i++;
	}
	return (exp);
}

char	*expansion(char *cmd, t_data *data, t_sum *sum, t_elem *env)
{
	char	*res;
	char	*ser;

	res = NULL;
	ser = ft_strdup("");
	data->sq = 0;
	data->dq = 0;
	cmd = expd(cmd, data, env, sum);
	res = ft_strjoin(cmd, " ");
	ser = ft_strjoin(ser, res);
	return (ser);
}

void	one_command(t_list *list, t_data __unused *data, t_sum __unused *sum)
{
	if (finding_here_doc(list) > 0)
		applying_her_doc(data, list);
	if (finding_rederection(list) > 0)
		applying_redirections_and_fd(data, list);
	execute_exe(list, sum);
}

void	check_mult_command(t_list *list, t_data __unused *data, t_sum *sum)
{
	if (is_builtin(list) == 1)
		execute_builtin(list, sum);
	else
		execute_exe(list, sum);
}

int	list_length(t_list *head)
{
	int		length;
	t_list	*current;

	length = 0;
	current = head;
	while (current != NULL)
	{
		length++;
		current = current->next;
	}
	return (length);
}
