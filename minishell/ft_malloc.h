/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:13:20 by mboudrio          #+#    #+#             */
/*   Updated: 2023/09/30 22:13:21 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

enum e_a_types {
	ALLOC,
	FREE,
	FREE_ALL,
	T_SIZE,
};

struct s_address
{
	void					*ptr;
	unsigned int			size;
	bool					dealloc;
	struct s_address		*next;
	struct s_address		*prev;
};
typedef struct s_address	t_address;

void		*ft_malloc(unsigned int size, void	*free_ptr,
				int type);
t_address	*create_node1(void *ptr, unsigned int size);
void		add_node_back1(t_address **head, t_address *node);
void		destroy_node1(t_address *node);
void		print_string(char *string);
void		print_number(unsigned int number);
void		print_str_with_int(char *string, unsigned int n);
#endif