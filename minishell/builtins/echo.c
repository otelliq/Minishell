/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:28:13 by otelliq           #+#    #+#             */
/*   Updated: 2023/09/29 22:42:27 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	option_check(t_list *list)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	if (list->args[i][j++] == '-')
	{
		while (list->args[i][j])
		{
			if (list->args[i][j] == 'n')
				flag = 1;
			else
			{
				flag = 0;
				break ;
			}
			j++;
		}
		if (flag == 1)
			return (1);
	}
	return (0);
}

void	echo_command(t_list *list)
{
	int	i;

	i = 0;
	if (list->args[i] == NULL)
	{
		printf("\n");
		return ;
	}
	if (option_check(list) != 0)
		i++;
	while (list->args[i])
	{
		printf("%s", list->args[i]);
		if (list->args[i + 1] != '\0')
			printf(" ");
		i++;
	}
	if (option_check(list) == 0)
		printf("\n");
}
