/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch_program_logic.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:03:01 by mboudrio          #+#    #+#             */
/*   Updated: 2023/09/30 22:01:43 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	reading_line(char *line)
{
	if (ft_strncmp(line, "", ft_strlen(line)) == 0 || !only_spaces(line))
		return (1);
	return (0);
}

void	initialize_data(t_data **data)
{
	*data = ft_malloc(sizeof(t_data), NULL, ALLOC);
	(*data)->lex = ft_malloc(sizeof(t_list), NULL, ALLOC);
	(*data)->lex = 0;
}

void	initialize_sum(t_sum **sum, char **env)
{
	*sum = malloc(sizeof(t_sum));
	(*sum)->env = env_init(env);
	(*sum)->exp = env_init(env);
	(*sum)->exitt = 0;
}

void	execute_program_logic(t_data *data, t_sum *sum)
{
	char	*line;
	char	*perfect_line;
	char	*tmp;

	while (1)
	{
		initialize_data(&data);
		signal(SIGINT, ft_signals);
		line = readline("minishell->");
		tmp = ft_strtrim(line, " \t");
		free(line);
		line = tmp;
		if (line == NULL)
			break ;
		add_history(line);
		if (*line && is_empty(line) && checking_errors(line))
		{
			perfect_line = add_spaces(line);
			pre_tokenization(perfect_line, data, sum, sum->env);
		}
	}
}

void	lunch_program_logic(char **env)
{
	t_data	*data;
	t_sum	*sum;

	data = NULL;
	initialize_sum(&sum, env);
	execute_program_logic(data, sum);
}
