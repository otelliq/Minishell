/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:56:44 by otelliq           #+#    #+#             */
/*   Updated: 2023/09/30 11:01:08 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	countvar(char *res)
{
	int	x;

	x = 0;
	while (res[x] && (ft_isalpha(res[x]) || ft_isdigit(res[x])))
		x++;
	return (x);
}

char	*get_env(t_data *data, int i)
{
	char	*value;

	if (data->envrt[i])
		value = ft_strdup(ft_strchr(data->envrt[i], '=') + 1);
	else
		value = ft_strdup("");
	return (value);
}

char	*get_exp(char *var, t_data *data, t_elem *env)
{
	int		i;
	char	*res;
	int		len;

	i = 0;
	data->envrt = change_list_to_array(env);
	len = ft_strlen(var);
	while (data->envrt[i])
	{
		if (ft_strncmp(data->envrt[i], var, len) == 0
			&& data->envrt[i][len] == '=')
			break ;
		else
			i++;
	}
	res = get_env(data, i);
	return (res);
}

void	apply_core(char *exp, t_data *data, t_elem *env, t_sum *sum)
{
	if (exp[data->i] == '?')
	{
		data->count_var = 1;
		data->var = ft_itoa(sum->exitt);
	}
	else
	{
		data->var = ft_substr(exp, data->i, data->count_var);
		data->var = get_exp(data->var, data, env);
	}
}

char	*apply_expansion(t_data *data, char *exp, t_elem *env, t_sum *sum)
{
	int		size;
	char	*res1;
	char	*res2;
	char	*new;

	size = data->i;
	data->i++;
	res1 = ft_substr(exp, 0, size);
	data->count_var = countvar(exp + data->i);
	apply_core(exp, data, env, sum);
	res2 = ft_strdup(exp + (data->i + data->count_var));
	new = ft_strjoin(ft_strjoin(res1, data->var), res2);
	return (new);
}
