/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:03:36 by mboudrio          #+#    #+#             */
/*   Updated: 2023/09/30 21:30:37 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	applying_redirections_and_fd(t_data *data, t_list *s)
{
	int	i;

	i = 0;
	while (s->all[i])
	{
		if (ft_strcmp(s->all[i], ">") == 0)
			output_redirection(data, s, i);
		else if (ft_strcmp(s->all[i], ">>") == 0)
			append_redirection(data, s, i);
		else if (ft_strcmp(s->all[i], "<") == 0)
			input_redirection(data, s, i);
		i++;
	}
}

void	here_doc_redirection(t_data *data, t_list *s, int i)
{
	data->input = open("/tmp/tempo.txt", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	while (1)
	{
		data->here_doc = readline("[heredoc] > ");
		if (data->here_doc == NULL)
			perror("Error reading heredoc input");
		if (*data->here_doc)
		{
			ft_putendl_fd(data->here_doc, data->input);
			free(data->here_doc);
		}
		if (ft_strcmp(data->here_doc, s->all[i + 1]) == 0)
			break ;
	}
	close(data->input);
	data->herdok = open("/tmp/tempo.txt", O_RDONLY);
	unlink("/tmp/tempo.txt");
	if (dup2(data->herdok, STDIN_FILENO) == -1)
	{
		close(data->input);
		exit(1);
	}
	close(data->herdok);
	data->here_doc = 0;
}

void	output_redirection(t_data *data, t_list *s, int i)
{
	data->output = open(s->all[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (data->output == -1)
	{
		perror("Error opening output file");
		exit(1);
	}
	if (dup2(data->output, STDOUT_FILENO) == -1)
	{
		perror("Duplication of file descriptor failed");
		close(data->output);
		exit(1);
	}
	if (close(data->output) == -1)
	{
		perror("Error closing output file descriptor");
		exit(1);
	}
}

void	append_redirection(t_data *data, t_list *s, int i)
{
	data->output = open(s->all[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (data->output == -1)
	{
		perror("Error opening output file for append");
		exit(1);
	}
	if (dup2(data->output, STDOUT_FILENO) == -1)
	{
		perror("Duplication of file descriptor failed");
		close(data->output);
		exit(1);
	}
	if (close(data->output) == -1)
	{
		perror("Error closing output file descriptor");
		exit(1);
	}
}

void	input_redirection(t_data *data, t_list *s, int i)
{
	data->input = open(s->all[i + 1], O_RDONLY);
	if (data->input == -1)
	{
		perror("Error opening input file");
		exit(1);
	}
	if (dup2(data->input, STDIN_FILENO) == -1)
	{
		perror("Duplication of file descriptor failed");
		close(data->input);
		exit(1);
	}
	if (close(data->input) == -1)
	{
		perror("Error closing input file descriptor");
		exit(1);
	}
}
