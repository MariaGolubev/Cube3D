/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/03 11:38:10 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/12 14:50:57 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int	queue_init(t_queue *queue, size_t size)
{
	queue->data = ft_calloc(size, sizeof(void *));
	if (queue->data == NULL)
		return (1);
	queue->front = 0;
	queue->rear = -1;
	queue->size = size;
	queue->count = 0;
	queue->is_allocated = false;
	return (0);
}
