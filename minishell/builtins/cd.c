/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 08:56:09 by otelliq           #+#    #+#             */
/*   Updated: 2023/09/30 21:58:51 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	apply_empty_cd(t_sum *zone)
{
	int		found;
	t_elem	*current;

	current = zone->env;
	found = 0;
	while (current)
	{
		if (ft_strcmp(current->name, "HOME") == 0)
		{
			found = 1;
			break ;
		}
		current = current->next;
	}
	if (found == 0)
	{
		perror("cd");
		zone->exitt = 1;
	}
	else
		chdir(current->value);
}

void	apply_cd(t_sum *new_path, t_sum *old_path, t_sum *zone)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd != NULL)
	{
		free(old_path->env->value);
		old_path->env->value = ft_strdup(new_path->env->value);
		free(new_path->env->value);
		new_path->env->value = ft_strdup(cwd);
		free(old_path->exp->value);
		old_path->exp->value = ft_strdup(new_path->exp->value);
		free(new_path->exp->value);
		new_path->exp->value = ft_strdup(cwd);
	}
	else
	{
		perror("getcwd");
		zone->exitt = 1;
	}
	free(cwd);
}

int	find_pwd(t_elem *env)
{
	while (env)
	{
		if (ft_strcmp(env->name, "PWD") == 0)
			return (1);
		env = env->next;
	}
	return (0);
}

void	cd_command(t_list *com, t_sum *zone)
{
	t_sum	*oldpwd_path;
	t_sum	*pwd_path;

	oldpwd_path = ft_malloc(sizeof(t_sum), NULL, ALLOC);
	*oldpwd_path = *zone;
	pwd_path = ft_malloc(sizeof(t_sum), NULL, ALLOC);
	*pwd_path = *zone;
	while (pwd_path->env && ft_strcmp(pwd_path->env->name, "PWD") != 0)
		pwd_path->env = pwd_path->env->next;
	while (pwd_path->exp && ft_strcmp(pwd_path->exp->name, "PWD") != 0)
		pwd_path->exp = pwd_path->exp->next;
	while (oldpwd_path->env && ft_strcmp(oldpwd_path->env->name, "OLDPWD") != 0)
		oldpwd_path->env = oldpwd_path->env->next;
	while (oldpwd_path->exp && ft_strcmp(oldpwd_path->exp->name, "OLDPWD") != 0)
		oldpwd_path->exp = oldpwd_path->exp->next;
	if (com->args[0] == NULL || (ft_strcmp(com->args[0], "~") == 0
			&& com->args[1] == NULL))
		apply_empty_cd(zone);
	else if (chdir(com->args[0]) == -1)
	{
		perror("cd");
		zone->exitt = 1;
	}
	apply_cd(pwd_path, oldpwd_path, zone);
}
