/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+	+#+			  */
/*   Created: 2023/09/18 10:16:38 by otelliq           #+#    #+#             */
/*   Updated: 2023/09/18 10:19:20 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_child(t_list *list, int *fid, t_data *data, t_sum *sum)
{
	if (finding_here_doc(list) > 0)
		applying_her_doc(data, list);
	if (finding_rederection(list) > 0)
		applying_redirections_and_fd(data, list);
	close(fid[0]);
	if (list->next)
		dup2(fid[1], 1);
	check_mult_command(list, data, sum);
	close(fid[1]);
	exit(0);
}

void	ft_dup(t_sum *sum, int child_pid)
{
	int	status;
	int	uid;

	uid = waitpid(child_pid, &status, 0);
	if (WIFEXITED(status))
	{
		sum->exitt = WEXITSTATUS(status);
	}
	else if (WIFSIGNALED(status))
	{
		sum->exitt = WTERMSIG(status) + 128;
	}
}

void	ft_dup2(int fid[2])
{
	close(fid[1]);
	dup2(fid[0], 0);
	close(fid[0]);
}

void	just_do_it(t_sum *sum, int status, pid_t child_pid)
{
	int	uid;

	uid = wait(&status);
	while (uid > 0)
	{
		if (uid < child_pid)
			sum->exitt = WEXITSTATUS(status);
		uid = wait(&status);
	}
	sum->exitt = WEXITSTATUS(status);
}

void	ft_fork(t_list *list, t_sum *sum, t_data *data)
{
	pid_t	child_pid;
	int		status;
	int		fid[2];
	int		stdi;
	int		stdo;

	stdi = dup(0);
	stdo = dup(1);
	data->envrt = change_list_to_array(sum->env);
	while (list)
	{
		pipe(fid);
		child_pid = fork();
		if (child_pid == 0)
			ft_child(list, fid, data, sum);
		close(fid[1]);
		dup2(fid[0], 0);
		waitpid(child_pid, &status, WNOHANG);
		sum->exitt = WEXITSTATUS(status);
		close(fid[0]);
		list = list->next;
	}
	just_do_it(sum, status, child_pid);
	dup2(stdi, 0);
	dup2(stdo, 1);
}
