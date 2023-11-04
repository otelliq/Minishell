/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:13:37 by mboudrio          #+#    #+#             */
/*   Updated: 2023/09/30 22:13:39 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void	*allocate_memory(unsigned int size, t_address **addresses)
{
	void		*ptr;
	t_address	*node;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	node = create_node1(ptr, size);
	if (node == NULL)
	{
		free(ptr);
		return (NULL);
	}
	add_node_back1(addresses, node);
	return (ptr);
}

static void	*free_memory(t_address **addresses)
{
	t_address	*t_node;

	t_node = *addresses;
	if (!*addresses)
		return (NULL);
	while (t_node->next)
	{
		t_node = t_node->next;
		destroy_node1(t_node->prev);
	}
	destroy_node1(t_node);
	*addresses = NULL;
	return (NULL);
}

static void	*free_pointer(void *ptr, t_address *addresses)
{
	t_address	*temp;

	temp = addresses;
	while (temp)
	{
		if (temp->ptr == ptr)
		{
			temp->prev->next = temp->next;
			free(temp->ptr);
			temp->dealloc = 1;
			temp->size = 0;
			temp->ptr = NULL;
			free(temp);
			return (NULL);
		}
		temp = temp->next;
	}
	return (NULL);
}

void	*ft_malloc(unsigned int size, void *free_ptr, int type)
{
	static t_address	*addresses = NULL;

	if (type == ALLOC)
		return (allocate_memory(size, &addresses));
	else if (type == FREE_ALL)
		return (free_memory(&addresses));
	else if (type == FREE)
		return (free_pointer(free_ptr, addresses));
	return (NULL);
}
