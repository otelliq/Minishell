/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:51:43 by otelliq           #+#    #+#             */
/*   Updated: 2023/09/29 23:50:56 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

void	exit_command(t_list *list, t_sum *sum)
{
	if (!list->args[0])
		exit(sum->exitt);
	else if (list->args[0] && (check_digit(list->args[0]) && !list->args[1]))
		exit(ft_atoi(list->args[0]));
	else if (!check_digit(list->args[0]))
	{
		printf("exit, %s is not numeric", list->args[0]);
		exit(255);
	}
	else if (check_digit(list->args[0]) && check_digit(list->args[1])
		&& list->args[1])
		printf("too many arguments\n");
}
