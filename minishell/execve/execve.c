/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 22:34:15 by otelliq           #+#    #+#             */
/*   Updated: 2023/09/30 16:23:51 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**find_executable(char *command, t_elem *elem)
{
	int		i;
	char	*s;
	char	**cmd;

	i = 0;
	while (elem)
	{
		if (ft_strcmp(elem->name, "PATH") == 0)
			s = ft_strdup(elem->value);
		elem = elem->next;
	}
	cmd = ft_split(s, ':');
	while (cmd[i])
	{
		cmd[i] = ft_strjoin_env(cmd[i], command);
		i++;
	}
	return (cmd);
}

void	ft_execve(t_list *list, t_sum *sum, char **elementv, int i)
{
	char	**path;

	path = NULL;
	signal(SIGQUIT, SIG_DFL);
	if (ft_access(list->command, X_OK) == 0)
		access_handling(list->command, list->all, elementv);
	if (path_finder(sum->env) == 1)
		path = find_executable(list->command, sum->env);
	{
		while (path[i])
		{
			if (ft_access(path[i], X_OK) == 0)
			{
				access_handling(path[i], list->cmdarg, path);
				exit(0);
			}
			i++;
		}
	}
	ft_putendl_fd("command not found", 2);
	exit(127);
}

char	**setup_exe(t_elem *elem)
{
	char	**envv;
	t_elem	*curr;
	int		len;
	int		i;

	curr = elem;
	len = 0;
	while (curr)
	{
		len++;
		curr = curr->next;
	}
	envv = (char **)ft_malloc(sizeof(char *) * (len + 1), NULL, ALLOC);
	if (!envv)
		return (NULL);
	curr = elem;
	i = 0;
	while (curr)
	{
		envv[i] = ft_strdup(curr->content);
		curr = curr->next;
		i++;
	}
	envv[i] = NULL;
	return (envv);
}

void	execute_exe(t_list *list, t_sum *sum)
{
	char	**envv;
	int		stat;
	pid_t	pid;

	envv = setup_exe(sum->env);
	pid = fork();
	if (pid == 0)
		ft_execve(list, sum, envv, 0);
	else if (pid > 0)
	{
		if (waitpid(pid, &stat, 0) == 1)
		{
			perror("wait");
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(stat) != 0)
			sum->exitt = WEXITSTATUS(stat);
		else if (WIFSIGNALED(stat))
			sum->exitt = WTERMSIG(stat) + 128;
	}
	else
		perror("fork");
}
