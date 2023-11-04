/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:49:59 by otelliq           #+#    #+#             */
/*   Updated: 2023/09/30 17:32:11 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	export_command(t_list *list, t_sum *g)
{
	t_elem	*exp;
	t_elem	*current_exp;

	exp = NULL;
	current_exp = g->exp;
	if (list->args[0] == NULL)
	{
		while (current_exp)
		{
			printf("declare -x ");
			if (current_exp->value == NULL)
				printf("%s=\'\'\n", current_exp->name);
			else
				printf("%s=\"%s\"\n", current_exp->name, current_exp->value);
			current_exp = current_exp->next;
		}
	}
	else
	{
		if (is_valid_export_variable(current_exp->name))
			export_new_variables(list, -1, g, exp);
		else
			printf("not a valid identifier\n");
	}
}

void	update_the_node(t_list *list, t_sum *g, int i, t_elem *exp)
{
	t_elem	*env;

	if (value_checker(g->exp, list->args[i]) == 1)
	{
		exp = create_node(list->args[i]);
		addback_node(&g->exp, exp);
	}
	if (value_checker(g->env, list->args[i]) == 1)
	{
		env = create_node(list->args[i]);
		addback_node(&g->env, env);
	}
}

void	export_new_variables(t_list *list, int i, t_sum *g, t_elem *exp)
{
	while (list->args[++i])
	{
		if (is_equal(list->args[i]) == 1)
			update_the_node(list, g, i, exp);
		else if (is_equal(list->args[i]) == 0)
		{
			if (value_checker(g->exp, list->args[i]) == 1)
			{
				exp = create_node(list->args[i]);
				addback_node(&g->exp, exp);
			}
		}
	}
}

int	is_valid_export_variable(char *variable_name)
{
	int	i;

	if (!variable_name || !ft_isalpha(variable_name[0]))
	{
		return (0);
	}
	i = 1;
	while (variable_name[i] != '\0')
	{
		if (!ft_isalnum(variable_name[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
