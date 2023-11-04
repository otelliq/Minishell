/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:51:33 by otelliq           #+#    #+#             */
/*   Updated: 2023/09/30 12:53:41 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	finding_here_doc(t_list *s)
{
	int	i;

	i = 0;
	while (s->all[i])
	{
		if (ft_strcmp(s->all[i], "<<") == 0)
			return (1);
		i++;
	}
	return (0);
}

int	finding_rederection(t_list *s)
{
	int	i;

	i = 0;
	while (s->all[i])
	{
		if (ft_strcmp(s->all[i], "<") == 0)
			return (1);
		if (ft_strcmp(s->all[i], ">") == 0)
			return (1);
		if (ft_strcmp(s->all[i], ">>") == 0)
			return (1);
		i++;
	}
	return (0);
}

void	applying_her_doc(t_data *data, t_list *s)
{
	int	i;

	i = 0;
	data->here_doc_flag = finding_here_doc(s);
	while (s->all[i])
	{
		if (ft_strcmp(s->all[i], "<<") == 0)
			here_doc_redirection(data, s, i);
		i++;
	}
}
