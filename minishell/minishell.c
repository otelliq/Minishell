/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:03:16 by mboudrio          #+#    #+#             */
/*   Updated: 2023/09/29 20:44:41 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	(void)av;
	if (ac != 1)
		return (1);
	if (!*env)
		return (0);
	signal(SIGQUIT, SIG_IGN);
	lunch_program_logic(env);
	return (0);
}
