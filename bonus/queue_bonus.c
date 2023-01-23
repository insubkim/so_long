/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/01/24 02:02:21 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_queue	*init_queue(void)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		handle_error(MALLOC_ERROR);
	queue -> front = 0;
	queue -> rear = 0;
	return (queue);
}

void	enqueue(t_queue *queue, t_node *node)
{
	if (!(queue -> front))
	{
		queue -> front = node;
		queue -> rear = node;
	}
	else
	{
		queue -> rear -> back = node;
		node -> next = queue -> rear;
		queue -> rear = node;
	}
}

t_node	*dequeue(t_queue *queue)
{
	t_node	*node;

	if (!(queue -> front))
		return (0);
	node = queue -> front;
	queue -> front = queue -> front -> back;
	if (queue -> front)
		queue -> front -> next = 0;
	else
		queue -> rear = 0;
	node -> back = 0;
	return (node);
}

t_node	*make_node(int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		handle_error(MALLOC_ERROR);
	node -> data = data;
	node -> next = 0;
	node -> back = 0;
	return (node);
}

void	free_linked_list(t_node *node)
{
	t_node	*tmp;

	while (node)
	{
		tmp = node;
		node = node -> back;
		free(tmp);
	}
}
