/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:14:14 by mboudrio          #+#    #+#             */
/*   Updated: 2023/09/30 22:14:16 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	print_str_with_int(char *string, unsigned int n)
{
	print_string(string);
	print_number(n);
	write(1, "\n", 1);
}

void	print_string(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		write(1, &string[i], 1);
		i++;
	}
}

void	print_number(unsigned int number)
{
	char	n;

	if (number >= 0 && number <= 9)
	{
		n = number + 48;
		write(1, &n, 1);
	}
	else
	{
		print_number(number / 10);
		print_number(number % 10);
	}
}
