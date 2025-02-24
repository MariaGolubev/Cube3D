/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue_destroy.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/03 11:40:36 by mgolubev      #+#    #+#                 */
/*   Updated: 2025/02/05 15:44:01 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	queue_destroy(t_queue *queue, void (*del)(void *))
{
	void	*data;

	data = queue_dequeue(queue);
	while (data != NULL)
	{
		del(data);
		data = queue_dequeue(queue);
	}
	free(queue->data);
	queue->data = NULL;
	queue->front = 0;
	queue->rear = 0;
	queue->size = 0;
	if (queue->is_allocated)
		free(queue);
}
